//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an XML element
typedef struct xml_element {
    char *name; // name of the element
    char **attributes; // array of attributes
    char *value; // value of the element
    struct xml_element **children; // array of child elements
    int num_attributes; // number of attributes
    int num_children; // number of child elements
} XmlElement;

// Parses an XML string and returns a pointer to the root element
XmlElement* parse_xml(char *input) {
    // TODO: Implement XML parser
}

// Recursively prints an XML element and its children
void print_xml_element(XmlElement *element, int depth) {
    // Print opening tag
    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("<%s", element->name);

    // Print attributes
    for (int i = 0; i < element->num_attributes; i++) {
        printf(" %s=\"%s\"", element->attributes[i * 2], element->attributes[i * 2 + 1]);
    }
    printf(">\n");

    // Print value
    if (element->value != NULL) {
        for (int i = 0; i < depth + 2; i++) {
            printf(" ");
        }
        printf("%s\n", element->value);
    }

    // Print children
    for (int i = 0; i < element->num_children; i++) {
        print_xml_element(element->children[i], depth + 2);
    }

    // Print closing tag
    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("</%s>\n", element->name);
}

int main() {
    char *xml_input = "<root><article id=\"123\"><title>My article</title><author>John Doe</author><content>This is my article.</content></article></root>";
    XmlElement *root = parse_xml(xml_input);
    print_xml_element(root, 0);

    return 0;
}