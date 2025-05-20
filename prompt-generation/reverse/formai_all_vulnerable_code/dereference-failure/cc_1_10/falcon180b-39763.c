//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

typedef struct element {
    char *name;
    char *value;
    struct element *next;
} element;

typedef struct {
    element *elements;
    int num_elements;
} xml_parser;

xml_parser *create_parser() {
    xml_parser *parser = (xml_parser *)malloc(sizeof(xml_parser));
    if (parser == NULL) {
        printf("Error: Unable to allocate memory for parser\n");
        exit(1);
    }
    parser->elements = NULL;
    parser->num_elements = 0;
    return parser;
}

void destroy_parser(xml_parser *parser) {
    element *current = parser->elements;
    while (current!= NULL) {
        element *next = current->next;
        free(current->name);
        free(current->value);
        free(current);
        current = next;
    }
    free(parser);
}

void add_element(xml_parser *parser, char *name, char *value) {
    element *new_element = (element *)malloc(sizeof(element));
    if (new_element == NULL) {
        printf("Error: Unable to allocate memory for element\n");
        exit(1);
    }
    new_element->name = strdup(name);
    new_element->value = strdup(value);
    new_element->next = NULL;
    if (parser->num_elements == MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached\n");
        exit(1);
    }
    parser->elements = (element *)realloc(parser->elements, sizeof(element) * (parser->num_elements + 1));
    parser->elements[parser->num_elements] = *new_element;
    parser->num_elements++;
}

void print_elements(xml_parser *parser) {
    element *current = parser->elements;
    while (current!= NULL) {
        printf("Name: %s, Value: %s\n", current->name, current->value);
        current = current->next;
    }
}

int main() {
    xml_parser *parser = create_parser();
    add_element(parser, "name", "John");
    add_element(parser, "age", "30");
    add_element(parser, "city", "New York");
    print_elements(parser);
    destroy_parser(parser);
    return 0;
}