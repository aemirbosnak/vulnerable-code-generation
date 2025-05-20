//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with a random data value
struct Node* newNode(void) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = rand() % 100;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtStart(struct Node** head_ref, struct Node* new_node) {
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, struct Node* new_node) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL)); // seed the random number generator

    // Create a list with 10 nodes
    struct Node* head = NULL;
    for (int i = 0; i < 10; i++) {
        struct Node* new_node = newNode();
        if (i % 2 == 0) {
            insertAtEnd(&head, new_node);
        } else {
            insertAtStart(&head, new_node);
        }
    }

    // Print the list
    printList(head);

    return 0;
}