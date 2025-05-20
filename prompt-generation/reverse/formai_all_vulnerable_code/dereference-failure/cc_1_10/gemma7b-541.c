//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct xml_node {
    char *name;
    struct xml_node *parent;
    struct xml_node **children;
    int child_count;
} xml_node;

xml_node *xml_node_create(char *name) {
    xml_node *node = malloc(sizeof(xml_node));
    node->name = strdup(name);
    node->parent = NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void xml_node_add_child(xml_node *parent, xml_node *child) {
    parent->children = realloc(parent->children, (parent->child_count + 1) * sizeof(xml_node *));
    parent->children[parent->child_count++] = child;
}

int xml_node_search(xml_node *node, char *name) {
    if (strcmp(node->name, name) == 0) {
        return 1;
    } else if (node->children) {
        for (int i = 0; i < node->child_count; i++) {
            if (xml_node_search(node->children[i], name) == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    xml_node *root = xml_node_create("root");
    xml_node *child1 = xml_node_create("child1");
    xml_node *child2 = xml_node_create("child2");
    xml_node_add_child(root, child1);
    xml_node_add_child(root, child2);

    if (xml_node_search(root, "child1") == 1) {
        printf("Child 1 found.\n");
    }

    return 0;
}