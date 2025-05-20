//FormAI DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

void encode(FILE *input, FILE *output, unsigned char key[]) {
    unsigned char buffer[1024];
    size_t read;
    int i = 0;
    while ((read = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (int j = 0; j < read; ++j) {
            buffer[j] ^= key[i];
            i = (i + 1) % KEY_LENGTH;
        }
        fwrite(buffer, 1, read, output);
    }
}

void decode(FILE *input, FILE *output, unsigned char key[]) {
    encode(input, output, key);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [mode] [input file] [output file]\n", argv[0]);
        fprintf(stderr, "\tmode:      e for encrypt, d for decrypt\n");
        fprintf(stderr, "\tinput:     input file path\n");
        fprintf(stderr, "\toutput:    output file path\n");
        return 1;
    }

    FILE *input = fopen(argv[2], "rb");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen(argv[3], "wb");
    if (!output) {
        perror("Error opening output file");
        return 1;
    }

    char *mode = argv[1];
    if (strcmp(mode, "e") == 0) {
        unsigned char key[KEY_LENGTH] = "thisisultraprecise";
        encode(input, output, key);
    } else if (strcmp(mode, "d") == 0) {
        unsigned char key[KEY_LENGTH] = "thisisultraprecise";
        decode(input, output, key);
    } else {
        fprintf(stderr, "Invalid mode: %s\n", mode);
        return 1;
    }

    fclose(input);
    fclose(output);
    return 0;
}