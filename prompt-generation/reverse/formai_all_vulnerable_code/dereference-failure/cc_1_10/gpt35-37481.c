//FormAI DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// define the structure for the Node data type
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// define the structure for the LinkedList data type
typedef struct LinkedList {
    Node* head;
} LinkedList;

// function to create a new Node
Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// function to create a new LinkedList
LinkedList* createLinkedList() {
    LinkedList* newLinkedList = malloc(sizeof(LinkedList));
    newLinkedList->head = NULL;
    return newLinkedList;
}

// function to add a Node to the LinkedList at the beginning
void addNode(LinkedList* linkedList, int value) {
    Node* newNode = createNode(value);
    if (linkedList->head == NULL) {
        linkedList->head = newNode;
    } else {
        newNode->next = linkedList->head;
        linkedList->head = newNode;
    }
}

// function to print out the LinkedList
void printLinkedList(LinkedList* linkedList) {
    Node* current = linkedList->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// main function to test LinkedList functionality
int main() {
    LinkedList* myLinkedList = createLinkedList();
    addNode(myLinkedList, 5);
    addNode(myLinkedList, 10);
    addNode(myLinkedList, 15);
    printLinkedList(myLinkedList);
    return 0;
}