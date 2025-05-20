//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element;

typedef struct {
    int count;
    element elements[MAX_ELEMENTS];
} xml_parser;

void init_parser(xml_parser* parser) {
    parser->count = 0;
}

int add_element(xml_parser* parser, char* name, char* value) {
    if (parser->count >= MAX_ELEMENTS) {
        return -1;
    }

    strncpy(parser->elements[parser->count].name, name, MAX_NAME_LENGTH);
    strncpy(parser->elements[parser->count].value, value, MAX_VALUE_LENGTH);

    parser->count++;

    return 0;
}

int main() {
    xml_parser parser;
    init_parser(&parser);

    char* xml = "<root><element name=\"name1\" value=\"value1\"></element><element name=\"name2\" value=\"value2\"></element></root>";

    char* token = strtok(xml, "< >");
    while (token!= NULL) {
        if (strcmp(token, "element") == 0) {
            char* name = strtok(NULL, " ");
            char* value = strtok(NULL, " ");

            if (name!= NULL && value!= NULL) {
                add_element(&parser, name, value);
            }
        }

        token = strtok(NULL, "< >");
    }

    for (int i = 0; i < parser.count; i++) {
        printf("name: %s\nvalue: %s\n", parser.elements[i].name, parser.elements[i].value);
    }

    return 0;
}