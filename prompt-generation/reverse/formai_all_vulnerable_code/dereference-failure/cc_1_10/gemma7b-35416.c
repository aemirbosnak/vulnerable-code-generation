//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XML_MAX_SIZE 1024

struct xml_node {
    char *name;
    struct xml_node *parent;
    struct xml_node **children;
    int child_count;
};

void xml_parse(struct xml_node *node, char *xml_data) {
    char *start = xml_data;
    char *end = xml_data + strlen(xml_data);

    while (start < end) {
        char *tag_start = strstr(start, "<");
        char *tag_end = strstr(start, ">");

        if (tag_start && tag_end) {
            char *node_name = malloc(tag_end - tag_start);
            memcpy(node_name, tag_start + 1, tag_end - tag_start - 1);

            struct xml_node *new_node = malloc(sizeof(struct xml_node));
            new_node->name = node_name;
            new_node->parent = node;

            if (node) {
                new_node->children = &node->children;
                node->child_count++;
            }

            xml_parse(new_node, tag_end + 1);
        } else {
            start++;
        }
    }
}

int main() {
    char xml_data[] = "<root><foo>bar</foo><bar>baz</bar></root>";

    struct xml_node *root = malloc(sizeof(struct xml_node));
    root->name = "root";

    xml_parse(root, xml_data);

    printf("Child count of root: %d\n", root->child_count);

    return 0;
}