//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Linked list operations
struct Node *insert_at_beginning(struct Node *head, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

struct Node *insert_at_end(struct Node *head, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

struct Node *insert_at_position(struct Node *head, int data, int position) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;

    if (position == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        struct Node *temp = head;
        int count = 1;
        while (temp != NULL && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp != NULL) {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    return head;
}

struct Node *delete_at_beginning(struct Node *head) {
    if (head == NULL) {
        return NULL;
    } else {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

struct Node *delete_at_end(struct Node *head) {
    if (head == NULL) {
        return NULL;
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    return head;
}

struct Node *delete_at_position(struct Node *head, int position) {
    if (head == NULL) {
        return NULL;
    } else if (position == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    } else {
        struct Node *temp = head;
        int count = 1;
        while (temp != NULL && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp != NULL && temp->next != NULL) {
            struct Node *temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
        }
    }
    return head;
}

// Print linked list
void print_linked_list(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize linked list
    struct Node *head = NULL;

    // Insert elements at the beginning
    head = insert_at_beginning(head, 1);
    head = insert_at_beginning(head, 2);
    head = insert_at_beginning(head, 3);

    // Print linked list
    printf("Linked list after inserting at the beginning: ");
    print_linked_list(head);

    // Insert elements at the end
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);
    head = insert_at_end(head, 6);

    // Print linked list
    printf("Linked list after inserting at the end: ");
    print_linked_list(head);

    // Insert elements at specific positions
    head = insert_at_position(head, 7, 3);
    head = insert_at_position(head, 8, 5);
    head = insert_at_position(head, 9, 7);

    // Print linked list
    printf("Linked list after inserting at specific positions: ");
    print_linked_list(head);

    // Delete elements at the beginning
    head = delete_at_beginning(head);
    head = delete_at_beginning(head);

    // Print linked list
    printf("Linked list after deleting at the beginning: ");
    print_linked_list(head);

    // Delete elements at the end
    head = delete_at_end(head);
    head = delete_at_end(head);

    // Print linked list
    printf("Linked list after deleting at the end: ");
    print_linked_list(head);

    // Delete elements at specific positions
    head = delete_at_position(head, 3);
    head = delete_at_position(head, 5);

    // Print linked list
    printf("Linked list after deleting at specific positions: ");
    print_linked_list(head);

    return 0;
}