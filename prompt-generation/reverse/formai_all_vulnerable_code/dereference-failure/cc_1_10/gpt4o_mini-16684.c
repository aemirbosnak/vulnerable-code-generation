//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a node in the XML Tree
typedef struct Node {
    char *name;
    char *value;
    struct Node *parent;
    struct Node **children;
    int child_count;
} Node;

// Function to create a new Node
Node* createNode(const char* name, const char* value, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = strdup(name);
    newNode->value = value ? strdup(value) : NULL;
    newNode->parent = parent;
    newNode->child_count = 0;
    newNode->children = NULL;

    return newNode;
}

// Function to add a child to a parent Node
void addChild(Node* parent, Node* child) {
    parent->children = (Node**)realloc(parent->children, sizeof(Node*) * (parent->child_count + 1));
    parent->children[parent->child_count] = child;
    parent->child_count++;
}

// Function to print the XML Tree
void printXMLTree(Node* node, int level) {
    if (!node) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    
    if (node->value) {
        printf("<%s>%s</%s>\n", node->name, node->value, node->name);
    } else {
        printf("<%s>\n", node->name);
        for (int i = 0; i < node->child_count; i++) {
            printXMLTree(node->children[i], level + 1);
        }
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("</%s>\n", node->name);
    }
}

// Function to free the XML Tree
void freeXMLTree(Node* node) {
    if (!node) return;

    for (int i = 0; i < node->child_count; i++) {
        freeXMLTree(node->children[i]);
    }

    free(node->name);
    if (node->value) {
        free(node->value);
    }
    free(node->children);
    free(node);
}

// Main function to demonstrate XML parsing
int main() {
    printf("Creating an XML tree...\n");

    Node* root = createNode("bookstore", NULL, NULL);
    
    Node* book1 = createNode("book", NULL, root);
    addChild(root, book1);
    
    Node* title1 = createNode("title", "The Great Gatsby", book1);
    addChild(book1, title1);
    
    Node* author1 = createNode("author", "F. Scott Fitzgerald", book1);
    addChild(book1, author1);
    
    Node* price1 = createNode("price", "10.99", book1);
    addChild(book1, price1);
    
    Node* book2 = createNode("book", NULL, root);
    addChild(root, book2);
    
    Node* title2 = createNode("title", "1984", book2);
    addChild(book2, title2);
    
    Node* author2 = createNode("author", "George Orwell", book2);
    addChild(book2, author2);
    
    Node* price2 = createNode("price", "8.99", book2);
    addChild(book2, price2);

    printf("Printing the XML tree...\n");
    printXMLTree(root, 0);
    
    freeXMLTree(root);
    printf("XML tree freed!\n");

    return 0;
}