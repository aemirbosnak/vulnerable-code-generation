//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Defines a node in a linked list.
typedef struct node {
    char* data;
    struct node* next;
} node_t;

// Creates a new node with the given data.
node_t* create_node(char* data) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Inserts a new node into the linked list.
void insert_node(node_t** head, char* data) {
    node_t* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Deletes a node from the linked list.
void delete_node(node_t** head, char* data) {
    if (*head == NULL) {
        return;
    } else if (strcmp((*head)->data, data) == 0) {
        *head = (*head)->next;
    } else {
        node_t* current = *head;
        while (current->next != NULL) {
            if (strcmp(current->next->data, data) == 0) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
    }
}

// Prints the linked list.
void print_list(node_t* head) {
    while (head != NULL) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

// Frees the linked list.
void free_list(node_t* head) {
    while (head != NULL) {
        node_t* next = head->next;
        free(head->data);
        free(head);
        head = next;
    }
}

int main() {
    // Creates a linked list of strings.
    node_t* head = NULL;
    insert_node(&head, "Hello");
    insert_node(&head, "World");
    insert_node(&head, "!");

    // Prints the linked list.
    print_list(head);

    // Deletes a node from the linked list.
    delete_node(&head, "World");

    // Prints the linked list again.
    printf("\n");
    print_list(head);

    // Frees the linked list.
    free_list(head);

    return 0;
}