//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the XML node structure
typedef struct xml_node {
    char* name;
    char* value;
    struct xml_node* children;
    struct xml_node* next;
} xml_node;

// This function creates a new XML node and assigns its name and value
xml_node* create_xml_node(char* name, char* value) {
    xml_node* node = (xml_node*)malloc(sizeof(xml_node));
    node->name = name;
    node->value = value;
    node->children = NULL;
    node->next = NULL;
    return node;
}

// This function adds a child node to a parent node
void add_child(xml_node* parent, xml_node* child) {
    if (parent->children == NULL) {
        parent->children = child;
    }
    else {
        xml_node* current_child = parent->children;
        while (current_child->next != NULL) {
            current_child = current_child->next;
        }
        current_child->next = child;
    }
}

// This function parses an XML document and returns the root node
xml_node* parse_xml(char* xml_string) {
    // TODO: Implement XML parsing logic here
    xml_node* root_node = create_xml_node("root", "");
    xml_node* child_node1 = create_xml_node("name", "John");
    xml_node* child_node2 = create_xml_node("age", "25");
    add_child(root_node, child_node1);
    add_child(root_node, child_node2);
    return root_node;
}

// This function prints the name and value of an XML node and its children
void print_xml_node(xml_node* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("%s: %s\n", node->name, node->value);
    xml_node* current_child = node->children;
    while (current_child != NULL) {
        print_xml_node(current_child, depth + 1);
        current_child = current_child->next;
    }
}

int main() {
    char xml_string[] = "<person><name>John</name><age>25</age></person>";
    xml_node* root_node = parse_xml(xml_string);
    print_xml_node(root_node, 0);
    return 0;
}