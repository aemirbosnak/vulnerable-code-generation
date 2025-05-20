//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in a linked list
struct node {
    int data;
    struct node *next;
};

// A function to insert a new node at the beginning of a linked list
struct node *insert_node(struct node *head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// A function to print the linked list
void print_linked_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// A function to reverse a linked list recursively
struct node *reverse_linked_list_recursive(struct node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct node *new_head = reverse_linked_list_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

int main() {
    // Create a linked list
    struct node *head = NULL;
    head = insert_node(head, 1);
    head = insert_node(head, 2);
    head = insert_node(head, 3);
    head = insert_node(head, 4);
    head = insert_node(head, 5);

    // Print the original linked list
    printf("Original linked list: ");
    print_linked_list(head);

    // Reverse the linked list recursively
    head = reverse_linked_list_recursive(head);

    // Print the reversed linked list
    printf("Reversed linked list: ");
    print_linked_list(head);

    return 0;
}