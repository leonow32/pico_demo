#include "../_config/_config.h"
#if COMPONENT_TOOLS_RP
#include "tools_rp.h"
#include "pico/stdlib.h"
#include "hardware/flash.h"

#if PICO_RP2350
    #include "hardware/psram.h"
#endif

extern char __flash_binary_start;
extern char __flash_binary_end;
extern char __StackTop;
extern char __bss_end__;

namespace tools_rp {

void test_cmd(int argc, char * argv[]) {
	uint32_t flash_size = PICO_FLASH_SIZE_BYTES;
    uint32_t flash_used = ((uint32_t)&__flash_binary_end - (uint32_t)&__flash_binary_start);
    uint32_t flash_free = flash_size - flash_used;

    uint32_t ram_size = ((uint32_t)&__StackTop - SRAM_BASE);
    uint32_t ram_used = ((uint32_t)&__bss_end__ - SRAM_BASE);
    uint32_t ram_free = ram_size - ram_used;

    #if PICO_RP2350
        uint32_t psram_size = psram_get_size();
    #else
        uint32_t psram_size = 0;
    #endif

    printf("           FLASH        RAM      PSRAM\n");
    printf("Size: %10lu %10lu %10lu\n", flash_size, ram_size, psram_size);
    printf("Used: %10lu %10lu\n",       flash_used, ram_used);
    printf("Free: %10lu %10lu\n",       flash_free, ram_free);
}

}

#endif
