//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generate a random key for encryption
unsigned char *generateKey(int keySize) {
    unsigned char *key = malloc(keySize);
    for (int i = 0; i < keySize; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

// Encrypt a file using the given key
void encryptFile(char *fileName, unsigned char *key, int keySize) {
    FILE *input = fopen(fileName, "rb");
    if (input == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return;
    }

    FILE *output = fopen("encrypted.txt", "wb");
    if (output == NULL) {
        printf("Error: Could not create output file\n");
        fclose(input);
        return;
    }

    // Write the key size to the output file
    fwrite(&keySize, sizeof(int), 1, output);

    // Write the key to the output file
    fwrite(key, keySize, 1, output);

    // Read the input file and encrypt it
    unsigned char buffer[1024];
    int bytesRead;
    while ((bytesRead = fread(buffer, 1, 1024, input)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % keySize];
        }
        fwrite(buffer, bytesRead, 1, output);
    }

    fclose(input);
    fclose(output);
}

// Decrypt a file using the given key
void decryptFile(char *fileName, unsigned char *key, int keySize) {
    FILE *input = fopen(fileName, "rb");
    if (input == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return;
    }

    FILE *output = fopen("decrypted.txt", "wb");
    if (output == NULL) {
        printf("Error: Could not create output file\n");
        fclose(input);
        return;
    }

    // Read the key size from the input file
    int keySizeActual;
    fread(&keySizeActual, sizeof(int), 1, input);

    // Check if the key size matches the expected key size
    if (keySizeActual != keySize) {
        printf("Error: Key size does not match\n");
        fclose(input);
        fclose(output);
        return;
    }

    // Read the key from the input file
    unsigned char *keyActual = malloc(keySize);
    fread(keyActual, keySize, 1, input);

    // Read the encrypted file and decrypt it
    unsigned char buffer[1024];
    int bytesRead;
    while ((bytesRead = fread(buffer, 1, 1024, input)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            buffer[i] ^= keyActual[i % keySize];
        }
        fwrite(buffer, bytesRead, 1, output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    // Generate a random key for encryption
    unsigned char *key = generateKey(16);

    // Encrypt a file using the given key
    encryptFile("input.txt", key, 16);

    // Decrypt the encrypted file using the given key
    decryptFile("encrypted.txt", key, 16);

    free(key);
    return 0;
}