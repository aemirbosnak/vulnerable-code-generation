//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 1024
#define MAX_ARRAY_SIZE 10

typedef struct node {
    char *str;
    struct node *next;
} node_t;

node_t *create_node(char *str) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->str = str;
    new_node->next = NULL;
    return new_node;
}

void free_node(node_t *node) {
    free(node->str);
    free(node);
}

void* malloc_with_logging(size_t size) {
    void *ptr = malloc(size);
    printf("Memory allocated at address %p of size %zu\n", ptr, size);
    return ptr;
}

void free_with_logging(void *ptr) {
    free(ptr);
    printf("Memory freed at address %p\n", ptr);
}

int main() {
    // Create a list of strings
    node_t *head = NULL;
    for (int i = 0; i < 10; i++) {
        char *str = malloc_with_logging(strlen("Hello, world!") + 1);
        strcpy(str, "Hello, world!");
        head = head->next = create_node(str);
    }

    // Print the list of strings
    for (node_t *cur = head; cur != NULL; cur = cur->next) {
        printf("%s\n", cur->str);
    }

    // Free the list of strings
    for (node_t *cur = head; cur != NULL;) {
        free_with_logging(cur->str);
        cur = cur->next;
    }

    return 0;
}