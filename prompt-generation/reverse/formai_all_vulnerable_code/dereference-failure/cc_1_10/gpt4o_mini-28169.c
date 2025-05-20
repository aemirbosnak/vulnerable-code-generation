//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void generate_keys(RSA **public_key, RSA **private_key) {
    int bits = 2048; // Key size
    BIGNUM *bn = BN_new();
    BN_set_word(bn, RSA_F4);
    
    // Generate RSA key pair
    *private_key = RSA_new();
    if (RSA_generate_key_ex(*private_key, bits, bn, NULL) != 1) {
        fprintf(stderr, "Error generating private key: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(EXIT_FAILURE);
    }

    // Create public key from private key
    *public_key = RSAPublicKey_dup(*private_key);
    if (*public_key == NULL) {
        fprintf(stderr, "Error duplicating public key: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(EXIT_FAILURE);
    }

    BN_free(bn);
}

void save_keys(RSA *public_key, RSA *private_key) {
    FILE *pub_file = fopen("public_key.pem", "wb");
    FILE *priv_file = fopen("private_key.pem", "wb");

    if (pub_file == NULL || priv_file == NULL) {
        fprintf(stderr, "Error opening file for saving keys: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(EXIT_FAILURE);
    }

    // Write the public key to a file
    if (PEM_write_RSAPublicKey(pub_file, public_key) != 1) {
        fprintf(stderr, "Error writing public key: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(EXIT_FAILURE);
    }

    // Write the private key to a file
    if (PEM_write_RSAPrivateKey(priv_file, private_key, NULL, NULL, 0, NULL, NULL) != 1) {
        fprintf(stderr, "Error writing private key: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(EXIT_FAILURE);
    }

    fclose(pub_file);
    fclose(priv_file);
}

void encrypt_message(RSA *public_key, const char *message, unsigned char **encrypted_message, int *encrypted_length) {
    int rsa_size = RSA_size(public_key);
    *encrypted_message = malloc(rsa_size);
    if (*encrypted_message == NULL) {
        fprintf(stderr, "Error allocating memory for encrypted message\n");
        exit(EXIT_FAILURE);
    }

    *encrypted_length = RSA_public_encrypt(strlen(message) + 1, (unsigned char *)message, *encrypted_message, public_key, RSA_PKCS1_OAEP_PADDING);
    if (*encrypted_length == -1) {
        fprintf(stderr, "Error encrypting message: %s\n", ERR_error_string(ERR_get_error(), NULL));
        free(*encrypted_message);
        exit(EXIT_FAILURE);
    }
}

void decrypt_message(RSA *private_key, unsigned char *encrypted_message, int encrypted_length, unsigned char **decrypted_message) {
    int rsa_size = RSA_size(private_key);
    *decrypted_message = malloc(rsa_size);
    if (*decrypted_message == NULL) {
        fprintf(stderr, "Error allocating memory for decrypted message\n");
        exit(EXIT_FAILURE);
    }

    int decrypted_length = RSA_private_decrypt(encrypted_length, encrypted_message, *decrypted_message, private_key, RSA_PKCS1_OAEP_PADDING);
    if (decrypted_length == -1) {
        fprintf(stderr, "Error decrypting message: %s\n", ERR_error_string(ERR_get_error(), NULL));
        free(*decrypted_message);
        exit(EXIT_FAILURE);
    }

    (*decrypted_message)[decrypted_length] = '\0'; // Null terminate the decrypted message
}

int main() {
    RSA *public_key = NULL;
    RSA *private_key = NULL;

    // Generate RSA keys
    generate_keys(&public_key, &private_key);

    // Save the keys to files
    save_keys(public_key, private_key);

    // Sample message
    const char *message = "Hello, this is a secret message.";
    unsigned char *encrypted_message = NULL;
    int encrypted_length = 0;

    // Encrypt the message
    encrypt_message(public_key, message, &encrypted_message, &encrypted_length);

    printf("Encrypted message (hex): ");
    for (int i = 0; i < encrypted_length; i++) {
        printf("%02x", encrypted_message[i]);
    }
    printf("\n");

    unsigned char *decrypted_message = NULL;

    // Decrypt the message
    decrypt_message(private_key, encrypted_message, encrypted_length, &decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    // Cleanup
    free(encrypted_message);
    free(decrypted_message);
    RSA_free(public_key);
    RSA_free(private_key);

    return 0;
}