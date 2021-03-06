/**
 * @file
 * Encryption/decryption module documentation file.
 *
 *  Copyright (C) 2006-2015, ARM Limited, All Rights Reserved
 *  SPDX-License-Identifier: GPL-2.0
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 */

/**
 * @addtogroup encdec_module Encryption/decryption module
 *
 * The Encryption/decryption module provides encryption/decryption functions.
 * One can differentiate between symmetric and asymmetric algorithms; the
 * symmetric ones are mostly used for message confidentiality and the asymmetric
 * ones for key exchange and message integrity.
 * Some symmetric algorithms provide different block cipher modes, mainly
 * Electronic Code Book (ECB) which is used for short (64-bit) messages and
 * Cipher Block Chaining (CBC) which provides the structure needed for longer
 * messages. In addition the Cipher Feedback Mode (CFB-128) stream cipher mode,
 * Counter mode (CTR) and Galois Counter Mode (GCM) are implemented for
 * specific algorithms.
 *
 * All symmetric encryption algorithms are accessible via the generic cipher layer
 * (see \c mbedtls_cipher_setup()).
 *
 * The asymmetric encryptrion algorithms are accessible via the generic public
 * key layer (see \c mbedtls_pk_init()).
 *
 * The following algorithms are provided:
 * - Symmetric:
 *   - AES (see \c mbedtls_aes_crypt_ecb(), \c mbedtls_aes_crypt_cbc(), \c mbedtls_aes_crypt_cfb128() and
 *     \c mbedtls_aes_crypt_ctr()).
 *   - ARCFOUR (see \c mbedtls_arc4_crypt()).
 *   - Blowfish / BF (see \c mbedtls_blowfish_crypt_ecb(), \c mbedtls_blowfish_crypt_cbc(),
 *     \c mbedtls_blowfish_crypt_cfb64() and \c mbedtls_blowfish_crypt_ctr())
 *   - Camellia (see \c mbedtls_camellia_crypt_ecb(), \c mbedtls_camellia_crypt_cbc(),
 *     \c mbedtls_camellia_crypt_cfb128() and \c mbedtls_camellia_crypt_ctr()).
 *   - DES/3DES (see \c mbedtls_des_crypt_ecb(), \c mbedtls_des_crypt_cbc(), \c mbedtls_des3_crypt_ecb()
 *     and \c mbedtls_des3_crypt_cbc()).
 *   - GCM (AES-GCM and CAMELLIA-GCM) (see \c mbedtls_gcm_init())
 *   - XTEA (see \c mbedtls_xtea_crypt_ecb()).
 * - Asymmetric:
 *   - Diffie-Hellman-Merkle (see \c mbedtls_dhm_read_public(), \c mbedtls_dhm_make_public()
 *     and \c mbedtls_dhm_calc_secret()).
 *   - RSA (see \c mbedtls_rsa_public() and \c mbedtls_rsa_private()).
 *   - Elliptic Curves over GF(p) (see \c mbedtls_ecp_point_init()).
 *   - Elliptic Curve Digital Signature Algorithm (ECDSA) (see \c mbedtls_ecdsa_init()).
 *   - Elliptic Curve Diffie Hellman (ECDH) (see \c mbedtls_ecdh_init()).
 *
 * This module provides encryption/decryption which can be used to provide
 * secrecy.
 *
 * It also provides asymmetric key functions which can be used for
 * confidentiality, integrity, authentication and non-repudiation.
 */
