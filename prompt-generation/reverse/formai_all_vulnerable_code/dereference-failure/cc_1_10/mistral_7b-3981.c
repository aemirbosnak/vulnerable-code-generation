//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for the doubly linked list
typedef struct Node {
    int data; // Data to be stored in the node
    struct Node* next; // Pointer to the next node
    struct Node* prev; // Pointer to the previous node
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the list
void push(Node** head, int data) {
    Node* new_node = newNode(data);
    if (*head != NULL) {
        new_node->next = *head;
        (*head)->prev = new_node;
    }
    *head = new_node;
}

// Function to insert a new node at the end of the list
void append(Node** head, int data) {
    Node* new_node = newNode(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

// Function to delete a node with the given data from the list
void deleteNode(Node** head, int data) {
    Node* current = *head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL)
                current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Data not found in the list\n");
}

// Function to display the contents of the list
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> %p <-> %p\n", current->data, current->next, current->prev);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    push(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    printf("Linked List: ");
    displayList(head);

    deleteNode(&head, 30);
    printf("Deleted 30. Updated List: ");
    displayList(head);

    return 0;
}