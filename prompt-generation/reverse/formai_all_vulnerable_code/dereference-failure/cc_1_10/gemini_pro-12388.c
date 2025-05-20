//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Define the linked list structure
typedef struct linked_list {
    node *head;
    node *tail;
} linked_list;

// Create a new linked list
linked_list *create_list() {
    linked_list *list = malloc(sizeof(linked_list));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(linked_list *list, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

// Insert a new node at the end of the linked list
void insert_at_end(linked_list *list, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Insert a new node at a specific position in the linked list
void insert_at_position(linked_list *list, int data, int position) {
    if (position == 0) {
        insert_at_beginning(list, data);
    } else {
        node *new_node = malloc(sizeof(node));
        new_node->data = data;
        new_node->next = NULL;
        node *current_node = list->head;
        for (int i = 0; i < position - 1; i++) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

// Delete a node from the beginning of the linked list
void delete_from_beginning(linked_list *list) {
    if (list->head == NULL) {
        return;
    } else {
        node *temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

// Delete a node from the end of the linked list
void delete_from_end(linked_list *list) {
    if (list->tail == NULL) {
        return;
    } else if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        node *current_node = list->head;
        while (current_node->next != list->tail) {
            current_node = current_node->next;
        }
        node *temp = list->tail;
        list->tail = current_node;
        current_node->next = NULL;
        free(temp);
    }
}

// Delete a node from a specific position in the linked list
void delete_from_position(linked_list *list, int position) {
    if (position == 0) {
        delete_from_beginning(list);
    } else {
        node *current_node = list->head;
        for (int i = 0; i < position - 1; i++) {
            current_node = current_node->next;
        }
        node *temp = current_node->next;
        current_node->next = temp->next;
        free(temp);
    }
}

// Print the linked list
void print_list(linked_list *list) {
    node *current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free the linked list
void free_list(linked_list *list) {
    node *current_node = list->head;
    while (current_node != NULL) {
        node *temp = current_node;
        current_node = current_node->next;
        free(temp);
    }
    free(list);
}

// Main function
int main() {
    // Create a new linked list
    linked_list *list = create_list();

    // Insert some nodes into the linked list
    insert_at_beginning(list, 1);
    insert_at_end(list, 2);
    insert_at_position(list, 3, 1);

    // Print the linked list
    printf("Linked list: ");
    print_list(list);

    // Delete a node from the beginning of the linked list
    delete_from_beginning(list);

    // Delete a node from the end of the linked list
    delete_from_end(list);

    // Delete a node from a specific position in the linked list
    delete_from_position(list, 1);

    // Print the linked list
    printf("Linked list: ");
    print_list(list);

    // Free the linked list
    free_list(list);

    return 0;
}