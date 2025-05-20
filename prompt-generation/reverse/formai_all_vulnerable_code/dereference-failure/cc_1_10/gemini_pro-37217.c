//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_SIZE 256
#define MAX_ATTRIBUTE_SIZE 256
#define MAX_CHILDREN 10

typedef struct Element {
    char name[MAX_ELEMENT_SIZE];
    char attributes[MAX_ATTRIBUTE_SIZE][MAX_ATTRIBUTE_SIZE];
    int num_attributes;
    struct Element *children[MAX_CHILDREN];
    int num_children;
} Element;

Element *parse_element(char *str) {
    Element *element = malloc(sizeof(Element));
    memset(element, 0, sizeof(Element));

    // Parse the element name
    int i = 0;
    while (str[i] != ' ' && str[i] != '>' && str[i] != '\0') {
        element->name[i] = str[i];
        i++;
    }

    // Parse the attributes
    while (str[i] == ' ') {
        i++;
    }
    while (str[i] != '>' && str[i] != '\0') {
        char attribute[MAX_ATTRIBUTE_SIZE];
        int j = 0;
        while (str[i] != '=' && str[i] != ' ' && str[i] != '>' && str[i] != '\0') {
            attribute[j] = str[i];
            j++;
            i++;
        }
        attribute[j] = '\0';

        char value[MAX_ATTRIBUTE_SIZE];
        j = 0;
        i++;
        while (str[i] != '"' && str[i] != ' ' && str[i] != '>' && str[i] != '\0') {
            value[j] = str[i];
            j++;
            i++;
        }
        value[j] = '\0';

        strcpy(element->attributes[element->num_attributes], attribute);
        strcpy(element->attributes[element->num_attributes + 1], value);
        element->num_attributes += 2;

        while (str[i] == ' ') {
            i++;
        }
    }

    // Parse the children
    while (str[i] != '\0') {
        if (str[i] == '<') {
            element->children[element->num_children] = parse_element(str + i);
            element->num_children++;
        }
        i++;
    }

    return element;
}

void print_element(Element *element, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s", element->name);
    for (int i = 0; i < element->num_attributes; i += 2) {
        printf(" %s=\"%s\"", element->attributes[i], element->attributes[i + 1]);
    }
    printf(">\n");

    for (int i = 0; i < element->num_children; i++) {
        print_element(element->children[i], depth + 1);
    }

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", element->name);
}

int main() {
    char *str = "<root><child1><child11></child11><child12></child12></child1><child2><child21></child21><child22></child22></child2></root>";

    Element *root = parse_element(str);

    print_element(root, 0);

    return 0;
}