//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XMLNode {
    char *tag;
    char *content;
    struct XMLNode **children;
    int child_count;
    struct XMLNode *next;
} XMLNode;

XMLNode* create_node(const char *tag, const char *content) {
    XMLNode *node = (XMLNode*)malloc(sizeof(XMLNode));
    node->tag = strdup(tag);
    node->content = strdup(content);
    node->children = NULL;
    node->child_count = 0;
    node->next = NULL;
    return node;
}

void add_child(XMLNode *parent, XMLNode *child) {
    parent->children = (XMLNode**)realloc(parent->children, sizeof(XMLNode*) * (parent->child_count + 1));
    parent->children[parent->child_count] = child;
    parent->child_count++;
}

void free_node(XMLNode *node) {
    if (node) {
        free(node->tag);
        free(node->content);
        for (int i = 0; i < node->child_count; i++) {
            free_node(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

void print_xml(XMLNode *node, int indent) {
    if (!node) return;
    
    for (int i = 0; i < indent; i++) printf("  ");
    printf("<%s>", node->tag);
    if (node->content && strlen(node->content) > 0) {
        printf("%s", node->content);
    }
    printf("\n");
    
    for (int i = 0; i < node->child_count; i++) {
        print_xml(node->children[i], indent + 1);
    }
    
    for (int i = 0; i < indent; i++) printf("  ");
    printf("</%s>\n", node->tag);
}

XMLNode* parse_xml(const char *xml) {
    XMLNode *root = NULL, *current = NULL;
    const char *ptr = xml;
    char tag[256] = {0}, content[256] = {0};
    int in_tag = 0, in_content = 0, content_index = 0;

    while (*ptr != '\0') {
        if (*ptr == '<') {
            if (in_content) {
                content[content_index] = '\0';
                if (current) {
                    current->content = strdup(content);
                }
                content_index = 0;
                in_content = 0;
            }

            if (*(ptr + 1) == '/') {
                // End tag
                ptr += 2;
                while (*ptr != '>') {
                    ptr++;
                }
                ptr++;
                if (current) {
                    current = current->next; // Move to the parent
                }
            } else {
                // Start tag
                ptr++;
                in_tag = 1;
                int tag_index = 0;
                while (*ptr != '>') {
                    if (*ptr == ' ') {
                        ptr++; // Ignore attributes for this simple parser
                        continue;
                    }
                    tag[tag_index++] = *ptr;
                    ptr++;
                }
                tag[tag_index] = '\0';
                ptr++; // Skip '>'

                XMLNode *new_node = create_node(tag, "");
                if (!root) {
                    root = new_node;
                } else {
                    if (current) {
                        add_child(current, new_node);
                    }
                }
                new_node->next = current; // Link to previous level
                current = new_node; // Set current to new node
                in_tag = 0;
            }
        } else {
            // Content text
            if (current) {
                in_content = 1;
                while (*ptr != '<' && *ptr != '\0') {
                    content[content_index++] = *ptr;
                    ptr++;
                }
                content[content_index] = '\0'; // Null-terminate the content
            }
        }

        if (*ptr != '\0') ptr++; // Skip to the next character
    }

    return root;
}

int main() {
    const char *xml_data = "<root><child>Hello</child><child>World</child></root>";

    XMLNode *xml_tree = parse_xml(xml_data);
    
    if (xml_tree) {
        printf("Parsed XML:\n");
        print_xml(xml_tree, 0);
        free_node(xml_tree);
    } else {
        printf("Failed to parse XML.\n");
    }

    return 0;
}