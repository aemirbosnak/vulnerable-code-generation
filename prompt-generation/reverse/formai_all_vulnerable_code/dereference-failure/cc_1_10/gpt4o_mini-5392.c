//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 100
#define MAX_VALUE_LENGTH 255
#define MAX_CHILDREN 10

// Define a structure for XML nodes
typedef struct XmlNode {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct XmlNode* children[MAX_CHILDREN];
    int child_count;
} XmlNode;

// Function to create a new XML node
XmlNode* create_node(const char* tag) {
    XmlNode* new_node = (XmlNode*)malloc(sizeof(XmlNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(new_node->tag, tag, MAX_TAG_LENGTH);
    new_node->tag[MAX_TAG_LENGTH - 1] = '\0';
    new_node->value[0] = '\0';
    new_node->child_count = 0;
    return new_node;
}

// Function to add a child node
void add_child(XmlNode* parent, XmlNode* child) {
    if (parent->child_count < MAX_CHILDREN) {
        parent->children[parent->child_count++] = child;
    } else {
        fprintf(stderr, "Maximum children limit reached for tag: %s\n", parent->tag);
    }
}

// Function to free the XML tree
void free_xml(XmlNode* node) {
    for (int i = 0; i < node->child_count; i++) {
        free_xml(node->children[i]);
    }
    free(node);
}

// Function to parse an XML file
XmlNode* parse_xml(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return NULL;
    }

    XmlNode* root = NULL;
    XmlNode* current = NULL;
    char line[512];
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "<%99[^>]>", tag) == 1) {
            XmlNode* new_node = create_node(tag);
            if (current == NULL) {
                root = new_node; // Set root node
            } else {
                add_child(current, new_node);
            }
            current = new_node; // Move current to the new node
        } else if (sscanf(line, "%[^<]", value) == 1) {
            strncpy(current->value, value, MAX_VALUE_LENGTH);
            current->value[MAX_VALUE_LENGTH - 1] = '\0';
        } else if (sscanf(line, "</%99[^>]>", tag) == 1) {
            // Moving back to parent, simulation of ending the tag
            // Normally you would have a stack to manage this
            current = root; // This is naive
        }
    }
    
    fclose(file);
    return root;
}

// Function to print the XML tree
void print_xml(XmlNode* node, int depth) {
    if (node == NULL) return;

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", node->tag);
    if (strlen(node->value) > 0) {
        printf("%s", node->value);
    }
    printf("\n");
    
    for (int i = 0; i < node->child_count; i++) {
        print_xml(node->children[i], depth + 1);
    }

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XmlNode* xml_tree = parse_xml(argv[1]);
    if (xml_tree != NULL) {
        print_xml(xml_tree, 0);
        free_xml(xml_tree);
    }

    return EXIT_SUCCESS;
}