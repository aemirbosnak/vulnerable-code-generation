//FormAI DATASET v1.0 Category: File Encyptor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
void encrypt_file(char* file_path, char* key);
void decrypt_file(char* file_path, char* key);
void generate_key(char* key, int key_length);
void xor_encrypt(char* data, int data_length, char* key, int key_length);
 
int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s <encrypt | decrypt> <file_path> <key_length>\n", argv[0]);
        return 0;
    }
 
    char* operation = argv[1];
    char* file_path = argv[2];
    int key_length = atoi(argv[3]);
 
    char* key = (char*)malloc(sizeof(char) * key_length);
    generate_key(key, key_length);
 
    if (strcmp(operation, "encrypt") == 0) {
        printf("Encrypting file '%s' with key '%s'...\n", file_path, key);
        encrypt_file(file_path, key);
        printf("File has been encrypted successfully.\n");
    }
    else if (strcmp(operation, "decrypt") == 0) {
        printf("Decrypting file '%s' with key '%s'...\n", file_path, key);
        decrypt_file(file_path, key);
        printf("File has been decrypted successfully.\n");
    }
    else {
        printf("Invalid operation. Use 'encrypt' or 'decrypt'.\n");
    }
 
    free(key);
    return 0;
}
 
void encrypt_file(char* file_path, char* key) {
    FILE* file = fopen(file_path, "r+");
 
    if (file == NULL) {
        printf("Cannot open file '%s'\n", file_path);
        return;
    }
 
    // get file size
    fseek(file, 0L, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
 
    char* data = (char*)malloc(sizeof(char) * file_size);
 
    fread(data, sizeof(char), file_size, file);
    xor_encrypt(data, file_size, key, strlen(key));
    rewind(file);
    fwrite(data, sizeof(char), file_size, file);
    fclose(file);
    free(data);
}
 
void decrypt_file(char* file_path, char* key) {
    encrypt_file(file_path, key);
}
 
void generate_key(char* key, int key_length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    srand(time(NULL));
 
    for (int i = 0; i < key_length; i++) {
        int index = rand() % (sizeof(charset) - 1);
        key[i] = charset[index];
    }
    key[key_length] = '\0';
}
 
void xor_encrypt(char* data, int data_length, char* key, int key_length) {
    for (int i = 0; i < data_length; i++) {
        data[i] ^= key[i % key_length];
    }
}