//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Node structure for Linked List
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print Linked List
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add a node at the beginning of Linked List
struct Node* addAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*head);
    (*head) = newNode;
    return (*head);
}

// Function to add a node at the end of Linked List
struct Node* addAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = (*head);
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return (*head);
}

// Function to delete a node from Linked List
struct Node* deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found in the Linked List\n");
        return *head;
    }
    if (prev == NULL) {
        *head = temp->next;
        free(temp);
        return *head;
    }
    prev->next = temp->next;
    free(temp);
    return *head;
}

int main() {
    struct Node* head = NULL;

    // Add elements to the Linked List
    addAtBeginning(&head, 1);
    addAtBeginning(&head, 2);
    addAtBeginning(&head, 3);

    // Print the Linked List
    printf("Linked List: ");
    printList(head);

    // Delete an element from the Linked List
    int dataToDelete = 2;
    deleteNode(&head, dataToDelete);

    // Print the Linked List after deletion
    printf("Linked List after deletion: ");
    printList(head);

    return 0;
}