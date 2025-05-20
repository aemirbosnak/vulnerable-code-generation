//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: accurate
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
    return new_node;
}

// Function to insert a node at the end of the linked list
Node *insert_at_end(Node *head, int data) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to insert a node after a given node
Node *insert_after(Node *head, int data, int after_data) {
    if (head == NULL) {
        return NULL;
    }
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == after_data) {
            Node *new_node = create_node(data);
            new_node->next = temp->next;
            temp->next = new_node;
            return head;
        }
        temp = temp->next;
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
    if (head->next == NULL) {
        Node *temp = head;
        head = NULL;
        free(temp);
        return head;
    }
    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node *to_delete = temp->next;
    temp->next = NULL;
    free(to_delete);
    return head;
}

// Function to delete a node with a given data
Node *delete_with_data(Node *head, int data) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == data) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == data) {
            Node *to_delete = temp->next;
            temp->next = temp->next->next;
            free(to_delete);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

// Function to print the linked list
void print_list(Node *head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a linked list
    Node *head = NULL;
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_after(head, 30, 20);
    print_list(head); // Output: 10 20 30

    // Delete a node from the beginning of the linked list
    head = delete_from_beginning(head);
    print_list(head); // Output: 20 30

    // Delete a node from the end of the linked list
    head = delete_from_end(head);
    print_list(head); // Output: 20

    // Delete a node with a given data
    head = delete_with_data(head, 20);
    print_list(head); // Output: The linked list is empty.

    return 0;
}