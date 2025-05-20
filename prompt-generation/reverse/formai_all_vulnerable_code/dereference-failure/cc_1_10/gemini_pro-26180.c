//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: complete
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

// Insert a node at the beginning of the linked list
void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the linked list
void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

// Insert a node after a given node
void insert_after(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the linked list
void delete_at_beginning(node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the linked list
void delete_at_end(node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node *current = *head;
    node *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
}

// Delete a node from the middle of the linked list
void delete_node(node **head, int key) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    node *current = *head;
    node *prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found\n", key);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Reverse a linked list
node *reverse_list(node *head) {
    node *prev = NULL;
    node *current = head;

    while (current != NULL) {
        node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Print the linked list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;

    // Insert some nodes into the linked list
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_end(&head, 30);
    insert_after(head->next, 40);

    // Print the linked list
    printf("Original linked list: ");
    print_list(head);

    // Reverse the linked list
    head = reverse_list(head);

    // Print the reversed linked list
    printf("Reversed linked list: ");
    print_list(head);

    // Delete a node from the beginning of the linked list
    delete_at_beginning(&head);

    // Print the linked list
    printf("Linked list after deleting a node from the beginning: ");
    print_list(head);

    // Delete a node from the end of the linked list
    delete_at_end(&head);

    // Print the linked list
    printf("Linked list after deleting a node from the end: ");
    print_list(head);

    // Delete a node from the middle of the linked list
    delete_node(&head, 40);

    // Print the linked list
    printf("Linked list after deleting a node from the middle: ");
    print_list(head);

    return 0;
}