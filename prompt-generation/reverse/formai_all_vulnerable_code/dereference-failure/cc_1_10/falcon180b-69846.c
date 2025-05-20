//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

typedef struct {
    char name[20];
    char value[100];
} element;

typedef struct {
    element *elements;
    int count;
} xml_parser;

void create_parser(xml_parser *parser) {
    parser->elements = (element *) malloc(MAX_ELEMENTS * sizeof(element));
    parser->count = 0;
}

void destroy_parser(xml_parser *parser) {
    free(parser->elements);
}

void add_element(xml_parser *parser, char *name, char *value) {
    if (parser->count >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements exceeded.\n");
        return;
    }

    strcpy(parser->elements[parser->count].name, name);
    strcpy(parser->elements[parser->count].value, value);
    parser->count++;
}

void print_parser(xml_parser *parser) {
    int i;

    for (i = 0; i < parser->count; i++) {
        printf("Name: %s\nValue: %s\n", parser->elements[i].name, parser->elements[i].value);
    }
}

int main() {
    xml_parser parser;
    char *xml = "<root>\n\t<element name=\"name\">John</element>\n\t<element name=\"age\">30</element>\n</root>";
    char *token;
    int i = 0;

    create_parser(&parser);

    token = strtok(xml, "\n");

    while (token!= NULL) {
        if (strstr(token, "<element")!= NULL) {
            token = strtok(NULL, ">");
            token = strtok(NULL, " ");

            while (token!= NULL && strcmp(token, "/")!= 0) {
                if (strstr(token, "name")!= NULL) {
                    token = strtok(NULL, " ");
                    add_element(&parser, "name", token);
                } else if (strstr(token, "age")!= NULL) {
                    token = strtok(NULL, " ");
                    add_element(&parser, "age", token);
                }

                token = strtok(NULL, " ");
            }
        }

        token = strtok(NULL, "\n");
    }

    print_parser(&parser);

    destroy_parser(&parser);

    return 0;
}