//FormAI DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define a node struct for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node and return a pointer to it
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = NULL;

    return new_node;
}

// Function to insert a new node at the beginning of the linked list
void insert_beginning(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to insert a new node at the end of the linked list
void insert_end(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last -> next != NULL)
        last = last -> next;

    last -> next = new_node;
    return;
}

// Function to delete a node with the given data from the linked list
void delete_node(Node** head_ref, int data) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp != NULL && temp -> data == data) {
        *head_ref = temp -> next;
        free(temp);
        return;
    }

    while (temp != NULL && temp -> data != data) {
        prev = temp;
        temp = temp -> next;
    }

    if (temp == NULL)
        return;

    prev -> next = temp -> next;
    free(temp);
}

// Function to print the linked list
void print_list(Node* head) {
    printf("Linked List: ");

    while (head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }

    printf("\n");
}

// Driver function to test the operations
int main() {

    Node* head = NULL;

    // Insert some nodes
    insert_end(&head, 5);
    insert_beginning(&head, 10);
    insert_beginning(&head, 20);
    insert_end(&head, 50);

    // Print the linked list
    print_list(head);

    // Delete a node
    delete_node(&head, 20);

    // Print the linked list again
    print_list(head);

    return 0;
}