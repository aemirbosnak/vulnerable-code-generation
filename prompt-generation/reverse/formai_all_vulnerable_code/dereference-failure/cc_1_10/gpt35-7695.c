//FormAI DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for linked list elements.
struct Node {
     int value;
     struct Node* next;
};

// Define linked list functions
void insert(struct Node** head, int value);
void display(struct Node* head);
void delete(struct Node** head, int value);
void reverse(struct Node** head);

int main() {
    // Create an empty linked list
    struct Node* head = NULL;

    // Populate linked list with values
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    // Display the linked list
    printf("Linked list: ");
    display(head);

    // Reverse the linked list
    reverse(&head);
    printf("\nLinked list after reversing: ");
    display(head);

    // Delete a value from the linked list
    delete(&head, 30);
    printf("\nLinked list after deleting 30: ");
    display(head);

    return 0;
}

// Insert a value into the linked list
void insert(struct Node** head, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    // If the linked list is empty, set the head node as the new node
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Traverse the linked list and add the node at the end
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Display the linked list values
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

// Delete a value from the linked list
void delete(struct Node** head, int value) {
    // If the linked list is empty, return
    if (*head == NULL) {
        return;
    }

    // If the value is at the head node, set the next node as the head node
    if ((*head)->value == value) {
        *head = (*head)->next;
        return;
    }

    // Traverse the linked list and delete the node with the given value
    struct Node* current = *head;
    while (current->next != NULL) {
        if (current->next->value == value) {
            current->next = current->next->next;
            return;
        }
        current = current->next;
    }
}

// Reverse the linked list
void reverse(struct Node** head) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}