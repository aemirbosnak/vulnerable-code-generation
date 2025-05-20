//FormAI DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

int main()
{
    // Define the plaintext message to be encrypted
    char *plaintext = "This is a top secret message.";

    // Generate a random AES key and initialization vector (IV)
    unsigned char key[AES_BLOCK_SIZE], iv[AES_BLOCK_SIZE];
    RAND_bytes(key, AES_BLOCK_SIZE);
    RAND_bytes(iv, AES_BLOCK_SIZE);

    // Print out the key and IV as hex values
    printf("Key: ");
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x", key[i]);
    }
    printf("\n");

    printf("IV: ");
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x", iv[i]);
    }
    printf("\n");

    // Create an AES context and initialize it with the key and IV
    AES_KEY aes_key;
    if (AES_set_encrypt_key(key, AES_BLOCK_SIZE * 8, &aes_key) < 0) {
        printf("Error initializing AES context.\n");
        return 1;
    }

    // Determine the length of the plaintext message
    int plaintext_len = strlen(plaintext);

    // Pad the plaintext message to be a multiple of the block size
    int padded_plaintext_len = plaintext_len + AES_BLOCK_SIZE - (plaintext_len % AES_BLOCK_SIZE);
    char *padded_plaintext = malloc(padded_plaintext_len);
    memcpy(padded_plaintext, plaintext, plaintext_len);
    memset(padded_plaintext + plaintext_len, 0, padded_plaintext_len - plaintext_len);

    // Allocate memory for the ciphertext
    char *ciphertext = malloc(padded_plaintext_len);

    // Encrypt the padded plaintext message
    AES_cbc_encrypt(padded_plaintext, ciphertext, padded_plaintext_len, &aes_key, iv, AES_ENCRYPT);

    // Print out the ciphertext as hex values
    printf("Ciphertext: ");
    for (int i = 0; i < padded_plaintext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(padded_plaintext);
    free(ciphertext);

    return 0;
}