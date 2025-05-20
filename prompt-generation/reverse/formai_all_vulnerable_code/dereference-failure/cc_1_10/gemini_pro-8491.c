//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Create a node
struct node {
    int data;
    struct node *next;
};

// Create a linked list
struct linked_list {
    struct node *head;
    struct node *tail;
};

// Create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(struct linked_list *list, struct node *new_node) {
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head = new_node;
    }
}

// Insert a node at the end of the linked list
void insert_at_end(struct linked_list *list, struct node *new_node) {
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Insert a node after a given node
void insert_after(struct linked_list *list, struct node *new_node, struct node *after) {
    if (after == NULL) {
        printf("The given node is not in the linked list.\n");
    } else {
        new_node->next = after->next;
        after->next = new_node;
    }
}

// Delete a node from the linked list
void delete_node(struct linked_list *list, struct node *node_to_delete) {
    if (node_to_delete == NULL) {
        printf("The given node is not in the linked list.\n");
    } else if (node_to_delete == list->head) {
        list->head = node_to_delete->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
        free(node_to_delete);
    } else {
        struct node *current_node = list->head;
        while (current_node->next != node_to_delete) {
            current_node = current_node->next;
        }
        if (node_to_delete == list->tail) {
            list->tail = current_node;
        }
        current_node->next = node_to_delete->next;
        free(node_to_delete);
    }
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

// Get the length of the linked list
int get_length(struct linked_list *list) {
    int length = 0;
    struct node *current_node = list->head;
    while (current_node != NULL) {
        length++;
        current_node = current_node->next;
    }
    return length;
}

// Reverse the linked list
void reverse_linked_list(struct linked_list *list) {
    struct node *previous_node = NULL;
    struct node *current_node = list->head;
    struct node *next_node = NULL;
    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    list->head = previous_node;
}

// Sort the linked list in ascending order
void sort_linked_list(struct linked_list *list) {
    struct node *current_node = list->head;
    struct node *next_node = NULL;
    int temp;
    while (current_node != NULL) {
        next_node = current_node->next;
        while (next_node != NULL) {
            if (current_node->data > next_node->data) {
                temp = current_node->data;
                current_node->data = next_node->data;
                next_node->data = temp;
            }
            next_node = next_node->next;
        }
        current_node = current_node->next;
    }
}

// Create a new linked list
struct linked_list *create_linked_list() {
    struct linked_list *new_list = (struct linked_list *)malloc(sizeof(struct linked_list));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

// Free the linked list
void free_linked_list(struct linked_list *list) {
    struct node *current_node = list->head;
    struct node *next_node = NULL;
    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(list);
}

// Main function
int main() {
    // Create a linked list
    struct linked_list *list = create_linked_list();

    // Insert some nodes into the linked list
    struct node *node1 = create_node(1);
    struct node *node2 = create_node(2);
    struct node *node3 = create_node(3);
    struct node *node4 = create_node(4);
    struct node *node5 = create_node(5);
    insert_at_beginning(list, node1);
    insert_at_end(list, node2);
    insert_after(list, node3, node1);
    insert_at_end(list, node4);
    insert_at_beginning(list, node5);

    // Print the linked list
    printf("Original linked list:\n");
    print_linked_list(list);

    // Reverse the linked list
    reverse_linked_list(list);

    // Print the reversed linked list
    printf("Reversed linked list:\n");
    print_linked_list(list);

    // Sort the linked list
    sort_linked_list(list);

    // Print the sorted linked list
    printf("Sorted linked list:\n");
    print_linked_list(list);

    // Free the linked list
    free_linked_list(list);

    return 0;
}