//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_parser_t;

xml_parser_t *create_parser() {
    xml_parser_t *parser = (xml_parser_t *)malloc(sizeof(xml_parser_t));
    parser->num_elements = 0;
    return parser;
}

void destroy_parser(xml_parser_t *parser) {
    free(parser);
}

int start_element(xml_parser_t *parser, const char *name, const char *value) {
    if (parser->num_elements >= MAX_ELEMENTS) {
        fprintf(stderr, "Error: too many elements\n");
        return -1;
    }

    strncpy(parser->elements[parser->num_elements].name, name, MAX_NAME_LENGTH);
    strncpy(parser->elements[parser->num_elements].value, value, MAX_VALUE_LENGTH);

    parser->num_elements++;

    return 0;
}

int end_element(xml_parser_t *parser, const char *name) {
    if (parser->num_elements <= 0) {
        fprintf(stderr, "Error: unexpected end element\n");
        return -1;
    }

    if (strcmp(parser->elements[parser->num_elements - 1].name, name)!= 0) {
        fprintf(stderr, "Error: mismatched end element\n");
        return -1;
    }

    parser->num_elements--;

    return 0;
}

void print_parser_state(xml_parser_t *parser) {
    printf("Num elements: %d\n", parser->num_elements);

    for (int i = 0; i < parser->num_elements; i++) {
        printf("Name: %s, Value: %s\n", parser->elements[i].name, parser->elements[i].value);
    }
}

int main() {
    xml_parser_t *parser = create_parser();

    start_element(parser, "root", "");
    start_element(parser, "child1", "value1");
    start_element(parser, "child2", "value2");
    end_element(parser, "child1");
    end_element(parser, "child2");
    end_element(parser, "root");

    print_parser_state(parser);

    destroy_parser(parser);

    return 0;
}