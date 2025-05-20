//FormAI DATASET v1.0 Category: Modern Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretpassword"      // Change this to your secret key
#define BLOCK_SIZE 16               // Block size in bytes

typedef struct {
    unsigned char state[256];
    unsigned char x;
    unsigned char y;
} rc4_ctx;

void rc4_init(rc4_ctx *ctx, const unsigned char *key, size_t keylen) {
    int i;

    // Initialize the state array
    for (i = 0; i < 256; i++) {
        ctx->state[i] = i;
    }

    ctx->x = 0;
    ctx->y = 0;

    // Mix in the key
    for (i = 0; i < 256; i++) {
        unsigned char j = i % keylen;
        unsigned char temp = ctx->state[i];
        ctx->state[i] = ctx->state[j];
        ctx->state[j] = temp ^ key[j];
    }
}

void rc4_crypt(rc4_ctx *ctx, unsigned char *buf, size_t buflen) {
    int i;

    for (i = 0; i < buflen; i++) {
        ctx->x++;
        ctx->y += ctx->state[ctx->x];
        unsigned char temp = ctx->state[ctx->x];
        ctx->state[ctx->x] = ctx->state[ctx->y];
        ctx->state[ctx->y] = temp;
        unsigned char k = ctx->state[(ctx->state[ctx->x] + ctx->state[ctx->y]) & 0xff];
        buf[i] ^= k;
    }
}

void encrypt(const unsigned char *input, size_t inputlen, unsigned char *output, size_t *outputlen) {
    rc4_ctx ctx;
    rc4_init(&ctx, (const unsigned char *)KEY, strlen(KEY));
    rc4_crypt(&ctx, output, inputlen);

    *outputlen = inputlen;
}

void decrypt(const unsigned char *input, size_t inputlen, unsigned char *output, size_t *outputlen) {
    rc4_ctx ctx;
    rc4_init(&ctx, (const unsigned char *)KEY, strlen(KEY));
    rc4_crypt(&ctx, output, inputlen);

    *outputlen = inputlen;
}

int main() {
    printf("Enter the string to be encrypted/decrypted: ");
    char input[100];
    scanf("%[^\n]%*c", input);  // Read the user input

    size_t inputlen = strlen(input);
    size_t outputlen;
    unsigned char *output = (unsigned char *)malloc(inputlen);

    encrypt((const unsigned char *)input, inputlen, output, &outputlen);

    printf("Encrypted string: ");
    for (int i = 0; i < outputlen; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    unsigned char *decrypted_output = (unsigned char *)malloc(outputlen);
    decrypt(output, outputlen, decrypted_output, &outputlen);

    printf("Decrypted string: ");
    for (int i = 0; i < outputlen; i++) {
        printf("%c", decrypted_output[i]);
    }
    printf("\n");

    free(output);
    free(decrypted_output);

    return 0;
}