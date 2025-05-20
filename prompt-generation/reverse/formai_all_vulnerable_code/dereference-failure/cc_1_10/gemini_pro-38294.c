//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

int main(int argc, char *argv[])
{
    // Check if the user provided enough arguments.
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <message> <public_key_file> <private_key_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the message from the command line.
    char *message = argv[1];

    // Read the public key from a file.
    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening public key file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    RSA *rsa = RSA_new();
    if (rsa == NULL) {
        fprintf(stderr, "Error creating RSA object\n");
        return EXIT_FAILURE;
    }

    if (PEM_read_RSA_PUBKEY(fp, &rsa, NULL, NULL) != 1) {
        fprintf(stderr, "Error reading public key from file: %s\n", argv[2]);
        RSA_free(rsa);
        return EXIT_FAILURE;
    }

    fclose(fp);

    // Encrypt the message using the public key.
    int encrypted_length = RSA_size(rsa);
    unsigned char *encrypted_message = malloc(encrypted_length);
    if (encrypted_message == NULL) {
        fprintf(stderr, "Error allocating memory for encrypted message\n");
        RSA_free(rsa);
        return EXIT_FAILURE;
    }

    int result = RSA_public_encrypt(strlen(message), (unsigned char *)message, encrypted_message, rsa, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        fprintf(stderr, "Error encrypting message: %s\n", ERR_error_string(ERR_get_error(), NULL));
        RSA_free(rsa);
        free(encrypted_message);
        return EXIT_FAILURE;
    }

    // Write the encrypted message to a file.
    fp = fopen(argv[3], "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening private key file: %s\n", argv[3]);
        RSA_free(rsa);
        free(encrypted_message);
        return EXIT_FAILURE;
    }

    fwrite(encrypted_message, encrypted_length, 1, fp);
    fclose(fp);

    // Free the RSA object and the encrypted message.
    RSA_free(rsa);
    free(encrypted_message);

    return EXIT_SUCCESS;
}