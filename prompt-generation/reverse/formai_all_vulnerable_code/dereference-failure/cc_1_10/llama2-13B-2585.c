//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete the first node of the list
struct Node* deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }

    struct Node* first_node = *head_ref;
    *head_ref = first_node->next;
    free(first_node);
    return first_node;
}

// Function to traverse the list and print the values
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Create a list of integers
    struct Node* head = NULL;
    for (int i = 0; i < 10; i++) {
        insertAtBeginning(&head, rand() % 10);
    }

    // Delete the first node of the list
    struct Node* deleted_node = deleteFirst(&head);

    // Print the remaining list
    printList(head);

    return 0;
}