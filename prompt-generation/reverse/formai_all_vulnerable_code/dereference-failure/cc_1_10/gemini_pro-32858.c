//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
struct Node* insert_at_beginning(struct Node *head, int data) {
    struct Node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a node at the end of the list
struct Node* insert_at_end(struct Node *head, int data) {
    struct Node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to insert a node at a specific position
struct Node* insert_at_position(struct Node *head, int data, int position) {
    if (position == 1) {
        return insert_at_beginning(head, data);
    }
    struct Node *new_node = create_node(data);
    struct Node *temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            free(new_node);
            return head;
        }
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Function to delete a node at the beginning of the list
struct Node* delete_at_beginning(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node at the end of the list
struct Node* delete_at_end(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete a node at a specific position
struct Node* delete_at_position(struct Node *head, int position) {
    if (position == 1) {
        return delete_at_beginning(head);
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return head;
        }
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Invalid position\n");
        return head;
    }
    struct Node *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
    return head;
}

// Function to print the list
void print_list(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node *head = NULL;

    // Inserting nodes at the beginning of the list
    head = insert_at_beginning(head, 10);
    head = insert_at_beginning(head, 20);
    head = insert_at_beginning(head, 30);

    // Printing the list after inserting nodes at the beginning
    printf("List after inserting nodes at the beginning: ");
    print_list(head);

    // Inserting nodes at the end of the list
    head = insert_at_end(head, 40);
    head = insert_at_end(head, 50);
    head = insert_at_end(head, 60);

    // Printing the list after inserting nodes at the end
    printf("List after inserting nodes at the end: ");
    print_list(head);

    // Inserting a node at a specific position
    head = insert_at_position(head, 25, 3);

    // Printing the list after inserting a node at a specific position
    printf("List after inserting a node at a specific position: ");
    print_list(head);

    // Deleting a node at the beginning of the list
    head = delete_at_beginning(head);

    // Printing the list after deleting a node at the beginning
    printf("List after deleting a node at the beginning: ");
    print_list(head);

    // Deleting a node at the end of the list
    head = delete_at_end(head);

    // Printing the list after deleting a node at the end
    printf("List after deleting a node at the end: ");
    print_list(head);

    // Deleting a node at a specific position
    head = delete_at_position(head, 3);

    // Printing the list after deleting a node at a specific position
    printf("List after deleting a node at a specific position: ");
    print_list(head);

    return 0;
}