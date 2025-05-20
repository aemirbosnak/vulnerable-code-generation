//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct list_node {
    char *name;
    struct list_node *next;
};

struct list {
    struct list_node *head;
    struct list_node *tail;
    int size;
};

struct list *create_list() {
    struct list *new_list = (struct list *)malloc(sizeof(struct list));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

void append_to_list(struct list *list, char *name) {
    struct list_node *new_node = (struct list_node *)malloc(sizeof(struct list_node));
    new_node->name = name;
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

void print_list(struct list *list) {
    struct list_node *current = list->head;
    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    struct list *list = create_list();

    append_to_list(list, "Alice");
    append_to_list(list, "Bob");
    append_to_list(list, "Charlie");

    print_list(list);

    return 0;
}