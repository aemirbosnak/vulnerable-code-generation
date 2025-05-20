//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* content;
} Element;

typedef struct {
    Element** elements;
    int size;
    int capacity;
} ElementList;

Element* createElement(char* name, char* content) {
    Element* element = (Element*)malloc(sizeof(Element));
    element->name = name;
    element->content = content;
    return element;
}

ElementList* createElementList() {
    ElementList* list = (ElementList*)malloc(sizeof(ElementList));
    list->elements = (Element**)malloc(sizeof(Element*) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void addElement(ElementList* list, Element* element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->elements = (Element**)realloc(list->elements, sizeof(Element*) * list->capacity);
    }
    list->elements[list->size] = element;
    list->size++;
}

void printElement(Element* element, int level) {
    printf("%*c<%s>%s</%s>\n", level * 4, ' ', element->name, element->content, element->name);
}

void printElementList(ElementList* list, int level) {
    for(int i=0;i<list->size;i++) {
        printElement(list->elements[i], level);
    }
}

void freeElement(Element* element) {
    free(element);
}

void freeElementList(ElementList* list) {
    for(int i=0;i<list->size;i++) {
        freeElement(list->elements[i]);
    }
    free(list->elements);
    free(list);
}

int main() {
    ElementList* list = createElementList();
    addElement(list, createElement("title", "XML Parser Example"));
    addElement(list, createElement("author", "John Doe"));
    addElement(list, createElement("content", "This is an example of an XML parser written in C."));
    addElement(list, createElement("date", "2021-01-01"));

    printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    printElementList(list, 0);

    freeElementList(list);

    return 0;
}