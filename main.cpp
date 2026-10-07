#include "config.h"

#if COMPONENT_UCOSMOS
    #include "uCosmos/uCosmos.h"
    #include "uCosmos/console.h"
#endif

int main() {
    stdio_init_all();
    sleep_ms(1000);

    #if COMPONENT_UCOSMOS
        os_init();
    #endif

    #if COMPONENT_CONSOLE
        console_init();
    #endif

    // ========================================
	// Main loop
	// ========================================
	
    task_scheduler();
}
