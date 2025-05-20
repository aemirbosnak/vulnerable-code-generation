//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(const char* filename, const char* key) {
    // Open the file for reading
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file '%s' for reading.\n", filename);
        return;
    }
    
    // Read the file content into a buffer
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = (char*)malloc(fileSize + 1);
    fread(buffer, fileSize, 1, file);
    fclose(file);
    
    // Convert the buffer into an array of integers
    int* encryptedData = (int*)malloc(fileSize / 4 * 4);
    int i;
    for (i = 0; i < fileSize / 4; i++) {
        encryptedData[i] = (buffer[i * 4] << 24) | (buffer[i * 4 + 1] << 16) | (buffer[i * 4 + 2] << 8) | buffer[i * 4 + 3];
    }
    
    // Create a new file with the encrypted data
    FILE* encryptedFile = fopen(filename, "wb");
    if (encryptedFile == NULL) {
        printf("Error opening encrypted file '%s' for writing.\n", filename);
        free(buffer);
        free(encryptedData);
        return;
    }
    
    // Write the encrypted data to the file
    fwrite(encryptedData, fileSize / 4 * 4, 1, encryptedFile);
    fclose(encryptedFile);
    
    // Free the memory
    free(buffer);
    free(encryptedData);
}

// Main function
int main(int argc, char** argv) {
    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        return 1;
    }
    
    // Encrypt the file
    encryptFile(argv[1], argv[2]);
    
    return 0;
}