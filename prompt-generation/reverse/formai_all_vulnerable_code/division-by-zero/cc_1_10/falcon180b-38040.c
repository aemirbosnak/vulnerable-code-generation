//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LEN 16
#define BLOCK_LEN 64

typedef struct {
    char key[KEY_LEN];
    int key_len;
    int mode;
} encryption_ctx;

void encrypt_block(char* block, encryption_ctx* ctx) {
    int i, j;
    char key[KEY_LEN];
    strcpy(key, ctx->key);
    for(i=0; i<ctx->key_len; i++) {
        key[i] = tolower(key[i]);
    }
    for(i=0; i<BLOCK_LEN; i++) {
        block[i] = block[i] ^ key[i%ctx->key_len];
    }
}

void decrypt_block(char* block, encryption_ctx* ctx) {
    int i, j;
    char key[KEY_LEN];
    strcpy(key, ctx->key);
    for(i=0; i<ctx->key_len; i++) {
        key[i] = tolower(key[i]);
    }
    for(i=0; i<BLOCK_LEN; i++) {
        block[i] = block[i] ^ key[i%ctx->key_len];
    }
}

int main() {
    encryption_ctx ctx;
    char key[KEY_LEN];
    char plain_text[BLOCK_LEN];
    char cipher_text[BLOCK_LEN];
    char decrypted_text[BLOCK_LEN];
    FILE* fp;
    int mode;

    printf("Enter encryption mode (1=encrypt, 2=decrypt): ");
    scanf("%d", &mode);

    printf("Enter key: ");
    scanf("%s", key);

    printf("Enter plain text: ");
    scanf("%s", plain_text);

    ctx.key_len = strlen(key);
    strcpy(ctx.key, key);
    ctx.mode = mode;

    if(mode == 1) {
        encrypt_block(plain_text, &ctx);
        printf("Cipher text: %s\n", plain_text);
    } else {
        decrypt_block(plain_text, &ctx);
        printf("Decrypted text: %s\n", plain_text);
    }

    return 0;
}