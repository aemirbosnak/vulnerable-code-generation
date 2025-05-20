//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// List structure
typedef struct list {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a new list
list_t *create_list() {
    list_t *new_list = (list_t *)malloc(sizeof(list_t));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

// Insert a node at the beginning of the list
void insert_at_beginning(list_t *list, int data) {
    node_t *new_node = create_node(data);
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head = new_node;
    }
    list->size++;
}

// Insert a node at the end of the list
void insert_at_end(list_t *list, int data) {
    node_t *new_node = create_node(data);
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

// Insert a node at a given position
void insert_at_position(list_t *list, int data, int position) {
    if (position < 0 || position > list->size) {
        printf("Invalid position\n");
        return;
    }
    node_t *new_node = create_node(data);
    if (position == 0) {
        insert_at_beginning(list, data);
    } else if (position == list->size) {
        insert_at_end(list, data);
    } else {
        node_t *current_node = list->head;
        for (int i = 0; i < position - 1; i++) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
    list->size++;
}

// Delete a node from the beginning of the list
void delete_from_beginning(list_t *list) {
    if (list->size == 0) {
        printf("List is empty\n");
        return;
    }
    node_t *current_node = list->head;
    list->head = list->head->next;
    if (list->size == 1) {
        list->tail = NULL;
    }
    free(current_node);
    list->size--;
}

// Delete a node from the end of the list
void delete_from_end(list_t *list) {
    if (list->size == 0) {
        printf("List is empty\n");
        return;
    }
    node_t *current_node = list->head;
    node_t *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (previous_node == NULL) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        previous_node->next = NULL;
        list->tail = previous_node;
    }
    free(current_node);
    list->size--;
}

// Delete a node from a given position
void delete_from_position(list_t *list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position\n");
        return;
    }
    node_t *current_node = list->head;
    node_t *previous_node = NULL;
    for (int i = 0; i < position; i++) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (previous_node == NULL) {
        list->head = list->head->next;
    } else {
        previous_node->next = current_node->next;
    }
    if (position == list->size - 1) {
        list->tail = previous_node;
    }
    free(current_node);
    list->size--;
}

// Print the list
void print_list(list_t *list) {
    node_t *current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    // Create a new list
    list_t *list = create_list();

    // Insert some data into the list
    insert_at_beginning(list, 1);
    insert_at_end(list, 2);
    insert_at_position(list, 3, 1);

    // Print the list
    printf("Original list: ");
    print_list(list);

    // Delete a node from the beginning of the list
    delete_from_beginning(list);

    // Print the list
    printf("After deleting from beginning: ");
    print_list(list);

    // Delete a node from the end of the list
    delete_from_end(list);

    // Print the list
    printf("After deleting from end: ");
    print_list(list);

    // Delete a node from a given position
    delete_from_position(list, 0);

    // Print the list
    printf("After deleting from position 0: ");
    print_list(list);

    // Free the list
    while (list->size > 0) {
        delete_from_end(list);
    }
    free(list);

    return 0;
}