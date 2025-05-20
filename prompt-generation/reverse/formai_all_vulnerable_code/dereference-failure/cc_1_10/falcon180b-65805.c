//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000
#define MAX_ELEMENT_NAME 100
#define MAX_ELEMENT_VALUE 1000

typedef struct {
    char name[MAX_ELEMENT_NAME];
    char value[MAX_ELEMENT_VALUE];
} element;

typedef struct {
    int num_elements;
    element *elements;
} xml_doc;

xml_doc *create_document() {
    xml_doc *doc = (xml_doc *) malloc(sizeof(xml_doc));
    doc->num_elements = 0;
    doc->elements = (element *) malloc(MAX_ELEMENTS * sizeof(element));
    return doc;
}

void destroy_document(xml_doc *doc) {
    free(doc->elements);
    free(doc);
}

void add_element(xml_doc *doc, char *name, char *value) {
    if (doc->num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return;
    }
    element *elem = &(doc->elements[doc->num_elements]);
    strcpy(elem->name, name);
    strcpy(elem->value, value);
    doc->num_elements++;
}

void print_document(xml_doc *doc) {
    printf("<Document>\n");
    for (int i = 0; i < doc->num_elements; i++) {
        printf("\t<%s>%s</%s>\n", doc->elements[i].name, doc->elements[i].value, doc->elements[i].name);
    }
    printf("</Document>\n");
}

int main() {
    xml_doc *doc = create_document();
    add_element(doc, "name", "John Doe");
    add_element(doc, "age", "30");
    add_element(doc, "city", "New York");
    print_document(doc);
    destroy_document(doc);
    return 0;
}