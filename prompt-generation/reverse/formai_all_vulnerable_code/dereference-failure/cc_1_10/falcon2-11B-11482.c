//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 32
#define MAX_FILE_SIZE 1024

void encryptFile(const char *filename, const char *key, char *encrypted_filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        printf("Error creating cipher context.\n");
        return;
    }

    int res = 1;
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL)!= 1) {
        printf("Error initializing encryption.\n");
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file))!= 0) {
        if (EVP_EncryptUpdate(ctx, buffer, &bytes_read, NULL, NULL)!= 1) {
            printf("Error encrypting data.\n");
            EVP_CIPHER_CTX_free(ctx);
            return;
        }
    }

    if (EVP_EncryptFinal_ex(ctx, buffer, &bytes_read)!= 1) {
        printf("Error encrypting final data.\n");
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    char encrypted_buffer[MAX_FILE_SIZE];
    memcpy(encrypted_buffer, buffer, bytes_read);
    encrypted_filename = strdup(encrypted_buffer);
    fclose(file);

    printf("File encrypted successfully.\n");
    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    const char *filename = "input.txt";
    const char *key = "ThisIsMySecretKey";
    char *encrypted_filename = NULL;

    encryptFile(filename, key, encrypted_filename);

    printf("Encrypted filename: %s\n", encrypted_filename);
    free(encrypted_filename);

    return 0;
}