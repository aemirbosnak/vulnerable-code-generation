//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t size;
    void *ptr;
    struct block *next;
} block_t;

typedef struct {
    block_t *head;
    size_t total;
} memory_t;

memory_t memory;

void init_memory() {
    memory.head = NULL;
    memory.total = 0;
}

void display_memory() {
    block_t *current = memory.head;
    printf("\nCurrent Memory Usage:\n");
    printf("-----------------------\n");
    printf("Address\tSize\tUsed By\n");
    printf("-----------------------\n");

    while (current != NULL) {
        printf("%p\t%ld bytes\t%s\n", current->ptr, current->size,
               current->size > 1024 ? "(large block)" : "(small block)");
        current = current->next;
    }
}

void add_block(size_t size) {
    void *new_block = malloc(size);

    if (new_block == NULL) {
        printf("Error: Unable to allocate memory\n");
        return;
    }

    block_t *new_block_node = (block_t *)malloc(sizeof(block_t));

    if (new_block_node == NULL) {
        free(new_block);
        printf("Error: Unable to allocate memory for block node\n");
        return;
    }

    new_block_node->size = size;
    new_block_node->ptr = new_block;
    new_block_node->next = memory.head;
    memory.head = new_block_node;
    memory.total += size + sizeof(block_t);
}

void remove_block(void *ptr) {
    block_t *current = memory.head;
    block_t *previous = NULL;

    while (current != NULL) {
        if (current->ptr == ptr) {
            if (previous == NULL) {
                memory.head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            memory.total -= current->size + sizeof(block_t);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    init_memory();

    int *array = (int *)calloc(10, sizeof(int));
    add_block(sizeof(int) * 10);

    char *string = (char *)malloc(100);
    strcpy(string, "Hello, World!");
    add_block(100);

    printf("Memory Usage After Allocations:\n");
    display_memory();

    free(string);
    remove_block(string);

    printf("\nMemory Usage After Freeing 'string':\n");
    display_memory();

    free(array);
    remove_block(array);

    printf("\nMemory Usage After Freeing 'array':\n");
    display_memory();

    init_memory();

    return 0;
}