//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the linked list structure
typedef struct list {
    Node* head;
} List;

// Function to create a new node with given data
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
    return newList;
}

// Function to add a node to the end of the list
void addNode(List* list, int data) {
    Node* newNode = createNode(data);
    Node* temp = list->head;
    if (temp == NULL) {
        list->head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(List* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    List* list = createList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 5);
    printList(list);
    return 0;
}