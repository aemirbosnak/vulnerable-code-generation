//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 64
#define MAX_TAG_VALUE 256

typedef struct XMLNode {
    char tag[MAX_TAG_NAME];
    char value[MAX_TAG_VALUE];
    struct XMLNode *next;
    struct XMLNode *child;
} XMLNode;

// Function to create a new node
XMLNode* create_node(const char *tag, const char *value) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    strncpy(node->tag, tag, MAX_TAG_NAME);
    strncpy(node->value, value, MAX_TAG_VALUE);
    node->next = NULL;
    node->child = NULL;
    return node;
}

// Function to add a child node
void add_child(XMLNode *parent, XMLNode *child) {
    if (parent->child) {
        XMLNode *sibling = parent->child;
        while (sibling->next) {
            sibling = sibling->next;
        }
        sibling->next = child;
    } else {
        parent->child = child;
    }
}

// Function to delete the XML node structure
void delete_xml(XMLNode *node) {
    if (node) {
        delete_xml(node->child);
        delete_xml(node->next);
        free(node);
    }
}

// Function to parse the XML string
XMLNode* parse_xml(const char *xml) {
    XMLNode *root = NULL;
    XMLNode *current_node = NULL;
    char tag[MAX_TAG_NAME];
    char value[MAX_TAG_VALUE];
    
    const char *ptr = xml;
    while (*ptr) {
        // If we hit a start tag
        if (*ptr == '<' && *(ptr + 1) != '/') {
            ptr++;
            sscanf(ptr, "%63[^>]", tag);
            ptr += strlen(tag) + 1; // Move pointer forward
            current_node = create_node(tag, "");
            if (!root) {
                root = current_node; // Set root if it is the first node
            } else {
                add_child(root, current_node); // Add to the XML structure
            }
        } 
        // If we hit an end tag
        else if (*ptr == '<' && *(ptr + 1) == '/') {
            while (*ptr && *ptr != '>') ptr++; // Skip to the end of the tag
            ptr++; // Move past '>'
        } 
        // If we hit a text node
        else if (current_node) {
            sscanf(ptr, "%255[^<]", value);
            strncpy(current_node->value, value, MAX_TAG_VALUE);
            ptr += strlen(value); // Move pointer forward
        } else {
            ptr++;
        }
    }

    return root;
}

// Function to print the XML tree
void print_xml(XMLNode *node, int indent) {
    if (node) {
        for (int i = 0; i < indent; i++) printf("  ");
        printf("<%s>%s</%s>\n", node->tag, node->value, node->tag);
        print_xml(node->child, indent + 1);
        print_xml(node->next, indent);
    }
}

int main() {
    const char *xml_string = "<root><child1>Hello</child1><child2>World</child2></root>";
    XMLNode *xml_tree = parse_xml(xml_string);
    
    printf("Parsed XML Structure:\n");
    print_xml(xml_tree, 0);
    
    delete_xml(xml_tree); // Free allocated memory
    return 0;
}