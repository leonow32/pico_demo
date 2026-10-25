import msvcrt
import sys
import time
import serial

running = True
port_name = sys.argv[1] if len(sys.argv) > 1 else "COM1"
is_connected = False

while running:
    try:
        with serial.Serial(port_name, 115200, timeout=0.1) as port:
            print(f"=== Port {port_name} otwarty")
            is_connected = True

            while running:
                if port.in_waiting > 0:
                    data = port.read(port.in_waiting)
                    try:
                        sys.stdout.write(data.decode("utf-8", errors="replace"))
                        sys.stdout.flush()
                    except Exception:
                        pass

                if msvcrt.kbhit():
                    char = msvcrt.getch()

                    if char == b"\x11":  # CTRL-Q zamyka program
                        running = False
                        break
                    try:
                        port.write(char)
                    except serial.SerialException:
                        break
                    except:
                        pass

                time.sleep(0.005)

    except (serial.SerialException, OSError):
        if msvcrt.kbhit():
            char = msvcrt.getch()

            if msvcrt.getch() == b"\x11":  # CTRL-Q zamyka program
                running = False
                break

        if not running:
            break

        if is_connected:
            print(f"=== Port {port_name} zamknięty")
            is_connected = False 

        time.sleep(0.01)

print("=== Koniec")