//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char name[MAX_SIZE];
    char value[MAX_SIZE];
    struct node *child;
    struct node *sibling;
} Node;

Node *new_node(const char *name, const char *value) {
    Node *node = malloc(sizeof(Node));
    strcpy(node->name, name);
    strcpy(node->value, value);
    node->child = NULL;
    node->sibling = NULL;
    return node;
}

void parse_xml(const char *xml, Node **root) {
    char tag[MAX_SIZE];
    char value[MAX_SIZE];
    char c;
    int i, j, k;
    Node *node = NULL;
    *root = NULL;
    for (i = 0; xml[i] != '\0'; ) {
        c = xml[i++];
        if (c == '<') {
            if (xml[i] == '/') {
                // closing tag
                i++;
                for (j = 0; xml[i] != '>'; j++)
                    tag[j] = xml[i++];
                tag[j] = '\0';
                if (!node || strcmp(node->name, tag) != 0) {
                    fprintf(stderr, "Error: close tag does not match\n");
                    exit(1);
                }
                node = node->sibling;
            } else {
                // opening tag            
                for (j = 0; xml[i] != '>'; j++)
                    tag[j] = xml[i++];
                tag[j] = '\0';
                i++;
                for (j = 0; xml[i] != '<'; j++)
                    value[j] = xml[i++];
                value[j] = '\0';
                while (xml[i] != '>') i++; // skip rest of tag
                if (*root == NULL) {
                    *root = new_node(tag, value);
                    node = *root;
                } else {
                    node->sibling = new_node(tag, value);
                    node = node->sibling;
                }
                if (xml[i+1] != '/') {
                    node->child = NULL;
                    parse_xml(xml+i+1, &node->child);
                    i++;
                }
            }
        } else if (c != ' ' && c != '\r' && c != '\n' && c != '\t') {
            fprintf(stderr, "Error: invalid character '%c'\n", c);
            exit(1);
        }
    }
}

void print_xml(Node *node, int level) {
    int i;
    for (i = 0; i < level; i++)
        printf("  ");
    printf("<%s>%s</%s>\n", node->name, node->value, node->name);
    if (node->child)
        print_xml(node->child, level+1);
    if (node->sibling)
        print_xml(node->sibling, level);
}

int main() {
    const char *xml = "<root><a>hello</a><b><c>world</c></b><d></d></root>";
    Node *root;
    parse_xml(xml, &root);
    print_xml(root, 0);
    return 0;
}