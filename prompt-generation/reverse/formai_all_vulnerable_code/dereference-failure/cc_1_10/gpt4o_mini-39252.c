//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Structure for the doubly linked list
typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// Function prototypes
DoublyLinkedList* createList();
void append(DoublyLinkedList* list, int data);
void prepend(DoublyLinkedList* list, int data);
void displayList(DoublyLinkedList* list);
void freeList(DoublyLinkedList* list);
void clearScreen();

int main() {
    DoublyLinkedList* list = createList();
    
    append(list, 1);
    append(list, 2);
    append(list, 3);
    prepend(list, 0);
    
    clearScreen();
    printf("Doubly Linked List Visualization:\n");
    displayList(list);

    freeList(list);
    return 0;
}

// Function to create a new doubly linked list
DoublyLinkedList* createList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to append an element to the end of the list
void append(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Function to prepend an element to the start of the list
void prepend(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;

    if (list->head == NULL) {
        newNode->next = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

// Function to display the list elements
void displayList(DoublyLinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf(" %d ", temp->data);
        if (temp->next != NULL) {
            printf("<->");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory of the list
void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}

// Function to clear the terminal screen
void clearScreen() {
    // ANSI escape code to clear the screen
    printf("\033[H\033[J");
}