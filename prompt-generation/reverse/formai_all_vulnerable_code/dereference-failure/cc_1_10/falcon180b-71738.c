//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 1000

typedef struct {
    char *name;
    char *value;
} element_t;

typedef struct {
    int count;
    element_t *elements;
} xml_t;

xml_t *xml_create(void) {
    xml_t *xml = malloc(sizeof(xml_t));
    if (xml == NULL) {
        printf("Error: failed to allocate memory for XML parser.\n");
        exit(1);
    }

    xml->count = 0;
    xml->elements = malloc(MAX_ELEMENTS * sizeof(element_t));
    if (xml->elements == NULL) {
        printf("Error: failed to allocate memory for XML elements.\n");
        exit(1);
    }

    return xml;
}

void xml_destroy(xml_t *xml) {
    free(xml->elements);
    free(xml);
}

void xml_add_element(xml_t *xml, const char *name, const char *value) {
    if (xml->count >= MAX_ELEMENTS) {
        printf("Error: maximum number of elements reached.\n");
        exit(1);
    }

    element_t *element = malloc(sizeof(element_t));
    if (element == NULL) {
        printf("Error: failed to allocate memory for XML element.\n");
        exit(1);
    }

    element->name = strdup(name);
    element->value = strdup(value);

    xml->elements[xml->count++] = *element;
    free(element);
}

void xml_print(const xml_t *xml) {
    if (xml == NULL) {
        printf("XML data is NULL.\n");
        return;
    }

    printf("XML Data:\n");
    for (int i = 0; i < xml->count; i++) {
        printf("  Element %d:\n", i + 1);
        printf("    Name: %s\n", xml->elements[i].name);
        printf("    Value: %s\n", xml->elements[i].value);
    }
}

int main() {
    xml_t *xml = xml_create();

    xml_add_element(xml, "name", "John Doe");
    xml_add_element(xml, "age", "30");
    xml_add_element(xml, "gender", "Male");

    xml_print(xml);

    xml_destroy(xml);

    return 0;
}