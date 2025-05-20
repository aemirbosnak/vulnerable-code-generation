//FormAI DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int value;
    struct Node* next;
};

// Define a function to allocate memory for a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Define a function to add a new node to the linked list
void addNode(struct Node** head, int value) {
    // If the list is empty, create a new node and make it the head
    if (*head == NULL) {
        *head = createNode(value);
        return;
    }

    // Otherwise, traverse to the end of the list
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Create a new node and link it to the end of the list
    current->next = createNode(value);
}

// Define a function to free all memory allocated to the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Create an empty list
    struct Node* myList = NULL;

    // Add some nodes to the list
    addNode(&myList, 5);
    addNode(&myList, 10);
    addNode(&myList, 15);

    // Traverse the list and print each value
    struct Node* current = myList;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }

    // Free all memory allocated to the list
    freeList(myList);

    return 0;
}