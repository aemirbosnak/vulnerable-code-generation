//FormAI DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define BITS 8

struct MemoryBlock {
    unsigned char *p;
    int size;
};

void Compress(char *input_file_name, char *output_file_name) {
    FILE *input_file = fopen(input_file_name, "rb");
    FILE *output_file = fopen(output_file_name, "wb");

    int block_size = 1 << BITS;
    unsigned char *block = (unsigned char*) malloc(block_size);
    int block_index = 0;

    int next_sym;
    int sym_count = 0;
    int max_sym_count = 1 << BITS;

    while ((next_sym = fgetc(input_file)) != EOF) {
        if (block_index >= block_size) {
            fwrite(block, 1, block_size, output_file);
            block_index = 0;
        }

        block[block_index++] = next_sym;

        if (++sym_count >= max_sym_count) {
            fwrite(&sym_count, sizeof(int), 1, output_file);
            fwrite(block, 1, block_size, output_file);
            block_index = 0;
            sym_count = 0;
        }
    }

    if (sym_count > 0) {
        fwrite(&sym_count, sizeof(int), 1, output_file);
        fwrite(block, 1, block_index, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    free(block);
}

void Decompress(char *input_file_name, char *output_file_name) {
    FILE *input_file = fopen(input_file_name, "rb");
    FILE *output_file = fopen(output_file_name, "wb");

    int block_size = 1 << BITS;
    unsigned char *block = (unsigned char*) malloc(block_size);

    int sym_count;

    while (fread(&sym_count, sizeof(int), 1, input_file) > 0) {
        if (fread(block, 1, block_size, input_file) < block_size) {
            fprintf(stderr, "File corrupted\n");
            exit(1);
        }

        for (int i = 0; i < sym_count; i++)
            fputc(block[i], output_file);
    }

    fclose(input_file);
    fclose(output_file);

    free(block);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [c/d] [input file] [output file]\n", argv[0]);
        exit(1);
    }

    if (argv[1][0] == 'c')
        Compress(argv[2], argv[3]);
    else if (argv[1][0] == 'd')
        Decompress(argv[2], argv[3]);
    else {
        fprintf(stderr, "Invalid mode: %c\n", argv[1][0]);
        exit(1);
    }

    return 0;
}