//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Declare a pointer to a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Declare a pointer to the head of the list
Node* head = NULL;

// Function to insert a node into the list
void insert(int data) {
    // Create a new node with the given data
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, set the head to the new node
    if (!head) {
        head = newNode;
    } else {
        // Otherwise, add the new node to the end of the list
        head->next = newNode;
        head = newNode;
    }
}

// Function to print the list
void print() {
    // If the list is empty, print "List is empty"
    if (!head) {
        printf("List is empty\n");
        return;
    }

    // Otherwise, print each node in the list
    printf("List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Recursive function to find a specific node in the list
Node* find(int data) {
    // If the list is empty, return NULL
    if (!head) {
        return NULL;
    }

    // Otherwise, search the list for the given data
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    // If the list is not empty and the given data was not found, return NULL
    return NULL;
}

int main() {
    // Insert some nodes into the list
    insert(1);
    insert(2);
    insert(3);
    insert(4);

    // Print the list
    print();

    // Find a specific node in the list
    Node* found = find(2);
    if (found) {
        printf("Found node with data %d\n", found->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}