#include <stdio.h>
#include "pico/stdlib.h"
#include "config.h"

#if COMPONENT_UCOSMOS
    #include "uCosmos/uCosmos.h"
    #include "uCosmos/console.h"
#endif

/*
#if ESP_PLATFORM

#elif PICO_RP2040 || PICO_RP2350
	
#endif
*/

int main() {
    stdio_init_all();
    sleep_ms(1000);

    #if COMPONENT_UCOSMOS
        os_init();
    #endif

    #if COMPONENT_CONSOLE
        console::init();
    #endif

    // ========================================
	// Main loop
	// ========================================
	
    task_scheduler();

    printf("You should not be here\n");
}
