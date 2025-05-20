//FormAI DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { // Define a struct called Node to store data and pointer to next node in the list
    int data;
    struct Node* next;
} Node;

typedef struct List { // Define a struct called List to store pointer to head and tail of the list
    Node* head;
    Node* tail;
} List;

List* CreateList() { // Create a function to create a new empty list
    List* list = (List*) malloc(sizeof(List)); // Allocate memory for the List struct
    list->head = NULL; // Set head to NULL
    list->tail = NULL; // Set tail to NULL
    return list;
}

void AddToList(List* list, int data) { // Create a function to add a new node to the end of the list
    Node* node = (Node*) malloc(sizeof(Node)); // Allocate memory for the Node struct
    node->data = data; // Set data for the new node
    node->next = NULL; // Set next pointer to NULL
    if (list->head == NULL) { // If the list is empty
        list->head = node; // Set head and tail to be the new node
        list->tail = node;
        return;
    }
    list->tail->next = node; // Set the next pointer for the previous tail to point to the new node
    list->tail = node; // Set tail to point to the new node
}

void PrintList(List* list) { // Create a function to print out the contents of the list
    Node* current = list->head; // Start at the head of the list
    printf("["); // Begin the output with a bracket
    while (current != NULL) { // While there are still nodes in the list
        printf("%d", current->data); // Print the current node's data
        if (current->next != NULL) { // If there is another node after the current one
            printf(", "); // Print a comma and a space
        }
        current = current->next; // Move to the next node in the list
    }
    printf("]"); // Finish the output with a closing bracket
}

int main() {
    List* list = CreateList(); // Create a new empty list
    AddToList(list, 5); // Add nodes to the list
    AddToList(list, 7);
    AddToList(list, 2);
    printf("List contents: "); // Print out the list contents
    PrintList(list);
    return 0;
}