//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char *name;
    char *value;
} element_t;

typedef struct {
    element_t *elements;
    int num_elements;
} xml_t;

xml_t *parse_xml(char *xml_string) {
    xml_t *root = malloc(sizeof(xml_t));
    root->elements = malloc(sizeof(element_t) * MAX_ELEMENTS);
    root->num_elements = 0;

    char *current_element = strtok(xml_string, "<");
    while (current_element!= NULL) {
        char *element_name = strtok(current_element, ">");
        if (element_name == NULL) break;

        char *value = strtok(NULL, ">");
        if (value == NULL) break;

        element_t *new_element = malloc(sizeof(element_t));
        new_element->name = strdup(element_name);
        new_element->value = strdup(value);

        root->elements[root->num_elements++] = *new_element;
    }

    return root;
}

void print_xml(xml_t *root) {
    for (int i = 0; i < root->num_elements; i++) {
        printf("<%s>%s</%s>\n", root->elements[i].name, root->elements[i].value, root->elements[i].name);
    }
}

int main() {
    char *xml_string = "<root><child1>value1</child1><child2>value2</child2></root>";
    xml_t *root = parse_xml(xml_string);
    print_xml(root);
    free(root->elements);
    free(root);
    return 0;
}