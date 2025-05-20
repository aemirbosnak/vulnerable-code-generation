//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BLOCK_SIZE 16

unsigned char* encrypt(unsigned char *plaintext, int *len, unsigned char *key, unsigned char *iv){
    EVP_CIPHER_CTX *ctx;
    
    int c_len = *len + BLOCK_SIZE;
    int f_len = 0;
    unsigned char *ciphertext = malloc(sizeof(unsigned char) * c_len);
    
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_EncryptUpdate(ctx, ciphertext, &c_len, plaintext, *len);
    EVP_EncryptFinal_ex(ctx, ciphertext+c_len, &f_len);
    *len = c_len + f_len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext;
}

unsigned char* decrypt(unsigned char *ciphertext, int *len, unsigned char *key, unsigned char *iv){
    EVP_CIPHER_CTX *ctx;
    
    int p_len = *len;
    int f_len = 0;
    unsigned char *plaintext = malloc(sizeof(unsigned char) * p_len);
    
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_DecryptUpdate(ctx, plaintext, &p_len, ciphertext, *len);
    EVP_DecryptFinal_ex(ctx, plaintext+p_len, &f_len);
    *len = p_len + f_len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext;
}

int main(){

    printf("\n\n*** CRYPTOGRAPHY IMPLEMENTATION ***\n\n");

    unsigned char *plaintext = "This is my secret message!";
    unsigned char *key = (unsigned char *)"a1b2c3d4e5f6g7h8i9j0k1l2m3n4o5p6"; //32 bytes key (256 bit)
    unsigned char *iv = (unsigned char *)"aabbccddeeff00112233445566778899"; //16 bytes initialization vector

    int plaintext_len = strlen((char *)plaintext);
    printf("Plaintext: %s\n", plaintext);

    //encryption
    int enc_len = plaintext_len + BLOCK_SIZE;
    unsigned char *ciphertext = encrypt(plaintext, &plaintext_len, key, iv);
    printf("Ciphertext: ");
    
    for(int i=0; i<enc_len; i++){
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    //decryption
    unsigned char *decrypted_plaintext = decrypt(ciphertext, &enc_len, key, iv);
    printf("Decrypted Plaintext: %s\n", decrypted_plaintext);
    
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}