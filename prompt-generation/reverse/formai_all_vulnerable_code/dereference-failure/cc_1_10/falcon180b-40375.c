//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: accurate
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

xml_t* parse_xml(char* xml_string) {
    xml_t* xml = malloc(sizeof(xml_t));
    memset(xml, 0, sizeof(xml_t));

    char* current_element = strtok(xml_string, "<");
    while (current_element!= NULL) {
        element_t* element = &xml->elements[xml->num_elements];
        strncpy(element->name, current_element, MAX_NAME_LEN);
        current_element = strtok(NULL, ">");
        if (current_element == NULL) {
            fprintf(stderr, "Error: Missing closing angle bracket.\n");
            exit(1);
        }
        current_element = strtok(NULL, "<");
        if (current_element == NULL) {
            fprintf(stderr, "Error: Missing opening angle bracket.\n");
            exit(1);
        }
        strncpy(element->value, current_element, MAX_VALUE_LEN);
        xml->num_elements++;
        current_element = strtok(NULL, "<");
    }

    return xml;
}

void print_xml(xml_t* xml) {
    for (int i = 0; i < xml->num_elements; i++) {
        element_t* element = &xml->elements[i];
        printf("<%s>%s</%s>\n", element->name, element->value, element->name);
    }
}

int main() {
    char xml_string[] = "<name>John</name><age>30</age><city>New York</city>";
    xml_t* xml = parse_xml(xml_string);
    print_xml(xml);

    return 0;
}