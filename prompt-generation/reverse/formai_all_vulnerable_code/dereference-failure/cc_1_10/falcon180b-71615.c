//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Element;

typedef struct {
    Element *elements;
    int num_elements;
} ElementList;

ElementList *createElementList() {
    ElementList *list = (ElementList *)malloc(sizeof(ElementList));
    if (list == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    list->elements = (Element *)malloc(MAX_ELEMENTS * sizeof(Element));
    if (list->elements == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    list->num_elements = 0;
    return list;
}

void addElement(ElementList *list, char *name, char *value) {
    if (list->num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached\n");
        exit(1);
    }
    strcpy(list->elements[list->num_elements].name, name);
    strcpy(list->elements[list->num_elements].value, value);
    list->num_elements++;
}

void printElementList(ElementList *list) {
    int i;
    for (i = 0; i < list->num_elements; i++) {
        printf("%s=%s\n", list->elements[i].name, list->elements[i].value);
    }
}

void destroyElementList(ElementList *list) {
    free(list->elements);
    free(list);
}

int main() {
    ElementList *list = createElementList();
    addElement(list, "name", "John");
    addElement(list, "age", "30");
    addElement(list, "city", "New York");
    printElementList(list);
    destroyElementList(list);
    return 0;
}