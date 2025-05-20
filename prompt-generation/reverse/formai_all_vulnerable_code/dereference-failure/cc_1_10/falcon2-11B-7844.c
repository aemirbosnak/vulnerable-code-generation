//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a custom data structure
typedef struct {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to add a node at the beginning of the list
void addNodeAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the list
void addNodeAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* lastNode = *head;
    while (lastNode->next!= NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Function to remove a node from the list
void removeNode(Node** head, int data) {
    Node* current = *head;
    Node* prev = NULL;
    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

// Function to traverse the list
void traverseList(Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;
    addNodeAtBeginning(&head, 10);
    addNodeAtEnd(&head, 20);
    addNodeAtEnd(&head, 30);
    printf("Original list: ");
    traverseList(head);
    printf("\n");

    // Asynchronous operation
    pthread_t thread;
    pthread_create(&thread, NULL, traverseList, (void*)&head);

    // Remove the middle node
    removeNode(&head, 20);
    printf("List after removal: ");
    traverseList(head);
    printf("\n");

    // Join the thread
    pthread_join(thread, NULL);

    printf("List after removal: ");
    traverseList(head);
    printf("\n");

    return 0;
}