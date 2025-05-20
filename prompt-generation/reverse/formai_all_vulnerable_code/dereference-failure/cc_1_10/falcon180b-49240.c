//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node definition for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Function to search for an element in the list
int search(struct Node* head, int x) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return 1;
        current = current->next;
    }
    return 0;
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;

    // Insert 5 elements in the list
    push(&head, 2);
    push(&head, 4);
    push(&head, 6);
    push(&head, 8);
    push(&head, 10);

    // Search for an element in the list
    int x = 8;
    if (search(head, x))
        printf("Element found in the list");
    else
        printf("Element not found in the list");

    return 0;
}