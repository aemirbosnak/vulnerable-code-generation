//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN_SIZE 8

typedef struct ListNode {
    size_t length;
    char data[1];
} ListNode;

typedef struct List {
    size_t size;
    size_t capacity;
    ListNode *nodes;
} List;

List *list_new() {
    List *list = malloc(sizeof(List));
    list->size = 0;
    list->capacity = MIN_SIZE;
    list->nodes = malloc(sizeof(ListNode) * MIN_SIZE);
    return list;
}

void list_destroy(List *list) {
    free(list->nodes);
    free(list);
}

void list_resize(List *list) {
    if (list->capacity == list->size) {
        list->capacity *= 2;
        list->nodes = realloc(list->nodes, sizeof(ListNode) * list->capacity);
    }
}

ListNode *list_append(List *list, const char *str) {
    size_t old_size = list->size;

    if (list->size + strlen(str) + 1 >= list->capacity) {
        list_resize(list);
    }

    ListNode *new_node = &list->nodes[old_size];
    new_node->length = strlen(str) + 1;
    memcpy(new_node->data, str, new_node->length);
    list->size++;

    return new_node;
}

ListNode *list_pop(List *list) {
    if (list->size == 0) {
        return NULL;
    }

    ListNode *popped_node = &list->nodes[list->size - 1];
    list->size--;
    return popped_node;
}

void list_print(List *list) {
    for (size_t i = 0; i < list->size; i++) {
        printf("%.*s ", list->nodes[i].length, list->nodes[i].data);
    }
    printf("\n");
}

int main() {
    List *my_list = list_new();

    list_append(my_list, "Hello");
    list_append(my_list, "World");
    list_append(my_list, "Linked");
    list_append(my_list, "List");

    list_print(my_list);

    ListNode *popped_node = list_pop(my_list);
    if (popped_node) {
        printf("Popped: %.*s\n", popped_node->length, popped_node->data);
    }

    list_print(my_list);

    list_destroy(my_list);

    return 0;
}