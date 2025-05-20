//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define LIST_SIZE 10
#define ELEMENT_SIZE 50

typedef struct Node {
    void* data;
    size_t size;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    size_t size;
} LinkedList;

LinkedList list_create() {
    LinkedList list = {NULL, NULL, 0};
    return list;
}

void list_destroy(LinkedList* list) {
    if (list->size == 0) return;

    Node* current = list->head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    list->head = list->tail = NULL;
    list->size = 0;
}

bool list_is_empty(const LinkedList* list) {
    return list->size == 0;
}

size_t list_size(const LinkedList* list) {
    return list->size;
}

Node* list_node_create(const void* data, size_t size) {
    Node* node = (Node*) calloc(1, sizeof(Node));
    node->data = malloc(size);
    memcpy(node->data, data, size);
    node->size = size;
    node->next = NULL;
    return node;
}

bool list_add(LinkedList* list, const void* data, size_t size) {
    Node* new_node = list_node_create(data, size);

    if (new_node == NULL) return false;

    if (list_is_empty(list)) {
        list->head = list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
    return true;
}

void list_print(const LinkedList* list) {
    Node* current = list->head;

    printf("List (%zu elements):\n", list->size);
    while (current != NULL) {
        printf("| %p | %p | %p | %p | %s |\n", current, current->data, current->size, current->next, current->data ? (char*) current->data : "NULL");
        current = current->next;
    }
}

int main() {
    LinkedList list = list_create();

    if (list_add(&list, "Hello", 6)) {}
    if (list_add(&list, "World", 5)) {}
    if (list_add(&list, "Linked", 7)) {}
    if (list_add(&list, "List", 5)) {}

    list_print(&list);

    list_destroy(&list);

    return 0;
}