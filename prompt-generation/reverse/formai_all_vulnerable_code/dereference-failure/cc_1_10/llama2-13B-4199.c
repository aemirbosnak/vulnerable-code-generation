//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_NODES 1000
#define MAX_KEY_LEN 20

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
    struct node *parent;
} Node;

typedef struct bst {
    Node *root;
    int num_nodes;
} BST;

#define BST_NULL (struct node *)0xDEADBEEF

void bst_insert(BST *tree, int key);
void bst_delete(BST *tree, int key);
int bst_search(BST *tree, int key);

int main() {
    srand(time(NULL));

    BST *tree = malloc(sizeof(struct bst));
    tree->root = BST_NULL;
    tree->num_nodes = 0;

    for (int i = 0; i < 1000; i++) {
        int key = rand() % 1000;
        bst_insert(tree, key);
    }

    for (int i = 0; i < 1000; i++) {
        int key = rand() % 1000;
        if (bst_search(tree, key) == 0) {
            printf("Found key %d\n", key);
        } else {
            printf("Key %d not found\n", key);
        }
    }

    return 0;
}

void bst_insert(BST *tree, int key) {
    Node *new_node = malloc(sizeof(struct node));
    new_node->key = key;
    new_node->left = BST_NULL;
    new_node->right = BST_NULL;
    new_node->parent = BST_NULL;

    if (tree->root == BST_NULL) {
        tree->root = new_node;
        tree->num_nodes++;
    } else {
        Node *current = tree->root;
        while (current != BST_NULL) {
            if (key < current->key) {
                if (current->left == BST_NULL) {
                    current->left = new_node;
                    break;
                } else {
                    current = current->left;
                }
            } else if (key > current->key) {
                if (current->right == BST_NULL) {
                    current->right = new_node;
                    break;
                } else {
                    current = current->right;
                }
            } else {
                // key already exists, do nothing
                return;
            }
        }
        if (current->left == BST_NULL) {
            current->left = new_node;
        } else {
            current->right = new_node;
        }
    }
}

void bst_delete(BST *tree, int key) {
    Node *current = tree->root;
    Node *prev = BST_NULL;

    while (current != BST_NULL) {
        if (key < current->key) {
            prev = current;
            current = current->left;
        } else if (key > current->key) {
            prev = current;
            current = current->right;
        } else {
            // key found, remove it
            if (current->left == BST_NULL) {
                prev->right = current->right;
            } else if (current->right == BST_NULL) {
                prev->left = current->left;
            } else {
                Node *temp = current->right;
                while (temp->left != BST_NULL) {
                    prev->left = temp->left;
                    temp = temp->left;
                }
                prev->right = temp;
            }
            free(current);
            tree->num_nodes--;
            return;
        }
    }
}

int bst_search(BST *tree, int key) {
    Node *current = tree->root;

    while (current != BST_NULL) {
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return 1;
        }
    }

    return 0;
}