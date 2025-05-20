//FormAI DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Linked List Node Structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Linked List Operations
void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
}

void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Error: previous node cannot be NULL!");
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = prevNode->next;

    prevNode->next = newNode;
}

void deleteNode(Node** head, int key) {
    Node* tempNode = *head, *prevNode = NULL;

    if (tempNode != NULL && tempNode->data == key) {
        *head = tempNode->next;
        free(tempNode);
        return;
    }

    while (tempNode != NULL && tempNode->data != key) {
        prevNode = tempNode;
        tempNode = tempNode->next;
    }

    if (tempNode == NULL) {
        printf("Error: key not found in Linked List!");
        return;
    }

    prevNode->next = tempNode->next;
    free(tempNode);
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Insertion at Beginning
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    printf("Linked List after Inserting 1 and 2 at Beginning: ");
    printList(head);

    // Insertion at End
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    printf("Linked List after Inserting 3 and 4 at End: ");
    printList(head);

    // Insertion after Node
    insertAfter(head->next, 5);
    printf("Linked List after Inserting 5 after 2: ");
    printList(head);

    // Deletion of Node
    deleteNode(&head, 3);
    printf("Linked List after Deleting Node with Data = 3: ");
    printList(head);

    return 0;
}