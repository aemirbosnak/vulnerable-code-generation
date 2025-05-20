//FormAI DATASET v1.0 Category: File Encyptor ; Style: realistic
#include <stdio.h>
#include <string.h>

#define ENCRYPTION_KEY 0x1F253A7B // Just a random key for demonstration purposes

void encryptFile(char* fileName);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file name>\n", argv[0]);
        return 1;
    }

    encryptFile(argv[1]);
    printf("File %s encrypted successfully!\n", argv[1]);

    return 0;
}

void encryptFile(char* fileName) {
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Failed to open file %s\n", fileName);
        return;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long int fileSize = ftell(file);
    rewind(file);

    // Read file data into buffer
    char* fileData = (char*)malloc(fileSize + 1);
    fread(fileData, fileSize, 1, file);
    fclose(file);

    // Encrypt file data using XOR
    for (int i = 0; i < fileSize; i++) {
        fileData[i] = fileData[i] ^ ((ENCRYPTION_KEY >> (i % 4)) & 0xFF);
    }

    // Write encrypted data back to file
    FILE* outputFile = fopen(fileName, "wb");
    if (outputFile == NULL) {
        printf("Failed to open file %s for writing\n", fileName);
        free(fileData);
        return;
    }

    fwrite(fileData, fileSize, 1, outputFile);
    fclose(outputFile);
    free(fileData);
}