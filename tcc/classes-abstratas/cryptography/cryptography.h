/*
 * crypto.h
 *
 *  Created on: 15 de fev de 2021
 *      Author: Paulo Sell
 */

#ifndef CRYPTOGRAPHY_CRYPTOGRAPHY_H_
#define CRYPTOGRAPHY_CRYPTOGRAPHY_H_

#include <iostream>

/* USER PRIVATE INCLUDE BEGINS HERE*/

/* USER PRIVATE INCLUDE ENDS HERE*/

class Cryptography {
public:

	enum SHA_t {
		SHA1 = 1, SHA224 = 2, SHA256 = 3, SHA512 = 4
	};

	enum ALGORITHM_t {
		RSA_PKCS1_V1_5 = 1, RSA_PSS = 2, ECDSA = 3
	};

	enum STATUS_t {
		FAIL = 0, SUCCESS = 1
	};

	typedef struct {
		uint8_t *x;
		uint8_t *y;
	} ecc_key_t;

	typedef struct {
		uint8_t *modulus;
		uint8_t *exponent;
		size_t modulus_len;
		size_t exponent_len;
	} rsa_key_t;

	typedef union {
		ecc_key_t ecc_key;
		rsa_key_t rsa_key;
	} key_t;

	Cryptography();
	virtual STATUS_t shaGen(uint8_t *buffer_in, size_t in_len,
			uint8_t *buffer_out, size_t *out_len, SHA_t sha_type);

	virtual STATUS_t sigCheck(uint8_t *buffer_expected, uint8_t *buffer_in,
			size_t buffer_in_len, key_t *pubkey, ALGORITHM_t algo);

	STATUS_t shaCheck(uint8_t *buffer_expected, uint8_t *buffer_digest,
			SHA_t sha_type);

	/*
	 * User might need to add specific platform methods
	 */

};

#endif /* CRYPTOGRAPHY_CRYPTOGRAPHY_H_ */
