//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[32];
    int level;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(char* name, int level) {
    Node* node = (Node*) malloc(sizeof(Node));
    strcpy(node->name, name);
    node->level = level;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertNode(Node* root, char* name, int level) {
    if (root == NULL) {
        root = newNode(name, level);
    } else if (strcmp(name, root->name) < 0) {
        root->left = insertNode(root->left, name, level + 1);
    } else {
        root->right = insertNode(root->right, name, level + 1);
    }
    return root;
}

void printTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 10;
    printTree(root->right, space);
    for (int i = 10; i < space; i++) {
        putchar(' ');
    }
    printf("%s\n", root->name);
    printTree(root->left, space);
}

int main() {
    Node* root = NULL;
    root = insertNode(root, "Elrond", 0);
    root = insertNode(root, "Gandalf", 1);
    root = insertNode(root, "Saruman", 2);
    root = insertNode(root, "Radagast", 3);
    root = insertNode(root, "Sauron", 4);
    root = insertNode(root, "Boromir", 5);
    root = insertNode(root, "Frodo", 6);
    root = insertNode(root, "Sam", 7);
    root = insertNode(root, "Merry", 8);
    root = insertNode(root, "Pippin", 9);
    printTree(root, 0);
    return 0;
}