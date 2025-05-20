//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>

// Load the public key from a file
RSA *load_public_key(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    RSA *rsa = RSA_new();
    if (rsa == NULL) {
        fprintf(stderr, "Error creating RSA object\n");
        fclose(fp);
        return NULL;
    }

    if (!PEM_read_RSA_PUBKEY(fp, &rsa, NULL, NULL)) {
        fprintf(stderr, "Error reading public key from file: %s\n", filename);
        RSA_free(rsa);
        fclose(fp);
        return NULL;
    }

    fclose(fp);
    return rsa;
}

// Encrypt a message using the public key
int encrypt_message(RSA *rsa, const unsigned char *message, size_t message_len, unsigned char **encrypted_message, size_t *encrypted_message_len) {
    // Get the size of the encrypted message
    *encrypted_message_len = RSA_size(rsa);

    // Allocate memory for the encrypted message
    *encrypted_message = (unsigned char *)malloc(*encrypted_message_len);
    if (*encrypted_message == NULL) {
        fprintf(stderr, "Error allocating memory for encrypted message\n");
        return -1;
    }

    // Encrypt the message
    int result = RSA_public_encrypt(message_len, message, *encrypted_message, rsa, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        fprintf(stderr, "Error encrypting message\n");
        free(*encrypted_message);
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <public_key_file> <message>\n", argv[0]);
        return -1;
    }

    // Load the public key
    RSA *rsa = load_public_key(argv[1]);
    if (rsa == NULL) {
        fprintf(stderr, "Error loading public key\n");
        return -1;
    }

    // Get the message to encrypt
    size_t message_len = strlen(argv[2]);
    unsigned char *message = (unsigned char *)argv[2];

    // Encrypt the message
    unsigned char *encrypted_message;
    size_t encrypted_message_len;
    if (encrypt_message(rsa, message, message_len, &encrypted_message, &encrypted_message_len) != 0) {
        fprintf(stderr, "Error encrypting message\n");
        RSA_free(rsa);
        return -1;
    }

    // Print the encrypted message
    printf("Encrypted message: ");
    for (size_t i = 0; i < encrypted_message_len; i++) {
        printf("%02x", encrypted_message[i]);
    }
    printf("\n");

    // Free the memory allocated for the encrypted message
    free(encrypted_message);

    // Free the RSA object
    RSA_free(rsa);

    return 0;
}