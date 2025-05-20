//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define verify(expr,msg) ((expr) ? (void)0 : (printf("%s:%d: Assertion failed: %s\n", __FILE__, __LINE__, msg), abort()))

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

typedef struct Tree {
    Node *root;
} Tree;

static Node *insert(Node *node, int val) {
    if (node == NULL) {
        node = malloc(sizeof(Node));
        node->val = val;
        node->left = node->right = NULL;
    } else if (val < node->val) {
        node->left = insert(node->left, val);
    } else {
        node->right = insert(node->right, val);
    }
    return node;
}

static Node *search(Node *node, int val) {
    if (node == NULL) {
        return NULL;
    } else if (val == node->val) {
        return node;
    } else if (val < node->val) {
        return search(node->left, val);
    } else {
        return search(node->right, val);
    }
}

static void destroy(Node *node) {
    if (node == NULL) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    free(node);
}

int main() {
    Tree tree = { NULL };

    for (int i = 0; i < 100; ++i) {
        tree.root = insert(tree.root, rand());
    }

    for (int i = 0; i < 100; ++i) {
        int val = rand();
        verify(search(tree.root, val) != NULL, "Search failed");
    }

    destroy(tree.root);
    return 0;
}