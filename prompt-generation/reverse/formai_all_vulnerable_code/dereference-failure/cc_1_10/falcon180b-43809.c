//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
} xml_t;

xml_t *parse_xml(char *xml_string) {
    xml_t *xml = malloc(sizeof(xml_t));
    xml->num_elements = 0;

    char *token = strtok(xml_string, "<");
    while (token!= NULL) {
        element_t *element = malloc(sizeof(element_t));
        strncpy(element->name, token, MAX_NAME_LENGTH);
        strncpy(element->value, "", MAX_VALUE_LENGTH);

        char *value_start = strchr(token, '=');
        if (value_start!= NULL) {
            strncpy(element->value, value_start + 1, MAX_VALUE_LENGTH);
            *(element->value + strlen(element->value) - 1) = '\0'; // Remove newline character
        }

        xml->elements[xml->num_elements++] = *element;

        token = strtok(NULL, "<");
    }

    return xml;
}

void print_xml(xml_t *xml) {
    for (int i = 0; i < xml->num_elements; i++) {
        printf("%s=%s\n", xml->elements[i].name, xml->elements[i].value);
    }
}

int main() {
    char xml_string[] = "<name>John</name><age>30</age><city>New York</city>";
    xml_t *xml = parse_xml(xml_string);
    print_xml(xml);

    free(xml);
    return 0;
}