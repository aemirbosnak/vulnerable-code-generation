//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    FILE *input = fopen(argv[1], "rb");
    FILE *output = fopen(argv[2], "wb");
    if (input == NULL || output == NULL) {
        fprintf(stderr, "Error opening files\n");
        exit(1);
    }

    int size = 0;
    fseek(input, 0, SEEK_END);
    size = ftell(input);
    fseek(input, 0, SEEK_SET);
    char *buffer = (char *) malloc(size + 1);

    if (fread(buffer, size, 1, input)!= 1) {
        fprintf(stderr, "Error reading from input file\n");
        exit(1);
    }

    if (buffer[size]!= '\n') {
        fprintf(stderr, "Error: input file does not end with a newline\n");
        exit(1);
    }

    int recovered_size = 0;
    int recovered_index = 0;
    int original_index = 0;

    while (original_index < size) {
        if (buffer[original_index] == '\n') {
            recovered_size = recovered_index - recovered_size;
            recovered_index = original_index + 1;
        } else {
            recovered_size += recovered_index - recovered_size;
            recovered_index = original_index + 1;
            original_index++;
        }
    }

    fwrite(buffer, recovered_size + 1, 1, output);
    fclose(input);
    fclose(output);

    free(buffer);
    return 0;
}