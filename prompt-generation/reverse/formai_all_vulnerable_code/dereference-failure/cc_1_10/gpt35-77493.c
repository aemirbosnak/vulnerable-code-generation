//FormAI DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Definition of the LinkedList structure
typedef struct {
    Node* head;
} LinkedList;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a Node at the beginning of the LinkedList
void insertAtBeginning(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

// Function to insert a Node at the end of the LinkedList
void insertAtEnd(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    Node* current = list->head;
    if(current == NULL) {
        list->head = newNode;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print the LinkedList
void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList myList = {NULL};
    insertAtBeginning(&myList, 5);
    insertAtBeginning(&myList, 10);
    insertAtEnd(&myList, 20);
    insertAtEnd(&myList, 25);
    printList(&myList);
    return 0;
}