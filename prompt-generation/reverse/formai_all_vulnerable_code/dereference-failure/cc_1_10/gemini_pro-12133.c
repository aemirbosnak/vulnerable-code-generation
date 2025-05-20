//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the data structure
struct node {
    int data;
    struct node *next;
};

// Define the linked list
struct linked_list {
    struct node *head;
    int size;
};

// Create a new linked list
struct linked_list *create_linked_list() {
    struct linked_list *list = (struct linked_list *)malloc(sizeof(struct linked_list));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(struct linked_list *list, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

// Insert a new node at the end of the linked list
void insert_at_end(struct linked_list *list, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct node *current_node = list->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

    list->size++;
}

// Insert a new node at a specific index in the linked list
void insert_at_index(struct linked_list *list, int index, int data) {
    if (index < 0 || index > list->size) {
        return;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;

    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        struct node *current_node = list->head;
        for (int i = 0; i < index - 1; i++) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
    }

    list->size++;
}

// Delete a node at the beginning of the linked list
void delete_at_beginning(struct linked_list *list) {
    if (list->head == NULL) {
        return;
    }

    struct node *temp_node = list->head;
    list->head = list->head->next;
    free(temp_node);

    list->size--;
}

// Delete a node at the end of the linked list
void delete_at_end(struct linked_list *list) {
    if (list->head == NULL) {
        return;
    }

    struct node *current_node = list->head;
    struct node *previous_node = NULL;

    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (previous_node == NULL) {
        list->head = NULL;
    } else {
        previous_node->next = NULL;
    }

    free(current_node);

    list->size--;
}

// Delete a node at a specific index in the linked list
void delete_at_index(struct linked_list *list, int index) {
    if (index < 0 || index >= list->size) {
        return;
    }

    struct node *current_node = list->head;
    struct node *previous_node = NULL;

    if (index == 0) {
        list->head = list->head->next;
    } else {
        for (int i = 0; i < index; i++) {
            previous_node = current_node;
            current_node = current_node->next;
        }

        if (previous_node == NULL) {
            list->head = current_node->next;
        } else {
            previous_node->next = current_node->next;
        }
    }

    free(current_node);

    list->size--;
}

// Print the linked list
void print_linked_list(struct linked_list *list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free the linked list
void free_linked_list(struct linked_list *list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(list);
}

int main() {
    // Create a new linked list
    struct linked_list *list = create_linked_list();

    // Insert some data into the linked list
    insert_at_beginning(list, 1);
    insert_at_end(list, 2);
    insert_at_index(list, 1, 3);

    // Print the linked list
    print_linked_list(list); // Output: 1 3 2

    // Delete a node from the beginning of the linked list
    delete_at_beginning(list);

    // Delete a node from the end of the linked list
    delete_at_end(list);

    // Delete a node from a specific index in the linked list
    delete_at_index(list, 1);

    // Print the linked list
    print_linked_list(list); // Output: 3

    // Free the linked list
    free_linked_list(list);

    return 0;
}