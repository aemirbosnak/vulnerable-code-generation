//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 100

typedef struct xmlNode xmlNode;
struct xmlNode {
    char* tag;
    char* value;
    xmlNode* parent;
    xmlNode* children[MAX_VALUE];
    int num_children;
};

xmlNode* xml_parser(char* xml_string, int* num_nodes);
void print_xml_tree(xmlNode* node, int indentation);

int main() {
    char* xml_string = "<root><person><name>John Doe</name><age>30</age></person></root>";
    int num_nodes = 0;
    xmlNode* root = xml_parser(xml_string, &num_nodes);
    printf("Parsed %d nodes\n", num_nodes);
    print_xml_tree(root, 0);
    return 0;
}

xmlNode* xml_parser(char* xml_string, int* num_nodes) {
    xmlNode* root = NULL;
    xmlNode* current_node = NULL;
    int depth = 0;
    char* tag = NULL;
    char* value = NULL;
    char* current_pos = xml_string;
    while (*current_pos != '\0') {
        if (*current_pos == '<') {
            if (*(current_pos + 1) == '/') {
                // Closing tag
                tag = strtok(current_pos + 2, ">");
                depth--;
                current_node = current_node->parent;
            } else {
                // Opening tag
                tag = strtok(current_pos + 1, ">");
                if (root == NULL) {
                    // Root node
                    root = (xmlNode*) malloc(sizeof(xmlNode));
                    root->tag = strdup(tag);
                    current_node = root;
                } else {
                    // Child node
                    xmlNode* new_node = (xmlNode*) malloc(sizeof(xmlNode));
                    new_node->tag = strdup(tag);
                    new_node->parent = current_node;
                    current_node->children[current_node->num_children] = new_node;
                    current_node->num_children++;
                    current_node = new_node;
                    (*num_nodes)++;
                }
                depth++;
            }
        } else {
            // Node value
            value = strtok(current_pos, "<");
            current_node->value = strdup(value);
        }
        current_pos++;
    }
    return root;
}

void print_xml_tree(xmlNode* node, int indentation) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < indentation; i++) {
        printf(" ");
    }
    printf("<%s>", node->tag);
    if (node->value != NULL) {
        printf("%s", node->value);
    }
    printf("\n");
    for (int i = 0; i < node->num_children; i++) {
        print_xml_tree(node->children[i], indentation + 4);
    }
    for (int i = 0; i < indentation; i++) {
        printf(" ");
    }
    printf("</%s>\n", node->tag);
}