//FormAI DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 1024

typedef struct Block {
    int size;
    struct Block *next;
    char data[0];
} Block;

Block *head = NULL;

void *allocate(int size) {
    Block *block, *temp;
    void *ptr;

    if (size <= 0) {
        return NULL;
    }

    size = (size / BLOCK_SIZE + 1) * BLOCK_SIZE;

    if (head == NULL) {
        block = (Block *) malloc(sizeof(Block) + size);
        if (block == NULL) {
            return NULL;
        }
        block->size = size;
        block->next = NULL;
        head = block;
    } else {
        temp = head;
        while (temp->next != NULL) {
            if (temp->size >= size) {
                break;
            }
            temp = temp->next;
        }
        if (temp->size >= size) {
            block = temp;
        } else {
            block = (Block *) malloc(sizeof(Block) + size);
            if (block == NULL) {
                return NULL;
            }
            block->size = size;
            block->next = temp->next;
            temp->next = block;
        }
    }

    ptr = (void *) block->data;
    head = block->next;

    return ptr;
}

void deallocate(void *ptr) {
    Block *block = (Block *) (((char *) ptr) - sizeof(Block));

    block->next = head;
    head = block;
}

int main() {
    int *x, *y, *z;

    x = (int *) allocate(sizeof(int));
    y = (int *) allocate(sizeof(int));
    z = (int *) allocate(sizeof(int));

    *x = 10;
    *y = 20;
    *z = 30;

    printf("x = %d\ny = %d\nz = %d\n", *x, *y, *z);

    deallocate(y);

    y = (int *) allocate(sizeof(int));

    *y = 40;

    printf("x = %d\ny = %d\nz = %d\n", *x, *y, *z);

    deallocate(x);
    deallocate(y);
    deallocate(z);

    return 0;
}