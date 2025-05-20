//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_node(node_t **head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void sort_list(node_t **head) {
    node_t *current = *head;
    node_t *next;
    int temp;

    while (current != NULL) {
        next = current->next;

        while (next != NULL) {
            if (current->data > next->data) {
                temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }

        current = current->next;
    }
}

int main() {
    node_t *head = NULL;
    int i;

    for (i = 10; i >= 1; i--) {
        insert_node(&head, i);
    }

    printf("Unsorted list: ");
    print_list(head);

    sort_list(&head);

    printf("Sorted list: ");
    print_list(head);

    return 0;
}