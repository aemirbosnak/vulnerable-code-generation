//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configure encryption options
#define KEY_SIZE 16
#define BLOCK_SIZE 16
#define MODE_CBC 1
#define MODE_ECB 0

// Encryption modes
enum encryption_mode {
    CBC,
    ECB
};

// Encryption algorithm
enum encryption_algorithm {
    AES_128,
    AES_192,
    AES_256
};

// Encryption context
struct encryption_context {
    unsigned char key[KEY_SIZE];
    unsigned char iv[BLOCK_SIZE];
    enum encryption_mode mode;
    enum encryption_algorithm algorithm;
};

// Initialize encryption context
void init_encryption_context(struct encryption_context *ctx, unsigned char *key, unsigned char *iv, enum encryption_mode mode, enum encryption_algorithm algorithm) {
    memcpy(ctx->key, key, KEY_SIZE);
    memcpy(ctx->iv, iv, BLOCK_SIZE);
    ctx->mode = mode;
    ctx->algorithm = algorithm;
}

// Encrypt data
int encrypt(struct encryption_context *ctx, unsigned char *plaintext, unsigned char *ciphertext, int len) {
    // Check length
    if (len % BLOCK_SIZE != 0) {
        return -1;
    }

    // Initialize variables
    unsigned char *p = plaintext;
    unsigned char *c = ciphertext;
    unsigned char *iv = ctx->iv;

    // Encrypt data
    for (int i = 0; i < len; i += BLOCK_SIZE) {
        // XOR with IV
        for (int j = 0; j < BLOCK_SIZE; j++) {
            p[j] ^= iv[j];
        }

        // Encrypt block
        // ...

        // Update IV
        memcpy(iv, c, BLOCK_SIZE);

        // Advance pointers
        p += BLOCK_SIZE;
        c += BLOCK_SIZE;
    }

    return 0;
}

// Decrypt data
int decrypt(struct encryption_context *ctx, unsigned char *ciphertext, unsigned char *plaintext, int len) {
    // Check length
    if (len % BLOCK_SIZE != 0) {
        return -1;
    }

    // Initialize variables
    unsigned char *p = plaintext;
    unsigned char *c = ciphertext;
    unsigned char *iv = ctx->iv;

    // Decrypt data
    for (int i = 0; i < len; i += BLOCK_SIZE) {
        // Decrypt block
        // ...

        // XOR with IV
        for (int j = 0; j < BLOCK_SIZE; j++) {
            p[j] ^= iv[j];
        }

        // Update IV
        memcpy(iv, c, BLOCK_SIZE);

        // Advance pointers
        p += BLOCK_SIZE;
        c += BLOCK_SIZE;
    }

    return 0;
}

// Example usage
int main() {
    // Configure encryption context
    struct encryption_context ctx;
    init_encryption_context(&ctx, "mysecretkey", "myinitializationvector", CBC, AES_128);

    // Plaintext
    char *plaintext = "Hello, world!";

    // Ciphertext
    unsigned char ciphertext[strlen(plaintext) + 1];

    // Encrypt data
    int len = encrypt(&ctx, (unsigned char *)plaintext, ciphertext, strlen(plaintext));
    if (len < 0) {
        printf("Error encrypting data.\n");
        return 1;
    }

    // Decrypt data
    unsigned char decrypted[strlen(plaintext) + 1];
    len = decrypt(&ctx, ciphertext, decrypted, len);
    if (len < 0) {
        printf("Error decrypting data.\n");
        return 1;
    }

    // Print decrypted text
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}