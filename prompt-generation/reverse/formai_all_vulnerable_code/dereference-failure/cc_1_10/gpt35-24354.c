//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUF_SIZE 1024

void handleErrors(void)
{
    printf("Error occured.\n");
    exit(EXIT_FAILURE);     
}

int main(int argc, char* argv[])
{
    // Initializing variables
    char *inputFile, *outputFile;
    const EVP_CIPHER *cipher;
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
    unsigned char* buffer = (unsigned char*) malloc(BUF_SIZE);
    int bytes_read, bytes_written;
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    // Checking argument count
    if(argc < 4 || argc > 5){
        printf("USAGE: %s <enc|dec> <input file> <output file> [key]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Setting cipher
    if(strcmp(argv[1], "enc") == 0){
        cipher = EVP_aes_256_cbc();
    }
    else if(strcmp(argv[1], "dec") == 0){
        cipher = EVP_aes_256_cbc();
    }
    else{
        printf("Invalid operation %s. Choose enc or dec.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Setting input and output files
    inputFile = argv[2];
    outputFile = argv[3];

    // Setting key and iv
    if(argc > 4){
        char* keyString = argv[4];
        if(strlen(keyString) != EVP_CIPHER_key_length(cipher)){
            printf("Invalid key size. Key size should be %d for chosen cipher.\n", EVP_CIPHER_key_length(cipher));
            exit(EXIT_FAILURE);
        }
        memcpy(key, keyString, sizeof(key));
    }
    else{
        printf("Enter key: ");
        scanf("%s", key);
    }
    if(!EVP_CIPHER_CTX_set_key_length(ctx, EVP_CIPHER_key_length(cipher))){
        handleErrors();
    }
    if(!EVP_CipherInit_ex(ctx, cipher, NULL, key, iv, strcmp(argv[1], "enc"))){
        handleErrors();
    }

    // opening input and output files
    FILE *fpIn = fopen(inputFile, "rb");
    FILE *fpOut = fopen(outputFile, "wb");
    if(!fpIn || !fpOut){
        printf("Error occured while opening files.\n");
        exit(EXIT_FAILURE);
    }

    while(1){
        // Reading input
        bytes_read = fread(buffer, sizeof(unsigned char), BUF_SIZE, fpIn);
        if(bytes_read <= 0) break;

        // Encrypting/Decrypting data
        if(!EVP_CipherUpdate(ctx, buffer, &bytes_written, buffer, bytes_read)){
            handleErrors();
        }
        fwrite(buffer, sizeof(unsigned char), bytes_written, fpOut);
    }

    // Final step of encryption/decryption
    if(!EVP_CipherFinal_ex(ctx, buffer, &bytes_written)){
        handleErrors();
    }
    fwrite(buffer, sizeof(unsigned char), bytes_written, fpOut);

    // Closing files
    fclose(fpIn);
    fclose(fpOut);
    EVP_CIPHER_CTX_free(ctx);
    free(buffer);
    return 0;
}