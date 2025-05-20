//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

int main(void)
{
    EVP_PKEY *evp_key = NULL;
    RSA *rsa_key = NULL;
    char *key_file = "private.pem";
    char *msg = "Hello, world!";
    unsigned char *enc_msg = NULL;
    size_t enc_msg_len = 0;
    unsigned char *dec_msg = NULL;
    size_t dec_msg_len = 0;

    FILE *fp = fopen(key_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening key file %s\n", key_file);
        exit(EXIT_FAILURE);
    }
    evp_key = PEM_read_PrivateKey(fp, NULL, NULL, NULL);
    fclose(fp);
    if (evp_key == NULL) {
        fprintf(stderr, "Error reading private key from %s\n", key_file);
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    rsa_key = EVP_PKEY_get1_RSA(evp_key);
    if (rsa_key == NULL) {
        fprintf(stderr, "Error getting RSA key from EVP key\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    enc_msg_len = RSA_size(rsa_key);
    enc_msg = malloc(enc_msg_len);
    if (enc_msg == NULL) {
        fprintf(stderr, "Error allocating memory for encrypted message\n");
        exit(EXIT_FAILURE);
    }
    if (RSA_public_encrypt(strlen(msg), (unsigned char *)msg, enc_msg, rsa_key, RSA_PKCS1_OAEP_PADDING) != 1) {
        fprintf(stderr, "Error encrypting message\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    dec_msg_len = RSA_size(rsa_key);
    dec_msg = malloc(dec_msg_len);
    if (dec_msg == NULL) {
        fprintf(stderr, "Error allocating memory for decrypted message\n");
        exit(EXIT_FAILURE);
    }
    if (RSA_private_decrypt(enc_msg_len, enc_msg, dec_msg, rsa_key, RSA_PKCS1_OAEP_PADDING) != 1) {
        fprintf(stderr, "Error decrypting message\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    printf("Encrypted message: %s\n", enc_msg);
    printf("Decrypted message: %s\n", dec_msg);
    RSA_free(rsa_key);
    EVP_PKEY_free(evp_key);
    free(enc_msg);
    free(dec_msg);
    return EXIT_SUCCESS;
}