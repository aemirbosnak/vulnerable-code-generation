//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000
#define MAX_ELEMENT_NAME 100
#define MAX_ELEMENT_VALUE 1000
#define MAX_ELEMENT_ATTRIBUTES 100

typedef struct {
    char name[MAX_ELEMENT_NAME];
    char value[MAX_ELEMENT_VALUE];
    int num_attributes;
    struct attribute *attributes[MAX_ELEMENT_ATTRIBUTES];
} element;

typedef struct attribute {
    char name[MAX_ELEMENT_NAME];
    char value[MAX_ELEMENT_VALUE];
} attribute;

int num_elements = 0;
element *elements[MAX_ELEMENTS];

void start_element(char *name) {
    if (num_elements < MAX_ELEMENTS) {
        element *new_element = (element*)malloc(sizeof(element));
        strcpy(new_element->name, name);
        new_element->num_attributes = 0;
        elements[num_elements++] = new_element;
    }
}

void end_element(char *name) {
    element *current_element = elements[num_elements - 1];
    strcpy(current_element->name, name);
}

void add_attribute(char *name, char *value) {
    element *current_element = elements[num_elements - 1];
    attribute *new_attribute = (attribute*)malloc(sizeof(attribute));
    strcpy(new_attribute->name, name);
    strcpy(new_attribute->value, value);
    current_element->attributes[current_element->num_attributes++] = new_attribute;
}

void start_document() {
    num_elements = 0;
}

void end_document() {
    printf("Number of elements: %d\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        element *current_element = elements[i];
        printf("Element name: %s\n", current_element->name);
        printf("Element value: %s\n", current_element->value);
        printf("Number of attributes: %d\n", current_element->num_attributes);
        for (int j = 0; j < current_element->num_attributes; j++) {
            attribute *current_attribute = current_element->attributes[j];
            printf("Attribute name: %s\n", current_attribute->name);
            printf("Attribute value: %s\n", current_attribute->value);
        }
    }
}

int main() {
    start_document();
    start_element("root");
    add_attribute("version", "1.0");
    start_element("person");
    add_attribute("id", "123");
    end_element("person");
    end_element("root");
    end_document();
    return 0;
}