//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to add a node at the end of the list
void append(Node** headRef, int newData) {
    Node* newNode = createNode(newData);

    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }

    Node* last = *headRef;
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
    return;
}

// Function to add a node after a given position
void addAfter(Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    Node* newNode = createNode(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return;
}

// Function to delete a node by key
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef, *prev;

    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);            
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to search for a node by key
Node* search(Node* head, int key) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    // Add nodes
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);

    // Print the list
    printf("Singly linked list: ");
    printList(head);

    // Add a node at the end
    append(&head, 40);

    // Print the list
    printf("\nSingly linked list after appending 40: ");
    printList(head);

    // Add a node after a given position
    Node* last = search(head, 30);
    addAfter(last, 35);

    // Print the list
    printf("\nSingly linked list after adding 35 after 30: ");
    printList(head);

    // Delete a node by key
    deleteNode(&head, 20);

    // Print the list
    printf("\nSingly linked list after deleting 20: ");
    printList(head);

    return 0;
}