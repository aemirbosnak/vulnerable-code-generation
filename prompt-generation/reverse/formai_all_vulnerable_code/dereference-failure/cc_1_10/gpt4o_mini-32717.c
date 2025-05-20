//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XmlNode {
    char *tag;
    char *content;
    struct XmlNode **children;
    int children_count;
} XmlNode;

// Function to create a new XML node
XmlNode* create_node(const char *tag, const char *content) {
    XmlNode *node = malloc(sizeof(XmlNode));
    if (!node) return NULL;

    node->tag = strdup(tag);
    node->content = content ? strdup(content) : NULL;
    node->children = NULL;
    node->children_count = 0;

    return node;
}

// Function to add a child node to a parent node
void add_child(XmlNode *parent, XmlNode *child) {
    parent->children_count++;
    parent->children = realloc(parent->children, parent->children_count * sizeof(XmlNode*));
    if (parent->children) {
        parent->children[parent->children_count - 1] = child;
    }
}

// Function to free the XML node and its children
void free_node(XmlNode *node) {
    if (node) {
        free(node->tag);
        free(node->content);
        for (int i = 0; i < node->children_count; i++) {
            free_node(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

// Function to parse XML into a tree structure
XmlNode* parse_xml(const char *xml) {
    XmlNode *root = NULL;
    XmlNode *current = NULL;
    const char *ptr = xml;
    while (*ptr) {
        if (*ptr == '<') {
            // Determine if it's an opening tag or closing tag
            if (*(ptr + 1) != '/') {
                // Opening tag
                const char *tag_start = ptr + 1;
                const char *tag_end = strchr(tag_start, '>');
                if (!tag_end) break;  // Malformed XML

                ptr = tag_end + 1;
                // Create new node
                XmlNode *new_node = create_node(strndup(tag_start, tag_end - tag_start), NULL);
                if (!root) root = new_node;  // Set root if needed
                if (current) add_child(current, new_node);
                current = new_node;  // Move current to the new node
            } else {
                // Closing tag
                if (current) {
                    current->content = strndup(ptr + 1, strchr(ptr, '>') - (ptr + 1));
                    current = NULL;  // Close current node
                }
                ptr = strchr(ptr, '>') + 1;
            }
        } else {
            ptr++;
        }
    }
    return root;
}

// Function to print the XML tree
void print_xml(XmlNode *node, int indentation) {
    if (!node) return;

    for (int i = 0; i < indentation; i++) printf("  ");
    printf("<%s>", node->tag);
    if (node->content) {
        printf("%s", node->content);
    }
    printf("\n");

    for (int i = 0; i < node->children_count; i++) {
        print_xml(node->children[i], indentation + 1);
    }

    for (int i = 0; i < indentation; i++) printf("  ");
    printf("</%s>\n", node->tag);
}

// Main function to demonstrate the XML parser
int main(int argc, char **argv) {
    const char *xml_data = "<root><child1>Hello</child1><child2><subchild>World</subchild></child2></root>";

    // Parse the XML
    XmlNode *document = parse_xml(xml_data);
    
    // Print the parsed XML
    print_xml(document, 0);

    // Free the allocated memory
    free_node(document);

    return 0;
}