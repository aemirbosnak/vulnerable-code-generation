//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_LENGTH 16

typedef struct {
    char key[KEY_LENGTH];
} encryption_context;

void init_context(encryption_context *ctx) {
    // Generate a random secret key
    ctx->key[0] = 'a' + (rand() % 26);
    for (int i = 1; i < KEY_LENGTH; i++) {
        ctx->key[i] = 'a' + (rand() % 26);
    }
}

void encrypt(encryption_context *ctx, char *message) {
    // Convert the message to uppercase
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = toupper(message[i]);
    }

    // Create a ciphertext by XORing the message with the secret key
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] ^ ctx->key[i % KEY_LENGTH];
    }
}

void decrypt(encryption_context *ctx, char *ciphertext) {
    // Create a plaintext by XORing the ciphertext with the secret key
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        ciphertext[i] = ciphertext[i] ^ ctx->key[i % KEY_LENGTH];
    }

    // Convert the plaintext to lowercase
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        ciphertext[i] = tolower(ciphertext[i]);
    }
}

int main() {
    encryption_context ctx;
    char message[] = "Hello, World!";
    char ciphertext[strlen(message) * 2];

    init_context(&ctx);
    encrypt(&ctx, message);
    decrypt(&ctx, ciphertext);

    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", ciphertext);
    printf("Decrypted message: %s\n", message);

    return 0;
}