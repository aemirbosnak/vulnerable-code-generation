//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void){
    printf("An error occured. Exiting program.");
    exit(1);
}

int main(int argc, char *argv[]){
    EVP_CIPHER_CTX *ctx;
    unsigned char *key, *iv, *plaintext, *ciphertext, *decryptedtext;
    int plaintext_len, ciphertext_len, decryptedtext_len;

    //initialize key, iv, and plaintext
    key = (unsigned char*) "01234567890123456789012345678901";
    iv = (unsigned char*) "0123456789012345";
    plaintext = (unsigned char*) "This is a top secret message.";

    //create context
    if(!(ctx = EVP_CIPHER_CTX_new())){
        handleErrors();
    }

    //initialize encryption operation
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)){
        handleErrors();
    }

    //encrypt plaintext
    ciphertext = (unsigned char*) malloc(strlen((char*) plaintext) + EVP_CIPHER_CTX_block_size(ctx));
    if(!ciphertext){
        handleErrors();
    }
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, strlen((char*) plaintext))){
        handleErrors();
    }

    //finish encryption
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len)){
        handleErrors();
    }

    //initialize decryption operation
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)){
        handleErrors();
    }

    //decrypt ciphertext
    decryptedtext = (unsigned char*) malloc(ciphertext_len);
    if(!decryptedtext){
        handleErrors();
    }
    if(1 != EVP_DecryptUpdate(ctx, decryptedtext, &decryptedtext_len, ciphertext, ciphertext_len)){
        handleErrors();
    }

    //finish decryption
    if(1 != EVP_DecryptFinal_ex(ctx, decryptedtext + decryptedtext_len, &decryptedtext_len)){
        handleErrors();
    }

    //print out results
    printf("Plain Text: %s\n", plaintext);
    printf("Cipher Text: ");
    for(int i = 0; i < ciphertext_len; i++){
        printf("%02x", ciphertext[i]);
    }
    printf("\nDecrypted Text: %s\n", decryptedtext);

    //clean up
    EVP_CIPHER_CTX_free(ctx);
    free(ciphertext);
    free(decryptedtext);
    return 0;
}