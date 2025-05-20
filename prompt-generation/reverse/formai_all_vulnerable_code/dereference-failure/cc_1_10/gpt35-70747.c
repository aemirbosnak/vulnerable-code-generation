//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <openssl/aes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AES_BLOCK_SIZE 16

/* Error message printing function */
void handleErrors(void)
{
    printf("An error occurred and the program will exit.\n");
    exit(1);
}

/* AES encryption function */
void encryptAES(unsigned char *plaintext, int plaintext_len,
               unsigned char *key, unsigned char *iv,
               unsigned char *ciphertext)
{
    AES_KEY aesKey;
    AES_set_encrypt_key(key, 128, &aesKey);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &aesKey, iv, AES_ENCRYPT);
}

/* AES decryption function */
void decryptAES(unsigned char *ciphertext, int ciphertext_len,
               unsigned char *key, unsigned char *iv,
               unsigned char *plaintext)
{
    AES_KEY aesKey;
    AES_set_decrypt_key(key, 128, &aesKey);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &aesKey, iv, AES_DECRYPT);
}

int main()
{
    /* Input plaintext message */
    char plaintext[] = "Hello, world! How are you today?";

    /* Generate random 128-bit AES key and 128-bit initialization vector (IV) */
    unsigned char key[AES_BLOCK_SIZE];
    RAND_bytes(key, AES_BLOCK_SIZE);

    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);

    /* Determine length of input message and add padding if necessary */
    size_t plaintext_len = strlen(plaintext) + 1;
    int padding_len = AES_BLOCK_SIZE - (plaintext_len % AES_BLOCK_SIZE);
    unsigned char *padded_plaintext = calloc(plaintext_len + padding_len, 1);
    memcpy(padded_plaintext, plaintext, plaintext_len);

    /* Encrypt the padded plaintext message */
    unsigned char *ciphertext = calloc(plaintext_len + padding_len, 1);
    encryptAES(padded_plaintext, plaintext_len + padding_len, key, iv, ciphertext);

    /* Print out various information about the input and encrypted message */
    printf("Input message: %s\n", plaintext);
    printf("Input message length: %lu\n", plaintext_len);
    printf("Padding length: %d\n", padding_len);
    printf("Padded message: %s\n", padded_plaintext);
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
    printf("Encrypted message: ");
    for (int i = 0; i < plaintext_len + padding_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    /* Decrypt the ciphertext message */
    unsigned char *decrypted_plaintext = calloc(plaintext_len + padding_len, 1);
    decryptAES(ciphertext, plaintext_len + padding_len, key, iv, decrypted_plaintext);

    /* Print out the decrypted message */
    printf("Decrypted message: %s\n", decrypted_plaintext);

    /* Free allocated memory */
    free(padded_plaintext);
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}