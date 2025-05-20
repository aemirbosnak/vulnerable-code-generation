//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    void* data;
    struct _node* next;
} node;

typedef struct {
    node* head;
    node* tail;
} linked_list;

void linked_list_init(linked_list* list) {
    list->head = list->tail = NULL;
}

void linked_list_push_front(linked_list* list, void* data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

void linked_list_push_back(linked_list* list, void* data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail != NULL) {
        list->tail->next = new_node;
    }
    list->tail = new_node;
    if (list->head == NULL) {
        list->head = new_node;
    }
}

void linked_list_pop_front(linked_list* list) {
    if (list->head != NULL) {
        node* old_head = list->head;
        list->head = list->head->next;
        free(old_head);
        if (list->head == NULL) {
            list->tail = NULL;
        }
    }
}

void linked_list_pop_back(linked_list* list) {
    if (list->tail != NULL) {
        node* old_tail = list->tail;
        if (list->head == list->tail) {
            list->head = list->tail = NULL;
        } else {
            node* new_tail = list->head;
            while (new_tail->next != list->tail) {
                new_tail = new_tail->next;
            }
            list->tail = new_tail;
            list->tail->next = NULL;
        }
        free(old_tail);
    }
}

void linked_list_free(linked_list* list) {
    while (list->head != NULL) {
        linked_list_pop_front(list);
    }
}

int main() {
    linked_list list;
    linked_list_init(&list);

    // Push some data onto the list
    linked_list_push_front(&list, "Hello");
    linked_list_push_back(&list, "World");

    // Print the list
    node* current = list.head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }

    // Pop some data off the list
    linked_list_pop_front(&list);
    linked_list_pop_back(&list);

    // Free the list
    linked_list_free(&list);

    return 0;
}