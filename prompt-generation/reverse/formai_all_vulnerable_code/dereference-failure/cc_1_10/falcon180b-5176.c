//Falcon-180B DATASET v1.0 Category: Memory management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked list structure
typedef struct {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

// Function to delete a node with given data from the list
void deleteNode(LinkedList* list, int data) {
    Node* currNode = list->head;
    Node* prevNode = NULL;
    while (currNode!= NULL && currNode->data!= data) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode == NULL) {
        printf("Node not found\n");
        return;
    }
    if (prevNode == NULL) {
        list->head = currNode->next;
    }
    else {
        prevNode->next = currNode->next;
    }
    if (currNode == list->tail) {
        list->tail = prevNode;
    }
    free(currNode);
    list->size--;
}

// Function to print the list
void printList(LinkedList* list) {
    Node* currNode = list->head;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

// Main function
int main() {
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    // Add some nodes
    addNode(&list, 1);
    addNode(&list, 2);
    addNode(&list, 3);

    // Print the list
    printList(&list);

    // Delete a node
    deleteNode(&list, 2);

    // Print the list again
    printList(&list);

    return 0;
}