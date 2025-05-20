//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element_t;

typedef struct {
    element_t *elements;
    int num_elements;
} xml_t;

xml_t *xml_create(void) {
    xml_t *xml = malloc(sizeof(xml_t));
    xml->elements = malloc(MAX_ELEMENTS * sizeof(element_t));
    xml->num_elements = 0;
    return xml;
}

void xml_destroy(xml_t *xml) {
    free(xml->elements);
    free(xml);
}

void xml_add_element(xml_t *xml, const char *name, const char *value) {
    if (xml->num_elements >= MAX_ELEMENTS) {
        fprintf(stderr, "Error: Too many elements.\n");
        return;
    }

    element_t *element = &xml->elements[xml->num_elements];
    strncpy(element->name, name, MAX_NAME_LENGTH);
    strncpy(element->value, value, MAX_VALUE_LENGTH);
    xml->num_elements++;
}

void xml_print(const xml_t *xml) {
    for (int i = 0; i < xml->num_elements; i++) {
        element_t element = xml->elements[i];
        printf("<%s>%s</%s>\n", element.name, element.value, element.name);
    }
}

int main(int argc, char *argv[]) {
    xml_t *xml = xml_create();

    xml_add_element(xml, "name", "John Doe");
    xml_add_element(xml, "age", "30");
    xml_add_element(xml, "address", "123 Main St");

    xml_print(xml);

    xml_destroy(xml);

    return 0;
}