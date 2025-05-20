//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// A trusty node to hold our data
struct Node {
    int data;
    struct Node *left, *right;
};

// Our very own binary search tree
struct Tree {
    struct Node *root;
};

// The grand creator of nodes
struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// The master inserter, placing nodes in their rightful place
struct Node *insert(struct Tree *tree, struct Node *node, int data) {
    if (tree->root == NULL) {
        tree->root = createNode(data);
        return tree->root;
    }
    if (data < node->data) {
        if (node->left == NULL) {
            node->left = createNode(data);
            return node->left;
        } else {
            return insert(tree, node->left, data);
        }
    } else {
        if (node->right == NULL) {
            node->right = createNode(data);
            return node->right;
        } else {
            return insert(tree, node->right, data);
        }
    }
}

// The swift searcher, finding your data in a flash
struct Node *search(struct Tree *tree, struct Node *node, int data) {
    if (node == NULL) {
        return NULL;
    }
    if (data == node->data) {
        return node;
    } else if (data < node->data) {
        return search(tree, node->left, data);
    } else {
        return search(tree, node->right, data);
    }
}

// The graceful printer, displaying your tree's beauty
void printTree(struct Tree *tree, struct Node *node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    printTree(tree, node->left);
    printTree(tree, node->right);
}

// The fearless destroyer, freeing your tree from memory's grasp
void destroyTree(struct Tree *tree, struct Node *node) {
    if (node == NULL) {
        return;
    }
    destroyTree(tree, node->left);
    destroyTree(tree, node->right);
    free(node);
}

int main() {
    // Let's create our very own binary search tree!
    struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
    tree->root = NULL;

    // Time to populate our tree with some exciting data!
    insert(tree, tree->root, 10);
    insert(tree, tree->root, 5);
    insert(tree, tree->root, 15);
    insert(tree, tree->root, 2);
    insert(tree, tree->root, 7);
    insert(tree, tree->root, 12);
    insert(tree, tree->root, 20);

    // Let's see our magnificent tree in all its glory!
    printf("In-order traversal: ");
    printTree(tree, tree->root);
    printf("\n");

    // Now, let's search for a particular piece of data. Say, the number 12?
    struct Node *foundNode = search(tree, tree->root, 12);
    if (foundNode != NULL) {
        printf("Found %d in the tree!\n", foundNode->data);
    } else {
        printf("Sorry, couldn't find your data in the tree.\n");
    }

    // Time to bid farewell to our beloved tree and free its memory.
    destroyTree(tree, tree->root);
    free(tree);

    return 0;
}