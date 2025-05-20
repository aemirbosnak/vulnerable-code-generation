//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
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
    printf("%d added to the list.\n", newData);
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
    printf("%d added to the list.\n", newData);
}

// Function to add a node after a given position
void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;

    printf("%d added to the list.\n", data);
}

// Function to delete a node with the given data
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef, *prev;

    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        printf("%d deleted from the list.\n", key);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the list.\n", key);
}

// Function to search for a node with the given data
Node* searchNode(Node* head, int key) {
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

// Driver code
int main() {
    Node* head = NULL;

    push(&head, 12);
    push(&head, 17);
    push(&head, 19);
    push(&head, 26);

    printf("Created linked list: ");
    printList(head);

    append(&head, 31);
    printf("\nLinked list after appending 31: ");
    printList(head);

    insertAfter(searchNode(head, 19), 24);
    printf("\nLinked list after inserting 24 after 19: ");
    printList(head);

    deleteNode(&head, 12);
    printf("\nLinked list after deleting 12: ");
    printList(head);

    deleteNode(&head, 26);
    printf("\nLinked list after deleting 26: ");
    printList(head);

    return 0;
}