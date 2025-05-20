//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// A node in a linked list
struct node {
    int data;
    struct node *next;
};

// A linked list
struct list {
    struct node *head;
    struct node *tail;
};

// Create a new linked list
struct list *create_list() {
    struct list *list = malloc(sizeof(struct list));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Insert a new node into the linked list
void insert_node(struct list *list, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Print the linked list
void print_list(struct list *list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Search for a value in the linked list
int search_list(struct list *list, int value) {
    struct node *current_node = list->head;
    int index = 0;
    while (current_node != NULL) {
        if (current_node->data == value) {
            return index;
        }
        current_node = current_node->next;
        index++;
    }
    return -1;
}

// Free the linked list
void free_list(struct list *list) {
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
    struct list *list = create_list();

    // Insert some values into the linked list
    insert_node(list, 1);
    insert_node(list, 2);
    insert_node(list, 3);
    insert_node(list, 4);
    insert_node(list, 5);

    // Print the linked list
    print_list(list);

    // Search for a value in the linked list
    int value = 3;
    int index = search_list(list, value);
    if (index == -1) {
        printf("Value not found\n");
    } else {
        printf("Value found at index %d\n", index);
    }

    // Free the linked list
    free_list(list);

    return 0;
}