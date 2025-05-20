//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// A macro to allocate memory with error checking
#define MALLOC(ptr, size) do { \
    ptr = malloc(size); \
    if (ptr == NULL) { \
        fprintf(stderr, "Error: malloc failed to allocate %lu bytes\n", size); \
        exit(1); \
    } \
} while (0)

// A macro to free memory with error checking
#define FREE(ptr) do { \
    free(ptr); \
    ptr = NULL; \
} while (0)

// A type for a node in a linked list
struct node {
    int data;
    struct node *next;
};

// A function to create a new node
struct node *create_node(int data) {
    struct node *new_node;
    MALLOC(new_node, sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// A function to insert a new node at the beginning of a linked list
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// A function to insert a new node at the end of a linked list
void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// A function to delete a node from a linked list
void delete_node(struct node **head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        struct node *temp = *head;
        *head = (*head)->next;
        FREE(temp);
        return;
    }
    struct node *current = *head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next == NULL) {
        return;
    }
    struct node *temp = current->next;
    current->next = current->next->next;
    FREE(temp);
}

// A function to print a linked list
void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// A function to free a linked list
void free_list(struct node *head) {
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        FREE(temp);
    }
}

int main() {
    struct node *head = NULL;

    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);

    print_list(head);

    delete_node(&head, 3);

    print_list(head);

    free_list(head);

    return 0;
}