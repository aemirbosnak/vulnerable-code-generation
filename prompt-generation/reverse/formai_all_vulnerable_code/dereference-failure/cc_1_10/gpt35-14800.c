//FormAI DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEY "secret"

void encrypt(FILE *input, FILE *output);

int main(int argc, char *argv[]) {
    FILE *input, *output;

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    output = fopen(argv[2], "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    encrypt(input, output);

    fclose(input);
    fclose(output);

    printf("Encryption successful!\n");

    return 0;
}

void encrypt(FILE *input, FILE *output) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    int key_length = strlen(KEY);
    int i, j;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input)) > 0) {
        for (i = 0, j = 0; i < bytes_read; i++, j++) {
            if (j == key_length) {
                j = 0;
            }
            buffer[i] = buffer[i] ^ KEY[j];
        }
        fwrite(buffer, sizeof(char), bytes_read, output);
    }
}