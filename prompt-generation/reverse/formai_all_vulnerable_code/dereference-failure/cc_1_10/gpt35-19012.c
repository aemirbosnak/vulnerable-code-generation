//FormAI DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define an abstract data type for a Node in our data structure
typedef struct Node {
    int value;              // The integer value of the Node
    struct Node* next;      // A pointer to the next Node in the sequence
} Node;

// Define an abstract data type for our linked list data structure
typedef struct List {
    Node* head;             // A pointer to the first Node in the list
    Node* tail;             // A pointer to the last Node in the list
    int length;             // The number of Nodes in the list
} List;

// Create a new Node with the given value and return a pointer to it
Node* createNode(int value) {
    Node* node = malloc(sizeof(Node));     // Allocate space for the Node
    node->value = value;                    // Set the Node's value to the given value
    node->next = NULL;                      // Set the Node's next pointer to NULL
    return node;
}

// Create a new List with no Nodes and return a pointer to it
List* createList() {
    List* list = malloc(sizeof(List));     // Allocate space for the List
    list->head = NULL;                      // Set the List's head and tail pointers to NULL
    list->tail = NULL;
    list->length = 0;                       // Set the List's length to 0
    return list;
}

// Add a new Node with the given value to the end of the List
void append(List* list, int value) {
    Node* node = createNode(value);         // Create a new Node with the given value
    if (list->head == NULL) {               // If the List is empty, set the head and tail pointers to the new Node
        list->head = node;
        list->tail = node;
    }
    else {                                  // Otherwise, set the tail Node's next pointer to the new Node, and update the tail pointer
        list->tail->next = node;
        list->tail = node;
    }
    list->length++;                         // Increment the List's length
}

// Print the values of all the Nodes in the List, separated by spaces
void printList(List* list) {
    Node* node = list->head;                // Start at the head of the list
    while (node != NULL) {                  // Loop through all the Nodes in the list
        printf("%d ", node->value);         // Print the Node's value
        node = node->next;                  // Move to the next Node in the list
    }
    printf("\n");                           // Print a newline character to separate the output from any other text
}

int main() {
    List* list = createList();              // Create a new List
    append(list, 1);                        // Add some values to the List
    append(list, 2);
    append(list, 3);
    append(list, 4);
    append(list, 5);
    printList(list);                        // Print the List's contents
    return 0;                               // Exit the program
}