//GEMINI-pro DATASET v1.0 Category: Educational ; Style: automated
#include <stdio.h>

// A structure to represent a linked list node
struct Node {
    int data;
    struct Node *next;
};

// A function to insert a new node at the beginning of a linked list
struct Node *insert_at_beginning(struct Node *head, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// A function to insert a new node at the end of a linked list
struct Node *insert_at_end(struct Node *head, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    struct Node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;

    return head;
}

// A function to insert a new node at a specific position in a linked list
struct Node *insert_at_position(struct Node *head, int data, int position) {
    if (position == 0) {
        return insert_at_beginning(head, data);
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;

    struct Node *current_node = head;
    for (int i = 0; i < position - 1; i++) {
        if (current_node->next == NULL) {
            return head;
        }
        current_node = current_node->next;
    }

    new_node->next = current_node->next;
    current_node->next = new_node;

    return head;
}

// A function to delete a node from the beginning of a linked list
struct Node *delete_from_beginning(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node *new_head = head->next;
    free(head);

    return new_head;
}

// A function to delete a node from the end of a linked list
struct Node *delete_from_end(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *current_node = head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }

    free(current_node->next);
    current_node->next = NULL;

    return head;
}

// A function to delete a node from a specific position in a linked list
struct Node *delete_from_position(struct Node *head, int position) {
    if (position == 0) {
        return delete_from_beginning(head);
    }

    struct Node *current_node = head;
    for (int i = 0; i < position - 1; i++) {
        if (current_node->next == NULL) {
            return head;
        }
        current_node = current_node->next;
    }

    struct Node *next_node = current_node->next->next;
    free(current_node->next);
    current_node->next = next_node;

    return head;
}

// A function to print a linked list
void print_linked_list(struct Node *head) {
    struct Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_position(head, 30, 1);
    head = insert_at_position(head, 40, 3);

    printf("Linked list before deletion: ");
    print_linked_list(head);

    head = delete_from_beginning(head);
    head = delete_from_end(head);
    head = delete_from_position(head, 1);

    printf("Linked list after deletion: ");
    print_linked_list(head);

    return 0;
}