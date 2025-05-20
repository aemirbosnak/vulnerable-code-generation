//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_t;

xml_t* create_xml() {
    xml_t* xml = (xml_t*)malloc(sizeof(xml_t));
    xml->num_elements = 0;
    return xml;
}

void add_element(xml_t* xml, char* name, char* value) {
    if (xml->num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return;
    }

    element_t* element = &xml->elements[xml->num_elements];
    strncpy(element->name, name, MAX_NAME_LENGTH);
    strncpy(element->value, value, MAX_VALUE_LENGTH);
    xml->num_elements++;
}

void print_xml(xml_t* xml) {
    printf("<xml>\n");
    for (int i = 0; i < xml->num_elements; i++) {
        element_t* element = &xml->elements[i];
        printf("  <%s>%s</%s>\n", element->name, element->value, element->name);
    }
    printf("</xml>\n");
}

int main() {
    xml_t* xml = create_xml();

    add_element(xml, "name", "John");
    add_element(xml, "age", "30");
    add_element(xml, "city", "New York");

    print_xml(xml);

    free(xml);
    return 0;
}