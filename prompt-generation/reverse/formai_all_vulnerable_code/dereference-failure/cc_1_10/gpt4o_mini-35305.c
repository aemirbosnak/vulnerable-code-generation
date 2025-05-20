//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XMLNode {
    char *element;
    char *value;
    struct XMLNode **children;
    int child_count;
} XMLNode;

XMLNode *create_node(const char *element, const char *value) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    node->element = strdup(element);
    node->value = strdup(value);
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(XMLNode *parent, XMLNode *child) {
    parent->children = (XMLNode **)realloc(parent->children, sizeof(XMLNode *) * (parent->child_count + 1));
    parent->children[parent->child_count] = child;
    parent->child_count++;
}

void print_xml(XMLNode *node, int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s>", node->element);
    if (node->value) {
        printf("%s</%s>\n", node->value, node->element);
    } else {
        printf("\n");
    }
    
    for (int i = 0; i < node->child_count; i++) {
        print_xml(node->children[i], level + 1);
    }

    if (!node->value) {
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("</%s>\n", node->element);
    }
}

void free_xml(XMLNode *node) {
    for (int i = 0; i < node->child_count; i++) {
        free_xml(node->children[i]);
    }
    free(node->element);
    free(node->value);
    free(node->children);
    free(node);
}

char *get_next_token(const char **input) {
    while (**input && (**input == ' ' || **input == '\n' || **input == '\t')) {
        (*input)++;
    }

    char *token_start = (char *)*input;

    if (**input == '<') { // start of a tag
        while (**input && **input != '>') {
            (*input)++;
        }
        (*input)++; // move past '>'
    } else { // start of a value
        while (**input && **input != '<') {
            (*input)++;
        }
    }

    size_t length = *input - token_start;
    char *token = (char *)malloc(length + 1);
    strncpy(token, token_start, length);
    token[length] = '\0';

    return token;
}

XMLNode *parse_xml(const char *input) {
    const char *ptr = input;
    XMLNode *root = NULL;
    XMLNode *current_node = NULL;

    while (*ptr) {
        char *token = get_next_token(&ptr);

        if (token[0] == '<') {
            if (token[1] != '/') { // opening tag
                char *element = token + 1;
                char *value_start = strchr(element, '>');
                if (value_start) {
                    *value_start = '\0';
                    if (current_node == NULL) {
                        root = create_node(element, NULL);
                        current_node = root;
                    } else {
                        XMLNode *new_node = create_node(element, NULL);
                        add_child(current_node, new_node);
                        current_node = new_node;
                    }
                } else {
                    current_node = create_node(element, NULL);
                    if (root == NULL) {
                        root = current_node;
                    } else {
                        add_child(current_node, current_node);
                    }
                }
            } else { // closing tag
                char *element = token + 2;
                element[strlen(element) - 1] = '\0'; // remove '>'
                if (current_node) {
                    current_node = current_node->children[current_node->child_count - 1];
                }
            }
        } else {
            // capturing node values
            if (current_node && *token) {
                current_node->value = strdup(token);
            }
        }

        free(token);
    }
    return root;
}

int main() {
    const char *xml_data = "<root><child1>Value1</child1><child2><subchild>Value2</subchild></child2></root>";
    
    XMLNode *parsed_xml = parse_xml(xml_data);
    
    if (parsed_xml != NULL) {
        print_xml(parsed_xml, 0);
        free_xml(parsed_xml);
    } else {
        printf("Failed to parse XML.\n");
    }
    
    return 0;
}