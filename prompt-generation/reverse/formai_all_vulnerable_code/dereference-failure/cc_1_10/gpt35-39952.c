//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// define xml node structure
typedef struct xml_node {
    char *name;
    char *value;
    struct xml_node *children;
    struct xml_node *next;
} xml_node_t;

// function to parse xml string and return root xml node
xml_node_t* parse_xml(char *xml_string) {
    xml_node_t *root_node = NULL;
    xml_node_t *current_node = NULL;
    char *token, *end_token;
    char *element_name = NULL;
    char *element_value = NULL;
    char *remaining_string = xml_string;
    int is_closing_tag = 0;
    
    // loop through xml string tokens
    while ((token = strtok_r(remaining_string, "<>", &remaining_string))) {
        // check if token is valid element name
        if (isalpha(token[0]) || (token[0] == '/' && isalpha(token[1]))) {
            // check if token is closing tag
            if (token[0] == '/') {
                is_closing_tag = 1;
                element_name = &token[1];
            } else {
                is_closing_tag = 0;
                element_name = strdup(token);
            }
            
            // check if element value contains any child nodes
            end_token = strstr(remaining_string, "</");
            if (end_token != NULL && strncmp(&end_token[2], element_name, strlen(element_name)) == 0) {
                *end_token = '\0';
                element_value = remaining_string;
                remaining_string = &end_token[2+strlen(element_name)+1];
            } else {
                element_value = NULL;
                remaining_string = end_token + 1;
            }
            
            // create new xml node for element
            xml_node_t *element_node = (xml_node_t*) malloc(sizeof(xml_node_t));
            element_node->name = element_name;
            element_node->value = element_value;
            element_node->children = NULL;
            element_node->next = NULL;
            
            // add node to xml tree
            if (root_node == NULL) {
                root_node = element_node;
                current_node = element_node;
            } else {
                if (is_closing_tag) {
                    current_node = current_node->next;
                } else {
                    element_node->next = current_node->children;
                    current_node->children = element_node;
                    current_node = element_node;
                }
            }
        }
    }
    
    return root_node;
}

// function to print xml tree
void print_xml(xml_node_t *node, int indent) {
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    
    printf("<%s>", node->name);
    
    if (node->value != NULL) {
        printf("%s", node->value);
    } else if (node->children != NULL) {
        printf("\n");
        print_xml(node->children, indent+2);
        for (int i = 0; i < indent; i++) {
            printf(" ");
        }
    }
    
    printf("</%s>\n", node->name);
    
    if (node->next != NULL) {
        print_xml(node->next, indent);
    }
}

int main() {
    char *example_xml = "<xml>\n<name>John</name>\n<age>25</age>\n<details><address>123 Main St</address><phone>555-5555</phone></details>\n</xml>";
    
    xml_node_t *root_node = parse_xml(example_xml);
    print_xml(root_node, 0);
    
    return 0;
}