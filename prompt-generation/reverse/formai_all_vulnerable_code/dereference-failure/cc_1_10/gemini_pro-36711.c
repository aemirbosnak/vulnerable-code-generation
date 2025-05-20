//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
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

// Insert a new node at the beginning of the linked list
void insert_at_beginning(linked_list_t *list, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
}

// Insert a new node at the end of the linked list
void insert_at_end(linked_list_t *list, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail != NULL) {
        list->tail->next = new_node;
    }
    list->tail = new_node;
    if (list->head == NULL) {
        list->head = new_node;
    }
    list->size++;
}

// Insert a new node at a specific position in the linked list
void insert_at_position(linked_list_t *list, int data, int position) {
    if (position == 0) {
        insert_at_beginning(list, data);
    } else if (position == list->size) {
        insert_at_end(list, data);
    } else {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->data = data;
        node_t *current_node = list->head;
        for (int i = 0; i < position - 1; i++) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
        list->size++;
    }
}

// Delete a node from the beginning of the linked list
void delete_from_beginning(linked_list_t *list) {
    if (list->head != NULL) {
        node_t *deleted_node = list->head;
        list->head = list->head->next;
        free(deleted_node);
        list->size--;
        if (list->head == NULL) {
            list->tail = NULL;
        }
    }
}

// Delete a node from the end of the linked list
void delete_from_end(linked_list_t *list) {
    if (list->tail != NULL) {
        node_t *current_node = list->head;
        if (current_node->next == NULL) {
            list->head = NULL;
            list->tail = NULL;
            free(current_node);
        } else {
            while (current_node->next->next != NULL) {
                current_node = current_node->next;
            }
            node_t *deleted_node = current_node->next;
            current_node->next = NULL;
            list->tail = current_node;
            free(deleted_node);
        }
        list->size--;
    }
}

// Delete a node from a specific position in the linked list
void delete_from_position(linked_list_t *list, int position) {
    if (position == 0) {
        delete_from_beginning(list);
    } else if (position == list->size - 1) {
        delete_from_end(list);
    } else {
        node_t *current_node = list->head;
        for (int i = 0; i < position - 1; i++) {
            current_node = current_node->next;
        }
        node_t *deleted_node = current_node->next;
        current_node->next = deleted_node->next;
        free(deleted_node);
        list->size--;
    }
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

// Destroy the linked list
void destroy_linked_list(linked_list_t *list) {
    while (list->head != NULL) {
        node_t *deleted_node = list->head;
        list->head = list->head->next;
        free(deleted_node);
    }
    free(list);
}

// Main function
int main() {
    // Create a new linked list
    linked_list_t *list = create_linked_list();

    // Insert some data into the linked list
    insert_at_beginning(list, 1);
    insert_at_end(list, 2);
    insert_at_position(list, 3, 1);

    // Print the linked list
    print_linked_list(list);

    // Delete some data from the linked list
    delete_from_beginning(list);
    delete_from_end(list);
    delete_from_position(list, 1);

    // Print the linked list
    print_linked_list(list);

    // Destroy the linked list
    destroy_linked_list(list);

    return 0;
}