//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void push(struct node** head_ref, int new_data) {
    struct node* new_node = newNode(new_data);
    struct node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Function to search for an element in the linked list
struct node* search(struct node* head, int x) {
    struct node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the linked list
void printList(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* head = NULL;

    // Add elements to the list
    push(&head, 5);
    push(&head, 10);
    push(&head, 15);
    push(&head, 20);

    // Search for an element in the list
    int searchItem = 15;
    struct node* result = search(head, searchItem);

    if (result == NULL)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", result->data);

    return 0;
}