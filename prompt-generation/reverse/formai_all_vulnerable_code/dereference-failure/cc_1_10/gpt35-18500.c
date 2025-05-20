//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct xml_node_t {
    char *tag;
    char *content;
    struct xml_node_t *children;
    struct xml_node_t *next_sibling;
} xml_node_t;

xml_node_t *parse_xml_file(char *filename) {
    // File I/O code goes here
    // For the sake of this example, we'll just hard-code some XML
    char *xml = "<root>\n"
                "  <child1>This is the first child</child1>\n"
                "  <child2>This is the second child</child2>\n"
                "</root>\n";
    
    xml_node_t *root = malloc(sizeof(xml_node_t));
    root->tag = "root";
    root->content = NULL;
    root->children = NULL;
    root->next_sibling = NULL;
    
    xml_node_t **current_node = &(root->children);
    
    char *position = xml;
    while (*position != '\0') {
        // Skip leading space
        while (isspace(*position)) {
            position++;
        }
        
        // Check for end tag
        if (*position == '<' && *(position+1) == '/') {
            char *end_tag = position + 2;
            while (*end_tag != '>') {
                end_tag++;
            }
            *end_tag = '\0';
            
            if (strcmp((*current_node)->tag, position+2) != 0) {
                printf("Error: end tag %s does not match start tag %s\n", position+2, (*current_node)->tag);
                exit(1);
            }
            
            current_node = &((*current_node)->next_sibling);
            position = end_tag + 1;
        }
        // Check for start tag
        else if (*position == '<') {
            char *start_tag = position + 1;
            char *end_tag = start_tag;
            while (*end_tag != '>') {
                end_tag++;
            }
            *end_tag = '\0';
            
            xml_node_t *new_node = malloc(sizeof(xml_node_t));
            new_node->tag = strdup(start_tag);
            new_node->content = NULL;
            new_node->children = NULL;
            new_node->next_sibling = NULL;
            
            *current_node = new_node;
            current_node = &(new_node->children);
            
            position = end_tag + 1;
        }
        // Must be content between tags
        else {
            char *end_content = position;
            while (*end_content != '<') {
                end_content++;
            }
            *end_content = '\0';
            
            (*current_node)->content = strdup(position);
            current_node = &((*current_node)->next_sibling);
            
            position = end_content;
        }
    }
    
    return root;
}

void print_xml_node(xml_node_t *node, int indent_level) {
    for (int i = 0; i < indent_level; i++) {
        printf("  ");
    }
    
    printf("<%s>", node->tag);
    
    if (node->content != NULL) {
        printf("%s", node->content);
    }
    else {
        printf("\n");
        xml_node_t *child = node->children;
        while (child != NULL) {
            print_xml_node(child, indent_level+1);
            child = child->next_sibling;
        }
        for (int i = 0; i < indent_level; i++) {
            printf("  ");
        }
    }
    
    printf("</%s>\n", node->tag);
}

int main() {
    xml_node_t *root = parse_xml_file("example.xml");
    print_xml_node(root, 0);
    
    return 0;
}