//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

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

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        *head = (*head)->next;
        free(*head);
        return;
    }
    struct Node* current = *head;
    while (current->next!= NULL) {
        if (current->next->data == data) {
            current->next = current->next->next;
            free(current->next);
            return;
        }
        current = current->next;
    }
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

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);
    printList(head); // Output: 1 2 3 4 5
    printf("Deleting node with data 4...\n");
    deleteNode(&head, 4);
    printList(head); // Output: 1 2 3 5
    return 0;
}