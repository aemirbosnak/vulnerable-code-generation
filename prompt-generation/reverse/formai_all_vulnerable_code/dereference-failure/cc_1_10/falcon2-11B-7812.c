//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked list head
Node* head = NULL;

// Function to create a new node and insert it at the beginning of the list
Node* insert(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to delete a node from the list
void delete(int data) {
    Node* current = head;
    Node* previous = NULL;

    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found in the list.\n", data);
    } else {
        if (previous == NULL) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

// Function to search for a node with a specific data value
Node* search(int data) {
    Node* current = head;

    while (current!= NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Function to print the entire linked list
void printList() {
    Node* current = head;

    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    // Insert nodes
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    // Print the list
    printList();

    // Delete a node
    delete(3);

    // Print the list again
    printList();

    return 0;
}