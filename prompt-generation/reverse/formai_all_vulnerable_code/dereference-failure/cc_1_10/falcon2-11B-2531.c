//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: mind-bending
#include <stdio.h>
#include <string.h>

// Function to encrypt a file
void encrypt_file(const char* file_name, const char* key) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: Failed to open file.\n");
        return;
    }
    
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    
    char* buffer = (char*)malloc(size);
    fread(buffer, 1, size, file);
    fclose(file);
    
    FILE* encrypted_file = fopen(file_name, "wb");
    if (encrypted_file == NULL) {
        printf("Error: Failed to open encrypted file.\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }
    
    fwrite(buffer, 1, size, encrypted_file);
    fclose(encrypted_file);
    
    free(buffer);
}

// Function to decrypt a file
void decrypt_file(const char* file_name, const char* key) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: Failed to open file.\n");
        return;
    }
    
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    
    char* buffer = (char*)malloc(size);
    fread(buffer, 1, size, file);
    fclose(file);
    
    FILE* decrypted_file = fopen(file_name, "wb");
    if (decrypted_file == NULL) {
        printf("Error: Failed to open decrypted file.\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }
    
    fwrite(buffer, 1, size, decrypted_file);
    fclose(decrypted_file);
    
    free(buffer);
}

int main() {
    const char* file_name = "test.txt";
    const char* key = "secret";
    
    // Encrypt the file
    encrypt_file(file_name, key);
    
    // Decrypt the file
    decrypt_file(file_name, key);
    
    return 0;
}