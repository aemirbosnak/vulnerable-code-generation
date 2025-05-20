//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define ENCRYPT 1
#define DECRYPT 0

void handleErrors(int status, char *msg) {
    if (status != 1) {
        printf("Error: %s\n", msg);
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
}

void printUsage(char *progname) {
    printf("Usage: %s <operation> <input file> <output file> <key file>\n", progname);
    printf("Operation: -e (encrypt) or -d (decrypt)\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 5) printUsage(argv[0]);

    // Check if operation is valid
    int operation;
    if (strcmp(argv[1], "-e") == 0) {
        operation = ENCRYPT;
    } else if (strcmp(argv[1], "-d") == 0) {
        operation = DECRYPT;
    } else {
        printUsage(argv[0]);
    }

    // Read key from file
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handleErrors(0, "EVP_CIPHER_CTX_new failed");

    FILE *keyfile = fopen(argv[4], "rb");
    if (!keyfile) handleErrors(0, "fopen failed for key file");

    unsigned char key[EVP_MAX_KEY_LENGTH];
    int keylen = fread(key, 1, EVP_MAX_KEY_LENGTH, keyfile);
    if (keylen <= 0) handleErrors(0, "fread failed for key file");

    fclose(keyfile);

    // Read input file
    FILE *inputfile = fopen(argv[2], "rb");
    if (!inputfile) handleErrors(0, "fopen failed for input file");

    fseek(inputfile, 0, SEEK_END);
    long inputlen = ftell(inputfile);
    fseek(inputfile, 0, SEEK_SET);

    unsigned char *input = malloc(inputlen);
    if (!input) handleErrors(0, "malloc failed for input");

    int readlen = fread(input, 1, inputlen, inputfile);
    if (readlen != inputlen) handleErrors(0, "fread failed for input file");

    fclose(inputfile);

    // Initialize cipher context
    if (operation == ENCRYPT) {
        if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL)) handleErrors(0, "EVP_EncryptInit_ex failed");
    } else {
        if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL)) handleErrors(0, "EVP_DecryptInit_ex failed");
    }

    // Encrypt or decrypt
    int outputlen = 0;
    unsigned char output[inputlen + EVP_MAX_BLOCK_LENGTH];
    if (!EVP_CipherUpdate(ctx, output, &outputlen, input, inputlen)) handleErrors(0, "EVP_CipherUpdate failed");

    int finaloutputlen = 0;
    if (!EVP_CipherFinal_ex(ctx, output + outputlen, &finaloutputlen)) handleErrors(0, "EVP_CipherFinal_ex failed");

    EVP_CIPHER_CTX_free(ctx);

    outputlen += finaloutputlen;

    // Write output file
    FILE *outputfile = fopen(argv[3], "wb");
    if (!outputfile) handleErrors(0, "fopen failed for output file");

    fwrite(output, 1, outputlen, outputfile);
    fclose(outputfile);

    free(input);

    return EXIT_SUCCESS;
}