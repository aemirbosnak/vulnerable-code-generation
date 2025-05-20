//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(char *data, int key) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] ^= key; // Simple XOR encryption
    }
}

void decrypt(char *data, int key) {
    encrypt(data, key); // Decrypting is the same as encrypting in XOR
}

void process_file(const char *filename, int key, int mode) {
    FILE *file = fopen(filename, "r+b"); // Open for reading and writing in binary mode
    if (!file) {
        perror("File opening failed");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        if (mode == 0) { // Encrypt mode
            encrypt(buffer, key);
        } else { // Decrypt mode
            decrypt(buffer, key);
        }
        fseek(file, -bytesRead, SEEK_CUR); // Go back to write the same number of bytes
        fwrite(buffer, sizeof(char), bytesRead, file);
    }

    fclose(file);
    printf("%s operation completed on %s\n", (mode == 0 ? "Encryption" : "Decryption"), filename);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <filename> <key> <mode>\n", argv[0]);
        fprintf(stderr, "mode: 0 for encrypt, 1 for decrypt\n");
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int key = atoi(argv[2]);
    int mode = atoi(argv[3]);

    if (mode != 0 && mode != 1) {
        fprintf(stderr, "Invalid mode. Use 0 for encryption and 1 for decryption.\n");
        return EXIT_FAILURE;
    }

    process_file(filename, key, mode);
    
    return EXIT_SUCCESS;
}