//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure for the list
typedef struct node {
    int key;
    struct node* next;
} Node;

// Function to create a new node
Node* newNode(int key) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    return node;
}

// Function to search for an element in the list
int search(Node* head, int key) {
    int count = 0;
    Node* current = head;

    while (current != NULL) {
        if (current->key == key) {
            count++;
            break;
        }
        current = current->next;
    }

    if (count == 1) {
        return 1; // Element found
    } else {
        return 0; // Element not found
    }
}

int main() {
    Node* head = NULL;

    // Create a list of integers
    for (int i = 1; i <= 10; i++) {
        head = newNode(i);
        head->next = NULL;
    }

    // Search for the element 5
    if (search(head, 5)) {
        printf("Element found at position %d\n", search(head, 5));
    } else {
        printf("Element not found\n");
    }

    return 0;
}