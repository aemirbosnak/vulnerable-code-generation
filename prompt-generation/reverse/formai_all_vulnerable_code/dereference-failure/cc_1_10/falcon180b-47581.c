//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char value[MAX_VALUE_LENGTH + 1];
} element_t;

typedef struct {
    int size;
    element_t *elements;
} xml_t;

xml_t *xml_parse(char *xml_string) {
    xml_t *xml = malloc(sizeof(xml_t));
    xml->size = 0;
    xml->elements = malloc(MAX_ELEMENTS * sizeof(element_t)); // Initialize with max elements

    char *token = strtok(xml_string, "<");
    while (token!= NULL) {
        element_t *element = &xml->elements[xml->size];
        strcpy(element->name, token);
        xml->size++;

        token = strtok(NULL, ">");
        if (token == NULL) {
            element->value[0] = '\0';
        } else {
            strcpy(element->value, token);
        }

        token = strtok(NULL, "<");
    }

    return xml;
}

void xml_print(xml_t *xml) {
    for (int i = 0; i < xml->size; i++) {
        element_t *element = &xml->elements[i];
        printf("<%s>%s</%s>\n", element->name, element->value, element->name);
    }
}

int main() {
    char xml_string[] =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
        "<root>"
            "<name>John</name>"
            "<age>30</age>"
        "</root>";

    xml_t *xml = xml_parse(xml_string);
    xml_print(xml);

    return 0;
}