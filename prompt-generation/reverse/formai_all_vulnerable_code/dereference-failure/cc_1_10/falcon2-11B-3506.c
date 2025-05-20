//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Node structure
struct Node {
    char tag[20];
    struct Node *next;
};

// XML parser functions
struct Node *get_root(char *xml) {
    struct Node *node = NULL;
    char *token = strtok(xml, "<");
    if (token == NULL) {
        return NULL;
    }
    node = malloc(sizeof(struct Node));
    strcpy(node->tag, token);
    token = strtok(NULL, ">");
    if (token == NULL) {
        return NULL;
    }
    node->next = NULL;
    return node;
}

void add_node(struct Node *root, char *token, struct Node *new_node) {
    if (strcmp(token, "<") == 0) {
        root = new_node;
    } else if (strcmp(token, ">") == 0) {
        root->next = new_node;
    } else {
        add_node(root->next, token, new_node);
    }
}

void print_xml(struct Node *node) {
    if (node == NULL) {
        return;
    }
    printf("<%s>\n", node->tag);
    print_xml(node->next);
    printf("</%s>\n", node->tag);
}

int main() {
    char xml[] = "<root><child1>Child 1</child1><child2>Child 2</child2></root>";
    struct Node *root = get_root(xml);
    if (root!= NULL) {
        add_node(root, "<", root);
        add_node(root, "child1", root);
        add_node(root->next, "<", root->next);
        add_node(root->next, "child2", root->next);
        print_xml(root);
    }
    return 0;
}