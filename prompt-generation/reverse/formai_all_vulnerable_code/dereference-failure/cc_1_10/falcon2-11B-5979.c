//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
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

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *head;
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to search a node in the linked list
struct Node* searchNode(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    return temp;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Creating a linked list
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Printing the linked list
    printf("Original Linked List: ");
    printList(head);

    // Deleting a node from the linked list
    deleteNode(&head, 30);

    // Printing the linked list after deletion
    printf("\nLinked List after Deletion: ");
    printList(head);

    // Searching a node in the linked list
    struct Node* temp = searchNode(head, 10);
    if (temp!= NULL) {
        printf("Node found at position: %d\n", temp->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}