//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Creating the linked list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 1);

    // Printing the linked list
    printList(head);

    // Invasive Style: Inserting a new node between 3 and 5
    Node* current = head;
    Node* previous = NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Finding the previous node of 3
    while (current != NULL && current->data != 3) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: 3 not found in the list\n");
        free(newNode);
        return 1;
    }

    // Creating the new node
    newNode->data = 4;
    newNode->next = current;

    // Linking the new node to the previous node
    if (previous == NULL) {
        head = newNode;
    } else {
        previous->next = newNode;
    }

    // Printing the updated linked list
    printList(head);

    return 0;
}