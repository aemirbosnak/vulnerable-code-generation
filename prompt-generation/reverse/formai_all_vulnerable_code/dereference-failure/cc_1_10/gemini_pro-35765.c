//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

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
    return new_node;
}

// Insert a node at the end of the list
node *insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}

// Insert a node after a given node
node *insert_after(node *head, int data, int after_data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node *current_node = head;
    while (current_node != NULL) {
        if (current_node->data == after_data) {
            new_node->next = current_node->next;
            current_node->next = new_node;
            return head;
        }
        current_node = current_node->next;
    }
    return head;
}

// Delete a node from the beginning of the list
node *delete_from_beginning(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *new_head = head->next;
    free(head);
    return new_head;
}

// Delete a node from the end of the list
node *delete_from_end(node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    node *current_node = head;
    node *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    previous_node->next = NULL;
    free(current_node);
    return head;
}

// Delete a node after a given node
node *delete_after(node *head, int after_data) {
    if (head == NULL) {
        return NULL;
    }
    node *current_node = head;
    node *previous_node = NULL;
    while (current_node != NULL) {
        if (current_node->data == after_data) {
            if (current_node->next == NULL) {
                return head;
            }
            previous_node->next = current_node->next;
            free(current_node);
            return head;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    return head;
}

// Print the list
void print_list(node *head) {
    node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    node *head = NULL;
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_after(head, 30, 10);
    print_list(head); // Output: 10 30 20
    head = delete_from_beginning(head);
    head = delete_from_end(head);
    head = delete_after(head, 30);
    print_list(head); // Output: 30
    return 0;
}