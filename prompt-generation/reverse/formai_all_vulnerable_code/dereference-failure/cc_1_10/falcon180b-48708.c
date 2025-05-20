//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: systematic
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
    element_t *elements;
    int num_elements;
} xml_t;

xml_t *parse_xml(char *xml_string) {
    xml_t *xml = (xml_t *)malloc(sizeof(xml_t));
    xml->elements = (element_t *)malloc(MAX_ELEMENTS * sizeof(element_t));
    xml->num_elements = 0;

    char *token = strtok(xml_string, "<");
    while (token!= NULL) {
        element_t *element = &(xml->elements[xml->num_elements]);
        strncpy(element->name, token, MAX_NAME_LENGTH);
        element->name[MAX_NAME_LENGTH - 1] = '\0';

        token = strtok(NULL, ">");
        if (token == NULL) {
            printf("Error: Missing closing tag for element '%s'\n", element->name);
            exit(1);
        }

        token = strtok(token, "<");
        if (token == NULL) {
            strncpy(element->value, "", MAX_VALUE_LENGTH);
        } else {
            strncpy(element->value, token, MAX_VALUE_LENGTH);
            element->value[MAX_VALUE_LENGTH - 1] = '\0';
        }

        xml->num_elements++;
        token = strtok(NULL, "<");
    }

    return xml;
}

void print_xml(xml_t *xml) {
    for (int i = 0; i < xml->num_elements; i++) {
        element_t *element = &(xml->elements[i]);
        printf("<%s>%s</%s>\n", element->name, element->value, element->name);
    }
}

int main() {
    char xml_string[] = "<root><child1>value1</child1><child2>value2</child2></root>";
    xml_t *xml = parse_xml(xml_string);
    print_xml(xml);

    free(xml->elements);
    free(xml);
    return 0;
}