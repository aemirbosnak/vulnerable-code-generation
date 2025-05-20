//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Define the XML parser structure
typedef struct xml_parser_t {
    char *element_tag;
    char *element_content;
    struct xml_parser_t *children;
    struct xml_parser_t *next;
} xml_parser_t;

// Prototypes
xml_parser_t* parse_element(char *xml);
xml_parser_t* parse_children(xml_parser_t *parent, char *xml);
xml_parser_t* parse_next(xml_parser_t *sibling, char *xml);
void print_xml_tree(xml_parser_t *root, int depth);

// Parse the current element
xml_parser_t* parse_element(char *xml) {
    xml_parser_t *element = malloc(sizeof(xml_parser_t));
    element->element_tag = malloc(sizeof(char) * MAX_LENGTH);
    element->element_content = malloc(sizeof(char) * MAX_LENGTH);
    element->children = NULL;
    element->next = NULL;
    
    int i = 1;
    int j = 0;
    
    // Extract the element tag
    while (xml[i] != '>' && !isspace(xml[i])) {
        element->element_tag[j++] = xml[i++];
    }
    element->element_tag[j] = '\0';
    
    // Extract the element content
    i++;
    j = 0;
    
    while (xml[i] != '<') {
        element->element_content[j++] = xml[i++];
    }
    element->element_content[j] = '\0';
    
    // Parse the element's children and next sibling
    element->children = parse_children(element, xml);
    element->next = parse_next(element->children, xml);
    
    return element;
}

// Parse the current element's children
xml_parser_t* parse_children(xml_parser_t *parent, char *xml) {
    int i = 1;
    char *child_start = strstr(xml + i, "<");
    xml_parser_t *child = NULL;
    
    while (child_start != NULL && *child_start != '/') {
        child = parse_element(child_start);
        if (child != NULL) {
            child->next = parent->children;
            parent->children = child;
        }
        i = child_start - xml + 1;
        child_start = strstr(xml + i, "<");
    }
    
    return parent->children;
}

// Parse the current element's next sibling
xml_parser_t* parse_next(xml_parser_t *sibling, char *xml) {
    // Find the next sibling
    int i = 1;
    char *sibling_start = NULL;
    
    if (sibling != NULL) {
        sibling_start = strstr(xml + i, sibling->element_tag);
    } else {
        sibling_start = xml + i;
    }
    
    while (sibling_start != NULL && *sibling_start != '/') {
        sibling_start += strlen(sibling->element_tag) + 2;
        sibling = parse_element(sibling_start);
        if (sibling != NULL) {
            return sibling;
        }
        i = sibling_start - xml + 1;
        sibling_start = strstr(xml + i, sibling->element_tag);
    }
    
    return NULL;
}

// Print the XML tree structure
void print_xml_tree(xml_parser_t *root, int depth) {
    if (root == NULL) {
        return;
    }
    
    // Indent according to depth
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    // Print the element tag and content
    printf("<%s>%s</%s>\n", root->element_tag, root->element_content, root->element_tag);
    
    // Print the children
    xml_parser_t *child = root->children;
    
    while (child != NULL) {
        print_xml_tree(child, depth + 1);
        child = child->next;
    }
}

int main() {
    // Define the XML string to parse
    char *xml = "<root><element1>Content1</element1><element2><subelement1>Content2</subelement1><subelement2>Content3</subelement2></element2></root>";
    
    // Parse the XML
    xml_parser_t *root = parse_element(xml);
    
    // Print the XML tree structure
    print_xml_tree(root, 0);
    
    return 0;
}