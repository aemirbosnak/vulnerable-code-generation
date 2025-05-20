//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: irregular
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
        node *new_node = (node *) malloc(sizeof(node));
        new_node->data = arr[i];
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            curr = head;
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

int search_list_iterative(node *head, int target) {
    node *curr = head;
    while (curr != NULL) {
        if (curr->data == target) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int search_list_recursive(node *head, int target) {
    if (head == NULL) {
        return 0;
    }
    if (head->data == target) {
        return 1;
    }
    return search_list_recursive(head->next, target);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = create_list(arr, size);
    print_list(head);
    int target = 5;
    int found = search_list_iterative(head, target);
    printf("Target %d found iteratively: %d\n", target, found);
    found = search_list_recursive(head, target);
    printf("Target %d found recursively: %d\n", target, found);
    return 0;
}