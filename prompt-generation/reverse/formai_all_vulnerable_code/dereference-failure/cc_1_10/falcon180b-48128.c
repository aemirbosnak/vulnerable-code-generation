//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a linked list structure
typedef struct List {
    Node* head;
    int size;
} List;

// Create a new node with the given data
Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create an empty linked list
List* createList() {
    List* newList = malloc(sizeof(List));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

// Add a node to the end of the linked list
void addNode(List* list, int data) {
    Node* newNode = createNode(data);
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

// Print the linked list
void printList(List* list) {
    if (list->head == NULL) {
        printf("Empty list\n");
    } else {
        printf("List: ");
        Node* temp = list->head;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Reverse the linked list
void reverseList(List* list) {
    Node* prev = NULL;
    Node* curr = list->head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}

// Main function
int main() {
    // Create a new linked list
    List* myList = createList();

    // Add some nodes to the list
    addNode(myList, 1);
    addNode(myList, 2);
    addNode(myList, 3);

    // Print the original list
    printf("Original list:\n");
    printList(myList);

    // Reverse the list
    reverseList(myList);

    // Print the reversed list
    printf("Reversed list:\n");
    printList(myList);

    // Free the memory used by the linked list
    free(myList->head);
    free(myList);

    return 0;
}