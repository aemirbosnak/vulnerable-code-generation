//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a Node in a doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Define a structure for the Doubly Linked List
typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize a Doubly Linked List
DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to insert a node at the head of the list
void insertAtHead(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) { // If the list is empty
        list->head = newNode;
        list->tail = newNode; // Both head and tail point to the new node
    } else {
        newNode->next = list->head; // Point newNode's next to current head
        list->head->prev = newNode; // Point current head's prev to newNode
        list->head = newNode; // Update head to newNode
    }
}

// Function to insert a node at the tail of the list
void insertAtTail(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->tail == NULL) { // If the list is empty
        list->head = newNode;
        list->tail = newNode; // Both head and tail point to the new node
    } else {
        newNode->prev = list->tail; // Point newNode's prev to current tail
        list->tail->next = newNode; // Point current tail's next to newNode
        list->tail = newNode; // Update tail to newNode
    }
}

// Function to reverse the linked list
void reverseList(DoublyLinkedList* list) {
    Node* temp = NULL;
    Node* current = list->head;

    // Swap next and prev for all nodes in the list
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node in original direction
    }

    // Adjust head and tail
    if (temp != NULL) {
        list->head = temp->prev;
    }
}

// Function to print the list from head to tail
void printList(DoublyLinkedList* list) {
    Node* current = list->head;
    printf("List (Head to Tail): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to print the list from tail to head
void printReverseList(DoublyLinkedList* list) {
    Node* current = list->tail;
    printf("List (Tail to Head): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Function to free the allocated memory for the list
void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// Main function
int main() {
    DoublyLinkedList* list = createDoublyLinkedList();

    // Insert some elements
    insertAtHead(list, 1);
    insertAtHead(list, 2);
    insertAtHead(list, 3);
    insertAtTail(list, 4);
    insertAtTail(list, 5);
    insertAtTail(list, 6);

    // Print the list
    printList(list);
    printReverseList(list);

    // Reverse the list and print again
    reverseList(list);
    printf("After reversing:\n");
    printList(list);
    printReverseList(list);

    // Free the list
    freeList(list);

    return 0;
}