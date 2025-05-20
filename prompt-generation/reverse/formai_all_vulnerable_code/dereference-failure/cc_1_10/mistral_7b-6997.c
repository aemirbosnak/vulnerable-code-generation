//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024
#define BLOCK_SIZE 128

void encrypt_byte(unsigned char *input, int key) {
    *input = (*input + key) % 256;
}

void encrypt_block(unsigned char *input, int key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        encrypt_byte(&input[i], key);
    }
}

void write_to_file(FILE *output, unsigned char *data, int size) {
    fwrite(data, size, 1, output);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (!input) {
        perror("Error opening input file.");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (!output) {
        perror("Error opening output file.");
        fclose(input);
        return 1;
    }

    int key = atoi(argv[3]);
    if (key < 1 || key > 25) {
        printf("Invalid key. Key must be between 1 and 25.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    unsigned char buffer[BLOCK_SIZE];
    while (fread(buffer, BLOCK_SIZE, 1, input) > 0) {
        encrypt_block(buffer, key);
        write_to_file(output, buffer, BLOCK_SIZE);
    }

    fclose(input);
    fclose(output);

    printf("File '%s' encrypted successfully.\n", argv[1]);

    return 0;
}