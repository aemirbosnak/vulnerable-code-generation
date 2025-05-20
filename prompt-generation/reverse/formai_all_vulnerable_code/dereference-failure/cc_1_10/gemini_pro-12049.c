//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_list(int *arr, int size) {
    node *head = NULL;
    node *curr = NULL;

    for (int i = 0; i < size; i++) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = arr[i];
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            curr = new_node;
        } else {
            curr->next = new_node;
            curr = curr->next;
        }
    }

    return head;
}

void print_list(node *head) {
    node *curr = head;

    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

void free_list(node *head) {
    node *curr = head;

    while (curr != NULL) {
        node *next = curr->next;
        free(curr);
        curr = next;
    }
}

int main() {
    // Create an array of integers
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create a linked list from the array
    node *head = create_list(arr, size);

    // Print the linked list
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}