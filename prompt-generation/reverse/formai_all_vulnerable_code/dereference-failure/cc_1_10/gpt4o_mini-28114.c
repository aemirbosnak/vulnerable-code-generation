//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

// Function to display usage instructions
void displayInstructions() {
    printf("Welcome to the C File Encryptor\n");
    printf("Usage: ./encryptor <action> <file> <key>\n");
    printf("Actions:\n");
    printf("  encrypt  : Encrypt the specified file\n");
    printf("  decrypt  : Decrypt the specified file\n");
    printf("  Example: ./encryptor encrypt myfile.txt 1234\n");
}

// Function to encrypt the content of the file
void encryptFile(const char *filename, const char *key) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file for encryption");
        return;
    }
    FILE *outFile = fopen("encrypted.dat", "wb");
    if (!outFile) {
        perror("Could not open output file for encryption");
        fclose(file);
        return;
    }

    int keyLen = strlen(key);
    int keyIndex = 0;
    unsigned char buffer[BUF_SIZE];

    while (fread(buffer, 1, BUF_SIZE, file)) {
        for (int i = 0; i < BUF_SIZE; i++) {
            buffer[i] ^= key[keyIndex % keyLen]; // XOR encryption
            keyIndex++;
        }
        fwrite(buffer, 1, BUF_SIZE, outFile);
    }

    printf("File encrypted successfully to 'encrypted.dat'\n");
    fclose(file);
    fclose(outFile);
}

// Function to decrypt the content of the file
void decryptFile(const char *filename, const char *key) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file for decryption");
        return;
    }
    FILE *outFile = fopen("decrypted.txt", "wb");
    if (!outFile) {
        perror("Could not open output file for decryption");
        fclose(file);
        return;
    }

    int keyLen = strlen(key);
    int keyIndex = 0;
    unsigned char buffer[BUF_SIZE];

    while (fread(buffer, 1, BUF_SIZE, file)) {
        for (int i = 0; i < BUF_SIZE; i++) {
            buffer[i] ^= key[keyIndex % keyLen]; // XOR decryption is the same as encryption
            keyIndex++;
        }
        fwrite(buffer, 1, BUF_SIZE, outFile);
    }

    printf("File decrypted successfully to 'decrypted.txt'\n");
    fclose(file);
    fclose(outFile);
}

// Main function to handle arguments and initiate encryption/decryption
int main(int argc, char *argv[]) {
    if (argc != 4) {
        displayInstructions();
        return EXIT_FAILURE;
    }

    const char *action = argv[1];
    const char *file = argv[2];
    const char *key = argv[3];

    if (strcmp(action, "encrypt") == 0) {
        encryptFile(file, key);
    } else if (strcmp(action, "decrypt") == 0) {
        decryptFile("encrypted.dat", key);
    } else {
        printf("Invalid action. Please use 'encrypt' or 'decrypt'.\n");
        displayInstructions();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}