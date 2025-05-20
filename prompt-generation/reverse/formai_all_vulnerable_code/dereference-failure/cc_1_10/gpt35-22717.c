//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Function to print the hex representation of a string
void print_hex(const char *title, const unsigned char *s, int len)
{
    printf("%s: ", title);
    for (int i = 0; i < len; ++i) {
        printf("%02x", s[i]);
    }
    printf("\n");
}

// Function to encrypt/decrypt data using AES CBC 256-bit encryption algorithm
int aes_cbc_256(char *plaintext, char *key, char *iv, int do_encrypt)
{
    // Create the cipher context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        printf("Error: EVP_CIPHER_CTX_new() failed.\n");
        return EXIT_FAILURE;
    }

    // Initialize the cipher context for AES CBC 256-bit encryption algorithm
    if (!EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)key, (unsigned char *)iv, do_encrypt)) {
        printf("Error: EVP_CipherInit_ex() failed.\n");
        return EXIT_FAILURE;
    }

    int len;
    int ciphertext_len;

    // Allocate memory for the ciphertext buffer
    unsigned char *ciphertext = malloc(strlen(plaintext));

    // Encrypt/decrypt the data
    if (!EVP_CipherUpdate(ctx, ciphertext, &len, (unsigned char *)plaintext, strlen(plaintext))) {
        printf("Error: EVP_CipherUpdate() failed.\n");
        return EXIT_FAILURE;
    }
    ciphertext_len = len;

    // Finalize the encryption/decryption process
    if (!EVP_CipherFinal_ex(ctx, ciphertext + len, &len)) {
        printf("Error: EVP_CipherFinal_ex() failed.\n");
        return EXIT_FAILURE;
    }
    ciphertext_len += len;

    // Print the plaintext, key, and initialization vector
    printf("Plaintext: %s\n", plaintext);
    print_hex("Key", (unsigned char *)key, strlen(key));
    print_hex("IV", (unsigned char *)iv, strlen(iv));

    if (do_encrypt) {
        print_hex("Ciphertext", ciphertext, ciphertext_len);
    } else {
        printf("Decrypted text: %s\n", ciphertext);
    }

    // Free the memory allocated for the ciphertext buffer and the cipher context
    free(ciphertext);
    EVP_CIPHER_CTX_free(ctx);

    return EXIT_SUCCESS;
}

int main()
{
    // Initialize the messages and keys
    char plaintext[] = "This is my secret message.";
    char key[] = "My secret key1234";
    char iv[] = "InIVwetrust5432";

    // Encrypt the plaintext using AES CBC 256-bit encryption algorithm
    aes_cbc_256(plaintext, key, iv, 1);

    // Decrypt the ciphertext using AES CBC 256-bit encryption algorithm
    char ciphertext[] = "3c0ad66f946409f33da1ee2d051f06b911f9c5e903e2d1d3de7e7d1f9b2fc1c1";
    aes_cbc_256(ciphertext, key, iv, 0);

    return EXIT_SUCCESS;
}