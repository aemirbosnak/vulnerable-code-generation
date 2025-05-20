//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XML_BUFFER_SIZE 256

typedef struct XML_Node {
    char *data;
    struct XML_Node *next;
    struct XML_Node *child;
    struct XML_Node *parent;
} XML_Node;

XML_Node *xml_node_create(char *data)
{
    XML_Node *node = malloc(sizeof(XML_Node));
    node->data = strdup(data);
    node->next = NULL;
    node->child = NULL;
    node->parent = NULL;

    return node;
}

void xml_node_add_child(XML_Node *parent, XML_Node *child)
{
    parent->child = child;
    child->parent = parent;
}

void xml_node_print(XML_Node *node)
{
    printf("%s", node->data);

    if (node->child)
    {
        xml_node_print(node->child);
    }
}

int main()
{
    XML_Node *root = xml_node_create("root");
    XML_Node *child1 = xml_node_create("child1");
    XML_Node *child2 = xml_node_create("child2");

    xml_node_add_child(root, child1);
    xml_node_add_child(root, child2);

    xml_node_print(root);

    return 0;
}