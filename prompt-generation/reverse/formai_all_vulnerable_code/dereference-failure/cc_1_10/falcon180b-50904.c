//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 200

typedef struct {
    char *name;
    char *value;
} element_t;

typedef struct {
    element_t elements[MAX_ELEMENTS];
    int num_elements;
} xml_t;

void init_xml(xml_t *xml) {
    xml->num_elements = 0;
}

void add_element(xml_t *xml, char *name, char *value) {
    if (xml->num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return;
    }

    element_t *new_element = (element_t *)malloc(sizeof(element_t));
    new_element->name = strdup(name);
    new_element->value = strdup(value);

    xml->elements[xml->num_elements] = *new_element;
    xml->num_elements++;
}

void print_xml(xml_t *xml) {
    printf("<xml>\n");

    for (int i = 0; i < xml->num_elements; i++) {
        element_t *element = &xml->elements[i];
        printf("  <%s>%s</%s>\n", element->name, element->value, element->name);
    }

    printf("</xml>\n");
}

int main() {
    xml_t xml;
    init_xml(&xml);

    add_element(&xml, "name", "John Doe");
    add_element(&xml, "age", "30");
    add_element(&xml, "city", "New York");

    print_xml(&xml);

    return 0;
}