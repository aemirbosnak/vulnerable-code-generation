//FormAI DATASET v1.0 Category: Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char **argv) {

    if(argc != 4) {
        printf("Usage: %s [plaintext] [key] [iv]\n", argv[0]);
        return 1;
    }

    //initialize variables
    char *plaintext = argv[1];
    char *key = argv[2];
    char *iv = argv[3];
    int plaintext_len = strlen(plaintext);
    int ciphertext_len, decryptedtext_len;

    //initialize cipher key and IV
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv, 1);

    //initialize cipher text
    unsigned char *ciphertext = malloc(plaintext_len + EVP_CIPHER_CTX_block_size(ctx));
    EVP_CipherUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char *) plaintext, plaintext_len);
    EVP_CipherFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len);
    ciphertext_len += plaintext_len;

    //print out the encrypted text
    printf("Ciphertext: ");
    for(int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    //initialize decrypted text
    unsigned char *decryptedtext = malloc(ciphertext_len);
    EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv, 0);
    EVP_CipherUpdate(ctx, decryptedtext, &decryptedtext_len, ciphertext, ciphertext_len);

    //print out the decrypted text
    printf("Decrypted text: %s\n", decryptedtext);

    //free memory and cleanup context
    free(ciphertext);
    free(decryptedtext);
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}