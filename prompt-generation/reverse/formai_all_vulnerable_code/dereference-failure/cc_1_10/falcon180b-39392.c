//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct element {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct element *next;
} element;

typedef struct {
    element *head;
} linked_list;

linked_list *create_list() {
    linked_list *list = (linked_list *) malloc(sizeof(linked_list));
    list->head = NULL;
    return list;
}

void add_element(linked_list *list, char *name, char *value) {
    element *new_element = (element *) malloc(sizeof(element));
    strncpy(new_element->name, name, MAX_NAME_LENGTH);
    strncpy(new_element->value, value, MAX_VALUE_LENGTH);
    new_element->next = NULL;

    if (list->head == NULL) {
        list->head = new_element;
    } else {
        element *last_element = list->head;
        while (last_element->next!= NULL) {
            last_element = last_element->next;
        }
        last_element->next = new_element;
    }
}

void print_list(linked_list *list) {
    element *current_element = list->head;
    while (current_element!= NULL) {
        printf("<%s>%s</%s>\n", current_element->name, current_element->value, current_element->name);
        current_element = current_element->next;
    }
}

int main() {
    linked_list *list = create_list();

    add_element(list, "name", "John Doe");
    add_element(list, "age", "30");
    add_element(list, "city", "New York");

    print_list(list);

    return 0;
}