//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <openssl/aes.h>
#include <openssl/evp.h>

#define MAX_LEN 100

void encrypt_file(char* input_file, char* output_file, char* password) {
    int file_size;
    int len;
    unsigned char* iv;
    FILE* input_fp, *output_fp;
    AES_KEY key;

    // Check if input file exists
    struct stat st;
    if (stat(input_file, &st) < 0) {
        perror("Error opening input file.");
        return;
    }

    file_size = st.st_size;

    // Initialize output file
    output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        perror("Error creating output file.");
        return;
    }

    // Initialize AES key
    len = strlen(password);
    AES_set_encrypt_key(password, len * 8, &key);

    // Generate random IV
    iv = malloc(AES_BLOCK_SIZE);
    if (RAND_bytes(iv, AES_BLOCK_SIZE) <= 0) {
        perror("Error generating random IV.");
        return;
    }

    // Encrypt file in blocks
    input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        perror("Error opening input file.");
        return;
    }

    char buffer[AES_BLOCK_SIZE];
    while (fread(buffer, sizeof(char), AES_BLOCK_SIZE, input_fp) > 0) {
        AES_cbc_encrypt((unsigned char*)buffer, (unsigned char*)buffer, AES_BLOCK_SIZE, &key, iv, 1);
        fwrite(buffer, sizeof(char), AES_BLOCK_SIZE, output_fp);
    }

    // Write remaining bytes from input file
    while (fread(buffer, sizeof(char), 1, input_fp) > 0) {
        fwrite(buffer, sizeof(char), 1, output_fp);
    }

    // Write IV to output file
    fwrite(iv, AES_BLOCK_SIZE, 1, output_fp);

    // Free memory and close files
    free(iv);
    fclose(input_fp);
    fclose(output_fp);

    printf("File '%s' encrypted and saved as '%s'.\n", input_file, output_file);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <password>\n", argv[0]);
        return 1;
    }

    encrypt_file(argv[1], argv[2], argv[3]);

    return 0;
}