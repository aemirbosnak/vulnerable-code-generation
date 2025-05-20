//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LEN 100

typedef struct _XMLNode {
    char *name;
    char *value;
    struct _XMLNode *next;
    struct _XMLNode *parent;
    struct _XMLNode *first_child;
    struct _XMLNode *last_child;
} XMLNode;

XMLNode *create_node(const char *name, const char *value) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    if (!node) {
        return NULL;
    }
    node->name = (char *)malloc(strlen(name) + 1);
    if (!node->name) {
        free(node);
        return NULL;
    }
    strcpy(node->name, name);
    node->value = (char *)malloc(strlen(value) + 1);
    if (!node->value) {
        free(node->name);
        free(node);
        return NULL;
    }
    strcpy(node->value, value);
    node->next = NULL;
    node->parent = NULL;
    node->first_child = NULL;
    node->last_child = NULL;
    return node;
}

void destroy_node(XMLNode *node) {
    if (!node) {
        return;
    }
    destroy_node(node->first_child);
    destroy_node(node->next);
    free(node->name);
    free(node->value);
    free(node);
}

int parse_xml(const char *xml, XMLNode **root) {
    char tag_name[MAX_TAG_NAME_LEN + 1];
    char value[1024];
    int tag_depth = 0;
    int in_tag = 0;
    int in_value = 0;
    XMLNode *current_node = NULL;
    XMLNode *parent_node = NULL;

    for (const char *p = xml; *p; p++) {
        if (*p == '<') {
            in_tag = 1;
            in_value = 0;
            tag_depth++;
            memset(tag_name, 0, sizeof(tag_name));
        } else if (*p == '>') {
            in_tag = 0;
            in_value = 1;
            memset(value, 0, sizeof(value));
            if (tag_depth == 1) {
                *root = create_node(tag_name, value);
                current_node = *root;
                parent_node = *root;
            } else {
                XMLNode *node = create_node(tag_name, value);
                if (!node) {
                    return -1;
                }
                node->parent = parent_node;
                if (!parent_node->first_child) {
                    parent_node->first_child = node;
                } else {
                    parent_node->last_child->next = node;
                }
                parent_node->last_child = node;
                current_node = node;
            }
        } else if (*p == '/') {
            if (in_tag) {
                tag_depth--;
                if (tag_depth == 0) {
                    current_node = parent_node;
                } else if (tag_depth == 1) {
                    parent_node = *root;
                } else {
                    parent_node = parent_node->parent;
                }
            }
        } else if (in_tag) {
            strncat(tag_name, p, 1);
        } else if (in_value) {
            strncat(value, p, 1);
        }
    }

    return 0;
}

void print_node(XMLNode *node, int depth) {
    if (!node) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("%s: %s\n", node->name, node->value);
    print_node(node->first_child, depth + 1);
    print_node(node->next, depth);
}

void free_xml(XMLNode *root) {
    if (!root) {
        return;
    }
    free_xml(root->first_child);
    free_xml(root->next);
    free(root->name);
    free(root->value);
    free(root);
}

int main() {
    const char *xml = "<root><child1>value1</child1><child2><grandchild1>value2</grandchild1><grandchild2>value3</grandchild2></child2></root>";
    XMLNode *root = NULL;
    int ret = parse_xml(xml, &root);
    if (ret != 0) {
        fprintf(stderr, "Error parsing XML: %d\n", ret);
        return 1;
    }
    print_node(root, 0);
    free_xml(root);
    return 0;
}