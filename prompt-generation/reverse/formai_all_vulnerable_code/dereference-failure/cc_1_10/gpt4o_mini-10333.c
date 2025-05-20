//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in a doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Initialize a doubly linked list
typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize the doubly linked list
DoublyLinkedList* createList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to append a node at the end of the list
void append(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    printf("🌟 Appended %d to the list!\n", data);
}

// Function to display the list forward
void displayForward(DoublyLinkedList* list) {
    Node* current = list->head;
    printf("🔍 List elements in forward direction: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to display the list backward
void displayBackward(DoublyLinkedList* list) {
    Node* current = list->tail;
    printf("🔄 List elements in backward direction: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Function to free the list
void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
    printf("🎉 Freed the list resources!\n");
}

int main() {
    printf("🎊 Welcome to the Exciting Doubly Linked List Visualizer! 🎊\n");

    // Create a new doubly linked list
    DoublyLinkedList* list = createList();

    // Append elements to the list
    append(list, 10);
    append(list, 20);
    append(list, 30);
    append(list, 40);
    append(list, 50);

    // Display elements of the list
    displayForward(list);

    // Display elements in reverse
    displayBackward(list);

    // Free the resources allocated for the list
    freeList(list);

    printf("🚀 Thanks for using the Doubly Linked List Visualizer! See you next time! 🚀\n");
    return 0;
}