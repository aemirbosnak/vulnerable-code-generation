//FormAI DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BUFFER_SIZE 1024

void encryptFile(char* filename);
void decryptFile(char* filename);
void xorEncrypt(char* buffer, size_t size, char* key);

int main(int argc, char** argv) {
    char filename[MAX_FILENAME_LENGTH];
    int choice = 0;
    
    printf("Welcome to C File Encryptor!\n");
    printf("Please choose an option below:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter file name to encrypt: ");
            scanf("%s", filename);
            encryptFile(filename);
            printf("%s encrypted successfully!\n", filename);
            break;
            
        case 2:
            printf("Enter file name to decrypt: ");
            scanf("%s", filename);
            decryptFile(filename);
            printf("%s decrypted successfully!\n", filename);
            break;
            
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    
    return 0;
}

void encryptFile(char* filename) {
    FILE* input = fopen(filename, "r");
    FILE* output = fopen("encrypted.bin", "wb");
    char buffer[MAX_BUFFER_SIZE];
    char key[] = "mysecretkey";
    
    if (input == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    
    while(!feof(input)) {
        size_t bytesRead = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, input);
        xorEncrypt(buffer, bytesRead, key);
        fwrite(buffer, sizeof(char), bytesRead, output);
    }
    
    fclose(input);
    fclose(output);
    remove(filename);
    rename("encrypted.bin", filename);
    printf("%s encrypted successfully!\n", filename);
}

void decryptFile(char* filename) {
    FILE* input = fopen(filename, "r");
    FILE* output = fopen("decrypted.bin", "wb");
    char buffer[MAX_BUFFER_SIZE];
    char key[] = "mysecretkey";
    
    if (input == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    
    while(!feof(input)) {
        size_t bytesRead = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, input);
        xorEncrypt(buffer, bytesRead, key);
        fwrite(buffer, sizeof(char), bytesRead, output);
    }
    
    fclose(input);
    fclose(output);
    remove(filename);
    rename("decrypted.bin", filename);
    printf("%s decrypted successfully!\n", filename);
}

void xorEncrypt(char* buffer, size_t size, char* key) {
    size_t keyLength = strlen(key);
    for (size_t i = 0; i < size; i++) {
        buffer[i] ^= key[i % keyLength];
    }
}