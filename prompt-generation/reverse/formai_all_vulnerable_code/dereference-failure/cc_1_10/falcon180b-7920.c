//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} element_t;

typedef struct {
    int count;
    element_t *elements;
} element_list_t;

element_list_t *create_element_list() {
    element_list_t *list = (element_list_t *) malloc(sizeof(element_list_t));
    list->count = 0;
    list->elements = (element_t *) malloc(MAX_ELEMENTS * sizeof(element_t));
    return list;
}

void destroy_element_list(element_list_t *list) {
    free(list->elements);
    free(list);
}

void add_element(element_list_t *list, char *name, char *value) {
    if (list->count >= MAX_ELEMENTS) {
        printf("Error: maximum number of elements reached.\n");
        return;
    }

    strcpy(list->elements[list->count].name, name);
    strcpy(list->elements[list->count].value, value);
    list->count++;
}

void print_element_list(element_list_t *list) {
    printf("Element count: %d\n", list->count);
    for (int i = 0; i < list->count; i++) {
        printf("Name: %s\nValue: %s\n", list->elements[i].name, list->elements[i].value);
    }
}

int main() {
    element_list_t *list = create_element_list();

    add_element(list, "name", "John");
    add_element(list, "age", "30");
    add_element(list, "city", "New York");

    print_element_list(list);

    destroy_element_list(list);

    return 0;
}