//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants for the program
#define MAX_SIZE 10000
#define BLOCK_SIZE 4096

// Function to encrypt data
void encrypt(char* data, int size, char* key) {
    for(int i = 0; i < size; i++) {
        data[i] ^= key[i % strlen(key)];
    }
}

int main(int argc, char** argv) {
    // Check if the number of arguments is correct
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];

    // Open the file and read its content
    FILE* file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }
    fseek(file, 0L, SEEK_END);
    int filesize = ftell(file);
    rewind(file);
    char* data = (char*)malloc(filesize);
    fread(data, sizeof(char), filesize, file);
    fclose(file);

    // Generate the encryption key
    char key[MAX_SIZE];
    for(int i = 0; i < BLOCK_SIZE; i++) {
        key[i] = rand() % 256;
    }

    // Encrypt the data
    encrypt(data, filesize, key);

    // Write the encrypted data back to the file
    file = fopen(filename, "wb");
    if(file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }
    fwrite(data, sizeof(char), filesize, file);
    fclose(file);

    // Prompt the user for the decryption key
    char input_key[MAX_SIZE];
    printf("Enter the decryption key: ");
    fgets(input_key, MAX_SIZE, stdin);

    // Decrypt the data using the input key
    if(strncmp(input_key, key, BLOCK_SIZE) == 0) {
        encrypt(data, filesize, input_key);
        printf("Decrypted data:\n%s\n", data);
    } else {
        printf("Error: Incorrect decryption key\n");
    }

    free(data);
    return 0;
}