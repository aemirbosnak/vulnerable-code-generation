//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_ELEMENT_SIZE 1000

typedef struct {
    char *name;
    char *value;
    struct element *next;
} element;

typedef struct {
    element *head;
    int count;
} element_list;

element_list *create_list() {
    element_list *list = (element_list *) malloc(sizeof(element_list));
    list->head = NULL;
    list->count = 0;
    return list;
}

void add_element(element_list *list, char *name, char *value) {
    element *new_element = (element *) malloc(sizeof(element));
    new_element->name = strdup(name);
    new_element->value = strdup(value);
    new_element->next = NULL;

    if (list->head == NULL) {
        list->head = new_element;
    } else {
        element *current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_element;
    }

    list->count++;
}

void print_list(element_list *list) {
    element *current = list->head;
    while (current!= NULL) {
        printf("Name: %s, Value: %s\n", current->name, current->value);
        current = current->next;
    }
}

void destroy_list(element_list *list) {
    element *current = list->head;
    while (current!= NULL) {
        element *temp = current;
        current = current->next;
        free(temp->name);
        free(temp->value);
        free(temp);
    }
    free(list);
}

int main() {
    element_list *list = create_list();

    add_element(list, "name", "John");
    add_element(list, "age", "30");
    add_element(list, "city", "New York");

    print_list(list);

    destroy_list(list);

    return 0;
}