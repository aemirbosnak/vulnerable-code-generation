//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdlib.h>
#include <stdio.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Linked list structure
typedef struct list {
    node *head;
} list;

// Create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a new list
list *create_list() {
    list *new_list = (list *)malloc(sizeof(list));
    new_list->head = NULL;
    return new_list;
}

// Insert a node at the beginning of the list
void insert_at_beginning(list *l, int data) {
    node *new_node = create_node(data);
    new_node->next = l->head;
    l->head = new_node;
}

// Insert a node at the end of the list
void insert_at_end(list *l, int data) {
    node *new_node = create_node(data);
    if (l->head == NULL) {
        l->head = new_node;
    } else {
        node *current_node = l->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Insert a node after a given node
void insert_after(list *l, int data, int after_data) {
    node *new_node = create_node(data);
    node *current_node = l->head;
    while (current_node != NULL && current_node->data != after_data) {
        current_node = current_node->next;
    }
    if (current_node != NULL) {
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

// Delete a node from the beginning of the list
void delete_from_beginning(list *l) {
    if (l->head != NULL) {
        node *temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
}

// Delete a node from the end of the list
void delete_from_end(list *l) {
    if (l->head == NULL) {
        return;
    } else if (l->head->next == NULL) {
        free(l->head);
        l->head = NULL;
    } else {
        node *current_node = l->head;
        while (current_node->next->next != NULL) {
            current_node = current_node->next;
        }
        free(current_node->next);
        current_node->next = NULL;
    }
}

// Delete a node after a given node
void delete_after(list *l, int after_data) {
    node *current_node = l->head;
    while (current_node != NULL && current_node->data != after_data) {
        current_node = current_node->next;
    }
    if (current_node != NULL && current_node->next != NULL) {
        node *temp = current_node->next;
        current_node->next = current_node->next->next;
        free(temp);
    }
}

// Print the list
void print_list(list *l) {
    node *current_node = l->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Driver code
int main() {
    list *l = create_list();
    insert_at_beginning(l, 10);
    insert_at_end(l, 20);
    insert_at_end(l, 30);
    insert_after(l, 15, 10);
    print_list(l); // Output: 10 15 20 30

    delete_from_beginning(l);
    delete_from_end(l);
    delete_after(l, 15);
    print_list(l); // Output: 15 20

    return 0;
}