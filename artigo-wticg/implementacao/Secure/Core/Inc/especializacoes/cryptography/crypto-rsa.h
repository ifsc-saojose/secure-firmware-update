/*
 * crypto-rsa.h
 *
 *  Created on: 23 de fev de 2021
 *      Author: Paulo Sell
 */

#ifndef INC_ESPECIALIZACOES_CRYPTOGRAPHY_CRYPTO_RSA_H_
#define INC_ESPECIALIZACOES_CRYPTOGRAPHY_CRYPTO_RSA_H_


#include <iostream>
#include "interfaces/cryptography/cryptography.h"
#include "crypto.h"



class CryptoRSA : public Cryptography {
public:

	CryptoRSA();
	STATUS_t shaGen(uint8_t * buffer_in, size_t in_len, uint8_t * buffer_out, size_t * out_len, SHA_t sha_type);
	STATUS_t sigCheck(uint8_t* buffer_expected, uint8_t * buffer_in, size_t buffer_in_len, key_t * pubkey, ALGORITHM_t algo);

};


#endif /* INC_ESPECIALIZACOES_CRYPTOGRAPHY_CRYPTO_RSA_H_ */
