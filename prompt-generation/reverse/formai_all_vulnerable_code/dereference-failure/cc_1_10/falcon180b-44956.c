//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_ELEMENT_NAME_LENGTH 50
#define MAX_ELEMENT_VALUE_LENGTH 200

typedef struct {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char value[MAX_ELEMENT_VALUE_LENGTH];
} Element;

typedef struct {
    Element *elements;
    int num_elements;
} ElementList;

ElementList *create_element_list() {
    ElementList *list = malloc(sizeof(ElementList));
    list->elements = malloc(MAX_ELEMENTS * sizeof(Element));
    list->num_elements = 0;
    return list;
}

void add_element(ElementList *list, const char *name, const char *value) {
    if (list->num_elements == MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return;
    }
    Element *element = &list->elements[list->num_elements];
    strcpy(element->name, name);
    strcpy(element->value, value);
    list->num_elements++;
}

void print_element_list(ElementList *list) {
    for (int i = 0; i < list->num_elements; i++) {
        Element *element = &list->elements[i];
        printf("Name: %s, Value: %s\n", element->name, element->value);
    }
}

void free_element_list(ElementList *list) {
    free(list->elements);
    free(list);
}

int main() {
    ElementList *list = create_element_list();
    add_element(list, "name", "John");
    add_element(list, "age", "30");
    print_element_list(list);
    free_element_list(list);
    return 0;
}