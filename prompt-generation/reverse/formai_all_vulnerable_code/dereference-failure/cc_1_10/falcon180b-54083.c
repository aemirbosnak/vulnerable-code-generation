//Falcon-180B DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MEMORY 1000000 // Maximum memory available

typedef struct node {
    int size;
    int free;
    struct node *next;
} Node;

Node *free_list = (void*)0;

void init() {
    free_list = (Node*)malloc(sizeof(Node));
    free_list->size = MAX_MEMORY - sizeof(Node);
    free_list->free = true;
    free_list->next = (void*)0;
}

void *my_malloc(int size) {
    Node *current = free_list;

    while (current!= NULL && current->size < size) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Out of memory\n");
        exit(1);
    }

    if (current->size == size) {
        current->free = false;
        return (void*)((int)current + sizeof(Node));
    } else {
        Node *new_block = (void*)malloc(size + sizeof(Node));
        new_block->size = size;
        new_block->free = false;
        new_block->next = current->next;
        current->size -= size + sizeof(Node);
        current->next = new_block;
        return (void*)((int)new_block + sizeof(Node));
    }
}

void my_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    Node *current = free_list;

    while (current!= NULL && (void*)current!= ptr) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid pointer\n");
        exit(1);
    }

    current->free = true;
}

int main() {
    init();

    int *a = my_malloc(10 * sizeof(int));
    int *b = my_malloc(20 * sizeof(int));
    int *c = my_malloc(30 * sizeof(int));

    *a = 1;
    *b = 2;
    *c = 3;

    printf("%d %d %d\n", *a, *b, *c);

    my_free(a);
    my_free(b);
    my_free(c);

    return 0;
}