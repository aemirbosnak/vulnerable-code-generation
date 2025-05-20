//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Define a linked list
struct linked_list {
    struct node *head;
    struct node *tail;
    int size;
};

// Create a new linked list
struct linked_list *create_linked_list() {
    struct linked_list *list = (struct linked_list *)malloc(sizeof(struct linked_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(struct linked_list *list, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
}

// Insert a new node at the end of the linked list
void insert_at_end(struct linked_list *list, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
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

// Insert a new node at a specific index in the linked list
void insert_at_index(struct linked_list *list, int index, int data) {
    if (index == 0) {
        insert_at_beginning(list, data);
    } else if (index == list->size) {
        insert_at_end(list, data);
    } else {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        struct node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        list->size++;
    }
}

// Delete the node at the beginning of the linked list
void delete_at_beginning(struct linked_list *list) {
    if (list->head == NULL) {
        return;
    }
    struct node *current = list->head;
    list->head = current->next;
    if (list->tail == current) {
        list->tail = NULL;
    }
    free(current);
    list->size--;
}

// Delete the node at the end of the linked list
void delete_at_end(struct linked_list *list) {
    if (list->tail == NULL) {
        return;
    }
    struct node *current = list->head;
    while (current->next != list->tail) {
        current = current->next;
    }
    list->tail = current;
    free(current->next);
    list->size--;
}

// Delete the node at a specific index in the linked list
void delete_at_index(struct linked_list *list, int index) {
    if (index == 0) {
        delete_at_beginning(list);
    } else if (index == list->size - 1) {
        delete_at_end(list);
    } else {
        struct node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        struct node *temp = current->next;
        current->next = temp->next;
        free(temp);
        list->size--;
    }
}

// Print the linked list
void print_linked_list(struct linked_list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free the linked list
void free_linked_list(struct linked_list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        struct node *temp = current->next;
        free(current);
        current = temp;
    }
    free(list);
}

int main() {
    // Create a new linked list
    struct linked_list *list = create_linked_list();

    // Insert some nodes into the linked list
    insert_at_beginning(list, 1);
    insert_at_end(list, 2);
    insert_at_index(list, 1, 3);

    // Print the linked list
    print_linked_list(list);

    // Delete some nodes from the linked list
    delete_at_beginning(list);
    delete_at_end(list);
    delete_at_index(list, 1);

    // Print the linked list
    print_linked_list(list);

    // Free the linked list
    free_linked_list(list);

    return 0;
}