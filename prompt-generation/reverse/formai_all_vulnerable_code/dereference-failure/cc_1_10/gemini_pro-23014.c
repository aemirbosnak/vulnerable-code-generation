//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node with the given data
Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
void insert_at_beginning(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end of the linked list
void insert_at_end(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert a new node at a given position in the linked list
void insert_at_position(Node **head, int data, int position) {
    if (position == 0) {
        insert_at_beginning(head, data);
        return;
    }
    Node *new_node = create_node(data);
    Node *temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp->next == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to delete a node from the beginning of the linked list
void delete_from_beginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the linked list
void delete_from_end(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node *to_delete = temp->next;
    temp->next = NULL;
    free(to_delete);
}

// Function to delete a node from a given position in the linked list
void delete_from_position(Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        delete_from_beginning(head);
        return;
    }
    Node *temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp->next == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    Node *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

// Function to print the linked list
void print_list(Node *head) {
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create an empty linked list
    Node *head = NULL;

    // Insert some nodes into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_position(&head, 15, 1);
    
    // Print the linked list
    printf("Original list: ");
    print_list(head);

    // Delete a node from the beginning of the linked list
    delete_from_beginning(&head);

    // Print the linked list
    printf("List after deleting a node from the beginning: ");
    print_list(head);

    // Delete a node from the end of the linked list
    delete_from_end(&head);

    // Print the linked list
    printf("List after deleting a node from the end: ");
    print_list(head);

    // Delete a node from a given position in the linked list
    delete_from_position(&head, 0);

    // Print the linked list
    printf("List after deleting a node from position 0: ");
    print_list(head);

    return 0;
}