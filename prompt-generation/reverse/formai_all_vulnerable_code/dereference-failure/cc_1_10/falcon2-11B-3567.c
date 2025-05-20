//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Define a linked list structure
struct List {
    struct Node* head;
    struct Node* tail;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new linked list
struct List* createList() {
    struct List* newList = (struct List*)malloc(sizeof(struct List));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

// Function to add a new node to the beginning of the list
void push(struct List* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
}

// Function to add a new node to the end of the list
void append(struct List* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Function to print the linked list
void printList(struct List* list) {
    struct Node* current = list->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct List* list = createList();
    push(list, 1);
    push(list, 2);
    push(list, 3);
    append(list, 4);
    append(list, 5);
    printList(list);
    return 0;
}