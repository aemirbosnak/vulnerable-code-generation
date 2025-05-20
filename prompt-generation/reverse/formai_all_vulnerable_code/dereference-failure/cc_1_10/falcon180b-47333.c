//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000

typedef struct {
    char *name;
    char *value;
    struct element *next;
} element;

typedef struct {
    element *head;
} element_list;

element_list *create_element_list() {
    element_list *list = (element_list *)malloc(sizeof(element_list));
    list->head = NULL;
    return list;
}

void add_element(element_list *list, char *name, char *value) {
    element *current = list->head;
    element *new_element = (element *)malloc(sizeof(element));
    new_element->name = strdup(name);
    new_element->value = strdup(value);
    new_element->next = NULL;

    if (list->head == NULL) {
        list->head = new_element;
        return;
    }

    while (current->next!= NULL) {
        current = current->next;
    }

    current->next = new_element;
}

void print_element_list(element_list *list) {
    element *current = list->head;

    while (current!= NULL) {
        printf("Name: %s\nValue: %s\n", current->name, current->value);
        current = current->next;
    }
}

void destroy_element_list(element_list *list) {
    element *current = list->head;
    element *next;

    while (current!= NULL) {
        next = current->next;
        free(current->name);
        free(current->value);
        free(current);
        current = next;
    }

    free(list);
}

int main() {
    element_list *list = create_element_list();

    add_element(list, "name", "John Doe");
    add_element(list, "age", "30");
    add_element(list, "city", "New York");

    print_element_list(list);

    destroy_element_list(list);

    return 0;
}