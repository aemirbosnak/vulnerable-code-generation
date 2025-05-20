//FormAI DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the data structure for each node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the list given its key
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef;
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        struct Node* prev = temp;
        temp = temp->next;
        if (temp == NULL) {
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
}

// Function to reverse the linked list
void reverseList(struct Node** headRef) {
    struct Node *prev = NULL, *current = *headRef, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}

int main() {
    printf("Welcome to the Linked List Operations program!\n");

    // Create and initialize the linked list
    struct Node* head = NULL;
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Print the original list
    printf("Original List: ");
    printList(head);

    // Insert a new node at the beginning
    insertAtBeginning(&head, 1);
    printf("List after inserting 1 at the beginning: ");
    printList(head);

    // Insert a new node at the end
    insertAtEnd(&head, 6);
    printf("List after inserting 6 at the end: ");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 2);
    printf("List after deleting the node with data = 2: ");
    printList(head);

    // Reverse the linked list
    reverseList(&head);
    printf("Reversed List: ");
    printList(head);

    // Free up the memory and exit
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    printf("Thank you for using the Linked List Operations program!\n");

    return 0;
}