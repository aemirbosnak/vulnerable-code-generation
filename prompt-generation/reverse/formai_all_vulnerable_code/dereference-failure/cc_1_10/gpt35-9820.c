//FormAI DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Defining the Node struct
struct Node {
    int data;
    struct Node* next;
};

// Defining the LinkedList struct
struct LinkedList {
    struct Node* head;
};

// Function to initialize a LinkedList
void initialize(struct LinkedList* list) {
    list->head = NULL;
}

// Function to insert a Node at the beginning of the LinkedList
void insertAtBeginning(struct LinkedList* list, int data) {
    // Creating a new Node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

// Function to display the LinkedList
void displayLinkedList(struct LinkedList list) {
    struct Node* current = list.head;
    printf("LinkedList: ");
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    // Initializing LinkedList
    struct LinkedList list;
    initialize(&list);
    
    // Inserting Nodes
    insertAtBeginning(&list, 2);
    insertAtBeginning(&list, 4);
    insertAtBeginning(&list, 6);
    insertAtBeginning(&list, 8);
    insertAtBeginning(&list, 10);
    
    // Displaying LinkedList
    displayLinkedList(list);
    
    return 0;
}