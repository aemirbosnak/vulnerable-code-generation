//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

void encrypt(char *message, char *key) {
    unsigned char iv[AES_BLOCK_SIZE], *ciphertext;
    AES_KEY aes_key;

    /* set random IV */
    RAND_bytes(iv, AES_BLOCK_SIZE);

    /* initialize key */
    AES_set_encrypt_key(key, 256, &aes_key);

    /* get message length */
    size_t message_len = strlen(message);

    /* determine number of blocks needed */
    size_t num_blocks = (message_len + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE;

    /* allocate memory for ciphertext */
    ciphertext = (unsigned char*)malloc(num_blocks * AES_BLOCK_SIZE);

    /* encrypt blocks */
    AES_cbc_encrypt(message, ciphertext, message_len, &aes_key, iv, AES_ENCRYPT);

    /* print IV and ciphertext */
    printf("IV: ");
    for (size_t i = 0; i < AES_BLOCK_SIZE; ++i) {
        printf("%02x", iv[i]);
    }
    printf("\nCiphertext: ");
    for (size_t i = 0; i < num_blocks * AES_BLOCK_SIZE; ++i) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    /* free memory */
    free(ciphertext);
}

int main() {
    char message[] = "This is a top secret message!";
    char key[] = "mysecretkey123456";

    /* encrypt message using AES CBC */
    encrypt(message, key);

    return 0;
}