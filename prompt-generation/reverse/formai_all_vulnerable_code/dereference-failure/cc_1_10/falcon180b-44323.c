//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_KEY_SIZE 1024
#define MAX_MESSAGE_SIZE 1000000

typedef struct {
    int key_size;
    char *key;
    int message_size;
    char *message;
} EncryptionContext;

void generate_key(char *key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(EncryptionContext *context) {
    int key_size = context->key_size;
    char *key = context->key;
    int message_size = context->message_size;
    char *message = context->message;

    for (int i = 0; i < message_size; i++) {
        message[i] = message[i] ^ key[i % key_size];
    }
}

void decrypt(EncryptionContext *context) {
    int key_size = context->key_size;
    char *key = context->key;
    int message_size = context->message_size;
    char *message = context->message;

    for (int i = 0; i < message_size; i++) {
        message[i] = message[i] ^ key[i % key_size];
    }
}

int main() {
    EncryptionContext context;
    context.key_size = MAX_KEY_SIZE;
    context.message_size = MAX_MESSAGE_SIZE;

    context.key = (char *) malloc(context.key_size);
    generate_key(context.key, context.key_size);

    context.message = (char *) malloc(context.message_size);
    for (int i = 0; i < context.message_size; i++) {
        context.message[i] = rand() % 256;
    }

    encrypt(&context);

    printf("Encrypted message:\n");
    for (int i = 0; i < context.message_size; i++) {
        printf("%d ", context.message[i]);
    }

    decrypt(&context);

    printf("\nDecrypted message:\n");
    for (int i = 0; i < context.message_size; i++) {
        printf("%d ", context.message[i]);
    }

    free(context.key);
    free(context.message);

    return 0;
}