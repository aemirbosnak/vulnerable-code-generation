//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

//This program will take a string as input and encrypt it using AES-128-CBC encryption algorithm

void handleErrors(void)
{
    printf("Error occurred. Aborting...\n");
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: ./crypto <string_to_encrypt>\n");
        return 1;
    }

    char *inputString = argv[1];
    unsigned char iv[EVP_MAX_IV_LENGTH] = {0};
    unsigned char key[EVP_MAX_KEY_LENGTH] = {0};

    // generate random key and initialization vector
    if (!RAND_bytes(key, 16) || !RAND_bytes(iv, 16)) {
        handleErrors();
    }

    // create an encryption context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        handleErrors();
    }

    // initialize encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1) {
        handleErrors();
    }

    int inputLength = strlen(inputString);
    int outputLength = 0;
    int finalOutputLength = 0;
    unsigned char *output = (unsigned char *)malloc(sizeof(unsigned char) * (inputLength + EVP_MAX_BLOCK_LENGTH));
    if (output == NULL) {
        handleErrors();
    }

    // encrypt input string
    if (EVP_EncryptUpdate(ctx, output, &outputLength, (unsigned char *)inputString, inputLength) != 1) {
        handleErrors();
    }

    // finalize encryption operation to get remaining blocks
    if (EVP_EncryptFinal_ex(ctx, output + outputLength, &finalOutputLength) != 1) {
        handleErrors();
    }

    outputLength += finalOutputLength;

    printf("Encrypted string: ");
    for (int i = 0; i < outputLength; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    // clear context and free memory
    EVP_CIPHER_CTX_free(ctx);
    free(output);
    return 0;
}