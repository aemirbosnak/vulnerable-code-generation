//Falcon-180B DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    void* data;
    struct node* next;
} Node;

// Linked list structure
typedef struct list {
    Node* head;
    int size;
} List;

// Function to initialize an empty list
void initList(List* list) {
    list->head = NULL;
    list->size = 0;
}

// Function to insert a new node at the end of the list
void insertNode(List* list, void* data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

// Function to delete a node from the list
void deleteNode(List* list, void* data) {
    Node* temp = list->head;
    Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: Node not found\n");
        return;
    }
    if (prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    list->size--;
}

// Function to print the list
void printList(List* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%p ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    List myList;
    initList(&myList);

    insertNode(&myList, (void*) 1);
    insertNode(&myList, (void*) 2);
    insertNode(&myList, (void*) 3);

    printList(&myList);

    deleteNode(&myList, (void*) 2);

    printList(&myList);

    return 0;
}