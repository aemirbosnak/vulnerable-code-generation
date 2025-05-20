//Falcon-180B DATASET v1.0 Category: Encryption ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 1024

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    char message[MAX_MESSAGE_SIZE];
    int message_size;
} EncryptionContext;

void generate_key(char* key, int key_size) {
    time_t now = time(NULL);
    srand(now);

    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(EncryptionContext* ctx) {
    for (int i = 0; i < ctx->message_size; i++) {
        char c = ctx->message[i];
        if (isalpha(c)) {
            ctx->message[i] = c + ctx->key[i % ctx->key_size];
        }
    }
}

void decrypt(EncryptionContext* ctx) {
    for (int i = 0; i < ctx->message_size; i++) {
        char c = ctx->message[i];
        if (isalpha(c)) {
            ctx->message[i] = c - ctx->key[i % ctx->key_size];
        }
    }
}

int main() {
    EncryptionContext ctx;

    printf("Enter message to encrypt: ");
    scanf("%s", ctx.message);
    ctx.message_size = strlen(ctx.message);

    printf("Enter encryption key (max %d characters): ", MAX_KEY_SIZE);
    scanf("%s", ctx.key);
    ctx.key_size = strlen(ctx.key);

    if (ctx.key_size > MAX_KEY_SIZE) {
        printf("Error: Key is too long.\n");
        return 1;
    }

    encrypt(&ctx);

    printf("Encrypted message: %s\n", ctx.message);

    return 0;
}