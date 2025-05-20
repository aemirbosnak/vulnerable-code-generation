//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_KEY_LENGTH 100

typedef struct node {
    char key[MAX_KEY_LENGTH];
    struct node *left, *right;
} Node;

Node *create_node(const char *key) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->key, key);
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node *insert(Node *root, const char *key) {
    if (root == NULL) {
        root = create_node(key);
    } else if (strcmp(key, root->key) < 0) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder_traversal(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%s ", root->key);
    inorder_traversal(root->right);
}

int main() {
    Node *root = NULL;
    char keys[10][MAX_KEY_LENGTH] = {
        "apple",
        "banana",
        "cherry",
        "date",
        "elderberry",
        "fig",
        "grape",
        "honeydew",
        "kiwi",
        "lemon"};

    for (int i = 0; i < 10; ++i) {
        root = insert(root, keys[i]);
    }

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}