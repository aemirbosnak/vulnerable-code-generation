//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// A simple node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// A linked list structure
typedef struct linked_list {
    node *head;
    node *tail;
    int size;
} linked_list;

// Create a new linked list
linked_list *create_linked_list() {
    linked_list *list = malloc(sizeof(linked_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
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
    list->size++;
}

// Insert a new node at the end of the linked list
void insert_at_end(linked_list *list, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail == NULL) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }
    list->tail = new_node;
    list->size++;
}

// Insert a new node at a specific position in the linked list
void insert_at_position(linked_list *list, int data, int position) {
    if (position < 0 || position > list->size) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0) {
        insert_at_beginning(list, data);
        return;
    }
    if (position == list->size) {
        insert_at_end(list, data);
        return;
    }
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    node *current_node = list->head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
    list->size++;
}

// Delete a node from the beginning of the linked list
void delete_from_beginning(linked_list *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *current_node = list->head;
    list->head = list->head->next;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    free(current_node);
    list->size--;
}

// Delete a node from the end of the linked list
void delete_from_end(linked_list *list) {
    if (list->tail == NULL) {
        printf("List is empty\n");
        return;
    }
    node *current_node = list->head;
    while (current_node->next != list->tail) {
        current_node = current_node->next;
    }
    list->tail = current_node;
    free(current_node->next);
    list->size--;
}

// Delete a node from a specific position in the linked list
void delete_from_position(linked_list *list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0) {
        delete_from_beginning(list);
        return;
    }
    if (position == list->size - 1) {
        delete_from_end(list);
        return;
    }
    node *current_node = list->head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }
    node *next_node = current_node->next->next;
    free(current_node->next);
    current_node->next = next_node;
    list->size--;
}

// Print the linked list
void print_linked_list(linked_list *list) {
    node *current_node = list->head;
    printf("Linked list: ");
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free the linked list
void free_linked_list(linked_list *list) {
    node *current_node = list->head;
    while (current_node != NULL) {
        node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(list);
}

// A sample input function
void sample_input(linked_list *list) {
    // Insert some sample data
    insert_at_beginning(list, 1);
    insert_at_end(list, 2);
    insert_at_position(list, 3, 1);
    insert_at_position(list, 4, 3);
    insert_at_position(list, 5, 0);
}

// A sample output function
void sample_output(linked_list *list) {
    // Print the linked list
    print_linked_list(list);
    
   // Delete some data and print again 
    delete_from_beginning(list);
    delete_from_end(list);
    delete_from_position(list, 2);
    print_linked_list(list);
    
    // Free the linked list
    free_linked_list(list);
}

int main() {

    linked_list *list = create_linked_list();
    sample_input(list);
    sample_output(list);
    
    return 0;
}