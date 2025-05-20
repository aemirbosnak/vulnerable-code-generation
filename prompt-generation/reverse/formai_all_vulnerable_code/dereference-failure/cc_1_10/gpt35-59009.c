//FormAI DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input_path, char *key_path);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./encryptor [input_file_path] [key_file_path]\n");
        exit(EXIT_FAILURE);
    }
    encrypt(argv[1], argv[2]);
    printf("Encryption complete!\n");
    return 0;
}

void encrypt(char *input_path, char *key_path) {
    FILE *input_file = fopen(input_path, "r");
    FILE *key_file = fopen(key_path, "r");
    if (input_file == NULL || key_file == NULL) {
        printf("Error opening input or key file.\n");
        exit(EXIT_FAILURE);
    }

    // Get length of input file
    fseek(input_file, 0L, SEEK_END);
    long input_size = ftell(input_file);
    fseek(input_file, 0L, SEEK_SET);

    // Get length of key file
    fseek(key_file, 0L, SEEK_END);
    long key_size = ftell(key_file);
    fseek(key_file, 0L, SEEK_SET);

    // Check if key is at least as long as input
    if (key_size < input_size) {
        printf("Key file is too short.\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for input and key buffers
    char *input_buffer = (char *) malloc(input_size * sizeof(char));
    char *key_buffer = (char *) malloc(key_size * sizeof(char));

    // Read input and key files into buffers
    fread(input_buffer, sizeof(char), input_size, input_file);
    fread(key_buffer, sizeof(char), key_size, key_file);

    // Encrypt input file using XOR
    for (int i = 0; i < input_size; i++) {
        input_buffer[i] ^= key_buffer[i];
    }

    // Overwrite input file with encrypted data
    fclose(input_file);
    input_file = fopen(input_path, "w");
    fwrite(input_buffer, sizeof(char), input_size, input_file);

    // Clean up
    free(input_buffer);
    free(key_buffer);
    fclose(input_file);
    fclose(key_file);
}