//FormAI DATASET v1.0 Category: File Encyptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTION_KEY 5

void encryptFile(char *filename);
void decryptFile(char *filename);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <encryption_key> <filename>\n", argv[0]);
        exit(1);
    }

    int encryptionKey = atoi(argv[1]);
    char *filename = argv[2];

    if (encryptionKey <= 0) {
        printf("Encryption key must be a positive integer.\n");
        exit(1);
    }

    // Check if file exists
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File '%s' not found.\n", filename);
        exit(1);
    }
    fclose(file);

    // Encrypt file
    if (encryptionKey > ENCRYPTION_KEY) {
        printf("Encryption key too large. Using default key of %d.\n", ENCRYPTION_KEY);
        encryptionKey = ENCRYPTION_KEY;
    }
    for (int i = 0; i < encryptionKey; i++) {
        encryptFile(filename);
    }
    printf("File '%s' encrypted successfully using encryption key of %d.\n", filename, encryptionKey);

    // Decrypt file
    for (int i = 0; i < encryptionKey; i++) {
        decryptFile(filename);
    }
    printf("File '%s' decrypted successfully.\n", filename);

    return 0;
}

void encryptFile(char *filename) {
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        printf("Failed to open file '%s'.\n", filename);
        exit(1);
    }

    fseek(file, 0L, SEEK_END);
    int fileSize = ftell(file);
    rewind(file);

    char *buffer = (char *) malloc(fileSize * sizeof(char));
    size_t result = fread(buffer, sizeof(char), fileSize, file);
    for (int i = 0; i < fileSize; i++) {
        buffer[i] = buffer[i] + ENCRYPTION_KEY;
    }
    fseek(file, 0L, SEEK_SET);
    fwrite(buffer, sizeof(char), fileSize, file);

    free(buffer);
    fclose(file);
}

void decryptFile(char *filename) {
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        printf("Failed to open file '%s'.\n", filename);
        exit(1);
    }

    fseek(file, 0L, SEEK_END);
    int fileSize = ftell(file);
    rewind(file);

    char *buffer = (char *) malloc(fileSize * sizeof(char));
    size_t result = fread(buffer, sizeof(char), fileSize, file);
    for (int i = 0; i < fileSize; i++) {
        buffer[i] = buffer[i] - ENCRYPTION_KEY;
    }
    fseek(file, 0L, SEEK_SET);
    fwrite(buffer, sizeof(char), fileSize, file);

    free(buffer);
    fclose(file);
}