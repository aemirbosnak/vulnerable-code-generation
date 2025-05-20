//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *head = NULL;

// Function to create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// Function to insert a new node at the beginning of the list
void insert_at_beginning(int data) {
    node_t *new_node = create_node(data);

    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
}

// Function to insert a new node at the end of the list
void insert_at_end(int data) {
    node_t *new_node = create_node(data);

    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current_node = head;

        while (current_node->next != NULL) {
            current_node = current_node->next;
        }

        current_node->next = new_node;
    }
}

// Function to insert a new node at a specific position in the list
void insert_at_position(int data, int position) {
    node_t *new_node = create_node(data);

    if (head == NULL) {
        head = new_node;
    } else if (position == 0) {
        insert_at_beginning(data);
    } else {
        node_t *current_node = head;

        for (int i = 0; i < position - 1; i++) {
            if (current_node->next == NULL) {
                printf("Invalid position!\n");
                return;
            }

            current_node = current_node->next;
        }

        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

// Function to delete a node from the beginning of the list
void delete_from_beginning() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        node_t *temp = head;

        head = head->next;
        free(temp);
    }
}

// Function to delete a node from the end of the list
void delete_from_end() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        node_t *current_node = head;

        while (current_node->next->next != NULL) {
            current_node = current_node->next;
        }

        free(current_node->next);
        current_node->next = NULL;
    }
}

// Function to delete a node from a specific position in the list
void delete_from_position(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
    } else if (position == 0) {
        delete_from_beginning();
    } else {
        node_t *current_node = head;

        for (int i = 0; i < position - 1; i++) {
            if (current_node->next == NULL) {
                printf("Invalid position!\n");
                return;
            }

            current_node = current_node->next;
        }

        node_t *temp = current_node->next;

        current_node->next = temp->next;
        free(temp);
    }
}

// Function to print the list
void print_list() {
    node_t *current_node = head;

    printf("List: ");
    while (current_node != NULL) {
        printf("%d ", current_node->data);

        current_node = current_node->next;
    }

    printf("\n");
}

int main() {
    // Create a linked list
    insert_at_beginning(10);
    insert_at_end(20);
    insert_at_position(30, 1);
    insert_at_position(40, 3);

    // Print the list
    print_list();

    // Delete a node from the beginning of the list
    delete_from_beginning();

    // Print the list
    print_list();

    // Delete a node from the end of the list
    delete_from_end();

    // Print the list
    print_list();

    // Delete a node from a specific position in the list
    delete_from_position(1);

    // Print the list
    print_list();

    return 0;
}