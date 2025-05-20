//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
    printf("%d added to the list\n", newData);
}

// Function to add a node at the end of the list
void append(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }
    struct Node* last = *headRef;
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
    printf("%d added to the list\n", newData);
}

// Function to add a node at a specific position
void addAtPosition(struct Node** headRef, int newData, int pos) {
    struct Node* newNode = createNode(newData);
    if (pos == 1) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    for (int i = 1; i < pos - 1 && temp!= NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d added to the list\n", newData);
}

// Function to delete a node with given data
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef;
    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        printf("%d deleted from the list\n", key);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    struct Node* prev = temp;
    while (temp->next!= NULL) {
        temp = temp->next;
        prev = prev->next;
    }
    prev->next = prev->next->next;
    free(temp);
    printf("%d deleted from the list\n", key);
}

// Function to display the list
void display(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    append(&head, 40);
    display(head);
    addAtPosition(&head, 25, 3);
    display(head);
    deleteNode(&head, 30);
    display(head);
    deleteNode(&head, 10);
    display(head);
    return 0;
}