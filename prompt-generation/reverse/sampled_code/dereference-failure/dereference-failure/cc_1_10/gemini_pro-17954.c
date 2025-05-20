//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

// AES-256 encryption key
unsigned char key[] = {
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
    0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff
};

// AES-256 encryption IV
unsigned char iv[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
};

// Encrypt a string using AES-256
char *aes_encrypt(char *plaintext)
{
    // Allocate memory for the ciphertext
    char *ciphertext = malloc(strlen(plaintext) + AES_BLOCK_SIZE);

    // Create an AES context
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 256, &aes_key);

    // Encrypt the plaintext
    AES_encrypt(plaintext, ciphertext, &aes_key);

    // Return the ciphertext
    return ciphertext;
}

// Decrypt a string using AES-256
char *aes_decrypt(char *ciphertext)
{
    // Allocate memory for the plaintext
    char *plaintext = malloc(strlen(ciphertext) + AES_BLOCK_SIZE);

    // Create an AES context
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 256, &aes_key);

    // Decrypt the ciphertext
    AES_decrypt(ciphertext, plaintext, &aes_key);

    // Return the plaintext
    return plaintext;
}

int main()
{
    // Get the plaintext from the user
    char plaintext[1024];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encrypt the plaintext
    char *ciphertext = aes_encrypt(plaintext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char *decrypted_plaintext = aes_decrypt(ciphertext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}