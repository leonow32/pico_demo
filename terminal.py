import threading
import time
import serial
import msvcrt
import sys

DEFAULT_PORT = "COM16"

class SerialTerminal:
    def __init__(self, port):
        self.port_name = port
        self.ser       = None
        self.running   = True
        self.lock = threading.Lock()

    def connect(self):
        while self.running:
            try:
                ser = serial.Serial(port=self.port_name, baudrate=115200, timeout=0.01)

                with self.lock:
                    self.ser = ser

                print(f"=== Połączono z {self.port_name} ===")
                return

            except serial.SerialException:
                time.sleep(0.01)

    def close_port(self):
        with self.lock:
            if self.ser is not None:
                try:
                    self.ser.close()
                except Exception:
                    pass
                self.ser = None

    def get_serial(self):
        with self.lock:
            return self.ser

    def rx_thread(self):
        while self.running:
            ser = self.get_serial()

            if ser is None:
                self.connect()
                continue

            try:
                data = ser.read(1024)

                if data:
                    print(data.decode("utf-8", errors="replace"), end="", flush=True)

            except (serial.SerialException, OSError):
                print("\n=== Port rozłączony ===")
                self.close_port()

    def tx_thread(self):
        while self.running:
            try:
                ch = msvcrt.getch()

            except(KeyboardInterrupt, EOFError):
                self.running = False
                break
                
            if ch == b'\x11':      # Ctrl+Q
                print("=== Koniec programu")
                self.running = False
                break

            ser = self.get_serial()

            if ser is None:
                continue

            try:
                ser.write(ch)

            except (serial.SerialException, OSError):
                print("=== Błąd zapisu")
                self.close_port()

    def run(self):
        rx = threading.Thread(target=self.rx_thread, daemon=True)
        rx.start()

        try:
            self.tx_thread()

        finally:
            self.running = False
            self.close_port()

if __name__ == "__main__":
    
    if len(sys.argv) > 1:
        port = sys.argv[1]
    else:
        port = DEFAULT_PORT
    
    term = SerialTerminal(port)
    term.run()
