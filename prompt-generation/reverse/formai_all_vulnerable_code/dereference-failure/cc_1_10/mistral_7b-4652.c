//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define BLOCK_SIZE 25

typedef struct Block {
    size_t size;
    void *data;
    struct Block *next;
} Block;

Block *head = NULL;

void print_memory() {
    printf("Current memory usage:\n");
    Block *current = head;
    while (current != NULL) {
        printf("Block %p: Size %ld, Data %p\n", current, current->size, current->data);
        current = current->next;
    }
}

void* my_malloc(size_t size) {
    if (size > MAX_SIZE) {
        fprintf(stderr, "Error: Size too large!\n");
        return NULL;
    }

    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (!new_block) {
        fprintf(stderr, "Error: Could not allocate memory!\n");
        return NULL;
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;

    print_memory();

    return (void *)((char *)new_block + sizeof(Block));
}

void my_free(void *ptr) {
    Block *current = head;
    Block *previous = NULL;

    while (current != NULL) {
        if ((void *)current >= ptr && (void *)current + current->size >= ptr) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);

            print_memory();
            break;
        }

        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        fprintf(stderr, "Error: Invalid pointer!\n");
    }
}

int main() {
    char *str1 = (char *)my_malloc(50);
    char *str2 = (char *)my_malloc(100);
    char *str3 = (char *)my_malloc(75);

    strcpy(str1, "Hello");
    strcpy(str2, "World");
    strcpy(str3, "This is an active C memory management example program!");

    printf("Allocated strings:\n");
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("String 3: %s\n", str3);

    my_free(str1);
    my_free(str2);
    my_free(str3);

    printf("Freed memory:\n");
    print_memory();

    char *str4 = (char *)my_malloc(200);

    if (str4 == NULL) {
        fprintf(stderr, "Error: Could not allocate memory!\n");
        return 1;
    }

    printf("Allocated string 4: %ld bytes\n", (long)str4 - (long)head);

    my_free(str4);

    printf("Freed memory after string 4:\n");
    print_memory();

    return 0;
}