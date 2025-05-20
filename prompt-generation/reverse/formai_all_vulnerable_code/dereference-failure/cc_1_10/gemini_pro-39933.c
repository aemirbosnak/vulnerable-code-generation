//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    char* data;
    struct node* next;
} node_t;

// Define the linked list structure
typedef struct linked_list {
    node_t* head;
    node_t* tail;
    int size;
} linked_list_t;

// Create a new linked list
linked_list_t* create_linked_list() {
    linked_list_t* list = malloc(sizeof(linked_list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Add a new node to the end of the linked list
void add_node(linked_list_t* list, char* data) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

// Print the linked list
void print_linked_list(linked_list_t* list) {
    node_t* current = list->head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

// Destroy the linked list
void destroy_linked_list(linked_list_t* list) {
    node_t* current = list->head;
    while (current != NULL) {
        node_t* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    // Create a new linked list
    linked_list_t* list = create_linked_list();

    // Add some nodes to the linked list
    add_node(list, "A");
    add_node(list, "B");
    add_node(list, "C");
    add_node(list, "D");
    add_node(list, "E");

    // Print the linked list
    printf("Original Linked List:\n");
    print_linked_list(list);

    // Reverse the linked list using a stack
    linked_list_t* reversed_list = create_linked_list();
    node_t* current = list->head;
    while (current != NULL) {
        add_node(reversed_list, current->data);
        current = current->next;
    }

    // Print the reversed linked list
    printf("\nReversed Linked List:\n");
    print_linked_list(reversed_list);

    // Destroy the linked lists
    destroy_linked_list(list);
    destroy_linked_list(reversed_list);

    return 0;
}