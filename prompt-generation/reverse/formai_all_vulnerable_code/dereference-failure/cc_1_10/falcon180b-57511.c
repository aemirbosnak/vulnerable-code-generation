//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_ELEMENT_LENGTH 1000

typedef struct {
    char *name;
    char *value;
} element_t;

typedef struct {
    element_t *elements;
    int element_count;
    int element_capacity;
} xml_parser_t;

void xml_parser_init(xml_parser_t *parser) {
    parser->elements = NULL;
    parser->element_count = 0;
    parser->element_capacity = 0;
}

void xml_parser_destroy(xml_parser_t *parser) {
    int i;
    for (i = 0; i < parser->element_count; i++) {
        free(parser->elements[i].name);
        free(parser->elements[i].value);
    }
    free(parser->elements);
}

void xml_parser_add_element(xml_parser_t *parser, char *name, char *value) {
    if (parser->element_count >= parser->element_capacity) {
        parser->element_capacity += MAX_ELEMENTS;
        parser->elements = realloc(parser->elements, parser->element_capacity * sizeof(element_t));
    }

    parser->elements[parser->element_count].name = strdup(name);
    parser->elements[parser->element_count].value = strdup(value);

    parser->element_count++;
}

void xml_parser_print_elements(xml_parser_t *parser) {
    int i;
    for (i = 0; i < parser->element_count; i++) {
        printf("Name: %s, Value: %s\n", parser->elements[i].name, parser->elements[i].value);
    }
}

int main() {
    xml_parser_t parser;
    xml_parser_init(&parser);

    char *xml_data = "<root><element name=\"name1\" value=\"value1\"/><element name=\"name2\" value=\"value2\"/><element name=\"name3\" value=\"value3\"/></root>";

    char *token = strtok(xml_data, "<");
    while (token!= NULL) {
        if (strcmp(token, "element") == 0) {
            char *name_token = strtok(NULL, " ");
            char *value_token = strtok(NULL, ">");

            xml_parser_add_element(&parser, name_token, value_token);
        }

        token = strtok(NULL, ">");
    }

    xml_parser_print_elements(&parser);

    xml_parser_destroy(&parser);

    return 0;
}