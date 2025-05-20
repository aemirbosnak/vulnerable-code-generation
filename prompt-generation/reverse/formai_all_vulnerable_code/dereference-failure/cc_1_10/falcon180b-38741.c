//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
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

// Function to add a node at a specific position in the list
void addAtPosition(struct Node** head_ref, int new_data, int pos) {
    struct Node* new_node = newNode(new_data);
    struct Node* temp = *head_ref;

    if (pos == 0) {
        new_node->next = temp;
        *head_ref = new_node;
        return;
    }

    for (int i = 0; i < pos - 1 && temp!= NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        printf("Invalid position\n");
    else {
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// Function to delete a node with the given data
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        temp = temp->next;
    }

    if (temp == NULL)
        printf("Key not found\n");
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    printf("List after adding nodes: ");
    printList(head);
    append(&head, 9);
    printf("\nList after appending node: ");
    printList(head);
    addAtPosition(&head, 2, 1);
    printf("\nList after adding node at position 1: ");
    printList(head);
    deleteNode(&head, 7);
    printf("\nList after deleting node with data 7: ");
    printList(head);
    deleteNode(&head, 9);
    printf("\nList after deleting node with data 9: ");
    printList(head);

    return 0;
}