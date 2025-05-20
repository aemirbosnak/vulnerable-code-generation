//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the linked list
struct node *insert_at_beginning(struct node *head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Insert a node at the end of the linked list
struct node *insert_at_end(struct node *head, int data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Insert a node at a specific position in the linked list
struct node *insert_at_position(struct node *head, int data, int position) {
    if (position == 0) {
        return insert_at_beginning(head, data);
    }
    struct node *new_node = create_node(data);
    struct node *temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp->next == NULL) {
            return head;
        }
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Delete a node from the beginning of the linked list
struct node *delete_from_beginning(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete a node from the end of the linked list
struct node *delete_from_end(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
    return head;
}

// Delete a node from a specific position in the linked list
struct node *delete_from_position(struct node *head, int position) {
    if (position == 0) {
        return delete_from_beginning(head);
    }
    struct node *temp = head;
    struct node *prev = NULL;
    for (int i = 0; i < position; i++) {
        if (temp->next == NULL) {
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    return head;
}

// Print the linked list
void print_linked_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse the linked list
struct node *reverse_linked_list(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    // Create a linked list
    struct node *head = NULL;
    head = insert_at_end(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);

    // Print the original linked list
    printf("Original linked list: ");
    print_linked_list(head);

    // Insert a node at the beginning of the linked list
    head = insert_at_beginning(head, 0);

    // Print the linked list after inserting a node at the beginning
    printf("Linked list after inserting a node at the beginning: ");
    print_linked_list(head);

    // Insert a node at the end of the linked list
    head = insert_at_end(head, 6);

    // Print the linked list after inserting a node at the end
    printf("Linked list after inserting a node at the end: ");
    print_linked_list(head);

    // Insert a node at a specific position in the linked list
    head = insert_at_position(head, 2, 3);

    // Print the linked list after inserting a node at a specific position
    printf("Linked list after inserting a node at position 3: ");
    print_linked_list(head);

    // Delete a node from the beginning of the linked list
    head = delete_from_beginning(head);

    // Print the linked list after deleting a node from the beginning
    printf("Linked list after deleting a node from the beginning: ");
    print_linked_list(head);

    // Delete a node from the end of the linked list
    head = delete_from_end(head);

    // Print the linked list after deleting a node from the end
    printf("Linked list after deleting a node from the end: ");
    print_linked_list(head);

    // Delete a node from a specific position in the linked list
    head = delete_from_position(head, 2);

    // Print the linked list after deleting a node from a specific position
    printf("Linked list after deleting a node from position 2: ");
    print_linked_list(head);

    // Reverse the linked list
    head = reverse_linked_list(head);

    // Print the reversed linked list
    printf("Reversed linked list: ");
    print_linked_list(head);

    return 0;
}