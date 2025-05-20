//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_KEY 100

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

typedef struct BinarySearchTree {
    Node *root;
} BinarySearchTree;

void insert(BinarySearchTree *tree, int key);
Node* search(BinarySearchTree *tree, int key);
void print(BinarySearchTree *tree);

int main() {
    BinarySearchTree *tree = (BinarySearchTree *) malloc(sizeof(BinarySearchTree));
    tree->root = NULL;

    // Insert some happy nodes
    insert(tree, 10);
    insert(tree, 20);
    insert(tree, 30);
    insert(tree, 40);
    insert(tree, 50);

    // Print the happy tree
    print(tree);

    return 0;
}

void insert(BinarySearchTree *tree, int key) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        Node *current = tree->root;
        while (current != NULL) {
            if (key < current->key) {
                if (current->left == NULL) {
                    current->left = new_node;
                    break;
                } else {
                    insert(current->left, key);
                    break;
                }
            } else if (key > current->key) {
                if (current->right == NULL) {
                    current->right = new_node;
                    break;
                } else {
                    insert(current->right, key);
                    break;
                }
            }
            current = current->left != NULL ? current->left : current->right;
        }
    }
}

Node* search(BinarySearchTree *tree, int key) {
    Node *current = tree->root;
    while (current != NULL) {
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return current;
        }
    }
    return NULL;
}

void print(BinarySearchTree *tree) {
    Node *current = tree->root;
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->left != NULL ? current->left : current->right;
    }
    printf("\n");
}