//FormAI DATASET v1.0 Category: Compression algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 256

void compress(FILE* input, FILE* output) {
    char* buffer = (char*)malloc(BLOCK_SIZE * sizeof(char));
    size_t n = 0;
    int c = 0;
    char last = 0;
    while ((n = fread(buffer, 1, BLOCK_SIZE, input)) > 0) {
        for (size_t i = 0; i < n; i++) {
            c = buffer[i] - last;
            if (c <= 127 && c >= -128) {
                fputc(c, output);
            } else {
                fputc(0x7F, output);
                fputc(buffer[i], output);
            }
            last = buffer[i];
        }
    }
    free(buffer);
}

void decompress(FILE* input, FILE* output) {
    int c = 0;
    char last = 0;
    while ((c = fgetc(input)) != EOF) {
        if (c == 0x7F) {
            fputc(fgetc(input), output);
        } else {
            fputc(last + c, output);
        }
        last += c;
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s [compress|decompress] [input file] [output file]\n", argv[0]);
        return 1;
    }

    char* mode = argv[1];
    char* input_filename = argv[2];
    char* output_filename = argv[3];

    FILE* input = fopen(input_filename, "rb");
    FILE* output = fopen(output_filename, "wb");

    if (input == NULL || output == NULL) {
        printf("Failed to open files\n");
        return 1;
    }

    if (strcmp(mode, "compress") == 0) {
        compress(input, output);
    } else if (strcmp(mode, "decompress") == 0) {
        decompress(input, output);
    } else {
        printf("Invalid mode\n");
        return 1;
    }

    fclose(input);
    fclose(output);

    return 0;
}