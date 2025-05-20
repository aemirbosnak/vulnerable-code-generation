//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#define KEY_LENGTH 2048
#define PUB_EXP 3
#define BUFFER_SIZE 256

void handle_error() {
    ERR_print_errors_fp(stderr);
    abort();
}

RSA *generate_keypair() {
    RSA *rsa = RSA_generate_key(KEY_LENGTH, PUB_EXP, NULL, NULL);
    if (rsa == NULL) {
        handle_error();
    }
    return rsa;
}

void save_public_key(RSA *rsa, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open %s for writing\n", filename);
        handle_error();
    }
    if (PEM_write_RSA_PUBKEY(fp, rsa) != 1) {
        handle_error();
    }
    fclose(fp);
}

void save_private_key(RSA *rsa, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open %s for writing\n", filename);
        handle_error();
    }
    if (PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL) != 1) {
        handle_error();
    }
    fclose(fp);
}

char *encrypt_message(RSA *rsa, const char *message) {
    int message_length = strlen(message);
    char *encrypted = malloc(RSA_size(rsa));
    if (encrypted == NULL) {
        fprintf(stderr, "Could not allocate memory for encryption\n");
        handle_error();
    }
    int result = RSA_public_encrypt(message_length, (unsigned char *)message, (unsigned char *)encrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        fprintf(stderr, "RSA encryption failed:\n");
        handle_error();
    }
    return encrypted;
}

char *decrypt_message(RSA *rsa, const char *encrypted) {
    char *decrypted = malloc(RSA_size(rsa));
    if (decrypted == NULL) {
        fprintf(stderr, "Could not allocate memory for decryption\n");
        handle_error();
    }
    int result = RSA_private_decrypt(RSA_size(rsa), (unsigned char *)encrypted, (unsigned char *)decrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        fprintf(stderr, "RSA decryption failed:\n");
        handle_error();
    }
    decrypted[result] = '\0';  // Ensure it's null-terminated
    return decrypted;
}

void cleanup(RSA *rsa) {
    RSA_free(rsa);
}

int main() {
    printf("=== Paranoid Public-Key Algorithm Demo ===\n");
    
    // Seed the random number generator for randomness
    srand(time(NULL));

    // Generate RSA key pair
    RSA *rsa = generate_keypair();
    
    // Save keys to files
    save_public_key(rsa, "public_key.pem");
    save_private_key(rsa, "private_key.pem");
    printf("Keys have been generated and saved to file.\n");

    // The message to encrypt
    char message[BUFFER_SIZE];
    printf("Enter a message to encrypt: ");
    fgets(message, BUFFER_SIZE, stdin);
    message[strcspn(message, "\n")] = 0;  // Remove newline character
    
    // Encrypt the message
    char *encrypted = encrypt_message(rsa, message);
    printf("Message encrypted successfully.\n");

    // Decrypt the message
    char *decrypted = decrypt_message(rsa, encrypted);
    printf("Decrypted message: %s\n", decrypted);

    // Clean up
    free(encrypted);
    free(decrypted);
    cleanup(rsa);

    printf("=== All operations completed successfully ===\n");
    return 0;
}