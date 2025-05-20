//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node at the end of the list
void append(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    Node* last = *head_ref;
    if (*head_ref == NULL)
        return;
    while (last->next!= NULL)
        last = last->next;
    last->next = new_node;
}

// Function to add a node after a given position in the list
void addNode(Node** head_ref, int new_data, int pos) {
    Node* new_node = newNode(new_data);
    Node* temp = *head_ref;
    if (pos == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL)
            return;
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to remove a node from the list
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref;
    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    Node* t = temp->next;
    free(temp);
    temp = t;
}

// Function to search for a node in the list
Node* search(Node* head, int key) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    append(&head, 6);
    append(&head, 5);
    printList(head); // Output: 7 1 3 6 5
    Node* node = search(head, 3);
    if (node!= NULL)
        printf("Found node with data %d\n", node->data);
    else
        printf("Node not found\n");
    deleteNode(&head, 1);
    printList(head); // Output: 7 3 6 5
    return 0;
}