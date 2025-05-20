//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LENGTH 20
#define MAX_FILE_NAME_LENGTH 20

typedef struct Node {
    char name[MAX_DIR_NAME_LENGTH];
    struct Node* child;
    struct Node* sibling;
} Node;

void insertNode(Node* parent, Node* newNode) {
    if (parent == NULL) {
        return;
    }

    if (parent->child == NULL) {
        parent->child = newNode;
    } else {
        insertNode(parent->child, newNode);
    }
}

void searchNode(Node* node, char* name) {
    if (strcmp(node->name, name) == 0) {
        return;
    }

    if (node->child != NULL) {
        searchNode(node->child, name);
    }

    if (node->sibling != NULL) {
        searchNode(node->sibling, name);
    }
}

int main() {
    Node* root = NULL;

    // Create a few nodes
    Node* node1 = malloc(sizeof(Node));
    strcpy(node1->name, "Root");
    node1->child = NULL;
    node1->sibling = NULL;

    Node* node2 = malloc(sizeof(Node));
    strcpy(node2->name, "Directory");
    node2->child = NULL;
    node2->sibling = NULL;

    insertNode(node1, node2);

    Node* node3 = malloc(sizeof(Node));
    strcpy(node3->name, "File.txt");
    node3->child = NULL;
    node3->sibling = NULL;

    insertNode(node2, node3);

    // Search for a node
    searchNode(node1, "File.txt");

    return 0;
}