//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 4096

typedef struct block {
    int is_allocated;
    int block_number;
} Block;

Block *bitmap;
int num_blocks;

void init_bitmap(int num_blocks) {
    bitmap = (Block *)malloc(num_blocks * sizeof(Block));
    for (int i = 0; i < num_blocks; i++) {
        bitmap[i].is_allocated = 0;
        bitmap[i].block_number = i;
    }
}

int find_free_block() {
    for (int i = 0; i < num_blocks; i++) {
        if (!bitmap[i].is_allocated) {
            bitmap[i].is_allocated = 1;
            return i;
        }
    }
    return -1;
}

int main() {
    num_blocks = 10;
    init_bitmap(num_blocks);

    int file_size = 100;
    char *file_data = (char *)malloc(file_size * sizeof(char));

    int current_block = find_free_block();
    for (int i = 0; i < file_size; i++) {
        if (i % BLOCK_SIZE == 0) {
            current_block = find_free_block();
        }
        file_data[i] = 'a';
        bitmap[current_block].is_allocated = 1;
    }

    printf("File data:\n%s\n", file_data);

    free(file_data);

    return 0;
}