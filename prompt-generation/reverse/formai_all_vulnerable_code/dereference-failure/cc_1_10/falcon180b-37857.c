//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

void createList(struct Node** head);
void addNode(struct Node** head, int data);
void deleteNode(struct Node** head, int data);
void printList(struct Node* node);

int main() {
    struct Node* head = NULL;

    // Create a list with 5 nodes
    createList(&head);

    // Print the list
    printf("Initial List:\n");
    printList(head);

    // Add a node with data 6
    addNode(&head, 6);

    // Print the list after adding a node
    printf("\nList after adding node with data 6:\n");
    printList(head);

    // Delete a node with data 3
    deleteNode(&head, 3);

    // Print the list after deleting a node
    printf("\nList after deleting node with data 3:\n");
    printList(head);

    return 0;
}

// Function to create an empty list
void createList(struct Node** head) {
    *head = NULL;
}

// Function to add a node at the end of the list
void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    }
    else {
        struct Node* temp = *head;
        while(temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node with the given data
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(struct Node* node) {
    while(node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}