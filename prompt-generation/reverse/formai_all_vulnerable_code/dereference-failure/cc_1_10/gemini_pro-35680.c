//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list of 10 nodes
    node *head = NULL;
    for (int i = 0; i < 10; i++) {
        node *new_node = malloc(sizeof(node));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }

    // Print the linked list
    print_list(head);

    // Reverse the linked list
    node *prev = NULL;
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    // Print the reversed linked list
    print_list(head);

    // Free the linked list
    while (head != NULL) {
        node *next = head->next;
        free(head);
        head = next;
    }

    return 0;
}