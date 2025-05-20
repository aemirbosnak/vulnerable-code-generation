//FormAI DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold the node data and the link to the next node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the beginning of the list
void push(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to add a node at a given position in the list
void insertAt(struct Node** headRef, int position, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    if (position == 0) {
        newNode->next = *headRef;
        *headRef = newNode;
    }
    else {
        struct Node* current = *headRef;
        for (int i = 0; i < position-1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to remove a node from the beginning of the list
void pop(struct Node** headRef) {
    struct Node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
}

// Function to remove a node from a given position in the list
void deleteAt(struct Node** headRef, int position) {
    if (position == 0) {
        struct Node* temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
    }
    else {
        struct Node* current = *headRef;
        for (int i = 0; i < position-1; i++) {
            current = current->next;
        }
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);
    insertAt(&head, 2, 4);
    printList(head);
    pop(&head);
    printList(head);
    deleteAt(&head, 1);
    printList(head);
    return 0;
}