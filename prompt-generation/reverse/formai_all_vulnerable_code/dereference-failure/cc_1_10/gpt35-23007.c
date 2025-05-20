//FormAI DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Node structure of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node at the end of the linked list
void addNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Function to display the linked list
void display(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nKey not found");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Driver program
int main() {
    struct Node* head = NULL;

    // Add nodes to Linked List
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    printf("Initial Linked List:\n");
    display(head);

    // Deleting a node in Linked list
    deleteNode(&head, 3);

    printf("\n\nLinked List after deleting node with value 3:\n");
    display(head);

    return 0;
}