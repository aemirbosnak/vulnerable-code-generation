//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: surrealist
#include <stdio.h> // for standard input/output functions
#include <stdlib.h> // for memory allocation
#include <string.h> // for string operations

typedef struct xml_node {
    char *tag_name;
    char **attributes;
    int num_attributes;
    char *value;
    struct xml_node **children;
    int num_children;
} xml_node;

void parse_node(char *node_str, xml_node *parent_node) {
    // function to parse a single node string and add it to the parent node
    xml_node *new_node = (xml_node *)malloc(sizeof(xml_node));
    new_node->tag_name = (char *)malloc(sizeof(char) * 50);
    new_node->attributes = (char **)malloc(sizeof(char *) * 10);
    new_node->num_attributes = 0;
    new_node->value = NULL;
    new_node->children = (xml_node **)malloc(sizeof(xml_node *) * 10);
    new_node->num_children = 0;

    // extract tag name
    int start = 1, end = 1;
    while (node_str[end] != ' ' && node_str[end] != '>') {
        end++;
    }
    strncpy(new_node->tag_name, node_str + start, end - start);
    new_node->tag_name[end - start] = '\0';

    // extract attributes (if any)
    while (node_str[end] != '>') {
        if (node_str[end] == ' ') {
            start = end + 1;
            end = start;
            while (node_str[end] != '=') {
                end++;
            }
            new_node->attributes[new_node->num_attributes] = (char *)malloc(sizeof(char) * 50);
            strncpy(new_node->attributes[new_node->num_attributes], node_str + start, end - start);
            new_node->attributes[new_node->num_attributes][end - start] = '\0';
            new_node->num_attributes++;
        }
        end++;
    }

    // extract value (if any)
    start = ++end;
    while (node_str[end] != '<') {
        end++;
    }
    new_node->value = (char *)malloc(sizeof(char) * (end - start + 1));
    strncpy(new_node->value, node_str + start, end - start);
    new_node->value[end - start] = '\0';

    // add new node to parent
    parent_node->children[parent_node->num_children] = new_node;
    parent_node->num_children++;
}

void parse_xml(char *xml_str, xml_node *root_node) {
    // function to parse entire xml string and build xml tree
    int start = 0, end = 0;
    while (end < strlen(xml_str)) {
        if (xml_str[end] == '<') {
            start = end;
            while (xml_str[end] != '>') {
                end++;
            }
            if (xml_str[end - 1] == '/') {
                end--;
            } else if (xml_str[start + 1] == '/') {
                root_node = root_node->children[root_node->num_children - 1]; // move up hierarchy
            } else {
                char *node_str = (char *)malloc(sizeof(char) * (end - start + 1));
                strncpy(node_str, xml_str + start, end - start + 1);
                node_str[end - start + 1] = '\0';
                parse_node(node_str, root_node);
                if (!root_node->num_children) {
                    root_node = root_node->children[0]; // move down hierarchy
                }
            }
        }
        end++;
    }
}

int main() {
    xml_node *root_node = (xml_node *)malloc(sizeof(xml_node));
    root_node->num_attributes = 0;
    root_node->attributes = (char **)malloc(sizeof(char *) * 10);
    root_node->value = NULL;
    root_node->num_children = 0;
    root_node->children = (xml_node **)malloc(sizeof(xml_node *) * 10);

    char *xml_str = "<root><element attribute1=\"value1\" attribute2=\"value2\">This is the element value</element><element>With no attributes or value</element><empty_element/></root>";
    parse_xml(xml_str, root_node);

    return 0;
}