//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
Node *insert_at_beginning(Node *head, int data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a node at the end of the linked list
Node *insert_at_end(Node *head, int data) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to insert a node at a specific position in the linked list
Node *insert_at_position(Node *head, int data, int position) {
    Node *new_node = create_node(data);
    if (position == 1) {
        new_node->next = head;
        head = new_node;
        return head;
    }
    Node *temp = head;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp != NULL) {
        new_node->next = temp->next;
        temp->next = new_node;
    }
    return head;
}

// Function to delete a node from the beginning of the linked list
Node *delete_from_beginning(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end of the linked list
Node *delete_from_end(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node from a specific position in the linked list
Node *delete_from_position(Node *head, int position) {
    if (head == NULL) {
        return NULL;
    }
    Node *temp = head;
    Node *prev = NULL;
    int count = 1;
    while (temp != NULL && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (temp != NULL) {
        if (prev == NULL) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
    return head;
}

// Function to print the linked list
void print_linked_list(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node *head = NULL;

    // Inserting nodes at the beginning of the linked list
    head = insert_at_beginning(head, 10);
    head = insert_at_beginning(head, 20);
    head = insert_at_beginning(head, 30);

    // Inserting nodes at the end of the linked list
    head = insert_at_end(head, 40);
    head = insert_at_end(head, 50);
    head = insert_at_end(head, 60);

    // Inserting nodes at a specific position in the linked list
    head = insert_at_position(head, 70, 4);
    head = insert_at_position(head, 80, 6);

    // Printing the linked list
    printf("Linked list: ");
    print_linked_list(head);

    // Deleting nodes from the beginning of the linked list
    head = delete_from_beginning(head);
    head = delete_from_beginning(head);

    // Deleting nodes from the end of the linked list
    head = delete_from_end(head);
    head = delete_from_end(head);

    // Deleting nodes from a specific position in the linked list
    head = delete_from_position(head, 4);
    head = delete_from_position(head, 2);

    // Printing the linked list
    printf("Linked list after deletions: ");
    print_linked_list(head);

    return 0;
}