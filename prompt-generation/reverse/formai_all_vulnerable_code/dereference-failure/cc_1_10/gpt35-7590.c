//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_SIZE 16
#define IV_SIZE 16
#define CIPHER_TYPE EVP_aes_128_cbc()

int main(int argc, char *argv[]) {
    
    /* Initialization Vector */
    unsigned char iv[IV_SIZE] = {0};
    /* Encryption Key */
    unsigned char key[KEY_SIZE] = {0};
    /* Plaintext and Ciphertext Buffers */
    unsigned char *plaintext = NULL;
    unsigned char *ciphertext = NULL;
    /* Ciphertext size variable */
    int ciphertext_len = 0;
    /* Encrypt/Decrypt Context */
    EVP_CIPHER_CTX *ctx;
    
    /* Generate a random Initialization Vector */
    RAND_bytes(iv, IV_SIZE);
    
    /* Generate a random Encryption Key */
    RAND_bytes(key, KEY_SIZE);
    
    /* Plaitext to be encrypted */
    char* plain = "This is a secret message to be encrypted.";
    
    /* Allocating memory for plaintext */
    plaintext = (unsigned char*)malloc(strlen(plain) + 1);
    memcpy(plaintext, plain, strlen(plain) + 1);
    
    /* Allocating memory for ciphertext */
    ciphertext = (unsigned char*)malloc(strlen(plain) + EVP_CIPHER_block_size(CIPHER_TYPE));
    
    /* Create and initialize a new context for encrypting the plaintext */
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, CIPHER_TYPE, NULL, key, iv);
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, strlen(plain));
    
    /* Finalize the encryption and add any remaining data */
    int final_len;
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &final_len);
    ciphertext_len += final_len;
    
    /* Print the Initialization Vector */
    printf("Initialization Vector (IV): ");
    for(int i=0;i<IV_SIZE;i++) {
        printf("%02x", iv[i]);
    }
    printf("\n");
    
    /* Print the Encryption Key */
    printf("Encryption Key: ");
    for(int i=0;i<KEY_SIZE;i++) {
        printf("%02x", key[i]);
    }
    printf("\n");
    
    /* Print the Ciphertext */
    printf("Ciphertext: ");
    for(int i=0;i<ciphertext_len;i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    
    /* Clean up the Encrypt/Decrypt Context */
    EVP_CIPHER_CTX_free(ctx);
    
    /* Freeing memory */
    free(plaintext);
    free(ciphertext);
    
    return 0;
}