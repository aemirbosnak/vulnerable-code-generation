//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// A very important data structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// A function to create a new node
Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// A function to insert a new node at the beginning of a linked list
void insert_at_beginning(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// A function to insert a new node at the end of a linked list
void insert_at_end(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

// A function to delete a node from the beginning of a linked list
void delete_from_beginning(Node **head) {
    if (*head == NULL) {
        printf("Error: Linked list is empty!\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// A function to delete a node from the end of a linked list
void delete_from_end(Node **head) {
    if (*head == NULL) {
        printf("Error: Linked list is empty!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node *prev = NULL;
    Node *curr = *head;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
}

// A function to print a linked list
void print_linked_list(Node *head) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list
    Node *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);
    insert_at_end(&head, 6);

    // Print the linked list
    printf("Original linked list: ");
    print_linked_list(head);

    // Delete a node from the beginning
    delete_from_beginning(&head);

    // Print the linked list
    printf("Linked list after deleting a node from the beginning: ");
    print_linked_list(head);

    // Delete a node from the end
    delete_from_end(&head);

    // Print the linked list
    printf("Linked list after deleting a node from the end: ");
    print_linked_list(head);

    return 0;
}