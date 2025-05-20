//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
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

// Function to add a node at the end of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to search for an element in the linked list
int search(struct Node* head, int x) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return 1;
        current = current->next;
    }
    return 0;
}

int main() {
    struct Node* head = NULL;

    // Create linked list 1->2->3->4->5
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    // Search for element 3
    int result = search(head, 3);

    // Print the result
    if (result == 1)
        printf("Element 3 found in the list");
    else
        printf("Element 3 not found in the list");

    return 0;
}