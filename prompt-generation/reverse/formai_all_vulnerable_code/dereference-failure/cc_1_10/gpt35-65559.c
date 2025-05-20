//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *name;
    char *value;
    struct Node *next;
} Node;

void print_tree(Node *root, int depth) {
    if (root == NULL) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("<%s>", root->name);
    if (root->value != NULL) printf("%s", root->value);
    printf("\n");
    print_tree(root->next, depth + 1);
    for (int i = 0; i < depth; i++) printf("  ");
    printf("</%s>\n", root->name);
}

Node *parse_xml(char *xml) {
    Node *root = NULL;
    Node *current = NULL;
    char *start = strchr(xml, '<');
    while (start != NULL) {
        if (start[1] == '/') current = current->next;
        else {
            Node *node = malloc(sizeof(Node));
            node->name = strdup(start + 1);
            char *end = strchr(node->name, '>');
            if (end) *end = '\0';
            node->value = NULL;
            node->next = NULL;
            if (root == NULL) root = current = node;
            else {
                current->next = node;
                current = node;
            }
            start = end;
        }
        start = strchr(start + 1, '<');
    }
    return root;
}

int main() {
    char xml[] = "<xml><name>John</name><age>30</age><city>New York</city></xml>";
    Node *tree = parse_xml(xml);
    print_tree(tree, 0);
    return 0;
}