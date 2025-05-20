//FormAI DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Defining a structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* currentNode = head;

    printf("Linked List: ");

    while(currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("NULL\n");
}

// Function to add a new node at the beginning of the linked list
void push(struct Node** head, int data) {
    // Allocating memory for the new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // Setting the data of the new node
    newNode->data = data;

    // Setting the next pointer of the new node
    newNode->next = (*head);

    // Updating the head of the linked list
    (*head) = newNode;

    printf("New node with data %d added at the beginning of the linked list.\n", data);
}

// Function to add a new node at the end of the linked list
void append(struct Node** head, int data) {
    // Allocating memory for the new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // Setting the data of the new node
    newNode->data = data;

    // Setting the next pointer of the new node to NULL
    newNode->next = NULL;

    // Checking if the linked list is empty
    if(*head == NULL) {
        // If linked list is empty, set the new node as the head of the linked list
        *head = newNode;

        printf("New node with data %d added at the end of the linked list.\n", data);
        return;
    }

    // Traverse to the last node of the linked list
    struct Node* lastNode = *head;
    while(lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    // Attach the new node to the end of the linked list
    lastNode->next = newNode;

    printf("New node with data %d added at the end of the linked list.\n", data);
}

// Function to insert a new node at a specific position in the linked list
void insert(struct Node** head, int data, int position) {
    // Allocating memory for the new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // Setting the data of the new node
    newNode->data = data;

    // Setting a pointer to the previous node
    struct Node* previousNode = NULL;

    // Setting a pointer to the current node
    struct Node* currentNode = *head;

    // Checking if the linked list is empty
    if(*head == NULL) {
        // If the linked list is empty, set the new node as the head of the linked list
        *head = newNode;

        printf("New node with data %d added at position %d of the linked list.\n", data, position);
        return;
    }

    // Traverse to the position where the new node needs to be inserted
    int currentPosition = 0;
    while(currentPosition != position && currentNode != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->next;
        currentPosition++;
    }

    // If the position is greater than the length of the linked list, insert the new node at the end of the linked list
    if(currentPosition < position) {
        previousNode->next = newNode;
        newNode->next = NULL;

        printf("New node with data %d added at position %d of the linked list.\n", data, currentPosition + 1);
        return;
    }

    // If the position is at the beginning of the linked list, set the new node as the head of the linked list
    if(previousNode == NULL) {
        *head = newNode;
    }
    // Otherwise, insert the new node in between two nodes
    else {
        previousNode->next = newNode;
    }

    newNode->next = currentNode;

    printf("New node with data %d added at position %d of the linked list.\n", data, currentPosition + 1);
}

// Function to delete a node at a specific position in the linked list
void deleteNode(struct Node** head, int position) {
    // Setting a pointer to the previous node
    struct Node* previousNode = NULL;

    // Setting a pointer to the current node
    struct Node* currentNode = *head;

    // Checking if the linked list is empty
    if(*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    // Traverse to the position of the node to be deleted
    int currentPosition = 0;
    while(currentPosition != position && currentNode != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->next;
        currentPosition++;
    }

    // If the position is greater than or equal to the length of the linked list, display an error message
    if(currentNode == NULL) {
        printf("Invalid position.\n");
        return;
    }

    // If the node to be deleted is the head of the linked list, set the next node as the new head
    if(previousNode == NULL) {
        *head = currentNode->next;
    }
    // Otherwise, connect the previous node to the next node, skipping the current node
    else {
        previousNode->next = currentNode->next;
    }

    printf("Node at position %d deleted from the linked list.\n", currentPosition + 1);

    // Freeing memory occupied by the deleted node
    free(currentNode);
}

int main() {
    struct Node* head = NULL;

    // Adding nodes to the linked list
    append(&head, 1);
    append(&head, 2);
    push(&head, 0);
    insert(&head, 3, 3);
    displayList(head);

    // Deleting nodes from the linked list
    deleteNode(&head, 2);
    deleteNode(&head, 3);
    displayList(head);

    return 0;
}