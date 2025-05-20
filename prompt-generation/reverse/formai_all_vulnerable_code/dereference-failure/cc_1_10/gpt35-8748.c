//FormAI DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encrypts the file byte by byte
void encryptFile(char* fileName, char* key) {
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error: Cannot open %s\n", fileName);
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate a buffer to hold the contents of the file
    char* buffer = malloc(fileSize);
    if (buffer == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }

    // Read the contents of the file into the buffer
    fread(buffer, 1, fileSize, file);

    // Encrypt the file byte by byte with the key
    int keyIndex = 0;
    for (int i = 0; i < fileSize; i++) {
        buffer[i] = buffer[i] ^ key[keyIndex];
        keyIndex++;
        if (keyIndex >= strlen(key)) {
            keyIndex = 0;
        }
    }

    // Write the encrypted data back to the file
    fseek(file, 0, SEEK_SET);
    fwrite(buffer, 1, fileSize, file);

    // Clean up
    free(buffer);
    fclose(file);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <file> <key>\n", argv[0]);
        return 1;
    }

    char* fileName = argv[1];
    char* key = argv[2];

    encryptFile(fileName, key);

    printf("The file \"%s\" has been encrypted with the key \"%s\".\n", fileName, key);

    return 0;
}