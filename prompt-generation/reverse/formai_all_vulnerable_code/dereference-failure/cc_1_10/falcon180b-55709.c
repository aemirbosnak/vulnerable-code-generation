//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 200

typedef struct {
    char* name;
    char* value;
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
        if (xml->num_elements >= MAX_ELEMENTS) {
            printf("Error: Maximum number of elements exceeded.\n");
            exit(1);
        }
        element_t* element = &(xml->elements[xml->num_elements]);
        strcpy(element->name, current_element);
        current_element = strtok(NULL, ">");
        if (current_element == NULL) {
            printf("Error: Missing closing tag.\n");
            exit(1);
        }
        current_element = strtok(NULL, "<");
        if (current_element == NULL) {
            printf("Error: Missing value.\n");
            exit(1);
        }
        strcpy(element->value, current_element);
        xml->num_elements++;
        current_element = strtok(NULL, "<");
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