//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_ELEMENT_NAME_LENGTH 100
#define MAX_ELEMENT_VALUE_LENGTH 1000

typedef struct {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char value[MAX_ELEMENT_VALUE_LENGTH];
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_t;

xml_t* parse_xml(char* xml_string) {
    xml_t* xml = malloc(sizeof(xml_t));
    if (xml == NULL) {
        printf("Error: Could not allocate memory for XML parser.\n");
        exit(1);
    }
    xml->num_elements = 0;
    char* current_element = strtok(xml_string, "<");
    while (current_element!= NULL) {
        if (xml->num_elements >= MAX_ELEMENTS) {
            printf("Error: XML contains too many elements.\n");
            exit(1);
        }
        element_t* element = &(xml->elements[xml->num_elements]);
        strcpy(element->name, current_element);
        current_element = strtok(NULL, ">");
        if (current_element == NULL) {
            printf("Error: Invalid XML syntax.\n");
            exit(1);
        }
        current_element = strtok(current_element, "<");
        if (current_element == NULL) {
            printf("Error: Invalid XML syntax.\n");
            exit(1);
        }
        strcpy(element->value, current_element);
        xml->num_elements++;
        current_element = strtok(NULL, ">");
    }
    return xml;
}

void print_xml(xml_t* xml) {
    for (int i = 0; i < xml->num_elements; i++) {
        element_t* element = &(xml->elements[i]);
        printf("<%s>%s</%s>\n", element->name, element->value, element->name);
    }
}

int main() {
    char* xml_string = "<person name=\"John\" age=\"25\" />";
    xml_t* xml = parse_xml(xml_string);
    print_xml(xml);
    free(xml);
    return 0;
}