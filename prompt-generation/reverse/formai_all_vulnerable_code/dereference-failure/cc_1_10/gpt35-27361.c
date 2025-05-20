//FormAI DATASET v1.0 Category: Data recovery tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <lost_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *lost_file = argv[1];
    char *output_file = argv[2];

    FILE *input = fopen(lost_file, "rb");
    if (input == NULL) {
        printf("Error: failed to open input file '%s'\n", lost_file);
        return 1;
    }

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error: failed to open output file '%s'\n", output_file);
        return 1;
    }

    unsigned char block[BLOCK_SIZE];
    memset(block, 0, BLOCK_SIZE);

    while (fread(&block, BLOCK_SIZE, 1, input) == 1) {
        unsigned char first_byte = block[0];
        unsigned char second_byte = block[1];

        if (first_byte == 0xFF && second_byte == 0xD8) {
            fwrite(&block, BLOCK_SIZE, 1, output);
            memset(block, 0, BLOCK_SIZE);
            continue;
        }

        if (first_byte == 0xFF && second_byte == 0xD9) {
            fwrite(&block, BLOCK_SIZE, 1, output);
            fclose(input);
            fclose(output);
            printf("Successfully recovered file '%s'\n", output_file);
            return 0;
        }

        fwrite(&block, BLOCK_SIZE, 1, output);
    }

    printf("Error: end of file reached without finding JPEG footer\n");
    fclose(input);
    fclose(output);
    return 1;
}