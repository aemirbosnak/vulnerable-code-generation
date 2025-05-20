//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/bio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/rand.h>

int main() {

    // Generate a random 64-byte key
    char* key = malloc(64);
    RAND_bytes(key, 64);

    // Generate a random message
    char* message = malloc(16);
    RAND_bytes(message, 16);

    // Create a RSA key pair
    RSA *rsa = RSA_new();
    BIGNUM *bn = BN_new();
    BN_set_word(bn, RSA_F4);
    RSA_generate_key_ex(rsa, 2048, bn, NULL);
    BN_free(bn);

    // Encrypt the message with the random key and RSA public key
    char* encrypted = malloc(256);
    RSA_public_encrypt(64, key, encrypted, rsa, RSA_PKCS1_OAEP_PADDING);

    // Decrypt the key with the RSA private key
    char* decrypted = malloc(64);
    RSA_private_decrypt(256, encrypted, decrypted, rsa, RSA_PKCS1_OAEP_PADDING);

    // Check if the decrypted key matches the original key
    int match = memcmp(key, decrypted, 64);

    if (match == 0) {
        printf("Key decrypted successfully!\n");

        // Hash the message using SHA256
        unsigned char* hash = malloc(SHA256_DIGEST_LENGTH);
        SHA256((const unsigned char*)message, strlen(message), hash);

        // Encrypt the hash with the key using AES-256-CBC
        char* iv = malloc(16);
        RAND_bytes(iv, 16);

        EVP_CIPHER_CTX *cipher_ctx = EVP_CIPHER_CTX_new();
        EVP_EncryptInit(cipher_ctx, EVP_aes_256_cbc(), key, iv);
        int cipher_len = strlen((const char*)hash);
        char* cipher_text = malloc(cipher_len);

        int len;
        EVP_EncryptUpdate(cipher_ctx, (unsigned char *) cipher_text, &len, hash, cipher_len);
        cipher_len = len;

        EVP_EncryptFinal(cipher_ctx, (unsigned char *) cipher_text + len, &len);
        cipher_len += len;

        // Print the encrypted hash and IV
        printf("Encrypted hash: \n");
        BIO_dump_fp(stdout, (const char*)cipher_text, cipher_len);
        printf("IV: ");
        for(int i=0; i<16; i++) {
            printf("%02x", iv[i]);
        }
        printf("\n");

        // Decrypt the hash with the key and IV
        EVP_CIPHER_CTX *decipher_ctx = EVP_CIPHER_CTX_new();
        EVP_DecryptInit(decipher_ctx, EVP_aes_256_cbc(), key, iv);
        int plain_len = cipher_len;
        char* plain_text = malloc(plain_len);

        EVP_DecryptUpdate(decipher_ctx, (unsigned char *) plain_text, &len, cipher_text, cipher_len);
        plain_len = len;

        EVP_DecryptFinal(decipher_ctx, (unsigned char *) plain_text + len, &len);
        plain_len += len;

        // Compare the decrypted hash and original hash
        int hash_match = memcmp(hash, plain_text, SHA256_DIGEST_LENGTH);

        if (hash_match == 0) {
            printf("Hash decrypted successfully!\n");
        } else {
            printf("Decrypted hash does not match original hash!\n");
        }

        EVP_CIPHER_CTX_free(cipher_ctx);
        EVP_CIPHER_CTX_free(decipher_ctx);

    } else {
        printf("Decrypted key does not match original key!\n");
    }

    free(key);
    free(message);
    free(encrypted);
    free(decrypted);
    return 0;
}