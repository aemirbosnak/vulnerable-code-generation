//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 50
#define MAX_ARRAY_SIZE 10

typedef struct node {
    char *str;
    struct node *next;
} node_t;

void* mem_alloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void mem_free(void *ptr) {
    free(ptr);
}

node_t* create_linked_list(void) {
    node_t *head = NULL;
    node_t *node = NULL;
    char str[MAX_STR_LEN];
    int i;

    // Create nodes and link them together
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        node = (node_t*)mem_alloc(sizeof(node_t));
        node->str = (char*)mem_alloc(MAX_STR_LEN);
        strcpy(node->str, "Node #");
        node->next = head;
        head = node;
    }

    return head;
}

int main() {
    node_t *head = create_linked_list();
    char input[MAX_STR_LEN];

    // Print the linked list
    printf("Linked list: ");
    for (node_t *current = head; current != NULL; current = current->next) {
        printf("%s ", current->str);
    }
    printf("\n");

    // Free the memory
    for (node_t *current = head; current != NULL;) {
        node_t *next = current->next;
        mem_free(current);
        current = next;
    }

    return 0;
}