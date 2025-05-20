//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the linked list structure
typedef struct LinkedList {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

// Initialize the linked list
void initLinkedList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Add a node to the end of the linked list
void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

// Remove a node from the linked list
bool removeNode(LinkedList* list, int data) {
    Node* currentNode = list->head;
    Node* previousNode = NULL;
    while (currentNode!= NULL && currentNode->data!= data) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        return false;
    }
    if (previousNode == NULL) {
        list->head = currentNode->next;
    } else {
        previousNode->next = currentNode->next;
    }
    if (currentNode == list->tail) {
        list->tail = previousNode;
    }
    free(currentNode);
    list->size--;
    return true;
}

// Print the linked list
void printLinkedList(LinkedList* list) {
    Node* currentNode = list->head;
    printf("Linked List: ");
    while (currentNode!= NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Main function
int main() {
    LinkedList myList;
    initLinkedList(&myList);
    addNode(&myList, 1);
    addNode(&myList, 2);
    addNode(&myList, 3);
    printLinkedList(&myList);
    removeNode(&myList, 2);
    printLinkedList(&myList);
    removeNode(&myList, 1);
    printLinkedList(&myList);
    removeNode(&myList, 3);
    printLinkedList(&myList);
    return 0;
}