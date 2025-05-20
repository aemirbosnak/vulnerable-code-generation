//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end of the list
void push(struct node** head_ref, int new_data) {
    struct node* new_node = newNode(new_data);
    struct node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL) {
        last = last->next;
    }

    last->next = new_node;

    return;
}

// Function to delete a node by key
void deleteNode(struct node **head_ref, int key) {
    struct node* temp = *head_ref, *prev;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;   
        free(temp);            
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
    return;
}

// Function to search for a node with the given key
struct node* search(struct node* head, int key) {
    struct node* current = head;

    while (current!= NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }

    return NULL;
}

// Function to print the list
void printList(struct node *node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* head = NULL;

    // Insert 7
    push(&head, 7);

    // Insert 1
    push(&head, 1);

    // Insert 6
    push(&head, 6);

    // Insert 5
    push(&head, 5);

    // Insert 2
    push(&head, 2);

    // Insert 3
    push(&head, 3);

    // Insert 4
    push(&head, 4);

    // Print the list
    printf("Original list: ");
    printList(head);

    // Search for key
    struct node* result = search(head, 5);

    if (result!= NULL)
        printf("\nKey found at position %d", result->data);
    else
        printf("\nKey not found in the list");

    return 0;
}