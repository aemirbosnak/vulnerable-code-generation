//FormAI DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* filename, char* key) {
    FILE* fp;
    char ch;
    int i = 0;

    // Open the file in binary read-write mode
    fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        exit(1);
    }

    // Encrypt the file with XOR operation
    while (fread(&ch, sizeof(char), 1, fp)) {
        ch = ch ^ key[i % strlen(key)];
        fseek(fp, -1, SEEK_CUR);
        fwrite(&ch, sizeof(char), 1, fp);
        fseek(fp, 0, SEEK_CUR);
        i++;
    }

    // Close the file
    fclose(fp);
}

int main(int argc, char* argv[]) {
    char* filename;
    char* key;

    // Check if the arguments are valid
    if (argc != 3) {
        printf("Error: Invalid arguments!\n");
        printf("Usage: ./encrypt <filename> <encryption_key>\n");
        return 1;
    }

    // Get the filename and encryption key from command line arguments
    filename = argv[1];
    key = argv[2];

    // Encrypt the file
    encrypt(filename, key);

    printf("File %s encrypted with key %s successfully!\n", filename, key);

    return 0;
}