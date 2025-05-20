//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
node *insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Insert a node at the end of the list
node *insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    return head;
}

// Insert a node after a given node
node *insert_after(node *head, int data, int after_data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        node *current_node = head;
        while (current_node->next != NULL && current_node->data != after_data) {
            current_node = current_node->next;
        }
        if (current_node->data == after_data) {
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
    }
    return head;
}

// Delete a node from the list
node *delete_node(node *head, int data) {
    if (head == NULL) {
        return head;
    } else if (head->data == data) {
        node *new_head = head->next;
        free(head);
        return new_head;
    } else {
        node *current_node = head;
        while (current_node->next != NULL && current_node->next->data != data) {
            current_node = current_node->next;
        }
        if (current_node->next != NULL) {
            node *temp = current_node->next;
            current_node->next = temp->next;
            free(temp);
        }
        return head;
    }
}

// Print the list
void print_list(node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        node *current_node = head;
        while (current_node != NULL) {
            printf("%d ", current_node->data);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create an empty list
    node *head = NULL;

    // Insert nodes into the list
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_after(head, 30, 10);
    head = insert_at_end(head, 40);

    // Print the list
    printf("The list is: ");
    print_list(head);

    // Delete a node from the list
    head = delete_node(head, 30);

    // Print the list
    printf("The list after deleting a node: ");
    print_list(head);

    return 0;
}