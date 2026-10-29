#include "_config/_config.h"
#ifndef INTERPRETER_COMMANDS_H_
#define INTERPRETER_COMMANDS_H_

// ========================================
// Includes
// ========================================

#include "uCosmos/console.h"
#include "uCosmos/commands.h"

#if COMPONENT_CIPHER_AES128
	#include "cipher_aes128/aes128_demo.h"
#endif

#if COMPONENT_CIPHER_SBOX
	#include "cipher_sbox/sbox_demo.h"
#endif

#if COMPONENT_CRC
	#include "crc/crc_demo.h"
#endif

#if COMPONENT_TOOLS_ESP32
	#include "tools_esp32/tools_esp32.h"
#endif

#if COMPONENT_TOOLS_RP
	#include "tools_rp/tools_rp.h"
#endif

// ========================================
// Command names and function pointers
// ========================================

const command_struct command_list[] = {
	#include "uCosmos/commands.hxx"
	#include "cipher_aes128/aes_demo.hxx"
	#include "cipher_sbox/sbox_demo.hxx"
	#include "crc/crc_demo.hxx"
	
// ========================================
// Hardware related
// ========================================

#if COMPONENT_TOOLS_RP
	{"reset",					tools_rp::reset_cmd},
	{"mem",						tools_rp::mem_cmd},
	{"fcpu",					tools_rp::fcpu_cmd},
#endif

#if COMPONENT_TOOLS_ESP32
	{"reset",					tools_esp32::reset_cmd},
	{"mem",						tools_esp32::mem_cmd},
	{"fcpu",					tools_esp32::fcpu_cmd},
#endif

// ========================================
// Command lists from submodules
// ========================================



};

#endif
