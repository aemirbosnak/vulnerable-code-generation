//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define MAGIC_NUMBER 0xDEADBEEF

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
};

void* malloc_with_flair(size_t size) {
    void* mem = malloc(size);
    if (mem == NULL) {
        printf("MALLOC FAILED WITH SIZE %zu\n", size);
        exit(EXIT_FAILURE);
    }

    // add some flair to the memory block
    *((int*)mem) = MAGIC_NUMBER;
    return mem;
}

void free_with_flair(void* mem) {
    if (mem == NULL) {
        printf("FREE NULL POINTER\n");
        return;
    }

    // check if the memory block has the magic number
    if (*((int*)mem) != MAGIC_NUMBER) {
        printf("FREE UNEXPECTED MEMORY BLOCK\n");
        return;
    }

    // free the memory block
    free(mem);
}

int main() {
    struct list* list = malloc_with_flair(sizeof(struct list));
    if (list == NULL) {
        printf("MALLOC FAILED FOR LIST\n");
        return EXIT_FAILURE;
    }

    // add some elements to the list
    struct node* node = malloc_with_flair(sizeof(struct node));
    node->data = 1;
    node->next = NULL;
    list->head = node;

    node = malloc_with_flair(sizeof(struct node));
    node->data = 2;
    node->next = NULL;
    list->head->next = node;

    node = malloc_with_flair(sizeof(struct node));
    node->data = 3;
    node->next = NULL;
    list->head->next->next = node;

    // free the list
    free_with_flair(list);

    return EXIT_SUCCESS;
}