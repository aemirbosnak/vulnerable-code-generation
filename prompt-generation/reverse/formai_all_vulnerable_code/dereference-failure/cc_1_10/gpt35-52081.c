//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096

typedef struct {
    unsigned char in_use;
    unsigned long size;
} DiskBlock;

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please provide a filename.\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");

    if (!file) {
        printf("File not found.\n");
        return 1;
    }

    fseek(file, 0L, SEEK_END);
    unsigned long file_size = ftell(file);
    unsigned long block_count = file_size / BLOCK_SIZE;
    if (file_size % BLOCK_SIZE != 0) {
        block_count++;
    }

    DiskBlock* blocks = (DiskBlock*) malloc(block_count * sizeof(DiskBlock));
    memset(blocks, 0, block_count * sizeof(DiskBlock));

    printf("Analyzing disk space...\n");

    fseek(file, 0L, SEEK_SET);
    unsigned long i = 0;
    while (i < file_size) {
        char buffer[BLOCK_SIZE];
        unsigned long bytes_read = fread(buffer, 1, BLOCK_SIZE, file);

        if (bytes_read < BLOCK_SIZE) {
            memset(buffer + bytes_read, 0, BLOCK_SIZE - bytes_read);
        }

        unsigned long j;
        for (j=0; j < BLOCK_SIZE; j++) {
            blocks[(i/BLOCK_SIZE)].size += buffer[j];
        }

        blocks[(i/BLOCK_SIZE)].in_use = 1;
        i += BLOCK_SIZE;
    }

    printf("Disk block analysis complete.\n");

    unsigned long used_blocks = 0;
    unsigned long free_blocks = 0;
    unsigned long used_space = 0;
    unsigned long free_space = 0;

    for (i=0; i < block_count; i++) {
        if (blocks[i].in_use) {
            used_blocks++;
            used_space += blocks[i].size;
        } else {
            free_blocks++;
            free_space += BLOCK_SIZE;
        }
    }

    printf("Total blocks: %lu\n", block_count);
    printf("Used blocks: %lu\n", used_blocks);
    printf("Free blocks: %lu\n", free_blocks);
    printf("Used space: %lu bytes\n", used_space);
    printf("Free space: %lu bytes\n", free_space);

    free(blocks);
    fclose(file);

    return 0;
}