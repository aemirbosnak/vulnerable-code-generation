//FormAI DATASET v1.0 Category: File system simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024
#define BLOCK_NUM 100

typedef struct {
    char *data;
    int size;
    int index;
} block;

block *fs[BLOCK_NUM];
int fs_size = 0;

void init_fs() {
    int i;
    for (i = 0; i < BLOCK_NUM; i++) {
        fs[i] = NULL;
    }
}

int get_empty_block_index() {
    int i;
    for (i = 0; i < BLOCK_NUM; i++) {
        if (fs[i] == NULL) {
            return i;
        }
    }
    return -1;
}

block *create_block() {
    block *new_block = (block *)malloc(sizeof(block));
    new_block->size = 0;
    new_block->index = get_empty_block_index();
    new_block->data = (char *)malloc(BLOCK_SIZE * sizeof(char));
    fs[new_block->index] = new_block;
    fs_size++;
    return new_block;
}

block *get_block(int block_index) {
    if (block_index < 0 || block_index >= BLOCK_NUM) {
        printf("Invalid block index %d\n", block_index);
        return NULL;
    }

    return fs[block_index];
}

void delete_block(int block_index) {
    if (block_index < 0 || block_index >= BLOCK_NUM) {
        printf("Invalid block index %d\n", block_index);
        return;
    }

    free(fs[block_index]->data);
    free(fs[block_index]);

    fs[block_index] = NULL;
    fs_size--;
}

int write_block(block *blk, char *data) {
    int len = strlen(data);
    if (len > BLOCK_SIZE) {
        printf("Data exceed block size\n");
        return -1;
    }

    strcpy(blk->data, data);
    blk->size = len;

    return 0;
}

char *read_block(block *blk) {
    return blk->data;
}

int main() {
    init_fs();

    block *blk1 = create_block();
    write_block(blk1, "Hello World");

    block *blk2 = create_block();
    write_block(blk2, "This is a demonstration of C File system simulation");

    printf("Block 1 content: %s\n", read_block(blk1));
    printf("Block 2 content: %s\n", read_block(blk2));

    delete_block(blk1->index);
    delete_block(blk2->index);

    printf("File system size: %d\n", fs_size);

    return 0;
}