#include "config.h"
#include "uCosmos/uCosmos.h"

#if COMPONENT_CIPHER_AES128
    #include "cipher_aes128/aes128_cbc_soft.h"
    #include "cipher_aes128/aes128_ecb_soft.h"
#endif

#if COMPONENT_CIPHER_SBOX
    #include "cipher_sbox/sbox.h"
#endif

#if COMPONENT_CRC
    #include "crc/crc.h"
#endif

int main() {
    stdio_init_all();
    // sleep_ms(1000);

    uCosmos_init();


    uCosmos_scheduler();
}
