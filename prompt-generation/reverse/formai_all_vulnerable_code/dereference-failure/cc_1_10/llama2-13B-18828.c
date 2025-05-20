//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_KEYS 100

typedef struct node {
    int key;
    struct node *left, *right;
} Node;

typedef struct bst {
    Node *root;
} BST;

void insert(BST *bst, int key);
Node* search(BST *bst, int key);
void print(BST *bst);

int main() {
    srand(time(NULL));

    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;

    for (int i = 0; i < MAX_NODES; i++) {
        int key = rand() % MAX_KEYS;
        insert(bst, key);
    }

    print(bst);

    return 0;
}

void insert(BST *bst, int key) {
    Node *new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    if (bst->root == NULL) {
        bst->root = new_node;
    } else {
        Node *current = bst->root;
        while (current != NULL) {
            if (key < current->key) {
                if (current->left == NULL) {
                    current->left = new_node;
                    break;
                } else {
                    insert(current->left, key);
                }
            } else if (key > current->key) {
                if (current->right == NULL) {
                    current->right = new_node;
                    break;
                } else {
                    insert(current->right, key);
                }
            }
            current = current->left != NULL ? current->left : current->right;
        }
    }
}

Node* search(BST *bst, int key) {
    Node *current = bst->root;
    while (current != NULL) {
        if (key == current->key) {
            return current;
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

void print(BST *bst) {
    Node *current = bst->root;
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->left != NULL ? current->left : current->right;
    }
    printf("\n");
}