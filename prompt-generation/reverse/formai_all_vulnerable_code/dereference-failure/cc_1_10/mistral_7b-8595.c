//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char name[20];
    int age;
    struct Node *left, *right;
} Node;

void printTree(Node *root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("%s (%d years)\n", root->name, root->age);

    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}

int main() {
    Node *node1 = (Node *)malloc(sizeof(Node));
    Node *node2 = (Node *)malloc(sizeof(Node));
    Node *node3 = (Node *)malloc(sizeof(Node));
    Node *node4 = (Node *)malloc(sizeof(Node));
    Node *node5 = (Node *)malloc(sizeof(Node));

    strcpy(node1->name, "Alice");
    node1->age = 25;
    node1->left = NULL;
    node1->right = node2;

    strcpy(node2->name, "Bob");
    node2->age = 30;
    node2->left = node3;
    node2->right = node4;

    strcpy(node3->name, "Charlie");
    node3->age = 20;
    node3->left = NULL;
    node3->right = node5;

    strcpy(node4->name, "David");
    node4->age = 35;
    node4->left = NULL;
    node4->right = NULL;

    strcpy(node5->name, "Eve");
    node5->age = 28;
    node5->left = NULL;
    node5->right = NULL;

    printTree(node1, 0);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);

    return 0;
}