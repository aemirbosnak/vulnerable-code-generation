//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block *next;
    char data[1];
} Block;

Block *head = NULL;

void print_memory_usage() {
    Block *current = head;
    printf("\nMemory Usage:\n");
    printf("----------------------------------\n");
    while (current != NULL) {
        printf("| Block Size: %zu | Block Address: %p |\n", current->size, current);
        current = current->next;
    }
    printf("----------------------------------\n");
}

void add_to_list(size_t size, char *data) {
    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (new_block == NULL) {
        printf("Error: Out of memory!\n");
        return;
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;

    memcpy(new_block->data, data, size);
}

void free_memory(void *ptr) {
    Block *current = head;
    Block *prev = NULL;

    while (current != NULL) {
        if (current == ptr) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    char *str1 = "Hello World!";
    char *str2 = "Another String!";
    size_t size1 = strlen(str1) + 1;
    size_t size2 = strlen(str2) + 1;

    add_to_list(size1, str1);
    add_to_list(size2, str2);

    print_memory_usage();

    free(str1);
    free_memory(str1);

    free(str2);
    free_memory(str2);

    print_memory_usage();

    return 0;
}