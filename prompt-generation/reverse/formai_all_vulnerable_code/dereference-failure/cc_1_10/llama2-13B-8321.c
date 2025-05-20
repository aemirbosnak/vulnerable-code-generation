//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtStart(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete the node with the given value
void deleteNode(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current->data == value) {
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

// Function to find the node with the given value and return its index
int findIndex(struct Node** head_ref, int value) {
    int index = 0;
    struct Node* current = *head_ref;

    while (current != NULL) {
        if (current->data == value) {
            return index;
        }
        index++;
        current = current->next;
    }
    return -1;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertAtStart(&head, 1);
    insertAtStart(&head, 2);
    insertAtStart(&head, 3);

    // Delete a node
    deleteNode(&head, 2);

    // Find the index of a node
    int index = findIndex(&head, 3);
    printf("The index of 3 is %d\n", index);

    return 0;
}