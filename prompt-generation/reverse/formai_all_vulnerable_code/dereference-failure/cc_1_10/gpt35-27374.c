//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

int main() {
    // Generate RSA Key Pair
    RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    if (!rsa) {
        printf("Error generating RSA Key Pair.\n");
        exit(EXIT_FAILURE);
    }

    // Convert RSA Key Pair to PEM format
    BIO *bio_private = BIO_new(BIO_s_mem());
    BIO *bio_public = BIO_new(BIO_s_mem());
    if (!PEM_write_bio_RSAPrivateKey(bio_private, rsa, NULL, NULL, 0, NULL, NULL)) {
        printf("Error writing RSA Private Key to BIO.\n");
        exit(EXIT_FAILURE);
    }
    if (!PEM_write_bio_RSA_PUBKEY(bio_public, rsa)) {
        printf("Error writing RSA Public Key to BIO.\n");
        exit(EXIT_FAILURE);
    }

    // Extract PEM format from BIO
    char *private_key = NULL;
    char *public_key = NULL;
    long private_key_size = BIO_get_mem_data(bio_private, &private_key);
    long public_key_size = BIO_get_mem_data(bio_public, &public_key);

    // Encrypt and Decrypt using RSA Key Pair
    char message[] = "Hello World!";
    int message_len = strlen(message) + 1; // Include null terminator

    // Encrypt
    char *encrypted = (char*) malloc(RSA_size(rsa));
    int encrypted_len = RSA_public_encrypt(message_len, (unsigned char *)message, (unsigned char *)encrypted, rsa, RSA_PKCS1_PADDING);
    if (encrypted_len == -1) {
        printf("Error encrypting message.\n");
        exit(EXIT_FAILURE);
    }

    // Decrypt
    char *decrypted = (char*) malloc(RSA_size(rsa));
    int decrypted_len = RSA_private_decrypt(encrypted_len, (unsigned char *)encrypted, (unsigned char *)decrypted, rsa, RSA_PKCS1_PADDING);
    if (decrypted_len == -1) {
        printf("Error decrypting message.\n");
        exit(EXIT_FAILURE);
    }

    // Output results
    printf("RSA Private Key:\n%s\n", private_key);
    printf("RSA Public Key:\n%s\n", public_key);
    printf("Original Message: %s\n", message);
    printf("Encrypted Message: ");
    for (int i = 0; i < encrypted_len; i++) {
        printf("%02x", (unsigned char)encrypted[i]);
    }
    printf("\n");
    printf("Decrypted Message: %s\n", decrypted);

    // Free memory
    RSA_free(rsa);
    BIO_free_all(bio_private);
    BIO_free_all(bio_public);
    free(private_key);
    free(public_key);
    free(encrypted);
    free(decrypted);

    return 0;
}