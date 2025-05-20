//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define a surrealist linked list node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* previous;
    struct Node* upper;
    struct Node* lower;
} Node;

// Function to insert a node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;
    newNode->upper = NULL;
    newNode->lower = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->lower = newNode;
        newNode->previous = *head;
        *head = newNode;
    }
}

// Function to traverse the linked list
void traverseList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    traverseList(head);

    return 0;
}