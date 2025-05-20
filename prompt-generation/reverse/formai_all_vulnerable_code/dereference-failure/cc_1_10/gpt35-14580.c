//FormAI DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize the head of the linked list as NULL
struct Node* head = NULL;

// Create a new node and return a pointer to the new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning of the linked list
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

// Insert a node at the end of the linked list
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Insert a node at a particular index in the linked list
void insertAtIndex(int value, int index) {
    struct Node* newNode = createNode(value);
    if (head == NULL || index == 0) {
        insertAtBeginning(value);
    }
    else {
        int i = 0;
        struct Node* temp = head;
        while (i < index-1 && temp->next != NULL) {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Delete a node from the beginning of the linked list
void deleteFromBeginning() {
    if (head == NULL) {
        printf("The linked list is already empty!\n");
    }
    else {
        head = head->next;
    }
}

// Delete a node from the end of the linked list
void deleteFromEnd() {
    if (head == NULL) {
        printf("The linked list is already empty!\n");
    }
    else if (head->next == NULL) {
        head = NULL;
    }
    else {
        struct Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}

// Delete a node from a particular index in the linked list
void deleteFromIndex(int index) {
    if (head == NULL) {
        printf("The linked list is already empty!\n");
    }
    else if (index == 0) {
        deleteFromBeginning();
    }
    else {
        int i = 0;
        struct Node* temp = head;
        while (i < index-1 && temp->next != NULL) {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL) {
            printf("The index is out of bounds.\n");
        }
        else {
            temp->next = temp->next->next;
        }
    }
}

// Traverse and display the linked list
void traverse() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The linked list is empty!\n");
    }
    else {
        printf("The linked list is: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // Insert nodes into the linked list
    insertAtBeginning(5);
    insertAtEnd(9);
    insertAtIndex(7, 1);
    
    // Traverse and display the linked list
    traverse();
    
    // Delete nodes from the linked list
    deleteFromBeginning();
    deleteFromEnd();
    deleteFromIndex(0);
    
    // Traverse and display the linked list again
    traverse();

    return 0;
}