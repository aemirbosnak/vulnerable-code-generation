//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Usage: %s <encrypt/decrypt> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    const char *cipher_name = "aes-256-cbc";
    const unsigned char *key = (unsigned char *)"mysecretpassword";
    const unsigned char *iv = (unsigned char *)"initialvector123";

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    if(strcmp(argv[1], "encrypt") == 0)
    {
        FILE *input_file = fopen(argv[2], "rb");
        FILE *output_file = fopen(argv[3], "wb");

        if(input_file == NULL || output_file == NULL)
        {
            printf("Error: Could not open files.\n");
            return 1;
        }

        unsigned char plaintext[1024];
        unsigned char ciphertext[1024 + EVP_MAX_BLOCK_LENGTH];
        int bytes_read, bytes_written;

        EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

        while((bytes_read = fread(plaintext, 1, 1024, input_file)) > 0)
        {
            EVP_EncryptUpdate(ctx, ciphertext, &bytes_written, plaintext, bytes_read);
            fwrite(ciphertext, 1, bytes_written, output_file);
        }

        EVP_EncryptFinal_ex(ctx, ciphertext, &bytes_written);
        fwrite(ciphertext, 1, bytes_written, output_file);

        fclose(input_file);
        fclose(output_file);

        printf("Encryption successful!\n");
    }
    else if(strcmp(argv[1], "decrypt") == 0)
    {
        FILE *input_file = fopen(argv[2], "rb");
        FILE *output_file = fopen(argv[3], "wb");

        if(input_file == NULL || output_file == NULL)
        {
            printf("Error: Could not open files.\n");
            return 1;
        }

        unsigned char ciphertext[1024 + EVP_MAX_BLOCK_LENGTH];
        unsigned char plaintext[1024];
        int bytes_read, bytes_written;

        EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

        while((bytes_read = fread(ciphertext, 1, 1024 + EVP_MAX_BLOCK_LENGTH, input_file)) > 0)
        {
            EVP_DecryptUpdate(ctx, plaintext, &bytes_written, ciphertext, bytes_read);
            fwrite(plaintext, 1, bytes_written, output_file);
        }

        EVP_DecryptFinal_ex(ctx, plaintext, &bytes_written);
        fwrite(plaintext, 1, bytes_written, output_file);

        fclose(input_file);
        fclose(output_file);

        printf("Decryption successful!\n");
    }
    else
    {
        printf("Invalid option selected.\n");
        return 1;
    }

    EVP_CIPHER_CTX_free(ctx);

    return 0;
}