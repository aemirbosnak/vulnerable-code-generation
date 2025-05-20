//FormAI DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024

int encrypt_file(char *file_path, char *key) {
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Failed to open file %s\n", file_path);
        return 1;
    }

    char *output_file_path = malloc(strlen(file_path) + 5);
    strcpy(output_file_path, file_path);
    strcat(output_file_path, ".enc");

    FILE *output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        printf("Failed to create output file");
        return 1;
    }

    unsigned char block[BLOCK_SIZE];
    int key_len = strlen(key);
    int i = 0;

    while (1) {
        size_t bytes_read = fread(block, 1, BLOCK_SIZE, file);
        if (bytes_read == 0) {
            break;
        }

        for (size_t j = 0; j < bytes_read; j++) {
            block[j] = block[j] ^ key[i];
            i++;
            if (i >= key_len) {
                i = 0;
            }
        }

        fwrite(block, 1, bytes_read, output_file);
    }

    fclose(file);
    fclose(output_file);

    printf("Encrypted file written to %s\n", output_file_path);
    free(output_file_path);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: <file path> <encryption key>\n");
        return 1;
    }

    char *file_path = argv[1];
    char *key = argv[2];

    return encrypt_file(file_path, key);
}