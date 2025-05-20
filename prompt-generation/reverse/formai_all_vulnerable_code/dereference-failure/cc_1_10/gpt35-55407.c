//FormAI DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define structure of the Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Functions to manipulate Linked List
void insert(Node** head_ref, int new_data);
void delete(Node** head_ref, int key);
void display(Node* node);

// Main function to run example program
int main() {
    Node* head = NULL;

    // Insert elements into Linked List
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    printf("Linked List before deletion: ");
    display(head);

    // Delete an element from Linked List
    delete(&head, 3);

    printf("Linked List after deletion: ");
    display(head);

    return 0;
}

// Function to insert an element into Linked List
void insert(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to delete an element from Linked List
void delete(Node** head_ref, int key) {
    Node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if(temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in Linked List
    if(temp == NULL) {
        return;
    }

    // Unlink the node from Linked List
    prev->next = temp->next;
    free(temp);
}

// Function to display all elements in Linked List
void display(Node* node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node-> next;
    }
    printf("\n");
}