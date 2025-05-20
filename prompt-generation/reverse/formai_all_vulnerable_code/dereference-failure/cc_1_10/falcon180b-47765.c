//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
    FILE *file;
    int block_size;
    char *block;
} Block;

Block *create_block(FILE *file, int block_size) {
    Block *block = (Block *) malloc(sizeof(Block));
    block->file = file;
    block->block_size = block_size;
    block->block = (char *) malloc(block_size);
    return block;
}

void destroy_block(Block *block) {
    free(block->block);
    free(block);
}

int read_block(Block *block, int block_number) {
    fseek(block->file, block_number * block->block_size, SEEK_SET);
    fread(block->block, block->block_size, 1, block->file);
    return 0;
}

int write_block(Block *block, int block_number) {
    fseek(block->file, block_number * block->block_size, SEEK_SET);
    fwrite(block->block, block->block_size, 1, block->file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    Block *input_block = create_block(input_file, BLOCK_SIZE);
    Block *output_block = create_block(output_file, BLOCK_SIZE);

    int block_number = 0;
    while (read_block(input_block, block_number) == 0) {
        if (memcmp(input_block->block, "DELETED", 7) == 0) {
            // Skip deleted blocks
            continue;
        }
        write_block(output_block, block_number);
        block_number++;
    }

    destroy_block(input_block);
    destroy_block(output_block);

    fclose(input_file);
    fclose(output_file);

    printf("Data recovery completed.\n");

    return 0;
}