//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define the linked list structure
typedef struct linked_list {
    node_t *head;
    node_t *tail;
    int size;
} linked_list_t;

// Create a new linked list
linked_list_t *create_linked_list() {
    linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Insert a new node at the end of the linked list
void insert_node(linked_list_t *list, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

// Search for a node in the linked list
node_t *search_node(linked_list_t *list, int data) {
    node_t *current_node = list->head;

    while (current_node != NULL) {
        if (current_node->data == data) {
            return current_node;
        }

        current_node = current_node->next;
    }

    return NULL;
}

// Print the linked list
void print_linked_list(linked_list_t *list) {
    node_t *current_node = list->head;

    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

// Free the linked list
void free_linked_list(linked_list_t *list) {
    node_t *current_node = list->head;

    while (current_node != NULL) {
        node_t *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    free(list);
}

// Main function
int main() {
    // Create a new linked list
    linked_list_t *list = create_linked_list();

    // Insert some nodes into the linked list
    insert_node(list, 10);
    insert_node(list, 20);
    insert_node(list, 30);
    insert_node(list, 40);
    insert_node(list, 50);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list(list);

    // Search for a node in the linked list
    node_t *found_node = search_node(list, 30);

    if (found_node != NULL) {
        printf("Node found: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    // Free the linked list
    free_linked_list(list);

    return 0;
}