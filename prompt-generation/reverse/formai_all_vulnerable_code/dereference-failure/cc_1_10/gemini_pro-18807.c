//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main()
{
    // The fateful meeting
    char *romeo = "My mistress' eyes are nothing like the sun";
    char *juliet = "O Romeo, Romeo! Wherefore art thou Romeo?";

    // Creating the public key
    EVP_PKEY *pkey = EVP_PKEY_new();
    if (EVP_PKEY_assign_RSA(pkey, RSA_new()) == 0) {
        perror("EVP_PKEY_assign_RSA");
        return EXIT_FAILURE;
    }

    // Romeo's heart, the private key
    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(pkey, NULL);
    if (EVP_PKEY_keygen_init(ctx) != 1) {
        perror("EVP_PKEY_keygen_init");
        return EXIT_FAILURE;
    }

    if (EVP_PKEY_keygen(ctx, pkey) != 1) {
        perror("EVP_PKEY_keygen");
        return EXIT_FAILURE;
    }

    EVP_PKEY_CTX_free(ctx);

    // Juliet's eyes, the public key
    EVP_PKEY *pubkey = EVP_PKEY_new();
    if (EVP_PKEY_copy_parameters(pubkey, pkey) == 0) {
        perror("EVP_PKEY_copy_parameters");
        return EXIT_FAILURE;
    }

    // Romeo's confession
    char *plaintext = "But soft! What light through yonder window breaks?";
    int plaintext_len = strlen(plaintext);

    // Sealing the love with Romeo's private key
    int ciphertext_len = 0;
    unsigned char *ciphertext = malloc(EVP_PKEY_size(pkey));
    if (EVP_PKEY_encrypt(pkey, ciphertext, &ciphertext_len, (unsigned char *)plaintext, plaintext_len) != 1) {
        perror("EVP_PKEY_encrypt");
        return EXIT_FAILURE;
    }

    // Juliet's revelation
    int decryptedtext_len = 0;
    unsigned char *decryptedtext = malloc(EVP_PKEY_size(pkey));
    if (EVP_PKEY_decrypt(pubkey, decryptedtext, &decryptedtext_len, ciphertext, ciphertext_len) != 1) {
        perror("EVP_PKEY_decrypt");
        return EXIT_FAILURE;
    }

    // The star-crossed lovers' eternal vow
    printf("%s", decryptedtext);

    // Freeing the lovers' hearts
    EVP_PKEY_free(pkey);
    EVP_PKEY_free(pubkey);
    free(ciphertext);
    free(decryptedtext);

    return EXIT_SUCCESS;
}