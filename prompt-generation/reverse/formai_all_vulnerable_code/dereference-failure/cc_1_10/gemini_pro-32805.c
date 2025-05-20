//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create a new node
Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
Node* insert_at_beginning(Node *head, int data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Insert a node at the end of the list
Node* insert_at_end(Node *head, int data) {
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

// Insert a node at a given position
Node* insert_at_position(Node *head, int data, int position) {
    if (position == 0) {
        return insert_at_beginning(head, data);
    }
    Node *new_node = create_node(data);
    Node *temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp->next == NULL) {
            printf("Invalid position\n");
            return head;
        }
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Delete a node from the beginning of the list
Node* delete_from_beginning(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete a node from the end of the list
Node* delete_from_end(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete a node from a given position
Node* delete_from_position(Node *head, int position) {
    if (position == 0) {
        return delete_from_beginning(head);
    }
    Node *temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp->next == NULL) {
            printf("Invalid position\n");
            return head;
        }
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    return head;
}

// Print the linked list
void print_list(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create an empty linked list
    Node *head = NULL;

    // Insert some nodes into the list
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_position(head, 30, 1);
    head = insert_at_position(head, 40, 3);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Delete a node from the beginning of the list
    head = delete_from_beginning(head);

    // Print the list
    printf("After deleting a node from the beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    head = delete_from_end(head);

    // Print the list
    printf("After deleting a node from the end: ");
    print_list(head);

    // Delete a node from a given position
    head = delete_from_position(head, 1);

    // Print the list
    printf("After deleting a node from position 1: ");
    print_list(head);

    return 0;
}