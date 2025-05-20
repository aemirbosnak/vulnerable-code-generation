//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: puzzling
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *name;
    char *value;
    struct Node *next;
    struct Node *child;
} Node;

Node *create_node(char *name, char *value) {
    Node *node = malloc(sizeof(Node));
    node->name = strdup(name);
    node->value = strdup(value);
    node->next = NULL;
    node->child = NULL;
    return node;
}

void free_node(Node *node) {
    if (node->name) free(node->name);
    if (node->value) free(node->value);
    if (node->child) free_node(node->child);
    if (node->next) free_node(node->next);
    free(node);
}

Node *parse_xml(char *xml) {
    Node *root = NULL;
    Node *current = NULL;
    char *token = strtok(xml, "<>");
    while (token) {
        if (!strcmp(token, "/")) {
            current = current->next;
        } else if (!current) {
            root = create_node(token, NULL);
            current = root;
        } else {
            char *value = strtok(NULL, "<>");
            Node *child = create_node(token, value);
            current->child = child;
            current = child;
        }
        token = strtok(NULL, "<>");
    }
    return root;
}

void print_xml(Node *node) {
    if (!node) return;
    printf("<%s>", node->name);
    if (node->value) printf("%s", node->value);
    if (node->child) print_xml(node->child);
    printf("</%s>", node->name);
    if (node->next) print_xml(node->next);
}

int main() {
    char *xml = "<root><child1>value1</child1><child2>value2</child2><child3><innerchild>value3</innerchild></child3></root>";
    Node *root = parse_xml(xml);
    print_xml(root);
    free_node(root);
    return 0;
}