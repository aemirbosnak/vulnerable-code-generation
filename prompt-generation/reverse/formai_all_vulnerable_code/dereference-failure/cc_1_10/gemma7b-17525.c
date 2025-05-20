//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

// Define an XML node structure
typedef struct xml_node {
    char *name;
    struct xml_node *parent;
    struct xml_node **children;
    int child_count;
} xml_node;

xml_node *xml_node_create(char *name)
{
    xml_node *node = (xml_node *)malloc(sizeof(xml_node));
    node->name = strdup(name);
    node->parent = NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void xml_node_add_child(xml_node *parent, xml_node *child)
{
    parent->children = realloc(parent->children, (parent->child_count + 1) * sizeof(xml_node *));
    parent->children[parent->child_count++] = child;
    child->parent = parent;
}

void xml_node_print(xml_node *node)
{
    printf("<%s>", node->name);
    for (int i = 0; i < node->child_count; i++) {
        xml_node_print(node->children[i]);
    }
    printf(">\n");
}

int main()
{
    xml_node *root = xml_node_create("root");
    xml_node *child1 = xml_node_create("child1");
    xml_node *child2 = xml_node_create("child2");
    xml_node_add_child(root, child1);
    xml_node_add_child(root, child2);

    xml_node_print(root);

    return 0;
}