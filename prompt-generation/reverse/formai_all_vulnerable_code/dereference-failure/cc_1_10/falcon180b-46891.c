//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct element_s {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_parser_t;

xml_parser_t* xml_parser_create() {
    xml_parser_t* parser = (xml_parser_t*)malloc(sizeof(xml_parser_t));
    parser->num_elements = 0;
    return parser;
}

void xml_parser_destroy(xml_parser_t* parser) {
    free(parser);
}

void xml_parser_add_element(xml_parser_t* parser, const char* name, const char* value) {
    if (parser->num_elements >= MAX_ELEMENTS) {
        printf("Error: too many elements\n");
        return;
    }

    element_t* element = &parser->elements[parser->num_elements];
    strncpy(element->name, name, MAX_NAME_LEN);
    strncpy(element->value, value, MAX_VALUE_LEN);

    parser->num_elements++;
}

void xml_parser_print_elements(xml_parser_t* parser) {
    for (int i = 0; i < parser->num_elements; i++) {
        element_t* element = &parser->elements[i];
        printf("Name: %s, Value: %s\n", element->name, element->value);
    }
}

int main() {
    xml_parser_t* parser = xml_parser_create();

    xml_parser_add_element(parser, "name", "John Doe");
    xml_parser_add_element(parser, "age", "30");
    xml_parser_add_element(parser, "city", "New York");

    xml_parser_print_elements(parser);

    xml_parser_destroy(parser);

    return 0;
}