//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 1000

typedef struct {
    char *name;
    char *value;
} element_t;

typedef struct {
    element_t elements[MAX_ELEMENTS];
    int num_elements;
} xml_t;

xml_t *xml_create() {
    xml_t *xml = (xml_t *)malloc(sizeof(xml_t));
    xml->num_elements = 0;
    return xml;
}

void xml_add_element(xml_t *xml, const char *name, const char *value) {
    if (xml->num_elements >= MAX_ELEMENTS) {
        fprintf(stderr, "Error: XML element limit reached\n");
        exit(1);
    }

    element_t *elem = &xml->elements[xml->num_elements];
    elem->name = strdup(name);
    elem->value = strdup(value);

    xml->num_elements++;
}

void xml_print(const xml_t *xml) {
    for (int i = 0; i < xml->num_elements; i++) {
        element_t *elem = &xml->elements[i];
        printf("<%s>%s</%s>\n", elem->name, elem->value, elem->name);
    }
}

int main() {
    xml_t *xml = xml_create();

    xml_add_element(xml, "name", "John Doe");
    xml_add_element(xml, "age", "30");
    xml_add_element(xml, "city", "New York");

    xml_print(xml);

    return 0;
}