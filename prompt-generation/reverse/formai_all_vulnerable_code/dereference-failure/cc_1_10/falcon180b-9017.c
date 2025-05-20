//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 16

void encrypt(FILE *input_file, FILE *output_file) {
    char input_buffer[BLOCK_SIZE];
    char output_buffer[BLOCK_SIZE + 1];
    int i;

    while (fread(input_buffer, sizeof(char), BLOCK_SIZE, input_file) > 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            output_buffer[i] = input_buffer[i] ^ KEY[i % strlen(KEY)];
        }
        output_buffer[BLOCK_SIZE] = '\0';
        fwrite(output_buffer, sizeof(char), BLOCK_SIZE + 1, output_file);
    }
}

void decrypt(FILE *input_file, FILE *output_file) {
    char input_buffer[BLOCK_SIZE + 1];
    char output_buffer[BLOCK_SIZE];
    int i;

    while (fread(input_buffer, sizeof(char), BLOCK_SIZE + 1, input_file) > 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            output_buffer[i] = input_buffer[i] ^ KEY[i % strlen(KEY)];
        }
        fwrite(output_buffer, sizeof(char), BLOCK_SIZE, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <encrypt/decrypt>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    if (strcmp(argv[3], "encrypt") == 0) {
        encrypt(input_file, output_file);
    } else if (strcmp(argv[3], "decrypt") == 0) {
        decrypt(input_file, output_file);
    } else {
        printf("Invalid operation specified.\n");
        return 1;
    }

    fclose(input_file);
    fclose(output_file);

    printf("Operation completed successfully.\n");
    return 0;
}