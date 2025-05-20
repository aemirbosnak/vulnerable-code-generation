//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

void encrypt(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error: could not open file(s)\n");
        exit(1);
    }

    char buffer[MAX_SIZE];
    int buffer_size = 0;
    int key = 42; // example key

    while (fread(buffer + buffer_size, 1, MAX_SIZE - buffer_size, input) > 0) {
        buffer_size += fread(buffer + buffer_size, 1, MAX_SIZE - buffer_size, input);
    }

    for (int i = 0; i < buffer_size; i++) {
        buffer[i] ^= key;
    }

    fwrite(buffer, 1, buffer_size, output);

    fclose(input);
    fclose(output);
}

void decrypt(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error: could not open file(s)\n");
        exit(1);
    }

    char buffer[MAX_SIZE];
    int buffer_size = 0;
    int key = 42; // example key

    while (fread(buffer + buffer_size, 1, MAX_SIZE - buffer_size, input) > 0) {
        buffer_size += fread(buffer + buffer_size, 1, MAX_SIZE - buffer_size, input);
    }

    for (int i = 0; i < buffer_size; i++) {
        buffer[i] ^= key;
    }

    fwrite(buffer, 1, buffer_size, output);

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <mode>\n", argv[0]);
        printf("Mode: 0 for encryption, 1 for decryption\n");
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    int mode = atoi(argv[3]);

    if (mode == 0) {
        encrypt(input_file, output_file);
    } else if (mode == 1) {
        decrypt(input_file, output_file);
    } else {
        printf("Invalid mode\n");
        return 1;
    }

    return 0;
}