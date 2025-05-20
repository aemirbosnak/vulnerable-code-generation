//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: complete
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
void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the list
void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Insert a node at a specific position in the list
void insert_at_position(node **head, int data, int position) {
    node *new_node = create_node(data);
    if (position == 0) {
        insert_at_beginning(head, data);
        return;
    }
    node *temp = *head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Delete a node from the beginning of the list
void delete_from_beginning(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list
void delete_from_end(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    node *to_delete = temp->next;
    temp->next = NULL;
    free(to_delete);
}

// Delete a node from a specific position in the list
void delete_from_position(node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        delete_from_beginning(head);
        return;
    }
    node *temp = *head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
    }
    node *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

// Print the list
void print_list(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    node *head = NULL;

    // Insert some nodes into the list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_position(&head, 30, 1);
    insert_at_end(&head, 40);

    // Print the list
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);

    // Print the list
    print_list(head);

    // Delete a node from the end of the list
    delete_from_end(&head);

    // Print the list
    print_list(head);

    // Delete a node from a specific position in the list
    delete_from_position(&head, 1);

    // Print the list
    print_list(head);

    return 0;
}