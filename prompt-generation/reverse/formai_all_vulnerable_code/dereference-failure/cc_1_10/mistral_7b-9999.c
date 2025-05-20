//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Node {
    char name[20];
    int height;
    struct Node *left, *right;
} Node;

Node *create_node(char *name) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->height = 0;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int height(Node *node) {
    if (node == NULL)
        return 0;
    else
        return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void update_height(Node *node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

Node *right_rotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    update_height(y);
    update_height(x);

    return x;
}

Node *left_rotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    update_height(x);
    update_height(y);

    return y;
}

Node *insert(Node *node, char *name) {
    if (node == NULL)
        return create_node(name);

    if (strcmp(name, node->name) < 0)
        node->left = insert(node->left, name);
    else if (strcmp(name, node->name) > 0)
        node->right = insert(node->right, name);

    update_height(node);

    int balance = height(node->left) - height(node->right);

    if (balance > 1) {
        if (height(node->left->left) >= height(node->left->right))
            node = right_rotate(node);
        else {
            node->left = left_rotate(node->left);
            node = right_rotate(node);
        }
    }

    return node;
}

void print_tree(Node *root, int space) {
    if (root == NULL)
        return;

    space += 10;

    print_tree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%s\n", root->name);

    print_tree(root->left, space);
}

int main() {
    Node *root = NULL;

    char names[20][20] = {
        "Apple", "Banana", "Cherry", "Durian", "Elderberry", "Fig",
        "Grapefruit", "Honeydew", "Jackfruit", "Kiwi", "Lemon",
        "Mango", "Orange", "Pineapple", "Quince", "Raspberry", "Strawberry",
        "Watermelon", "Yellow passion fruit"};

    for (int i = 0; i < 14; i++)
        root = insert(root, names[i]);

    print_tree(root, 0);

    return 0;
}