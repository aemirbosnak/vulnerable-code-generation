//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int size;
    struct node *next;
} node_t;

node_t *head = NULL;

void push(int size) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->size = size;
    new_node->next = head;
    head = new_node;
}

int pop() {
    if (head == NULL) {
        return -1;
    }

    int size = head->size;
    node_t *next = head->next;
    free(head);
    head = next;

    return size;
}

int get_current_ram_usage() {
    int total_size = 0;

    node_t *current = head;
    while (current != NULL) {
        total_size += current->size;
        current = current->next;
    }

    return total_size;
}

int main() {
    int i;

    // Allocate a bunch of memory to simulate RAM usage
    for (i = 0; i < 10000; i++) {
        push(rand() % 1000);
    }

    // Print the current RAM usage
    printf("Current RAM usage: %d bytes\n", get_current_ram_usage());

    // Free the allocated memory
    while (pop() != -1) {
        // Do nothing
    }

    // Print the current RAM usage
    printf("Current RAM usage: %d bytes\n", get_current_ram_usage());

    return 0;
}