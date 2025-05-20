//FormAI DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

// Add a new node at the beginning of the linked list
void addNodeAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Add a new node at the end of the linked list
void addNodeAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

// Delete a node with the given data
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        return;
    }
    struct Node* temp = *head;
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Print the linked list
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    addNodeAtBeginning(&head, 4);
    addNodeAtBeginning(&head, 2);
    addNodeAtEnd(&head, 6);
    addNodeAtEnd(&head, 8);
    printLinkedList(head);
    deleteNode(&head, 6);
    printLinkedList(head);
    return 0;
}