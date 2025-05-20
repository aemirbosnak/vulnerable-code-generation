//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 10

typedef struct Block {
    size_t size;
    struct Block *next, *prev;
} Block;

Block *head = NULL, *tail = NULL;

void print_memory() {
    Block *current = head;
    printf("\nMemory Blocks:\n");
    while (current != NULL) {
        printf("Block size: %d, Address: %p, Previous: %p, Next: %p\n", current->size, current, current->prev, current->next);
        current = current->next;
    }
}

void add_block(size_t size) {
    Block *new_block = (Block *) malloc(sizeof(Block) + size);
    if (new_block == NULL) {
        printf("\nError: Out of memory!\n");
        exit(1);
    }

    new_block->size = size;
    new_block->next = NULL;
    new_block->prev = tail;

    if (tail != NULL)
        tail->next = new_block;

    if (head == NULL)
        head = new_block;
    else
        tail = new_block;
}

void remove_block(void *ptr) {
    Block *current = head, *prev;

    while (current != NULL) {
        if (current == (Block *) ((char *) head + (current->size + sizeof(Block)))) {
            if (current->prev != NULL)
                prev->next = current->next;
            else
                head = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    int i;
    char *str;

    add_block(100);
    add_block(50);
    add_block(200);
    add_block(150);

    print_memory();

    str = (char *) malloc(10);
    add_block(sizeof(int) + sizeof(char) * 10);

    print_memory();

    int *num = (int *) malloc(sizeof(int));
    add_block(sizeof(int));

    print_memory();

    free(str);
    remove_block(str);

    print_memory();

    free(num);
    remove_block(num);

    print_memory();

    return 0;
}