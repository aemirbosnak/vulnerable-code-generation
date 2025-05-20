//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

int main(int argc, char *argv[])
{
    // Check if the user has provided enough arguments.
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <message> <public_key.pem> <private_key.pem>\n", argv[0]);
        return 1;
    }

    // Read the message from the command line.
    char *message = argv[1];

    // Read the public key from a file.
    FILE *public_key_file = fopen(argv[2], "rb");
    if (public_key_file == NULL) {
        fprintf(stderr, "Error opening public key file: %s\n", argv[2]);
        return 1;
    }

    RSA *public_key = RSA_new();
    if (PEM_read_RSA_PUBKEY(public_key_file, &public_key, NULL, NULL) == 0) {
        fprintf(stderr, "Error reading public key from file: %s\n", argv[2]);
        fclose(public_key_file);
        return 1;
    }
    fclose(public_key_file);

    // Read the private key from a file.
    FILE *private_key_file = fopen(argv[3], "rb");
    if (private_key_file == NULL) {
        fprintf(stderr, "Error opening private key file: %s\n", argv[3]);
        return 1;
    }

    RSA *private_key = RSA_new();
    if (PEM_read_RSAPrivateKey(private_key_file, &private_key, NULL, NULL) == 0) {
        fprintf(stderr, "Error reading private key from file: %s\n", argv[3]);
        fclose(private_key_file);
        return 1;
    }
    fclose(private_key_file);

    // Encrypt the message using the public key.
    int encrypted_message_length = RSA_size(public_key);
    unsigned char *encrypted_message = malloc(encrypted_message_length);
    if (encrypted_message == NULL) {
        fprintf(stderr, "Error allocating memory for encrypted message\n");
        return 1;
    }

    if (RSA_public_encrypt(strlen(message), (unsigned char *)message, encrypted_message, public_key, RSA_PKCS1_OAEP_PADDING) == -1) {
        fprintf(stderr, "Error encrypting message\n");
        free(encrypted_message);
        return 1;
    }

    // Decrypt the message using the private key.
    unsigned char *decrypted_message = malloc(strlen(message));
    if (decrypted_message == NULL) {
        fprintf(stderr, "Error allocating memory for decrypted message\n");
        return 1;
    }

    if (RSA_private_decrypt(encrypted_message_length, encrypted_message, decrypted_message, private_key, RSA_PKCS1_OAEP_PADDING) == -1) {
        fprintf(stderr, "Error decrypting message\n");
        free(decrypted_message);
        free(encrypted_message);
        return 1;
    }

    // Print the decrypted message.
    printf("Decrypted message: %s\n", decrypted_message);

    // Free the allocated memory.
    free(decrypted_message);
    free(encrypted_message);

    // Free the RSA keys.
    RSA_free(public_key);
    RSA_free(private_key);

    return 0;
}