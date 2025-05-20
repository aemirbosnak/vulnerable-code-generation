//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked list structure
typedef struct list {
    Node* head;
} List;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty list
List* createList() {
    List* newList = (List*) malloc(sizeof(List));
    if (newList == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    newList->head = NULL;
    return newList;
}

// Function to add a node at the end of the list
void addNode(List* list, int data) {
    Node* newNode = createNode(data);
    Node* temp = list->head;
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to remove a node with the given data
void removeNode(List* list, int data) {
    Node* temp = list->head;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        list->head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(List* list) {
    Node* temp = list->head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    List* list = createList();
    addNode(list, 5);
    addNode(list, 10);
    addNode(list, 15);
    printList(list);
    removeNode(list, 10);
    printList(list);
    removeNode(list, 5);
    printList(list);
    removeNode(list, 15);
    printList(list);
    free(list);
    return 0;
}