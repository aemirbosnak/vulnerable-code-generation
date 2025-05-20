//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for our linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to add an element to the end of the linked list
void addElement(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int main() {
    Node* head = NULL;

    // Add some elements to the linked list
    addElement(&head, 1);
    addElement(&head, 2);
    addElement(&head, 3);
    addElement(&head, 4);
    addElement(&head, 5);

    // Print the linked list
    printf("Linked List:\n");
    printList(head);

    // Reverse the linked list
    Node* prev = NULL;
    Node* current = head;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    // Print the reversed linked list
    printf("\nReversed Linked List:\n");
    printList(head);

    return 0;
}