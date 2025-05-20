//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 20

// A structure to represent a node in a linked list
typedef struct node {
    char *data;
    struct node *next;
} node_t;

// A function to allocate memory for a node
node_t *create_node(const char *data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = (char *)malloc(strlen(data) + 1);
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

// A function to print the linked list
void print_list(node_t *head) {
    while (head != NULL) {
        printf("%s -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a list of strings
    node_t *head = NULL;
    head = create_node("apple");
    head = create_node("banana");
    head = create_node("cherry");

    // Print the list
    print_list(head);

    // Free the memory allocated for the list
    node_t *current = head;
    while (current != NULL) {
        free(current->data);
        current = current->next;
    }
    free(head);

    return 0;
}