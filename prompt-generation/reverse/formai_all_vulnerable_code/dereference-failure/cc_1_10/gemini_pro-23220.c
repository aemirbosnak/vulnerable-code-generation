//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;

void insert_node(node **head, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void sort_list(node **head) {
    node *curr = *head;
    node *prev = NULL;
    node *next;

    while (curr) {
        next = curr->next;
        if (prev && prev->data > curr->data) {
            if (!prev->next) {
                *head = curr;
            }
            prev->next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } else {
            prev = curr;
            curr = next;
        }
    }
}

int main() {
    node *head = NULL;

    insert_node(&head, 5);
    insert_node(&head, 3);
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 4);

    print_list(head); // 1 2 3 4 5

    sort_list(&head);

    print_list(head); // 1 2 3 4 5

    return 0;
}