//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Head and tail pointers
Node *head = NULL;
Node *tail = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to insert a node after a given node
void insertAfterNode(Node *prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    Node *newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    if (tail == prevNode) {
        tail = newNode;
    }
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    free(temp);
}

// Function to delete a node from the end of the list
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = tail = NULL;
    } else {
        tail = prev;
        prev->next = NULL;
    }
    free(temp);
}

// Function to delete a node from the middle of the list
void deleteNode(Node *node) {
    if (node == NULL) {
        printf("Node cannot be NULL\n");
        return;
    }
    if (node == head) {
        deleteFromBeginning();
        return;
    }
    if (node == tail) {
        deleteFromEnd();
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp != node) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = node->next;
    free(node);
}

// Function to print the list
void printList() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAfterNode(head, 15);
    printList();  // Output: 10 15 20 30
    deleteFromBeginning();
    printList();  // Output: 15 20 30
    deleteFromEnd();
    printList();  // Output: 15 20
    deleteNode(head->next);
    printList();  // Output: 15
    return 0;
}