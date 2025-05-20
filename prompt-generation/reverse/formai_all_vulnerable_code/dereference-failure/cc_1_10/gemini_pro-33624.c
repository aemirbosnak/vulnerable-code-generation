//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define P(x, y) ((x) ^ (y)) // XOR
#define S(x, y) ((x) | (y)) // OR
#define M(x, y) ((x) & (y)) // AND

typedef struct {
    unsigned char *key;
    unsigned char *iv;
    size_t key_size;
    size_t iv_size;
} aes_ctx;

typedef struct {
    unsigned char *plaintext;
    unsigned char *ciphertext;
    size_t plaintext_size;
    size_t ciphertext_size;
} aes_data;

aes_ctx *aes_init(const unsigned char *key, size_t key_size, const unsigned char *iv, size_t iv_size) {
    aes_ctx *ctx = (aes_ctx *)malloc(sizeof(aes_ctx));
    ctx->key = (unsigned char *)malloc(key_size);
    ctx->iv = (unsigned char *)malloc(iv_size);
    memcpy(ctx->key, key, key_size);
    memcpy(ctx->iv, iv, iv_size);
    ctx->key_size = key_size;
    ctx->iv_size = iv_size;
    return ctx;
}

void aes_free(aes_ctx *ctx) {
    free(ctx->key);
    free(ctx->iv);
    free(ctx);
}

aes_data *aes_encrypt(aes_ctx *ctx, const unsigned char *plaintext, size_t plaintext_size) {
    aes_data *data = (aes_data *)malloc(sizeof(aes_data));
    data->plaintext = (unsigned char *)malloc(plaintext_size);
    data->ciphertext = (unsigned char *)malloc(plaintext_size);
    memcpy(data->plaintext, plaintext, plaintext_size);

    // Encryption
    for (size_t i = 0; i < plaintext_size; i++) {
        data->ciphertext[i] = P(data->plaintext[i], ctx->key[i & 0x0F]);
    }

    data->ciphertext_size = plaintext_size;

    return data;
}

aes_data *aes_decrypt(aes_ctx *ctx, const unsigned char *ciphertext, size_t ciphertext_size) {
    aes_data *data = (aes_data *)malloc(sizeof(aes_data));
    data->ciphertext = (unsigned char *)malloc(ciphertext_size);
    data->plaintext = (unsigned char *)malloc(ciphertext_size);
    memcpy(data->ciphertext, ciphertext, ciphertext_size);

    // Decryption
    for (size_t i = 0; i < ciphertext_size; i++) {
        data->plaintext[i] = S(data->ciphertext[i], ctx->iv[i & 0x0F]);
    }

    data->plaintext_size = ciphertext_size;

    return data;
}

int main() {
    // Key: "AES-128"
    unsigned char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
    // IV: "0000000000000000"
    unsigned char iv[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    // Initialize the AES context
    aes_ctx *ctx = aes_init(key, sizeof(key), iv, sizeof(iv));

    // Plaintext: "Hello, world!"
    unsigned char plaintext[] = "Hello, world!";
    size_t plaintext_size = strlen(plaintext);

    // Encrypt the plaintext
    aes_data *encrypted_data = aes_encrypt(ctx, plaintext, plaintext_size);

    // Print the ciphertext
    printf("Ciphertext: ");
    for (size_t i = 0; i < encrypted_data->ciphertext_size; i++) {
        printf("%02X ", encrypted_data->ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    aes_data *decrypted_data = aes_decrypt(ctx, encrypted_data->ciphertext, encrypted_data->ciphertext_size);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_data->plaintext);

    // Free the AES context and the encrypted/decrypted data
    aes_free(ctx);
    free(encrypted_data->plaintext);
    free(encrypted_data->ciphertext);
    free(decrypted_data->plaintext);
    free(decrypted_data->ciphertext);

    return 0;
}