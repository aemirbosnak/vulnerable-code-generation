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
struct Node* newNode() {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = rand() % 100;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode();
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to remove the node with the given data value
void removeNode(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head_ref = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to traverse the list and print the data values
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes with random data values
    insertNode(&head, 42);
    insertNode(&head, 99);
    insertNode(&head, 23);
    insertNode(&head, 66);

    // Remove a node with a random data value
    removeNode(&head, rand() % 100);

    // Traverse the list and print the data values
    printList(head);

    return 0;
}