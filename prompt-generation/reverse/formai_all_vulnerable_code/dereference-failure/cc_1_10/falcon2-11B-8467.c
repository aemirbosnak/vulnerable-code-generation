//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*head);
    (*head) = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = (*head);
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create the head of the list
    struct Node* head = NULL;

    // Insert 10 nodes at the beginning of the list
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 60);
    insertAtBeginning(&head, 70);
    insertAtBeginning(&head, 80);
    insertAtBeginning(&head, 90);
    insertAtBeginning(&head, 100);

    // Print the list
    printf("Linked list: ");
    printList(head);

    // Insert 5 nodes at the end of the list
    insertAtEnd(&head, 101);
    insertAtEnd(&head, 102);
    insertAtEnd(&head, 103);
    insertAtEnd(&head, 104);
    insertAtEnd(&head, 105);

    // Print the updated list
    printf("Updated linked list: ");
    printList(head);

    return 0;
}