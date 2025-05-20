//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Defining the structure of a linked list
typedef struct list {
    Node* head;
    Node* tail;
    int size;
} List;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new linked list
List* createList() {
    List* newList = (List*)malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
}

// Function to add a node to the end of the linked list
void addNode(List* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

// Function to remove a node from the linked list
void removeNode(List* list, int data) {
    Node* currNode = list->head;
    Node* prevNode = NULL;
    while (currNode!= NULL && currNode->data!= data) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode == NULL) {
        printf("Node not found.\n");
    } else {
        if (prevNode == NULL) {
            list->head = currNode->next;
        } else {
            prevNode->next = currNode->next;
        }
        if (currNode == list->tail) {
            list->tail = prevNode;
        }
        free(currNode);
        list->size--;
    }
}

// Function to print the linked list
void printList(List* list) {
    printf("Linked List:\n");
    Node* currNode = list->head;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    List* myList = createList();

    addNode(myList, 1);
    addNode(myList, 2);
    addNode(myList, 3);

    printList(myList);

    removeNode(myList, 2);

    printList(myList);

    return 0;
}