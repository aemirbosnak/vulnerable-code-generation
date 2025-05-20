//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new linked list
struct Node* newList(int size) {
    struct Node* head = NULL;
    for (int i = 0; i < size; i++) {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Function to traverse the linked list
void traverseList(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printf("%d ", head->data);
    traverseList(head->next);
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    current->next = newNode;
    return newNode;
}

// Function to remove the first node from the linked list
struct Node* removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    struct Node* removedNode = *head_ref;
    *head_ref = removedNode->next;
    free(removedNode);
    return removedNode;
}

// Function to remove the last node from the linked list
struct Node* removeLast(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    free(current);
    return previous;
}

int main() {
    struct Node* head = newList(5);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    removeFirst(&head);
    removeLast(&head);
    traverseList(head);
    return 0;
}