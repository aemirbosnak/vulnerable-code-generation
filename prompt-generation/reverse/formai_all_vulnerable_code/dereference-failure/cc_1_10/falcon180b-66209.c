//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
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

void destroy_xml(xml_t* xml) {
    free(xml);
}

int add_element(xml_t* xml, const char* name, const char* value) {
    if (xml->num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return -1;
    }

    strncpy(xml->elements[xml->num_elements].name, name, MAX_NAME_LEN);
    strncpy(xml->elements[xml->num_elements].value, value, MAX_VALUE_LEN);

    xml->num_elements++;

    return 0;
}

int main() {
    xml_t* xml = create_xml();

    add_element(xml, "name", "John Doe");
    add_element(xml, "age", "30");
    add_element(xml, "city", "New York");

    printf("XML data:\n");
    for (int i = 0; i < xml->num_elements; i++) {
        printf("Name: %s, Value: %s\n", xml->elements[i].name, xml->elements[i].value);
    }

    destroy_xml(xml);

    return 0;
}