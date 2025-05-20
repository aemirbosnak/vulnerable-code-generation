//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_parser_t;

xml_parser_t* create_parser() {
    xml_parser_t* parser = (xml_parser_t*)malloc(sizeof(xml_parser_t));
    parser->num_elements = 0;
    return parser;
}

void destroy_parser(xml_parser_t* parser) {
    free(parser);
}

void start_element(xml_parser_t* parser, const char* name, const char* value) {
    if (parser->num_elements >= MAX_ELEMENTS) {
        printf("Error: Too many elements.\n");
        return;
    }

    strcpy(parser->elements[parser->num_elements].name, name);
    strcpy(parser->elements[parser->num_elements].value, value);
    parser->num_elements++;
}

void end_element(xml_parser_t* parser) {
    if (parser->num_elements <= 0) {
        printf("Error: No elements found.\n");
        return;
    }

    parser->num_elements--;
}

void print_elements(xml_parser_t* parser) {
    if (parser->num_elements <= 0) {
        printf("No elements found.\n");
        return;
    }

    for (int i = 0; i < parser->num_elements; i++) {
        printf("Name: %s\nValue: %s\n", parser->elements[i].name, parser->elements[i].value);
    }
}

int main() {
    xml_parser_t* parser = create_parser();

    start_element(parser, "example", "value");
    start_element(parser, "child", "child_value");
    end_element(parser);
    start_element(parser, "another_child", "another_child_value");
    end_element(parser);

    print_elements(parser);

    destroy_parser(parser);

    return 0;
}