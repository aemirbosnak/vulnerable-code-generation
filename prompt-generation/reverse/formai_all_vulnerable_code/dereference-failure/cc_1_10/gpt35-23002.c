//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext){
    AES_KEY encrypt_key;
    AES_set_encrypt_key(key, 128, &encrypt_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &encrypt_key, iv, AES_ENCRYPT);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext){
    AES_KEY decrypt_key;
    AES_set_decrypt_key(key, 128, &decrypt_key);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &decrypt_key, iv, AES_DECRYPT);
}

int main(){
    unsigned char *key = (unsigned char *)"0123456789123456";
    unsigned char *iv = (unsigned char *)"0123456789123456";
    unsigned char *plaintext = (unsigned char *)"Hello, world!";
    int plaintext_len = strlen((char *)plaintext);
    int ciphertext_len = 0;

    //allocate memory for ciphertext
    unsigned char *ciphertext = malloc(plaintext_len + AES_BLOCK_SIZE);
    if(ciphertext == NULL) {
        printf("Error: Unable to allocate memory for ciphertext");
        exit(EXIT_FAILURE);
    }

    //encrypt plaintext
    encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    ciphertext_len = strlen((char *)ciphertext);

    //allocate memory for decrypted plaintext
    unsigned char *decrypted_plaintext = malloc(ciphertext_len);
    if(decrypted_plaintext == NULL) {
        printf("Error: Unable to allocate memory for decrypted plaintext");
        exit(EXIT_FAILURE);
    }

    //decrypt ciphertext
    decrypt(ciphertext, ciphertext_len, key, iv, decrypted_plaintext);

    //print out results
    printf("Original plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for(int i = 0; i < ciphertext_len; i++){
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    //free allocated memory
    free(ciphertext);
    free(decrypted_plaintext);
    return 0;
}