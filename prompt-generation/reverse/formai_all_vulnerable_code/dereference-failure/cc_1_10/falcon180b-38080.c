//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 32
#define MAX_PLAIN_TEXT_LEN 1024
#define MAX_CIPHER_TEXT_LEN (MAX_PLAIN_TEXT_LEN + 2)

typedef struct {
    char key[MAX_KEY_LEN + 1];
    char plain_text[MAX_PLAIN_TEXT_LEN + 1];
    char cipher_text[MAX_CIPHER_TEXT_LEN + 1];
} encryption_context_t;

void generate_key(char* key, int len) {
    for (int i = 0; i < len; i++) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[len] = '\0';
}

void encrypt(encryption_context_t* ctx) {
    int i;
    for (i = 0; ctx->plain_text[i]!= '\0'; i++) {
        ctx->cipher_text[i] = ctx->plain_text[i];
    }
    ctx->cipher_text[i] = '\0';
}

void decrypt(encryption_context_t* ctx) {
    int i;
    for (i = 0; ctx->cipher_text[i]!= '\0'; i++) {
        ctx->plain_text[i] = ctx->cipher_text[i];
    }
    ctx->plain_text[i] = '\0';
}

int main() {
    encryption_context_t ctx;
    int len;

    printf("Enter the length of the key (between 1 and %d):\n", MAX_KEY_LEN);
    scanf("%d", &len);

    generate_key(ctx.key, len);
    printf("Generated key: %s\n", ctx.key);

    printf("Enter the plain text to be encrypted:\n");
    scanf("%s", ctx.plain_text);

    encrypt(&ctx);
    printf("Encrypted text: %s\n", ctx.cipher_text);

    printf("Enter the encrypted text to be decrypted:\n");
    scanf("%s", ctx.cipher_text);

    decrypt(&ctx);
    printf("Decrypted text: %s\n", ctx.plain_text);

    return 0;
}