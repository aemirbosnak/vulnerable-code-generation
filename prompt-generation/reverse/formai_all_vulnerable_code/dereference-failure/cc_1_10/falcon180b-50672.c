//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_t;

xml_t* parse_xml(char* xml_string) {
    xml_t* xml = (xml_t*)malloc(sizeof(xml_t));
    xml->num_elements = 0;

    char* current_element = strtok(xml_string, "<");
    while (current_element!= NULL) {
        element_t* new_element = (element_t*)malloc(sizeof(element_t));
        strcpy(new_element->name, current_element);
        current_element = strtok(NULL, ">");
        if (current_element!= NULL) {
            strcpy(new_element->value, current_element);
        } else {
            strcpy(new_element->value, "");
        }
        xml->elements[xml->num_elements++] = *new_element;
    }

    return xml;
}

void print_xml(xml_t* xml) {
    for (int i = 0; i < xml->num_elements; i++) {
        printf("<%s>%s</%s>\n", xml->elements[i].name, xml->elements[i].value, xml->elements[i].name);
    }
}

int main() {
    char* xml_string = "<name>John</name><age>30</age><city>New York</city>";
    xml_t* xml = parse_xml(xml_string);
    print_xml(xml);
    free(xml);
    return 0;
}