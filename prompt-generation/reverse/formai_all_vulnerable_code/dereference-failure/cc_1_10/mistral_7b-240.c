//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    char shape;
    struct Node *left, *right;
} Node;

void display(Node *root, int level) {
    int i;
    if (root == NULL)
        return;

    for (i = 0; i < level; i++)
        printf("\t");

    printf("Key : %d, Shape : %c\n", root->key, root->shape);

    if (root->left != NULL)
        display(root->left, level + 1);

    if (root->right != NULL)
        display(root->right, level + 1);
}

Node *newNode(int key, char shape) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->shape = shape;
    node->left = node->right = NULL;
    return node;
}

Node *insert(Node *root, int key, char shape) {
    if (root == NULL)
        return newNode(key, shape);

    if (key < root->key)
        root->left = insert(root->left, key, shape);
    else if (key > root->key)
        root->right = insert(root->right, key, shape);

    return root;
}

int search(Node *root, int key) {
    if (root == NULL || root->key == key)
        return 1;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

int main() {
    int i, keys[] = {20, 30, 40, 50, 60, 70, 80};
    char shapes[] = {'S', 'C', 'M', 'T', 'S', 'C', 'M'};
    Node *root = NULL;

    for (i = 0; i < 7; i++)
        root = insert(root, keys[i], shapes[i]);

    printf("Binary Tree:\n");
    display(root, 0);

    int target = 60;

    if (search(root, target))
        printf("\nElement %d found!\n", target);
    else
        printf("\nElement %d not found!\n", target);

    return 0;
}