//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_TAG_LENGTH 100
#define MAX_ATTRS 20
#define MAX_ATTR_LENGTH 50
#define MAX_VALUE_LENGTH 200
#define MAX_CHILDREN 50
#define BUFFER_SIZE 1024

// Define struct for XML element
typedef struct xml_element {
    char tag[MAX_TAG_LENGTH];
    char attrs[MAX_ATTRS][MAX_ATTR_LENGTH];
    char values[MAX_ATTRS][MAX_VALUE_LENGTH];
    struct xml_element* children[MAX_CHILDREN];
    int num_children;
} xml_element;

// Function to parse XML string and return root element
xml_element* parse_xml(const char* xml_str) {
    char buffer[BUFFER_SIZE];
    int index = 0;
    xml_element* root = NULL;

    while (xml_str[index] != '\0') {
        // Find start of tag
        if (xml_str[index] == '<') {
            // Check if closing tag
            if (xml_str[index + 1] == '/') {
                // TODO: Handle closing tag
            } else {
                // Create new element and add to current element's children
                xml_element* elem = (xml_element*) malloc(sizeof(xml_element));
                if (root == NULL) {
                    root = elem;
                } else {
                    root->children[root->num_children++] = elem;
                }

                // Read tag name
                int i = 0;
                index++;
                while (xml_str[index] != ' ' && xml_str[index] != '>') {
                    elem->tag[i++] = xml_str[index++];
                }
                elem->tag[i] = '\0';

                // Read attributes
                int attr_index = 0;
                while (xml_str[index] != '>') {
                    // Skip whitespace
                    while (xml_str[index] == ' ') {
                        index++;
                    }

                    // Read attribute name
                    i = 0;
                    while (xml_str[index] != '=') {
                        elem->attrs[attr_index][i++] = xml_str[index++];
                    }
                    elem->attrs[attr_index][i] = '\0';
                    index++; // Skip '=' character

                    // Read attribute value
                    i = 0;
                    char quote_char = xml_str[index];
                    index++; // Skip quote character
                    while (xml_str[index] != quote_char) {
                        elem->values[attr_index][i++] = xml_str[index++];
                    }
                    elem->values[attr_index][i] = '\0';
                    index++; // Skip closing quote character

                    attr_index++;
                }
            }
        }
        index++;
    }

    return root;
}

int main() {
    // Example XML string to parse
    const char* xml_str = "<bookstore><book category=\"children\"><title>The Cat in the Hat</title><author>Dr. Seuss</author><year>1957</year></book><book category=\"cooking\"><title>The Joy of Cooking</title><author>Irma Rombauer</author><year>1931</year></book></bookstore>";

    // Parse XML string and print element information
    xml_element* root = parse_xml(xml_str);
    if (root != NULL) {
        printf("Root element is: <%s>\n", root->tag);
        for (int i = 0; i < root->num_children; i++) {
            xml_element* child = root->children[i];
            printf("Child element %d is: <%s>\n", i+1, child->tag);
            for (int j = 0; j < MAX_ATTRS && child->attrs[j][0] != '\0'; j++) {
                printf("  Attribute %s=%s\n", child->attrs[j], child->values[j]);
            }
        }
    }

    return 0;
}