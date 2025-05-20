//FormAI DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head; // global variable - pointer to head node.

// Create a new node and return pointer to it.
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning of the linked list.
void insertNode(int data) {
    Node *newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

// Append a node at the end of the linked list.
void appendNode(int data) {
    Node *newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// Insert a node at the given position in the linked list.
void insertNodeAt(int pos, int data) {
    Node *newNode = createNode(data);
    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *temp = head;
    for(int i=1; i<pos-1 && temp!=NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Position %d does not exist in the linked list.\n", pos);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete the first node in the linked list.
void deleteFirstNode() {
    if(head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    Node *temp = head;
    head = temp->next;
    free(temp);
}

// Delete the last node in the linked list.
void deleteLastNode() {
    if(head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    Node *temp = head;
    Node *prev;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == head) {
        head = NULL;
    }
    else {
        prev->next = NULL;
    }
    free(temp);
}

// Delete a node at the given position in the linked list.
void deleteNodeAt(int pos) {
    if(head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    Node *temp = head;
    if(pos == 1) {
        head = temp->next;
        free(temp);
        return;
    }
    Node *prev;
    for(int i=1; i<pos && temp!=NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Position %d does not exist in the linked list.\n", pos);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Display the linked list.
void displayLinkedList() {
    printf("Linked List: ");
    if(head == NULL) {
        printf("Empty\n");
        return;
    }
    Node *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    head = NULL;
    // Test the linked list operations
    insertNode(1);
    displayLinkedList();
    appendNode(2);
    displayLinkedList();
    insertNodeAt(2, 3);
    displayLinkedList();
    deleteFirstNode();
    displayLinkedList();
    deleteLastNode();
    displayLinkedList();
    deleteNodeAt(1);
    displayLinkedList();
    return 0;
}