//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LIST_SIZE 10
#define ELEMENT_SIZE 50

typedef struct node {
    char data[ELEMENT_SIZE];
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
    size_t size;
} List;

List *list_create() {
    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

Node *node_create(const char *data) {
    Node *node = malloc(sizeof(Node));
    strncpy(node->data, data, ELEMENT_SIZE - 1);
    node->next = NULL;
    return node;
}

void list_append(List *list, const char *data) {
    Node *new_node = node_create(data);

    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

void list_print(const List *list) {
    Node *current = list->head;

    printf("List size: %ld\n", list->size);

    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

bool list_is_empty(const List *list) {
    return list->size == 0;
}

void list_destroy(List *list) {
    Node *current = list->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

int main() {
    List *list = list_create();

    list_append(list, "Apple");
    list_append(list, "Banana");
    list_append(list, "Cherry");
    list_append(list, "Durian");
    list_append(list, "Elderberry");

    list_print(list);

    if (list_is_empty(list)) {
        printf("List is empty\n");
    } else {
        printf("List is not empty\n");
    }

    list_destroy(list);

    return 0;
}