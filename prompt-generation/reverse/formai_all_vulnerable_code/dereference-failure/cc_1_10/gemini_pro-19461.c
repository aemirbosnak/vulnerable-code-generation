//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_list(int n) {
    node *head = NULL;
    for (int i = 0; i < n; i++) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = rand() % 100;
        new_node->next = head;
        head = new_node;
    }
    return head;
}

void print_list(node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void free_list(node *head) {
    while (head != NULL) {
        node *next = head->next;
        free(head);
        head = next;
    }
}

int main() {
    int n = 10;
    node *head = create_list(n);

    printf("Original list:\n");
    print_list(head);

    // Reverse the list
    node *prev = NULL;
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    printf("Reversed list:\n");
    print_list(head);

    // Free the list
    free_list(head);

    return 0;
}