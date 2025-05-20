//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define MAX_KEY_LENGTH 32
#define MAX_IV_LENGTH 16

typedef struct {
    unsigned char *data;
    size_t len;
} buffer_t;

typedef struct {
    buffer_t key;
    buffer_t iv;
} aes_key_t;

typedef struct {
    EVP_CIPHER_CTX *ctx;
    aes_key_t key;
    int ecrypted_len;
} aes_t;

/*
 * Generate an AES key and IV
 */
void aes_key_gen(aes_key_t *key)
{
    unsigned char *key_data = malloc(MAX_KEY_LENGTH);
    unsigned char *iv_data = malloc(MAX_IV_LENGTH);

    RAND_bytes(key_data, MAX_KEY_LENGTH);
    RAND_bytes(iv_data, MAX_IV_LENGTH);

    key->key.data = key_data;
    key->key.len = MAX_KEY_LENGTH;
    key->iv.data = iv_data;
    key->iv.len = MAX_IV_LENGTH;
}

/*
 * Initialize an AES cipher context
 */
void aes_init(aes_t *aes, aes_key_t *key)
{
    EVP_CIPHER_CTX *ctx;

    if ((ctx = EVP_CIPHER_CTX_new()) == NULL) {
        printf("Error initializing cipher context\n");
        exit(EXIT_FAILURE);
    }

    aes->ctx = ctx;
    aes->key = *key;
    aes->ecrypted_len = 0;

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key->key.data, key->iv.data);
}

/*
 * Encrypt a buffer with AES cipher
 */
buffer_t aes_encrypt(aes_t *aes, buffer_t input)
{
    int len;
    buffer_t output;
    unsigned char *output_data = malloc(input.len + EVP_CIPHER_block_size(EVP_aes_256_cbc()));

    EVP_EncryptUpdate(aes->ctx, output_data, &len, input.data, input.len);
    aes->ecrypted_len += len;

    EVP_EncryptFinal_ex(aes->ctx, output_data + len, &len);
    aes->ecrypted_len += len;

    output.data = output_data;
    output.len = aes->ecrypted_len;

    return output;
}

int main(int argc, char *argv[])
{
    aes_t aes;
    aes_key_t key;
    char *input_data = "This is a secret message";

    aes_key_gen(&key);
    aes_init(&aes, &key);

    buffer_t input;
    input.data = (unsigned char *) input_data;
    input.len = strlen(input_data);

    buffer_t output = aes_encrypt(&aes, input);

    printf("Encrypted message:\n");
    for (int i = 0; i < output.len; i++) {
        printf("%02x ", output.data[i]);
    }
    printf("\n");

    return 0;
}