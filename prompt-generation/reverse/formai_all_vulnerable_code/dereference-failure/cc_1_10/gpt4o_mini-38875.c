//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_NAME 100
#define MAX_NODE_VALUE 255
#define MAX_CHILDREN 10

typedef struct XMLNode {
    char name[MAX_NODE_NAME];
    char value[MAX_NODE_VALUE];
    struct XMLNode *children[MAX_CHILDREN];
    int child_count;
} XMLNode;

XMLNode* create_node(const char *name, const char *value) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    strncpy(node->name, name, MAX_NODE_NAME);
    strncpy(node->value, value, MAX_NODE_VALUE);
    node->child_count = 0;
    return node;
}

void add_child(XMLNode *parent, XMLNode *child) {
    if (parent->child_count < MAX_CHILDREN) {
        parent->children[parent->child_count++] = child;
    } else {
        printf("Error: Maximum child limit reached.\n");
    }
}

void free_xml_tree(XMLNode *node) {
    for (int i = 0; i < node->child_count; i++) {
        free_xml_tree(node->children[i]);
    }
    free(node);
}

void print_xml_node(XMLNode *node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("<%s>", node->name);
    if (strlen(node->value) > 0) {
        printf("%s", node->value);
    }
    printf("\n");
    for (int i = 0; i < node->child_count; i++) {
        print_xml_node(node->children[i], depth + 1);
    }
    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("</%s>\n", node->name);
}

int main() {
    // Create XML structure
    XMLNode *root = create_node("bookstore", "");

    XMLNode *book1 = create_node("book", "");
    add_child(book1, create_node("title", "The Great Gatsby"));
    add_child(book1, create_node("author", "F. Scott Fitzgerald"));
    add_child(book1, create_node("year", "1925"));
    
    XMLNode *book2 = create_node("book", "");
    add_child(book2, create_node("title", "1984"));
    add_child(book2, create_node("author", "George Orwell"));
    add_child(book2, create_node("year", "1949"));

    add_child(root, book1);
    add_child(root, book2);

    // Print the XML structure
    print_xml_node(root, 0);

    // Free memory
    free_xml_tree(root);
    return 0;
}