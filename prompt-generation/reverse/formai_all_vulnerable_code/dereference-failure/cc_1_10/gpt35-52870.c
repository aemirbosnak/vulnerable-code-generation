//FormAI DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Defining the structure for a linked list node
struct Node {
    int data; // Data in the node
    struct Node* next; // Address of the next node
};

// Function to create a new node with given data
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int val) {
    struct Node* newNode = createNode(val);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a new node after a given node in the linked list
void insertAfterNode(struct Node* prevNode, int val) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL!");
        return;
    }
    struct Node* newNode = createNode(val);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** headRef, int val) {
    struct Node* newNode = createNode(val);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* lastNode = *headRef;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->next = newNode;
}

// Function to delete a node with a given key from the linked list
void deleteNodeByKey(struct Node** headRef, int key) {
    struct Node* temp = *headRef, *prev;
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

// Function to delete a node at a given position from the linked list
void deleteNodeByPos(struct Node** headRef, int pos) {
    if (*headRef == NULL)
        return;
    struct Node* temp = *headRef;
    if (pos == 0) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to display the contents of the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

//Main Function
int main() {
    // Creating a linked list with 3 nodes
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

    // Display the initial linked list
    printf("Initial Linked List : ");
    displayList(head);

    // Inserting a new node at the beginning of the linked list
    insertAtBeginning(&head, 0);
    printf("\nLinked List after insertion at beginning : ");
    displayList(head);

    // Inserting a new node after a given node in the linked list
    insertAfterNode(second, 4);
    printf("\nLinked List after insertion after node with value 2 : ");
    displayList(head);

    // Inserting a new node at the end of the linked list
    insertAtEnd(&head, 5);
    printf("\nLinked List after insertion at end : ");
    displayList(head);

    // Deleting a node with a given key from the linked list
    deleteNodeByKey(&head, 3);
    printf("\nLinked List after deletion of node with value 3 : ");
    displayList(head);

    // Deleting a node at a given position from the linked list
    deleteNodeByPos(&head, 2);
    printf("\nLinked List after deletion at position 2 : ");
    displayList(head);

    return 0;
}