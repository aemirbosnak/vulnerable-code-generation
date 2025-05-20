//FormAI DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>

// Defining the structure for the node of our linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int newData) {
    // Allocating memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Assigning new data to the new node
    newNode->data = newData;
    // Setting the next pointer of the new node to the current head pointer
    newNode->next = *headRef;
    // Updating the head pointer to point to the new node
    *headRef = newNode;
}

// Function to print the linked list
void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

int main() {
    // Creating a new linked list with 4 initial nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Inserting a new node at the beginning of the linked list
    insertAtBeginning(&head, 0);

    // Printing the linked list
    printf("Linked List: ");
    printList(head);

    return 0;
}