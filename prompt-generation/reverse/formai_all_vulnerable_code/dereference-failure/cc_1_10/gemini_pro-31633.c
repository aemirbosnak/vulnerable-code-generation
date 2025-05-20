//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(node **head, node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void bubble_sort_list(node **head) {
    int swapped;
    do {
        swapped = 0;
        node *current = *head;
        while (current->next != NULL) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

int main() {
    node *head = NULL;
    insert_node(&head, create_node(10));
    insert_node(&head, create_node(5));
    insert_node(&head, create_node(15));
    insert_node(&head, create_node(2));
    insert_node(&head, create_node(7));

    printf("Unsorted list:\n");
    print_list(head);

    bubble_sort_list(&head);

    printf("Sorted list:\n");
    print_list(head);

    return 0;
}