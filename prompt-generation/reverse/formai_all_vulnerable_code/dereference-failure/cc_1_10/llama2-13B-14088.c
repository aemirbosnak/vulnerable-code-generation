//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct node {
    int data;
    struct node* next;
};

// Function to create a linked list
struct node* create_list(int* numbers, int n) {
    struct node* head = NULL;
    int i;
    for (i = 0; i < n; i++) {
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = numbers[i];
        new_node->next = head;
        head = new_node;
    }
    return head;
}

// Function to print the linked list
void print_list(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to find the minimum element in the linked list
struct node* find_min(struct node* head) {
    struct node* current = head;
    struct node* previous = NULL;
    while (current != NULL) {
        if (previous == NULL || current->data < previous->data) {
            previous = current;
            current = current->next;
        } else {
            current = current->next;
        }
    }
    return previous;
}

int main() {
    int numbers[] = {10, 5, 2, 8, 3, 1};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    struct node* head = create_list(numbers, n);
    print_list(head);

    struct node* min = find_min(head);
    printf("Minimum element: %d\n", min->data);

    return 0;
}