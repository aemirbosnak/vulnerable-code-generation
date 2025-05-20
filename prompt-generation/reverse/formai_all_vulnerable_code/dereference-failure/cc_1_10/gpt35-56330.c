//FormAI DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_SIZE 1024

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void handleErrors(void){
    ERR_print_errors_fp(stderr);
    abort();
}

void *encrpyt(void *fileNamePtr){
    char *fileName = (char *)fileNamePtr;
    char encryptedFileName[MAX_SIZE];
    memset(encryptedFileName, 0, MAX_SIZE);
    strcat(encryptedFileName, fileName);
    strcat(encryptedFileName, ".encrypted");

    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char *)"0123456789012345";
    unsigned char inBuffer[MAX_SIZE];
    unsigned char outBuffer[MAX_SIZE + EVP_CIPHER_block_size(EVP_aes_256_cbc())];

    FILE *inFile = fopen(fileName, "rb");
    if(inFile == NULL){
        printf("Error opening file %s\n", fileName);
        return NULL;
    }

    FILE *outFile = fopen(encryptedFileName, "wb");
    if(outFile == NULL){
        printf("Error creating file %s\n", encryptedFileName);
        fclose(inFile);
        return NULL;
    }
    
    EVP_CIPHER_CTX *ctx;
    int len;
    unsigned int outLen;
    
    ctx = EVP_CIPHER_CTX_new();
    if(ctx == NULL){
        printf("Error creating new cipher context\n");
        fclose(inFile);
        fclose(outFile);
        return NULL;
    }
    
    if(!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)){
        handleErrors();
    }
    
    while(1){
        pthread_mutex_lock(&mutex);
        len = fread(inBuffer, 1, MAX_SIZE, inFile);
        if(ferror(inFile)){
            printf("Error reading from file %s\n", fileName);
            fclose(inFile);
            fclose(outFile);
            EVP_CIPHER_CTX_free(ctx);
            return NULL;
        }
        pthread_mutex_unlock(&mutex);
        
        if(len == 0){
            break;
        }
        
        if(!EVP_EncryptUpdate(ctx, outBuffer, &len, inBuffer, len)){
            handleErrors();
        }
        
        pthread_mutex_lock(&mutex);
        outLen = fwrite(outBuffer, 1, len, outFile);
        if(outLen != len){
            printf("Error writing to file %s. Write length mismatch.\n", encryptedFileName);
            fclose(inFile);
            fclose(outFile);
            EVP_CIPHER_CTX_free(ctx);
            return NULL;
        }
        pthread_mutex_unlock(&mutex);
    }
    
    if(!EVP_EncryptFinal_ex(ctx, outBuffer, &len)){
        handleErrors();
    }
    
    pthread_mutex_lock(&mutex);
    outLen = fwrite(outBuffer, 1, len, outFile);
    if(outLen != len){
        printf("Error writing to file %s. Write length mismatch.\n", encryptedFileName);
        fclose(inFile);
        fclose(outFile);
        EVP_CIPHER_CTX_free(ctx);
        return NULL;
    }
    pthread_mutex_unlock(&mutex);
    
    fclose(inFile);
    fclose(outFile);
    EVP_CIPHER_CTX_free(ctx);

    return NULL;
}

int main(int argc, char **argv){
    if(argc < 2){
        printf("Usage: %s <file_names>\n", argv[0]);
        return 0;
    }

    int i;
    pthread_t *threads = malloc(sizeof(pthread_t) * argc);
    memset(threads, 0, sizeof(pthread_t) * argc);
    
    for(i = 1; i < argc; i++){
        if(pthread_create(&threads[i], NULL, encrpyt, argv[i]) != 0){
            printf("Error creating thread to encrypt file %s\n", argv[i]);
        }
    }

    for(i = 1; i < argc; i++){
        pthread_join(threads[i], NULL);
        printf("File %s encrypted.\n", argv[i]);
    }

    free(threads);
    return 0;
}