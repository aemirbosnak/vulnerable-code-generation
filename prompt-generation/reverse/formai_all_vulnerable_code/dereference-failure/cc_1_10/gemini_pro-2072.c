//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int size;
} Block;

void recover(FILE *fp, const char *filename) {
    int block_size = 512;
    Block block;
    block.data = malloc(block_size);
    block.size = 0;

    while (fread(block.data, 1, block_size, fp) == block_size) {
        if (block.data[0] == 0xff && block.data[1] == 0xd8 && block.data[2] == 0xff) {
            if (block.size > 0) {
                char *new_filename = malloc(strlen(filename) + 5);
                sprintf(new_filename, "%s.%03d.jpg", filename, block.size);
                FILE *new_fp = fopen(new_filename, "wb");
                fwrite(block.data, 1, block.size, new_fp);
                fclose(new_fp);
                free(new_filename);
            }
            block.size = 0;
        }
        block.size += block_size;
    }

    if (block.size > 0) {
        char *new_filename = malloc(strlen(filename) + 5);
        sprintf(new_filename, "%s.%03d.jpg", filename, block.size);
        FILE *new_fp = fopen(new_filename, "wb");
        fwrite(block.data, 1, block.size, new_fp);
        fclose(new_fp);
        free(new_filename);
    }

    free(block.data);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    recover(fp, argv[2]);

    fclose(fp);

    return 0;
}