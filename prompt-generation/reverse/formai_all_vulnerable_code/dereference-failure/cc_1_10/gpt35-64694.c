//FormAI DATASET v1.0 Category: modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/aes.h>

#define BLOCK_SIZE 16

int encrypt(const unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext)
{
    AES_KEY encrypt_key;
    if (AES_set_encrypt_key(key, 128, &encrypt_key) < 0) return -1;

    int num_blocks = (plaintext_len + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int padded_len = num_blocks * BLOCK_SIZE;
    unsigned char *padded_plaintext = calloc(padded_len, sizeof(unsigned char));
    memcpy(padded_plaintext, plaintext, plaintext_len);

    for (int i = plaintext_len; i < padded_len; i++)
        padded_plaintext[i] = (unsigned char)(padded_len - plaintext_len);

    unsigned char iv_copy[BLOCK_SIZE];
    memcpy(iv_copy, iv, BLOCK_SIZE);

    for (int i = 0; i < num_blocks; i++) {
        AES_cbc_encrypt(padded_plaintext + (i * BLOCK_SIZE), ciphertext + (i * BLOCK_SIZE), BLOCK_SIZE, &encrypt_key, iv_copy, AES_ENCRYPT);
        memcpy(iv_copy, ciphertext + (i * BLOCK_SIZE), BLOCK_SIZE);
    }

    free(padded_plaintext);
    return padded_len;
}

int decrypt(const unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *decryptedtext)
{
    AES_KEY decrypt_key;
    if (AES_set_decrypt_key(key, 128, &decrypt_key) < 0) return -1;

    unsigned char iv_copy[BLOCK_SIZE];
    memcpy(iv_copy, iv, BLOCK_SIZE);

    for (int i = 0; i < ciphertext_len / BLOCK_SIZE; i++) {
        AES_cbc_encrypt(ciphertext + (i * BLOCK_SIZE), decryptedtext + (i * BLOCK_SIZE), BLOCK_SIZE, &decrypt_key, iv_copy, AES_DECRYPT);
        memcpy(iv_copy, ciphertext + (i * BLOCK_SIZE), BLOCK_SIZE);
    }

    int padded_len = decryptedtext[ciphertext_len - 1];
    return decryptedtext[ciphertext_len - 1] > BLOCK_SIZE ? -1 : ciphertext_len - padded_len;
}

int main()
{
    unsigned char key[] = "passwordpassword";
    unsigned char iv[] = "iviviviviviviviv";
    unsigned char plaintext[] = "The quick brown fox jumps over the lazy dog";
    int plaintext_len = strlen((char *)plaintext);

    unsigned char ciphertext[1024];
    int ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    unsigned char decryptedtext[1024];
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

    ciphertext[ciphertext_len] = 0;
    decryptedtext[decryptedtext_len] = 0;

    printf("Original Text: %s\n", plaintext);
    printf("Encrypted Text: %s\n", ciphertext);
    printf("Decrypted Text: %s\n", decryptedtext);

    return 0;
}