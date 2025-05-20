//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_NAME 100
#define MAX_NODE_VALUE 255
#define MAX_CHILDREN 10

typedef struct XmlNode {
    char name[MAX_NODE_NAME];
    char value[MAX_NODE_VALUE];
    struct XmlNode* children[MAX_CHILDREN];
    int child_count;
} XmlNode;

// Function to create a new XML node
XmlNode* create_xml_node(const char* name, const char* value) {
    XmlNode* node = (XmlNode*)malloc(sizeof(XmlNode));
    strncpy(node->name, name, MAX_NODE_NAME);
    strncpy(node->value, value, MAX_NODE_VALUE);
    node->child_count = 0;
    return node;
}

// Function to add a child node
void add_child(XmlNode* parent, XmlNode* child) {
    if (parent->child_count < MAX_CHILDREN) {
        parent->children[parent->child_count++] = child;
    } else {
        printf("Max children limit reached for node %s\n", parent->name);
    }
}

// Function to parse a simple XML string
XmlNode* parse_xml(const char* xml) {
    XmlNode* root = NULL;
    XmlNode* currentNode = NULL;

    char nodeName[MAX_NODE_NAME];
    char nodeValue[MAX_NODE_VALUE];
    int index = 0;
    while (*xml) {
        // Check for opening tag
        if (*xml == '<') {
            xml++;
            if (*xml == '/') {
                xml++; // skip closing tag (/)
                while (*xml != '>') xml++; // skip to '>'
                xml++; // move past '>'
                currentNode = NULL; // close the current node
            } else {
                // Get node name
                index = 0;
                while (*xml != '>') {
                    if (*xml == ' ') break; // attribute space
                    nodeName[index++] = *xml;
                    xml++;
                }
                nodeName[index] = '\0'; // null terminate
                currentNode = create_xml_node(nodeName, "");
                if (!root) {
                    root = currentNode; // set as root
                } else {
                    add_child(root, currentNode); // add to root for simplicity
                }
                xml++; // move past '>'
            }
        } else {
            // Assuming we are reading node values for simplicity
            index = 0;
            while (*xml != '<' && *xml) {
                nodeValue[index++] = *xml;
                xml++;
            }
            nodeValue[index] = '\0'; // null terminate
            if (currentNode) {
                strncpy(currentNode->value, nodeValue, MAX_NODE_VALUE); // set value
            }
        }
    }
    return root;
}

// Function to print the XML tree
void print_xml(XmlNode* node, int level) {
    if (!node) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("<%s>%s</%s>\n", node->name, node->value, node->name);
    for (int i = 0; i < node->child_count; i++) {
        print_xml(node->children[i], level + 1);
    }
}

// Clean up XML node memory
void free_xml_node(XmlNode* node) {
    if (!node) return;
    for (int i = 0; i < node->child_count; i++) {
        free_xml_node(node->children[i]);
    }
    free(node);
}

int main() {
    const char* xml_input = "<root>Value 1<child1>Child Value 1</child1><child2>Child Value 2</child2></root>";
    
    printf("Parsing XML:\n%s\n", xml_input);
    XmlNode* xml_tree = parse_xml(xml_input);
    
    printf("\nParsed XML Structure:\n");
    print_xml(xml_tree, 0);

    free_xml_node(xml_tree); // free the allocated memory
    return 0;
}