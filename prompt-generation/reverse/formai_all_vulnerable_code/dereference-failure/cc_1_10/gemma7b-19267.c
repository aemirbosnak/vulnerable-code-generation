//Gemma-7B DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct {
    char name[MAX_BUFFER_SIZE];
    int id;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
} linked_list;

linked_list* create_list() {
    linked_list* list = malloc(sizeof(linked_list));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_node(linked_list* list, char* name, int id) {
    node* new_node = malloc(sizeof(node));
    strcpy(new_node->name, name);
    new_node->id = id;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

int main() {
    linked_list* my_list = create_list();

    add_node(my_list, "Bob", 1);
    add_node(my_list, "Alice", 2);
    add_node(my_list, "Tom", 3);
    add_node(my_list, "Jerry", 4);

    node* current_node = my_list->head;

    while (current_node) {
        printf("Name: %s, ID: %d\n", current_node->name, current_node->id);
        current_node = current_node->next;
    }

    return 0;
}