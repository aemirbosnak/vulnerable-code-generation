//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096

typedef struct block {
    size_t size;
    struct block *next;
    char data[BLOCK_SIZE];
} Block;

Block *head = NULL;

void print_memory() {
    Block *current = head;
    printf("Memory blocks:\n");
    while (current != NULL) {
        printf("Block size: %ld, Data address: %p\n", current->size, (void *)current->data);
        current = current->next;
    }
}

void* my_malloc(size_t size) {
    if (size > BLOCK_SIZE) {
        fprintf(stderr, "Error: Requested size exceeds block size.\n");
        return NULL;
    }

    Block *new_block = malloc(sizeof(Block) + size);
    if (new_block == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        return NULL;
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;

    return (void *)((char *)new_block + sizeof(Block));
}

void my_free(void *ptr) {
    Block *current = head;
    Block *prev = NULL;

    while (current != NULL) {
        if ((void *)current->data <= ptr && (void *)((char *)current + sizeof(Block) + current->size) > ptr) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    int *a = (int *)my_malloc(sizeof(int));
    int *b = (int *)my_malloc(sizeof(int) * 5);
    char *c = (char *)my_malloc(1024);

    *a = 42;
    *(a + 1) = 17;

    for (int i = 0; i < 5; i++) {
        *(b + i) = i;
    }

    strcpy(c, "Hello, World!");

    print_memory();

    my_free(a);
    my_free(b);
    my_free(c);

    print_memory();

    return 0;
}