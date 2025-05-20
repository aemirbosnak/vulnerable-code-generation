//FormAI DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void encryptFile(char* filename, char* key) {
    FILE* originalFile = fopen(filename, "rb");

    if (!originalFile) {
        printf("Error: Could not open file %s.\n", filename);        
        return;
    }

    char encryptedFilename[MAX_FILENAME_LENGTH];
    sprintf(encryptedFilename, "encrypted_%s", filename);
    FILE* encryptedFile = fopen(encryptedFilename, "wb");

    if (!encryptedFile) {
        printf("Error: Could not create encrypted file %s.\n", encryptedFilename);
        fclose(originalFile);
        return;
    }

    int keyLength = strlen(key);
    int bytesRead;
    char buffer[keyLength];

    while ((bytesRead = fread(buffer, sizeof(char), keyLength, originalFile)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i];
        }

        fwrite(buffer, sizeof(char), bytesRead, encryptedFile);
    }

    printf("File %s encrypted and saved as %s.\n", filename, encryptedFilename);

    fclose(originalFile);
    fclose(encryptedFile);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        return 1;
    }

    encryptFile(argv[1], argv[2]);

    return 0;
}