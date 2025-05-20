//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct linked_list {
    struct node *head;
    int size;
} linked_list;

linked_list *create_linked_list() {
    linked_list *list = (linked_list *)malloc(sizeof(linked_list));
    list->head = NULL;
    list->size = 0;
    return list;
}

void insert_at_beginning(linked_list *list, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void insert_at_end(linked_list *list, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        node *current_node = list->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    list->size++;
}

void insert_at_index(linked_list *list, int index, int data) {
    if (index < 0 || index > list->size) {
        printf("Invalid index\n");
        return;
    }

    if (index == 0) {
        insert_at_beginning(list, data);
    } else {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;

        node *current_node = list->head;
        for (int i = 0; i < index - 1; i++) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
        list->size++;
    }
}

void delete_at_beginning(linked_list *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

void delete_at_end(linked_list *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        list->size--;
        return;
    }

    node *current_node = list->head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }
    free(current_node->next);
    current_node->next = NULL;
    list->size--;
}

void delete_at_index(linked_list *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return;
    }

    if (index == 0) {
        delete_at_beginning(list);
    } else {
        node *current_node = list->head;
        for (int i = 0; i < index - 1; i++) {
            current_node = current_node->next;
        }
        node *temp = current_node->next;
        current_node->next = current_node->next->next;
        free(temp);
        list->size--;
    }
}

void print_linked_list(linked_list *list) {
    node *current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    linked_list *list = create_linked_list();

    // Inserting elements into the linked list
    for (int i = 0; i < 10; i++) {
        insert_at_end(list, i);
    }

    // Printing the linked list
    printf("Original linked list: ");
    print_linked_list(list);

    // Deleting elements from the linked list
    delete_at_beginning(list);
    delete_at_end(list);
    delete_at_index(list, 3);

    // Printing the linked list
    printf("Modified linked list: ");
    print_linked_list(list);

    // Inserting elements into the linked list at different positions
    insert_at_beginning(list, 10);
    insert_at_index(list, 3, 20);
    insert_at_end(list, 30);

    // Printing the linked list
    printf("Modified linked list: ");
    print_linked_list(list);

    return 0;
}