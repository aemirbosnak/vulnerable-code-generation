//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct linked_list {
    node *head;
    node *tail;
    int size;
} linked_list;

linked_list *create_linked_list() {
    linked_list *list = (linked_list *)malloc(sizeof(linked_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void insert_at_beginning(linked_list *list, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->size == 0) {
        list->tail = new_node;
    }
    list->size++;
}

void insert_at_end(linked_list *list, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void insert_at_index(linked_list *list, int index, int data) {
    if (index == 0) {
        insert_at_beginning(list, data);
    } else if (index == list->size) {
        insert_at_end(list, data);
    } else {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        list->size++;
    }
}

void delete_at_beginning(linked_list *list) {
    if (list->size == 0) {
        return;
    }
    node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
    if (list->size == 0) {
        list->tail = NULL;
    }
}

void delete_at_end(linked_list *list) {
    if (list->size == 0) {
        return;
    }
    node *current = list->head;
    for (int i = 0; i < list->size - 2; i++) {
        current = current->next;
    }
    node *temp = list->tail;
    current->next = NULL;
    list->tail = current;
    free(temp);
    list->size--;
}

void delete_at_index(linked_list *list, int index) {
    if (index == 0) {
        delete_at_beginning(list);
    } else if (index == list->size - 1) {
        delete_at_end(list);
    } else {
        node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        node *temp = current->next;
        current->next = current->next->next;
        free(temp);
        list->size--;
    }
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
    insert_at_beginning(list, 1);
    insert_at_end(list, 2);
    insert_at_index(list, 1, 3);
    print_linked_list(list);  // Output: 1 3 2
    delete_at_beginning(list);
    delete_at_end(list);
    delete_at_index(list, 0);
    print_linked_list(list);  // Output: 3
    return 0;
}