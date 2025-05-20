//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
} linked_list;

linked_list *create_linked_list() {
    linked_list *list = malloc(sizeof(linked_list));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insert_at_head(linked_list *list, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

void insert_at_tail(linked_list *list, int data) {
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

void delete_at_head(linked_list *list) {
    if (list->head == NULL) {
        return;
    }
    node *old_head = list->head;
    list->head = list->head->next;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    free(old_head);
}

void delete_at_tail(linked_list *list) {
    if (list->tail == NULL) {
        return;
    }
    node *old_tail = list->tail;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        node *new_tail = list->head;
        while (new_tail->next != list->tail) {
            new_tail = new_tail->next;
        }
        list->tail = new_tail;
        new_tail->next = NULL;
    }
    free(old_tail);
}

void print_linked_list(linked_list *list) {
    node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    linked_list *list = create_linked_list();

    // Insert some data into the linked list
    insert_at_head(list, 1);
    insert_at_tail(list, 2);
    insert_at_head(list, 3);
    insert_at_tail(list, 4);

    // Print the linked list
    printf("The linked list is: ");
    print_linked_list(list);

    // Delete the first element from the linked list
    delete_at_head(list);

    // Print the linked list
    printf("The linked list after deleting the first element is: ");
    print_linked_list(list);

    // Delete the last element from the linked list
    delete_at_tail(list);

    // Print the linked list
    printf("The linked list after deleting the last element is: ");
    print_linked_list(list);

    return 0;
}