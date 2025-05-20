//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
    char *filename;
    int size;
    int num_blocks;
    char **blocks;
} File;

void read_file(FILE *fp, char *filename, int *size, int *num_blocks) {
    fseek(fp, 0, SEEK_END);
    *size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char buffer[BLOCK_SIZE];
    int block_num = 0;
    while (fread(buffer, 1, BLOCK_SIZE, fp) == BLOCK_SIZE) {
        block_num++;
    }
    *num_blocks = block_num;
}

void write_file(FILE *fp, char *filename, int size, int num_blocks, char **blocks) {
    fwrite(blocks[0], size, 1, fp);
}

int main() {
    char *filename = "test.txt";
    FILE *fp = fopen(filename, "r");

    int size, num_blocks;
    read_file(fp, filename, &size, &num_blocks);

    char **blocks = malloc(num_blocks * sizeof(char *));
    for (int i = 0; i < num_blocks; i++) {
        blocks[i] = malloc(BLOCK_SIZE);
    }

    int block_num = 0;
    while (size > 0) {
        int to_read = (size > BLOCK_SIZE)? BLOCK_SIZE : size;
        fread(blocks[block_num], 1, to_read, fp);
        size -= to_read;
        block_num++;
    }

    fclose(fp);

    // Simulate data loss
    blocks[2] = NULL;

    // Recover lost data
    for (int i = 0; i < num_blocks; i++) {
        if (blocks[i] == NULL) {
            char *new_block = malloc(BLOCK_SIZE);
            memset(new_block, 'X', BLOCK_SIZE);
            blocks[i] = new_block;
        }
    }

    write_file(fp, filename, size, num_blocks, blocks);

    for (int i = 0; i < num_blocks; i++) {
        free(blocks[i]);
    }
    free(blocks);

    return 0;
}