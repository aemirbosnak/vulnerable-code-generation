//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LEN 256

typedef struct Node {
    char name[MAX_DIR_NAME_LEN];
    struct Node* next;
    struct Node* child;
} Node;

void traverse(Node* node) {
    printf("%s ", node->name);
    if (node->child) {
        traverse(node->child);
    }
}

int main() {
    Node* root = NULL;

    // Create a few nodes
    Node* node1 = malloc(sizeof(Node));
    strcpy(node1->name, "node1");
    node1->next = NULL;
    node1->child = NULL;

    Node* node2 = malloc(sizeof(Node));
    strcpy(node2->name, "node2");
    node2->next = NULL;
    node2->child = NULL;

    Node* node3 = malloc(sizeof(Node));
    strcpy(node3->name, "node3");
    node3->next = NULL;
    node3->child = NULL;

    Node* node4 = malloc(sizeof(Node));
    strcpy(node4->name, "node4");
    node4->next = NULL;
    node4->child = NULL;

    // Link the nodes
    node1->child = node2;
    node2->child = node3;
    node3->child = node4;

    // Traverse the tree
    traverse(root);

    return 0;
}