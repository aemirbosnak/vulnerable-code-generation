//LLAMA2-13B DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Insert a node in the middle of the list
    struct Node* middle = newNode(4);
    middle->next = head;
    head = middle;

    // Insert some nodes at the end of the list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 7);

    // Print the list
    printList(head);

    return 0;
}