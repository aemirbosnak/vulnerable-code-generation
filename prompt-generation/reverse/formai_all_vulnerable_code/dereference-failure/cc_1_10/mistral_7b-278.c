//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

typedef struct block {
    size_t size;
    char name[32];
    struct block *next;
} Block;

Block *head = NULL;
size_t total_allocated = 0;

void *my_malloc(size_t size, const char *name) {
    if (size == 0) {
        fprintf(stderr, "Error: size must be greater than zero\n");
        return NULL;
    }

    void *ptr = malloc(size + sizeof(Block));
    if (ptr == NULL) {
        fprintf(stderr, "Error: out of memory\n");
        return NULL;
    }

    Block *new_block = (Block *)((char *)ptr - sizeof(Block));
    strcpy(new_block->name, name);
    new_block->size = size;
    new_block->next = head;
    head = new_block;
    total_allocated += size + sizeof(Block);

    return (char *)ptr + sizeof(Block);
}

void my_free(void *ptr) {
    Block *current = head;
    Block *previous = NULL;

    while (current != NULL) {
        if (current == (void *)((char *)ptr - sizeof(Block))) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            total_allocated -= current->size + sizeof(Block);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void print_memory_usage() {
    printf("Memory usage:\n");
    printf("Total allocated: %ld bytes\n", total_allocated);
    Block *current = head;
    while (current != NULL) {
        printf("%s: %ld bytes\n", current->name, current->size);
        total_allocated -= current->size + sizeof(Block);
        current = current->next;
    }
}

int main() {
    int *a = (int *)my_malloc("array", sizeof(int) * 10);
    int *b = (int *)my_malloc("vector", sizeof(int) * 5);
    my_free(a);

    print_memory_usage();

    return 0;
}