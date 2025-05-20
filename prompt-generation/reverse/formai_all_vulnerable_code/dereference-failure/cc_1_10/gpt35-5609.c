//FormAI DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The key used to encrypt and decrypt the file
#define KEY 0x69

// Function to encrypt the file
void encrypt(char* fileName) {
    FILE* file;
    file = fopen(fileName, "rb+");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        fseek(file, -1, SEEK_CUR);
        fputc(ch^KEY, file);
    }
    fclose(file);
}

// Function to decrypt the file
void decrypt(char* fileName) {
    FILE* file;
    file = fopen(fileName, "rb+");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        fseek(file, -1, SEEK_CUR);
        fputc(ch^KEY, file);
    }
    fclose(file);
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    char* fileName = argv[1];
    if (strcmp(argv[0], "./encryptor") == 0) {
        encrypt(fileName);
        printf("File encrypted successfully.\n");
    }
    else if (strcmp(argv[0], "./decryptor") == 0) {
        decrypt(fileName);
        printf("File decrypted successfully.\n");
    }
    else {
        printf("Invalid command.\n");
        exit(1);
    }
    return 0;
}