//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// A struct to represent a node in a linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// A function to create a new node with the given data
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// A function to insert a new node at the beginning of the linked list
node *insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// A function to insert a new node at the end of the linked list
node *insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// A function to insert a new node after a given node
node *insert_after(node *head, int after_data, int data) {
    if (head == NULL) {
        return NULL;
    }
    node *current = head;
    while (current != NULL) {
        if (current->data == after_data) {
            node *new_node = create_node(data);
            new_node->next = current->next;
            current->next = new_node;
            return head;
        }
        current = current->next;
    }
    return head;
}

// A function to delete a node from the linked list
node *delete_node(node *head, int data) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == data) {
        node *new_head = head->next;
        free(head);
        return new_head;
    }
    node *current = head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            node *temp = current->next;
            current->next = temp->next;
            free(temp);
            return head;
        }
        current = current->next;
    }
    return head;
}

// A function to print the linked list
void print_linked_list(node *head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// A function to free the linked list
void free_linked_list(node *head) {
    if (head == NULL) {
        return;
    }
    node *current = head;
    while (current != NULL) {
        node *temp = current->next;
        free(current);
        current = temp;
    }
}

int main() {
    // Create a linked list
    node *head = NULL;
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_after(head, 20, 25);

    // Print the linked list
    printf("The linked list is: ");
    print_linked_list(head);

    // Delete a node from the linked list
    head = delete_node(head, 25);

    // Print the linked list
    printf("The linked list after deletion is: ");
    print_linked_list(head);

    // Free the linked list
    free_linked_list(head);

    return 0;
}