#ifndef AES128_CONFIG_H_
#define AES128_CONFIG_H_

#if PRODUCT_DEMO

	constexpr uint8_t aes128_key[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
	constexpr uint8_t aes128_iv[16]  = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	#define AES128_USE_CBC					false		// Cipher Block Chaining: Each plaintext block is XORed with the previous ciphertext block before encryption. Requires IV, more secure, recommended.
	#define AES128_USE_CBC_SOFT				true		// Software implementation of CBC without hardware acceleration
	#define AES128_USE_ECB					false		// Electronic Codebook: Divides plaintext into fixed-size blocks, each encrypted independently. No IV needed, but less secure, not recommended for sensitive data.
	#define AES128_USE_ECB_SOFT				true		// Software implementation of ECB without hardware acceleration

	#define AES128_USE_DEMO_COMMANDS 		true
	#define AES128_CONFIG_DONE
#endif

// ========================================
// Error handling
// ========================================

#ifndef AES128_CONFIG_DONE
	#error "Missing config"
#endif

#endif
