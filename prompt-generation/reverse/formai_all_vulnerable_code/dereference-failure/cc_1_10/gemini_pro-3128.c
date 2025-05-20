//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Create a linked list node
struct Node {
    int data;
    struct Node *next;
};

// Insert a node at the beginning of the linked list
struct Node *insert_at_beginning(struct Node *head, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

// Insert a node at the end of the linked list
struct Node *insert_at_end(struct Node *head, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct Node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

    return head;
}

// Insert a node at a specific position in the linked list
struct Node *insert_at_position(struct Node *head, int data, int position) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;

    if (position == 0) {
        head = insert_at_beginning(head, data);
    } else {
        struct Node *current_node = head;
        for (int i = 0; i < position - 1; i++) {
            if (current_node == NULL) {
                printf("Invalid position!\n");
                return head;
            }
            current_node = current_node->next;
        }

        if (current_node == NULL) {
            head = insert_at_end(head, data);
        } else {
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
    }

    return head;
}

// Delete a node from the beginning of the linked list
struct Node *delete_from_beginning(struct Node *head) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return head;
    }

    struct Node *new_head = head->next;
    free(head);
    return new_head;
}

// Delete a node from the end of the linked list
struct Node *delete_from_end(struct Node *head) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *current_node = head;
    struct Node *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    previous_node->next = NULL;
    free(current_node);
    return head;
}

// Delete a node from a specific position in the linked list
struct Node *delete_from_position(struct Node *head, int position) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return head;
    }

    if (position == 0) {
        head = delete_from_beginning(head);
    } else {
        struct Node *current_node = head;
        struct Node *previous_node = NULL;
        for (int i = 0; i < position; i++) {
            if (current_node == NULL) {
                printf("Invalid position!\n");
                return head;
            }
            previous_node = current_node;
            current_node = current_node->next;
        }

        if (current_node == NULL) {
            head = delete_from_end(head);
        } else {
            previous_node->next = current_node->next;
            free(current_node);
        }
    }

    return head;
}

// Print the linked list
void print_linked_list(struct Node *head) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    struct Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// main function
int main() {
    // Create an empty linked list
    struct Node *head = NULL;

    // Insert some nodes into the linked list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_position(head, 3, 1);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list(head);

    // Delete a node from the beginning of the linked list
    head = delete_from_beginning(head);

    // Print the linked list
    printf("Linked list after deleting the first node: ");
    print_linked_list(head);

    // Delete a node from the end of the linked list
    head = delete_from_end(head);

    // Print the linked list
    printf("Linked list after deleting the last node: ");
    print_linked_list(head);

    // Delete a node from a specific position in the linked list
    head = delete_from_position(head, 1);

    // Print the linked list
    printf("Linked list after deleting the second node: ");
    print_linked_list(head);

    return 0;
}