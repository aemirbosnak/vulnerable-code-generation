//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a Node in a doubly linked list
typedef struct Node {
    char data[100];
    struct Node* next;
    struct Node* prev;
} Node;

// Define a structure for the Doubly Linked List
typedef struct {
    Node* head;
    Node* tail;
    int size;
} DoublyLinkedList;

// Function to create a new node
Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize the doubly linked list
void initList(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Function to add a node to the end of the list
void addNode(DoublyLinkedList* list, const char* data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    list->size++;
}

// Function to print the list from head to tail
void printList(DoublyLinkedList* list) {
    Node* current = list->head;
    printf("List (head to tail): ");
    while (current != NULL) {
        printf("%s <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to print the list from tail to head
void printListReverse(DoublyLinkedList* list) {
    Node* current = list->tail;
    printf("List (tail to head): ");
    while (current != NULL) {
        printf("%s <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Function to free the list
void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Main function to demonstrate the Linked List operations
int main() {
    DoublyLinkedList list;
    initList(&list);
    
    printf("Adding nodes to the doubly linked list...\n");
    addNode(&list, "Node 1");
    addNode(&list, "Node 2");
    addNode(&list, "Node 3");
    addNode(&list, "Node 4");
    
    printList(&list);
    printListReverse(&list);

    printf("Freeing the list...\n");
    freeList(&list);
    return 0;
}