//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH + 1];
    int age;
    struct Node *left, *right;
} Node;

Node *new_node(const char *name, int age) {
    Node *new = (Node *) malloc(sizeof(Node));
    strcpy(new->name, name);
    new->age = age;
    new->left = new->right = NULL;
    return new;
}

Node *insert(Node *root, const char *name, int age) {
    if (!root)
        return new_node(name, age);

    if (strcmp(name, root->name) < 0)
        root->left = insert(root->left, name, age);
    else if (strcmp(name, root->name) > 0)
        root->right = insert(root->right, name, age);

    return root;
}

void print_tree(Node *root, int level) {
    if (!root)
        return;

    for (int i = 0; i < level * 2; ++i)
        putchar(' ');

    printf("%s (%d)\n", root->name, root->age);

    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
}

int main() {
    Node *tree = NULL;

    tree = insert(tree, "Alice", 30);
    tree = insert(tree, "Bob", 25);
    tree = insert(tree, "Charlie", 35);
    tree = insert(tree, "David", 28);
    tree = insert(tree, "Eve", 32);

    print_tree(tree, 0);

    return 0;
}