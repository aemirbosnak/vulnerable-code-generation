//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the linked list
void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Insert a node after a given node
void insert_after(node_t *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    node_t *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the linked list
void delete_from_beginning(node_t **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the linked list
void delete_from_end(node_t **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node_t *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete a node from the middle of the linked list
void delete_from_middle(node_t **head, node_t *node_to_delete) {
    if (*head == NULL || node_to_delete == NULL) {
        printf("Linked list is empty or node to delete is not present\n");
        return;
    }
    if (*head == node_to_delete) {
        *head = (*head)->next;
        free(node_to_delete);
        return;
    }
    node_t *temp = *head;
    while (temp->next != node_to_delete) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Node to delete is not present in the linked list\n");
            return;
        }
    }
    temp->next = node_to_delete->next;
    free(node_to_delete);
}

// Print the linked list
void print_linked_list(node_t *head) {
    node_t *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Get the length of the linked list
int get_length(node_t *head) {
    int length = 0;
    node_t *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Reverse the linked list
void reverse_linked_list(node_t **head) {
    node_t *prev = NULL;
    node_t *current = *head;
    while (current != NULL) {
        node_t *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Driver code
int main() {
    // Create a linked list
    node_t *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);

    // Print the linked list
    printf("Original linked list: ");
    print_linked_list(head);

    // Insert a node at the beginning of the linked list
    insert_at_beginning(&head, 0);

    // Print the linked list
    printf("Linked list after inserting a node at the beginning: ");
    print_linked_list(head);

    // Insert a node at the end of the linked list
    insert_at_end(&head, 6);

    // Print the linked list
    printf("Linked list after inserting a node at the end: ");
    print_linked_list(head);

    // Insert a node after a given node
    insert_after(head->next, 2.5);

    // Print the linked list
    printf("Linked list after inserting a node after a given node: ");
    print_linked_list(head);

    // Delete a node from the beginning of the linked list
    delete_from_beginning(&head);

    // Print the linked list
    printf("Linked list after deleting a node from the beginning: ");
    print_linked_list(head);

    // Delete a node from the end of the linked list
    delete_from_end(&head);

    // Print the linked list
    printf("Linked list after deleting a node from the end: ");
    print_linked_list(head);

    // Delete a node from the middle of the linked list
    delete_from_middle(&head, head->next->next);

    // Print the linked list
    printf("Linked list after deleting a node from the middle: ");
    print_linked_list(head);

    // Get the length of the linked list
    int length = get_length(head);

    // Print the length of the linked list
    printf("Length of the linked list: %d\n", length);

    // Reverse the linked list
    reverse_linked_list(&head);

    // Print the linked list
    printf("Reversed linked list: ");
    print_linked_list(head);

    // Free the linked list
    node_t *temp = head;
    while (temp != NULL) {
        node_t *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}