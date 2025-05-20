//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BINARY_LENGTH 256
#define HEADER_LENGTH 16

typedef struct {
    char name[16];
    unsigned char data[BINARY_LENGTH];
} CyberPunkFile;

void binary_to_text(unsigned char *binary, FILE *output_file) {
    for (int i = 0; i < BINARY_LENGTH; ++i) {
        if (binary[i] < 0x20 || binary[i] > 0x7E) {
            fprintf(output_file, "\\x%02X", binary[i]);
        } else {
            fprintf(output_file, "%c", binary[i]);
        }
    }
}

void text_to_binary(const char *text, CyberPunkFile *file) {
    FILE *input_file = fopen(text, "r");
    if (!input_file) {
        perror("Error opening text file");
        exit(EXIT_FAILURE);
    }

    fseek(input_file, SEEK_END, SEEK_SET);
    size_t length = ftell(input_file);
    rewind(input_file);

    for (size_t i = 0; i < length; ++i) {
        char c = fgetc(input_file);
        if (c == EOF) {
            perror("Error reading text file");
            exit(EXIT_FAILURE);
        }

        if (isalnum(c) || c == ' ') {
            file->data[i] = (unsigned char)tolower(c);
        } else {
            file->data[i] = (unsigned char)0x3A; // Replace non-alphanumeric characters with colon
        }
    }

    fclose(input_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <text_file> <output_binary_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    CyberPunkFile file;
    strcpy(file.name, argv[2]);
    text_to_binary(argv[1], &file);

    FILE *output_file = fopen(file.name, "wb");
    if (!output_file) {
        perror("Error opening output binary file");
        exit(EXIT_FAILURE);
    }

    // Write header - Cyberpunk style file identifier
    fprintf(output_file, "CP%s:\n", file.name);
    for (int i = 0; i < 12; ++i) {
        fprintf(output_file, "%02X", i % 16 == 0 ? 0x5A : 0x3A);
    }
    fprintf(output_file, "\n");

    // Write file name
    size_t name_length = strlen(file.name);
    fprintf(output_file, "%s\n", file.name);

    // Write file data
    binary_to_text(file.data, output_file);

    fclose(output_file);
    printf("File converted successfully.\n");

    return EXIT_SUCCESS;
}