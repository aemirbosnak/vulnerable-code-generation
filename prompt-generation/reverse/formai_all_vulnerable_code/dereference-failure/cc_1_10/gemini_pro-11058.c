//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Define the head of the linked list
struct node *head = NULL;

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current_node = head;

        while (current_node->next != NULL) {
            current_node = current_node->next;
        }

        current_node->next = new_node;
    }
}

// Function to insert a node at a specific position in the linked list
void insert_at_position(int data, int position) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;

    if (position == 0) {
        insert_at_beginning(data);
    } else {
        struct node *current_node = head;
        int current_position = 0;

        while (current_node != NULL && current_position < position - 1) {
            current_node = current_node->next;
            current_position++;
        }

        if (current_node != NULL) {
            new_node->next = current_node->next;
            current_node->next = new_node;
        } else {
            printf("Invalid position\n");
        }
    }
}

// Function to delete a node from the beginning of the linked list
void delete_at_beginning() {
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to delete a node from the end of the linked list
void delete_at_end() {
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *current_node = head;

        while (current_node->next->next != NULL) {
            current_node = current_node->next;
        }

        free(current_node->next);
        current_node->next = NULL;
    }
}

// Function to delete a node from a specific position in the linked list
void delete_at_position(int position) {
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else if (position == 0) {
        delete_at_beginning();
    } else {
        struct node *current_node = head;
        int current_position = 0;

        while (current_node != NULL && current_position < position - 1) {
            current_node = current_node->next;
            current_position++;
        }

        if (current_node != NULL && current_node->next != NULL) {
            struct node *temp = current_node->next;
            current_node->next = temp->next;
            free(temp);
        } else {
            printf("Invalid position\n");
        }
    }
}

// Function to print the linked list
void print_linked_list() {
    struct node *current_node = head;

    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

// Main function
int main() {
    // Insert some nodes into the linked list
    insert_at_beginning(10);
    insert_at_end(20);
    insert_at_position(30, 1);
    insert_at_position(40, 3);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list();

    // Delete a node from the beginning of the linked list
    delete_at_beginning();

    // Print the linked list
    printf("Linked list after deleting a node from the beginning: ");
    print_linked_list();

    // Delete a node from the end of the linked list
    delete_at_end();

    // Print the linked list
    printf("Linked list after deleting a node from the end: ");
    print_linked_list();

    // Delete a node from a specific position in the linked list
    delete_at_position(1);

    // Print the linked list
    printf("Linked list after deleting a node from a specific position: ");
    print_linked_list();

    return 0;
}