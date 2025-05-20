//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* create_node(int data);
void append_node(Node** head, int data);
void prepend_node(Node** head, int data);
void delete_node(Node** head, int data);
void print_list(Node* head);

int main() {
    Node* head = NULL;

    // Test append_node
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 3);
    print_list(head);

    // Test prepend_node
    prepend_node(&head, 0);
    print_list(head);

    // Test delete_node
    delete_node(&head, 1);
    print_list(head);

    return 0;
}

// Create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Append a new node to the end of the list
void append_node(Node** head, int data) {
    Node* new_node = create_node(data);
    Node* temp = *head;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Prepend a new node to the beginning of the list
void prepend_node(Node** head, int data) {
    Node* new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    new_node->next = *head;
    *head = new_node;
}

// Delete a node with given data from the list
void delete_node(Node** head, int data) {
    Node* temp = *head;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    Node* next_node = temp->next;
    free(temp);
    temp = next_node;
}

// Print the contents of the list
void print_list(Node* head) {
    Node* temp = head;
    printf("List: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}