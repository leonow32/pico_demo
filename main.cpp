#include "_config/_config.h"
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

#if COMPONENT_TOOLS_RP
	#include "tools_rp/tools_rp.h"
#endif

#define GENERATE_SLEEP_TASK(name)     \
	void name(run_mode_t run_mode) {  \
		switch(run_mode) {            \
			case os_run:              \
				sleep_ms(1);          \
				break;                \
                                      \
			case os_id:               \
				task_name = __func__; \
				break;                \
		}                             \
	}                                 \

GENERATE_SLEEP_TASK(sleep_1ms_task);
GENERATE_SLEEP_TASK(sleep_2ms_task);
GENERATE_SLEEP_TASK(sleep_5ms_task);
GENERATE_SLEEP_TASK(sleep_10ms_task);
GENERATE_SLEEP_TASK(sleep_20ms_task);
GENERATE_SLEEP_TASK(sleep_50ms_task);
GENERATE_SLEEP_TASK(sleep_100ms_task);
GENERATE_SLEEP_TASK(sleep_200ms_task);
GENERATE_SLEEP_TASK(sleep_500ms_task);

int main() {
	stdio_init_all();
	sleep_ms(300);

	uCosmos_init();

	task_add(sleep_1ms_task,   1000);
	task_add(sleep_2ms_task,   500);
	task_add(sleep_5ms_task,   200);
	task_add(sleep_10ms_task,  100);
	task_add(sleep_20ms_task,  50);
	task_add(sleep_50ms_task,  20);
	task_add(sleep_100ms_task, 10);
	task_add(sleep_200ms_task, 5);
	task_add(sleep_500ms_task, 2);

	uCosmos_scheduler();

	LOGW("End of main()");
}
