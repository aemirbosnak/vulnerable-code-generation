//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Salt size in bytes
#define SALT_SIZE 16

// Key size in bits
#define KEY_SIZE 256

// Number of rounds
#define ROUNDS 10000

// Generate a random salt
static void generate_salt(unsigned char *salt) {
    if (RAND_bytes(salt, SALT_SIZE) != 1) {
        fprintf(stderr, "Error generating salt\n");
        exit(1);
    }
}

// Derive a key from a password and salt
static void derive_key(const char *password, const unsigned char *salt, unsigned char *key) {
    if (PKCS5_PBKDF2_HMAC_SHA1(password, strlen(password), salt, SALT_SIZE, ROUNDS, KEY_SIZE / 8, key) != 1) {
        fprintf(stderr, "Error deriving key\n");
        exit(1);
    }
}

// Encrypt a file
static void encrypt_file(const char *input_file, const char *output_file, const unsigned char *key) {
    EVP_CIPHER_CTX *ctx;
    FILE *input, *output;
    int len;
    unsigned char buffer[1024];

    if ((ctx = EVP_CIPHER_CTX_new()) == NULL) {
        fprintf(stderr, "Error creating cipher context\n");
        exit(1);
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) {
        fprintf(stderr, "Error initializing cipher\n");
        exit(1);
    }

    if ((input = fopen(input_file, "rb")) == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(1);
    }

    if ((output = fopen(output_file, "wb")) == NULL) {
        fprintf(stderr, "Error opening output file\n");
        exit(1);
    }

    while ((len = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        if (EVP_EncryptUpdate(ctx, buffer, &len, buffer, len) != 1) {
            fprintf(stderr, "Error encrypting data\n");
            exit(1);
        }

        if (fwrite(buffer, 1, len, output) != len) {
            fprintf(stderr, "Error writing encrypted data\n");
            exit(1);
        }
    }

    if (EVP_EncryptFinal_ex(ctx, buffer, &len) != 1) {
        fprintf(stderr, "Error finalizing encryption\n");
        exit(1);
    }

    if (fwrite(buffer, 1, len, output) != len) {
        fprintf(stderr, "Error writing final encrypted data\n");
        exit(1);
    }

    EVP_CIPHER_CTX_free(ctx);
    fclose(input);
    fclose(output);
}

// Decrypt a file
static void decrypt_file(const char *input_file, const char *output_file, const unsigned char *key) {
    EVP_CIPHER_CTX *ctx;
    FILE *input, *output;
    int len;
    unsigned char buffer[1024];

    if ((ctx = EVP_CIPHER_CTX_new()) == NULL) {
        fprintf(stderr, "Error creating cipher context\n");
        exit(1);
    }

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) {
        fprintf(stderr, "Error initializing cipher\n");
        exit(1);
    }

    if ((input = fopen(input_file, "rb")) == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(1);
    }

    if ((output = fopen(output_file, "wb")) == NULL) {
        fprintf(stderr, "Error opening output file\n");
        exit(1);
    }

    while ((len = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        if (EVP_DecryptUpdate(ctx, buffer, &len, buffer, len) != 1) {
            fprintf(stderr, "Error decrypting data\n");
            exit(1);
        }

        if (fwrite(buffer, 1, len, output) != len) {
            fprintf(stderr, "Error writing decrypted data\n");
            exit(1);
        }
    }

    if (EVP_DecryptFinal_ex(ctx, buffer, &len) != 1) {
        fprintf(stderr, "Error finalizing decryption\n");
        exit(1);
    }

    if (fwrite(buffer, 1, len, output) != len) {
        fprintf(stderr, "Error writing final decrypted data\n");
        exit(1);
    }

    EVP_CIPHER_CTX_free(ctx);
    fclose(input);
    fclose(output);
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <password> <encrypt/decrypt>\n", argv[0]);
        exit(1);
    }

    unsigned char salt[SALT_SIZE];
    unsigned char key[KEY_SIZE / 8];

    // Generate a random salt
    generate_salt(salt);

    // Derive a key from the password and salt
    derive_key(argv[3], salt, key);

    if (!strcmp(argv[4], "encrypt")) {
        // Encrypt the file
        encrypt_file(argv[1], argv[2], key);
    } else if (!strcmp(argv[4], "decrypt")) {
        // Decrypt the file
        decrypt_file(argv[1], argv[2], key);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[4]);
        exit(1);
    }

    return 0;
}