//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to insert a node at the beginning of a linked list
node *insert_beginning(node *head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// Function to insert a node at the end of a linked list
node *insert_end(node *head, int data) {
    if (head == NULL) {
        return insert_beginning(head, data);
    }
    head->next = insert_end(head->next, data);
    return head;
}

// Function to print a linked list
void print_list(node *head) {
    if (head == NULL) {
        printf("NULL\n");
    } else {
        printf("%d -> ", head->data);
        print_list(head->next);
    }
}

// Function to visualize a linked list using ASCII art
void visualize_list(node *head) {
    if (head == NULL) {
        printf("NULL\n");
    } else {
        printf("+---+   \n");
        printf("| %d |   \n", head->data);
        printf("+---+   \n");
        printf("      \\  \n");
        printf("       v  \n");
        visualize_list(head->next);
    }
}

// Main function
int main() {
    // Create an empty linked list
    node *head = NULL;

    // Insert some data into the linked list
    head = insert_beginning(head, 1);
    head = insert_end(head, 2);
    head = insert_end(head, 3);
    head = insert_end(head, 4);
    head = insert_end(head, 5);

    // Print the linked list
    printf("Linked list:\n");
    print_list(head);

    // Visualize the linked list
    printf("Visualized linked list:\n");
    visualize_list(head);

    return 0;
}