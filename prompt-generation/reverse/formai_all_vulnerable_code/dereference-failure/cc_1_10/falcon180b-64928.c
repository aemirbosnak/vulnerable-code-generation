//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000

typedef struct {
    char *name;
    char *value;
} element_t;

typedef struct {
    int size;
    element_t *elements;
} xml_t;

void init_xml(xml_t *xml) {
    xml->size = 0;
    xml->elements = (element_t *) malloc(MAX_ELEMENTS * sizeof(element_t));
}

void add_element(xml_t *xml, char *name, char *value) {
    if (xml->size >= MAX_ELEMENTS) {
        printf("Error: XML element limit reached.\n");
        return;
    }

    xml->elements[xml->size].name = strdup(name);
    xml->elements[xml->size].value = strdup(value);
    xml->size++;
}

void print_xml(xml_t *xml) {
    for (int i = 0; i < xml->size; i++) {
        printf("<%s>%s</%s>\n", xml->elements[i].name, xml->elements[i].value, xml->elements[i].name);
    }
}

void free_xml(xml_t *xml) {
    for (int i = 0; i < xml->size; i++) {
        free(xml->elements[i].name);
        free(xml->elements[i].value);
    }
    free(xml->elements);
}

int main() {
    xml_t xml;
    init_xml(&xml);

    add_element(&xml, "name", "John");
    add_element(&xml, "age", "30");
    add_element(&xml, "city", "New York");

    print_xml(&xml);

    free_xml(&xml);

    return 0;
}