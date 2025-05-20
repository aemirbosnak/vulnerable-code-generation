//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
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

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to add a new node at the beginning of the list
void addAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a new node at the end of the list
void addAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node with the given data from the list
void deleteNode(struct Node** head, int data) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node not found\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Function to search for a node with the given data in the list
int searchNode(struct Node* head, int data) {
    struct Node* current = head;

    while (current!= NULL && current->data!= data) {
        current = current->next;
    }

    if (current == NULL) {
        return -1;
    }

    return current->data;
}

int main() {
    // Create the linked list
    struct Node* head = NULL;
    addAtBeginning(&head, 10);
    addAtEnd(&head, 20);
    addAtEnd(&head, 30);
    addAtEnd(&head, 40);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Delete a node with the data 20
    deleteNode(&head, 20);

    // Print the linked list after deletion
    printf("Linked List after deletion: ");
    printList(head);

    // Search for a node with the data 30
    int dataToSearch = 30;
    int nodeIndex = searchNode(head, dataToSearch);
    printf("Node found at index %d\n", nodeIndex);

    return 0;
}