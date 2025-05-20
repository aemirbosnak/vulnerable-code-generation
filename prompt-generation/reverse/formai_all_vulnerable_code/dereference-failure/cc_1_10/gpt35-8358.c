//FormAI DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

/*
 * Definition of a Linked List node
 */
struct Node {
    int data;
    struct Node* next;
};

/*
 * Function declaration for Linked List operations
 */
void insertAtBeginning(struct Node**, int);
void insertAtEnd(struct Node**, int);
void insertAtPosition(struct Node**, int, int);
void deleteAtBeginning(struct Node**);
void deleteAtEnd(struct Node**);
void deleteAtPosition(struct Node**, int);
void searchLinkedList(struct Node*, int);
void displayLinkedList(struct Node*);

/*
 * Main function
 */
int main() {
    struct Node* head = NULL; // Pointer to head node

    // Insert nodes at the beginning of the Linked List
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);
    printf("Linked List after inserting 15, 10 and 5 at the beginning:\n");
    displayLinkedList(head);

    // Insert nodes at the end of the Linked List
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printf("Linked List after inserting 20, 30 and 40 at the end:\n");
    displayLinkedList(head);

    // Insert nodes at a particular position in the Linked List
    insertAtPosition(&head, 25, 4);
    insertAtPosition(&head, 35, 6);
    insertAtPosition(&head, 45, 8);
    printf("Linked List after inserting 25, 35 and 45 at positions 4, 6 and 8 respectively:\n");
    displayLinkedList(head);

    // Delete the first node of the Linked List
    deleteAtBeginning(&head);
    printf("Linked List after deleting the first node:\n");
    displayLinkedList(head);

    // Delete the last node of the Linked List
    deleteAtEnd(&head);
    printf("Linked List after deleting the last node:\n");
    displayLinkedList(head);

    // Delete a node at a specific position in the Linked List
    deleteAtPosition(&head, 3);
    printf("Linked List after deleting the node at position 3:\n");
    displayLinkedList(head);

    // Search for a node in the Linked List
    searchLinkedList(head, 25);

    return 0;
}

/*
 * Function to insert a node at the beginning of the Linked List
 */
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

/*
 * Function to insert a node at the end of the Linked List
 */
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

/*
 * Function to insert a node at a particular position in the Linked List
 */
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = (*head);
        (*head) = newNode;
        return;
    }

    struct Node* tempNode = *head;
    for (int i = 1; i < position - 1; i++) {
        tempNode = tempNode->next;
    }
    newNode->next = tempNode->next;
    tempNode->next = newNode;
}

/*
 * Function to delete the first node of the Linked List
 */
void deleteAtBeginning(struct Node** head) {
    struct Node* tempNode = *head;

    if (tempNode == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    *head = tempNode->next;
    free(tempNode);
}

/*
 * Function to delete the last node of the Linked List
 */
void deleteAtEnd(struct Node** head) {
    struct Node* tempNode = *head;

    if (tempNode == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    if (tempNode->next == NULL) {
        *head = NULL;
        free(tempNode);
        return;
    }

    while (tempNode->next->next != NULL) {
        tempNode = tempNode->next;
    }

    struct Node* lastNode = tempNode->next;
    tempNode->next = NULL;
    free(lastNode);
}

/*
 * Function to delete a node at a particular position in the Linked List
 */
void deleteAtPosition(struct Node** head, int position) {
    struct Node* tempNode = *head;

    if (tempNode == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    if (position == 1) {
        *head = tempNode->next;
        free(tempNode);
        return;
    }

    for (int i = 1; i < position - 1; i++) {
        tempNode = tempNode->next;
    }

    struct Node* deleteNode = tempNode->next;
    tempNode->next = deleteNode->next;
    free(deleteNode);
}

/*
 * Function to search for a node in the Linked List
 */
void searchLinkedList(struct Node* head, int key) {
    struct Node* tempNode = head;

    while (tempNode != NULL) {
        if (tempNode->data == key) {
            printf("Node with data %d found in the Linked List!\n", key);
            return;
        }
        tempNode = tempNode->next;
    }

    printf("Node with data %d not found in the Linked List!\n", key);
}

/*
 * Function to display the Linked List
 */
void displayLinkedList(struct Node* head) {
    struct Node* tempNode = head;

    if (tempNode == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    while (tempNode != NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}