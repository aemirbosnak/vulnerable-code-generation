//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

typedef struct Node {
    char name[20];
    int age;
    struct Node *left, *right;
} Node;

Node* newNode(char *name, int age) {
    Node *new = (Node*) malloc(sizeof(Node));
    strcpy(new->name, name);
    new->age = age;
    new->left = new->right = NULL;
    return new;
}

Node* insert(Node *root, Node *node) {
    if (root == NULL) {
        root = node;
    } else {
        if (strcmp(node->name, root->name) < 0) {
            root->left = insert(root->left, node);
        } else {
            root->right = insert(root->right, node);
        }
    }
    return root;
}

void printTree(Node *root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("%s (%d)\n", root->name, root->age);
    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}

int main(void) {
    Node *root = NULL;

    root = insert(root, newNode("Alice", 25));
    root = insert(root, newNode("Bob", 30));
    root = insert(root, newNode("Charlie", 22));
    root = insert(root, newNode("David", 28));
    root = insert(root, newNode("Eve", 35));

    printTree(root, 0);

    return 0;
}