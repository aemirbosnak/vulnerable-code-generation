//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XMLNode {
    char *tag;
    char *value;
    struct XMLNode *next;
    struct XMLNode *child;
} XMLNode;

XMLNode *create_node(const char *tag, const char *value) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    node->tag = strdup(tag);
    node->value = strdup(value);
    node->next = NULL;
    node->child = NULL;
    return node;
}

void free_node(XMLNode *node) {
    if (node) {
        free(node->tag);
        free(node->value);
        free(node);
    }
}

void free_tree(XMLNode *node) {
    if (node) {
        free_tree(node->child);
        free_tree(node->next);
        free_node(node);
    }
}

XMLNode *parse_xml(const char *xml) {
    XMLNode *root = NULL;
    XMLNode *current = NULL;
    char tag[128];
    char value[256];
    const char *p = xml;
    
    while (*p) {
        // Skip whitespace
        while (*p && (*p == ' ' || *p == '\n' || *p == '\t')) p++;

        if (*p == '<') {
            // Found a tag
            p++;
            if (*p == '/') {
                // Closing tag, move up the tree
                while (*p && *p != '>') p++;
                if (*p) p++; // Consume '>'
                current = current->next; // Move to next sibling
                continue;
            }

            // Read tag name
            int i = 0;
            while (*p && *p != '>' && *p != ' ') {
                tag[i++] = *p++;
            }
            tag[i] = '\0';

            // Create a new node
            XMLNode *new_node = create_node(tag, NULL);
            if (!root) {
                root = new_node; // This is the root node
            } else {
                if (current) {
                    current->child = new_node; // Add as a child
                }
            }
            current = new_node; // Move to the current node

            // Skip attributes
            while (*p && *p != '>') p++;
            if (*p == '>') p++; // Consume '>'

        } else if (*p) {
            // Read the value
            int i = 0;
            while (*p && *p != '<') {
                value[i++] = *p++;
            }
            value[i] = '\0';
            if (current) {
                current->value = strdup(value); // Set value for the current node
            }
        }
    }

    return root;
}

void print_tree(XMLNode *node, int depth) {
    while (node) {
        for (int i = 0; i < depth; i++) printf("  ");
        printf("<%s>", node->tag);
        if (node->value) {
            printf(" %s", node->value);
        }
        printf("\n");
        print_tree(node->child, depth + 1);
        node = node->next;
        for (int i = 0; i < depth; i++) printf("  ");
        printf("</%s>\n", node ? node->tag : "");
    }
}

int main() {
    const char *xml_data = "<root><child1>Value 1</child1><child2>Value 2</child2></root>";
    
    XMLNode *tree = parse_xml(xml_data);
    printf("Parsed XML Structure:\n");
    print_tree(tree, 0);
    
    free_tree(tree);
    return 0;
}