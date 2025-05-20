//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xml_node xml_node;
typedef struct xml_attribute xml_attribute;

// A struct to represent an XML attribute
struct xml_attribute {
    char *name;
    char *value;
    xml_attribute *next;
};

// A struct to represent an XML node
struct xml_node {
    char *name;
    char *text;
    xml_attribute *attributes;
    xml_node *children;
    xml_node *next;
};

xml_node* parse_xml(char *xml);

// Helper functions
xml_attribute* add_attribute(xml_attribute *attributes, char *name, char *value);
void add_child(xml_node *parent, xml_node *child);
void print_xml(xml_node *node);
void free_xml(xml_node *node);

int main(void) {
    char *xml = "<bookstore>"
                "<book category=\"fiction\">"
                "<title>The Great Gatsby</title>"
                "<author>F. Scott Fitzgerald</author>"
                "<price>10.99</price>"
                "</book>"
                "<book category=\"cooking\">"
                "<title>The Joy of Cooking</title>"
                "<author>Irma S. Rombauer, Marion Rombauer Becker, and Ethan Becker</author>"
                "<price>29.99</price>"
                "</book>"
                "</bookstore>";

    xml_node *root = parse_xml(xml);
    print_xml(root);
    free_xml(root);

    return 0;
}

// Parses an XML string and returns the root node of the XML tree
xml_node* parse_xml(char *xml) {
    xml_node *root = NULL;
    xml_node *current_node = NULL;
    xml_attribute *current_attribute = NULL;

    char *token;
    char *strtok_ptr;
    token = strtok_r(xml, "<>", &strtok_ptr);

    while (token != NULL) {
        if (token[0] == '/') {
            current_node = current_node->next;
        } else if (token[0] == '?') {
            // Skip XML declaration
        } else if (token[0] == '!') {
            // Skip comments
        } else {
            xml_node *node = malloc(sizeof(xml_node));
            node->name = token;
            node->text = NULL;
            node->attributes = NULL;
            node->children = NULL;
            node->next = NULL;

            if (current_node != NULL) {
                add_child(current_node, node);
            } else {
                root = node;
            }

            current_node = node;

            // Parse attributes
            token = strtok_r(NULL, "<>", &strtok_ptr);
            while (token[0] != '/') {
                char *attribute_name = token;
                char *attribute_value = strchr(token, '=') + 1;
                strtok(attribute_value, "\"");
                attribute_value = strtok(NULL, "\"");
                current_attribute = add_attribute(current_attribute, attribute_name, attribute_value);
                token = strtok_r(NULL, "<>", &strtok_ptr);
            }

            current_node->attributes = current_attribute;
            current_attribute = NULL;

            if (token[1] != '\0') {
                // Parse child nodes
                current_node = parse_xml(token);
            }
        }

        token = strtok_r(NULL, "<>", &strtok_ptr);
    }

    return root;
}

// Adds an attribute to the linked list of attributes
xml_attribute* add_attribute(xml_attribute *attributes, char *name, char *value) {
    xml_attribute *attribute = malloc(sizeof(xml_attribute));
    attribute->name = strdup(name);
    attribute->value = strdup(value);
    attribute->next = attributes;
    return attribute;
}

// Adds a child node to the linked list of children
void add_child(xml_node *parent, xml_node *child) {
    xml_node *current = parent->children;
    if (current == NULL) {
        parent->children = child;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = child;
    }
}

// Prints the XML tree in a human-readable format
void print_xml(xml_node *node) {
    if (node == NULL) {
        return;
    }

    printf("<%s", node->name);

    // Print attributes
    xml_attribute *current_attribute = node->attributes;
    while (current_attribute != NULL) {
        printf(" %s=\"%s\"", current_attribute->name, current_attribute->value);
        current_attribute = current_attribute->next;
    }

    printf(">");

    // Print child nodes
    xml_node *current_child = node->children;
    while (current_child != NULL) {
        print_xml(current_child);
        current_child = current_child->next;
    }

    if (node->text != NULL) {
        printf("%s", node->text);
    }

    printf("</%s>", node->name);
}

// Frees the memory used by the XML tree
void free_xml(xml_node *node) {
    if (node == NULL) {
        return;
    }

    // Free attributes
    xml_attribute *current_attribute = node->attributes;
    while (current_attribute != NULL) {
        xml_attribute *next = current_attribute->next;
        free(current_attribute->name);
        free(current_attribute->value);
        free(current_attribute);
        current_attribute = next;
    }

    // Free child nodes
    xml_node *current_child = node->children;
    while (current_child != NULL) {
        xml_node *next = current_child->next;
        free_xml(current_child);
        current_child = next;
    }

    // Free node name and text
    free(node->name);
    free(node->text);

    // Free node itself
    free(node);
}