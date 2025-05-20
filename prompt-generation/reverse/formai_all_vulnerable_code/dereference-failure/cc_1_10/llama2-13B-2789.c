//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20

struct node {
    char *name;
    int age;
    struct node *next;
};

void *malloc_hook(size_t size) {
    if (size == 0) {
        printf("Oops, you tried to allocate zero bytes!\n");
        return NULL;
    }

    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Out of memory! (%d bytes)\n", size);
        exit(1);
    }

    printf("Allocated %d bytes at %p\n", size, ptr);
    return ptr;
}

void free_hook(void *ptr) {
    printf("Freeing %p\n", ptr);
    free(ptr);
}

int main() {
    struct node *head = NULL;
    struct node *node;

    // Create a linked list of nodes
    for (int i = 0; i < 5; i++) {
        node = malloc_hook(sizeof(struct node));
        if (node == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        node->name = malloc(MAX_STR_LEN);
        if (node->name == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        strcpy(node->name, "Node #");
        node->age = i;
        node->next = head;
        head = node;
    }

    // Print the linked list
    printf("Linked list:\n");
    for (node = head; node != NULL; node = node->next) {
        printf("%s (%d)\n", node->name, node->age);
    }

    // Free the linked list
    for (node = head; node != NULL;) {
        struct node *tmp = node->next;
        free(node);
        node = tmp;
    }

    return 0;
}