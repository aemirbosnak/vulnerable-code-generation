//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: interoperable
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
    linked_list_t *list = malloc(sizeof(linked_list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(linked_list_t *list, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
}

// Insert a node at the end of the linked list
void insert_at_end(linked_list_t *list, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

// Insert a node at a specific position in the linked list
void insert_at_position(linked_list_t *list, int data, int position) {
    if (position == 0) {
        insert_at_beginning(list, data);
    } else if (position == list->size) {
        insert_at_end(list, data);
    } else {
        node_t *new_node = malloc(sizeof(node_t));
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
    if (list->head == NULL) {
        return;
    }
    node_t *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

// Delete a node from the end of the linked list
void delete_from_end(linked_list_t *list) {
    if (list->tail == NULL) {
        return;
    }
    node_t *current_node = list->head;
    while (current_node->next != list->tail) {
        current_node = current_node->next;
    }
    free(list->tail);
    list->tail = current_node;
    list->tail->next = NULL;
    list->size--;
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
        node_t *temp = current_node->next;
        current_node->next = temp->next;
        free(temp);
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

// Free the linked list
void free_linked_list(linked_list_t *list) {
    node_t *current_node = list->head;
    while (current_node != NULL) {
        node_t *temp = current_node;
        current_node = current_node->next;
        free(temp);
    }
    free(list);
}

// Main function
int main() {
    // Create a linked list
    linked_list_t *list = create_linked_list();

    // Insert some nodes into the linked list
    insert_at_beginning(list, 10);
    insert_at_end(list, 20);
    insert_at_position(list, 30, 1);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list(list);

    // Delete a node from the beginning of the linked list
    delete_from_beginning(list);

    // Delete a node from the end of the linked list
    delete_from_end(list);

    // Delete a node from a specific position in the linked list
    delete_from_position(list, 1);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list(list);

    // Free the linked list
    free_linked_list(list);

    return 0;
}