//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} EncryptionContext;

EncryptionContext* createEncryptionContext(char* key, char* message) {
    EncryptionContext* ctx = malloc(sizeof(EncryptionContext));
    strcpy(ctx->key, key);
    strcpy(ctx->message, message);
    return ctx;
}

void freeEncryptionContext(EncryptionContext* ctx) {
    free(ctx);
}

void encryptMessage(EncryptionContext* ctx) {
    int keyLength = strlen(ctx->key);
    int messageLength = strlen(ctx->message);

    for (int i = 0; i < messageLength; i++) {
        char c = tolower(ctx->message[i]);
        char k = ctx->key[i % keyLength];
        int offset = isalpha(c)? 'a' : '0';
        ctx->message[i] = (c - offset + k - offset) % 26 + offset;
    }
}

void decryptMessage(EncryptionContext* ctx) {
    int keyLength = strlen(ctx->key);
    int messageLength = strlen(ctx->message);

    for (int i = 0; i < messageLength; i++) {
        char c = ctx->message[i];
        char k = ctx->key[i % keyLength];
        int offset = isalpha(c)? 'a' : '0';
        ctx->message[i] = (c - offset - k + 26) % 26 + offset;
    }
}

int main() {
    EncryptionContext* ctx = createEncryptionContext("mysecretkey", "Hello, world!");
    encryptMessage(ctx);
    printf("Encrypted message: %s\n", ctx->message);

    decryptMessage(ctx);
    printf("Decrypted message: %s\n", ctx->message);

    freeEncryptionContext(ctx);
    return 0;
}