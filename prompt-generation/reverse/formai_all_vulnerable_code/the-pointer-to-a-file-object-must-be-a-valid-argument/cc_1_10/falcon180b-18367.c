//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element_t;

typedef struct {
    int size;
    element_t elements[MAX_ELEMENTS];
} xml_parser_t;

xml_parser_t* create_parser() {
    xml_parser_t* parser = (xml_parser_t*)malloc(sizeof(xml_parser_t));
    parser->size = 0;
    return parser;
}

void destroy_parser(xml_parser_t* parser) {
    free(parser);
}

int add_element(xml_parser_t* parser, char* name, char* value) {
    if (parser->size >= MAX_ELEMENTS) {
        return -1;
    }

    strcpy(parser->elements[parser->size].name, name);
    strcpy(parser->elements[parser->size].value, value);
    parser->size++;

    return 0;
}

int main() {
    FILE* file = fopen("example.xml", "r");
    char line[MAX_VALUE_LENGTH];
    xml_parser_t* parser = create_parser();

    while (fgets(line, MAX_VALUE_LENGTH, file)!= NULL) {
        char* name = strtok(line, " ");
        char* value = strtok(NULL, " ");

        if (name == NULL || value == NULL) {
            printf("Invalid line: %s\n", line);
            continue;
        }

        add_element(parser, name, value);
    }

    fclose(file);

    for (int i = 0; i < parser->size; i++) {
        printf("Name: %s\nValue: %s\n", parser->elements[i].name, parser->elements[i].value);
    }

    destroy_parser(parser);

    return 0;
}