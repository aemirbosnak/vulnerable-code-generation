//FormAI DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_file(char* filename, char* key);
void decrypt_file(char* filename, char* key);

int main(int argc, char *argv[]) {
    char* filename;
    char* key;
    char* mode;
    
    // Parse command line arguments
    if(argc < 4) {
        fprintf(stderr, "Usage: file_encryptor <filename> <key> <mode>\n");
        exit(1);
    }
    filename = argv[1];
    key = argv[2];
    mode = argv[3];
    
    if(strcmp(mode, "encrypt") == 0) {
        encrypt_file(filename, key);
        printf("File %s encrypted with key %s\n", filename, key);
    }
    else if(strcmp(mode, "decrypt") == 0) {
        decrypt_file(filename, key);
        printf("File %s decrypted with key %s\n", filename, key);
    }
    else {
        fprintf(stderr, "Invalid mode: %s. Must be 'encrypt' or 'decrypt'\n", mode);
        exit(1);
    }
    
    return 0;
}

void encrypt_file(char* filename, char* key) {
    FILE* file = fopen(filename, "rb+");
    if(file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }
    
    // Get file size
    fseek(file, 0, SEEK_END);
    long int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // Read file data into buffer
    char* buffer = malloc(size);
    fread(buffer, 1, size, file);
    
    // Encrypt buffer with key
    int key_length = strlen(key);
    for(int i = 0; i < size; i++) {
        buffer[i] ^= key[i % key_length];
    }
    
    // Write buffer back to file
    fseek(file, 0, SEEK_SET);
    fwrite(buffer, 1, size, file);
    
    fclose(file);
    free(buffer);
}

void decrypt_file(char* filename, char* key) {
    encrypt_file(filename, key);
}