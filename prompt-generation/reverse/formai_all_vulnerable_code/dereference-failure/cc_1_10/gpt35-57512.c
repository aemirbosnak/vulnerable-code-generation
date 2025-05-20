//FormAI DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(const char* file_path, const char* key) {
    FILE* file_ptr = fopen(file_path, "rb+");
    if (file_ptr == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    fseek(file_ptr, 0, SEEK_END);
    long file_size = ftell(file_ptr);
    fseek(file_ptr, 0, SEEK_SET);

    char* buffer = (char*)malloc(file_size + 1);
    memset(buffer, 0, file_size + 1);
    fread(buffer, 1, file_size, file_ptr);

    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    fseek(file_ptr, 0, SEEK_SET);
    fwrite(buffer, 1, file_size, file_ptr);

    free(buffer);
    fclose(file_ptr);
}

void decrypt(const char* file_path, const char* key) {
    // The decrypt function simply runs the encrypt function again, as
    // the XOR encryption is symmetrical.
    encrypt(file_path, key);
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: ./file_encryptor [encrypt/decrypt] [file_path] [key]\n");
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[2], argv[3]);
        printf("Encryption complete.\n");
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[2], argv[3]);
        printf("Decryption complete.\n");
    } else {
        printf("Invalid operation.\n");
        return 1;
    }

    return 0;
}