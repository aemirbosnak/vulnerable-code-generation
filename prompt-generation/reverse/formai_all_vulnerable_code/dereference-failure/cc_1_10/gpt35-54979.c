//FormAI DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the Linked List structure
struct LinkedList {
    struct Node* head;
};

// Initialize an empty Linked List
void initialize(struct LinkedList* ll) {
    ll->head = NULL;
}

// Insert a Node at the beginning of the Linked List
void insert_at_beginning(struct LinkedList* ll, int data) {
    // Create a new Node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    // Link the new Node to the head of the Linked List
    new_node->next = ll->head;
    ll->head = new_node;
}

// Insert a Node at the end of the Linked List
void insert_at_end(struct LinkedList* ll, int data) {
    // Create a new Node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    // If the Linked List is empty, make the new Node the head
    if (ll->head == NULL) {
        ll->head = new_node;
        return;
    }

    // Traverse to the end of the Linked List
    struct Node* temp = ll->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new Node to the last Node in the Linked List
    temp->next = new_node;
}

// Delete a Node with a given data value from the Linked List
void delete(struct LinkedList* ll, int data) {
    // If the Linked List is empty or the value doesn't exist, simply return
    if (ll->head == NULL) {
        return;
    }

    // If the Node to be deleted is the head of the Linked List, just update the head pointer
    if (ll->head->data == data) {
        struct Node* temp = ll->head;
        ll->head = ll->head->next;
        free(temp);
        return;
    }

    // Traverse to the Node before the desired Node to be deleted
    struct Node* temp = ll->head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }

    // If the desired Node doesn't exist in the Linked List, simply return
    if (temp->next == NULL) {
        return;
    }

    // Otherwise, delete the Node and link the previous Node to the next Node
    struct Node* delete_node = temp->next;
    temp->next = delete_node->next;
    free(delete_node);
}

// Display the current state of the Linked List
void display(struct LinkedList* ll) {
    struct Node* temp = ll->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Example usage of the Linked List operations
int main() {
    struct LinkedList ll;
    initialize(&ll);
    
    insert_at_beginning(&ll, 5);
    insert_at_beginning(&ll, 10);
    insert_at_end(&ll, 20);
    insert_at_beginning(&ll, 15);
    
    display(&ll);

    delete(&ll, 10);
    delete(&ll, 25);
    
    display(&ll);

    return 0;
}