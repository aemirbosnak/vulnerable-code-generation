//FormAI DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the file
void encrypt(char *filename, char *key) {
    FILE *fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Checking key length
    int keyLen = strlen(key);
    if (keyLen < 5) {
        printf("Error: Key length must be at least 5 characters long!\n");
        exit(1);
    }

    // Reading the file contents
    unsigned char *buffer = (unsigned char*) malloc(sizeof(unsigned char) * keyLen);
    int bytesRead = fread(buffer, 1, keyLen, fp);

    // Encrypting the file contents using XOR cipher
    int i;
    for (i = 0; i < bytesRead; i++) {
        buffer[i] = buffer[i] ^ key[i % keyLen];
    }

    // Writing the encrypted file contents back to the file
    fseek(fp, 0, SEEK_SET);
    fwrite(buffer, sizeof(unsigned char), bytesRead, fp);

    free(buffer);
    fclose(fp);

    printf("File encrypted successfully!\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./encrypt <filename> <key>\n");
        exit(1);
    }

    char *filename = argv[1];
    char *key = argv[2];

    encrypt(filename, key);

    return 0;
}