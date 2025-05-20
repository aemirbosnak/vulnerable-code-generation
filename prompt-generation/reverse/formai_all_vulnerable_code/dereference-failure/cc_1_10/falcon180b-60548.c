//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
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

xml_t* parse_xml(char* xml_string) {
    xml_t* xml = (xml_t*)malloc(sizeof(xml_t));
    memset(xml, 0, sizeof(xml_t));

    char* current_element = strtok(xml_string, "<");
    while (current_element!= NULL) {
        if (xml->num_elements >= MAX_ELEMENTS) {
            printf("Error: Too many elements\n");
            free(xml);
            return NULL;
        }

        element_t* element = &xml->elements[xml->num_elements];
        strncpy(element->name, current_element, MAX_NAME_LENGTH);
        current_element = strtok(NULL, ">");

        if (current_element == NULL) {
            printf("Error: Missing closing bracket\n");
            free(xml);
            return NULL;
        }

        current_element = strtok(NULL, "<");
        while (current_element!= NULL && strcmp(current_element, "/")!= 0) {
            strncat(element->value, current_element, MAX_VALUE_LENGTH);
            current_element = strtok(NULL, ">");
        }

        xml->num_elements++;
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

    if (xml!= NULL) {
        print_xml(xml);
        free(xml);
    }

    return 0;
}