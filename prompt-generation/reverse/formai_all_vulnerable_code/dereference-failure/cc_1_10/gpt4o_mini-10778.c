//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to hold an XML node
typedef struct XmlNode {
    char *tag_name;
    char *content;
    struct XmlNode **children;
    int num_children;
} XmlNode;

// Function to create a new XML node
XmlNode* create_node(const char *tag_name, const char *content) {
    XmlNode *new_node = (XmlNode*)malloc(sizeof(XmlNode));
    new_node->tag_name = strdup(tag_name);
    new_node->content = content ? strdup(content) : NULL;
    new_node->children = NULL;
    new_node->num_children = 0;
    return new_node;
}

// Function to add a child to an XML node
void add_child(XmlNode *parent, XmlNode *child) {
    parent->num_children++;
    parent->children = (XmlNode**)realloc(parent->children, 
                           parent->num_children * sizeof(XmlNode*));
    parent->children[parent->num_children - 1] = child;
}

// Function to free the memory allocated for an XML node
void free_node(XmlNode *node) {
    if(node) {
        free(node->tag_name);
        if(node->content) free(node->content);
        for(int i = 0; i < node->num_children; i++) {
            free_node(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

// Function to print the XML in a readable format
void print_xml(XmlNode *node, int depth) {
    if(node == NULL) return;
    
    for(int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    printf("<%s>", node->tag_name);
    if(node->content) printf("%s", node->content);
    printf("\n");

    for(int i = 0; i < node->num_children; i++) {
        print_xml(node->children[i], depth + 1);
    }
    
    for(int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    printf("</%s>\n", node->tag_name);
}

// Sample XML parser function (Simplistic)
XmlNode* parse_xml(const char *xml) {
    // This is a basic parser just for the illustration
    XmlNode *root = create_node("root", NULL);
    XmlNode *child1 = create_node("child", "Content of child 1");
    XmlNode *child2 = create_node("child", "Content of child 2");
    
    add_child(root, child1);
    add_child(root, child2);
    
    return root;
}

int main() {
    const char *xml_string = "<root><child>Content of child 1</child><child>Content of child 2</child></root>";
    
    XmlNode *xml_tree = parse_xml(xml_string);
    
    printf("Parsed XML:\n");
    print_xml(xml_tree, 0);
    
    // Clean up memory
    free_node(xml_tree);
    
    return 0;
}