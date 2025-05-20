//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

// Function to encrypt the message using AES128
void aes128_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext)
{
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &aes_key, iv, AES_ENCRYPT);
}

// Function to decrypt the message using AES128
void aes128_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext)
{
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &aes_key, iv, AES_DECRYPT);
}

int main()
{
    // Initialization Vector (IV)
    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    // Encryption Key
    unsigned char key[AES_BLOCK_SIZE];
    memset(key, 0x00, AES_BLOCK_SIZE);

    // Plaintext Message
    unsigned char plaintext[] = "Sample plaintext message.";

    // Length of the plaintext message
    int plaintext_len = strlen(plaintext);

    // Size of the encrypted message
    int encrytped_len = 0;

    // Encrypted Message
    unsigned char* ciphertext;

    // Allocate memory to hold the encrypted message based on the plaintext message length.
    ciphertext = malloc(plaintext_len + AES_BLOCK_SIZE);
    memset(ciphertext, 0, plaintext_len + AES_BLOCK_SIZE);

    // Encrypt the plaintext message
    aes128_encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    encrytped_len = strlen(ciphertext);

    // Print the encrypted message
    printf("Encrypted message: ");
    for(int i=0; i<encrytped_len; i++)
    {
        printf("%02x ", ciphertext[i]);
    }

    // Allocate memory to hold the decrypted message based on the encrypted message length.
    unsigned char* decryptedtext;
    decryptedtext = malloc(encrytped_len + AES_BLOCK_SIZE);
    memset(decryptedtext, 0, encrytped_len + AES_BLOCK_SIZE);

    // Decrypt the encrypted message
    aes128_decrypt(ciphertext, encrytped_len, key, iv, decryptedtext);

    // Print the decrypted message
    printf("\nDecrypted message: %s\n", decryptedtext);

    // Free up memory allocated by ciphertext and decryptedtext
    free(ciphertext);
    free(decryptedtext);

    return 0;
}