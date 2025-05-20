//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void end_element(xml_parser_t* parser, const char* name) {
    int i;
    for (i = 0; i < parser->num_elements; i++) {
        if (strcmp(parser->elements[i].name, name) == 0) {
            parser->num_elements--;
            memmove(&parser->elements[i], &parser->elements[i+1], sizeof(element_t) * (parser->num_elements - i));
            break;
        }
    }
}

void characters(xml_parser_t* parser, const char* str) {
    int i;
    for (i = 0; i < parser->num_elements; i++) {
        if (parser->elements[i].value[0] == '\0') {
            strcpy(parser->elements[i].value, str);
            break;
        }
    }
}

void print_elements(xml_parser_t* parser) {
    int i;
    for (i = 0; i < parser->num_elements; i++) {
        printf("Name: %s\nValue: %s\n", parser->elements[i].name, parser->elements[i].value);
    }
}

int main() {
    xml_parser_t* parser = create_parser();
    start_element(parser, "root", "");
    start_element(parser, "child1", "value1");
    characters(parser, "Some text here");
    end_element(parser, "child1");
    start_element(parser, "child2", "value2");
    end_element(parser, "child2");
    end_element(parser, "root");
    print_elements(parser);
    destroy_parser(parser);
    return 0;
}