//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdlib.h>
#include <pthread.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BinarySearchTree {
    TreeNode *root;
    pthread_mutex_t lock;
} BinarySearchTree;

BinarySearchTree *create_binary_search_tree() {
    BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
    tree->root = NULL;
    pthread_mutex_init(&tree->lock, NULL);
    return tree;
}

void insert_node(BinarySearchTree *tree, int data) {
    pthread_mutex_lock(&tree->lock);

    TreeNode *new_node = malloc(sizeof(TreeNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        TreeNode *current_node = tree->root;
        while (current_node != NULL) {
            if (data < current_node->data) {
                if (current_node->left == NULL) {
                    current_node->left = new_node;
                    break;
                } else {
                    current_node = current_node->left;
                }
            } else {
                if (current_node->right == NULL) {
                    current_node->right = new_node;
                    break;
                } else {
                    current_node = current_node->right;
                }
            }
        }
    }

    pthread_mutex_unlock(&tree->lock);
}

int search_node(BinarySearchTree *tree, int data) {
    pthread_mutex_lock(&tree->lock);

    TreeNode *current_node = tree->root;
    while (current_node != NULL) {
        if (data == current_node->data) {
            pthread_mutex_unlock(&tree->lock);
            return 1;
        } else if (data < current_node->data) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }

    pthread_mutex_unlock(&tree->lock);
    return 0;
}

void delete_node(BinarySearchTree *tree, int data) {
    pthread_mutex_lock(&tree->lock);

    TreeNode *current_node = tree->root;
    TreeNode *parent_node = NULL;
    while (current_node != NULL) {
        if (data == current_node->data) {
            break;
        } else if (data < current_node->data) {
            parent_node = current_node;
            current_node = current_node->left;
        } else {
            parent_node = current_node;
            current_node = current_node->right;
        }
    }

    if (current_node == NULL) {
        pthread_mutex_unlock(&tree->lock);
        return;
    }

    if (current_node->left == NULL && current_node->right == NULL) {
        if (parent_node == NULL) {
            tree->root = NULL;
        } else if (parent_node->left == current_node) {
            parent_node->left = NULL;
        } else {
            parent_node->right = NULL;
        }
        free(current_node);
    } else if (current_node->left == NULL) {
        if (parent_node == NULL) {
            tree->root = current_node->right;
        } else if (parent_node->left == current_node) {
            parent_node->left = current_node->right;
        } else {
            parent_node->right = current_node->right;
        }
        free(current_node);
    } else if (current_node->right == NULL) {
        if (parent_node == NULL) {
            tree->root = current_node->left;
        } else if (parent_node->left == current_node) {
            parent_node->left = current_node->left;
        } else {
            parent_node->right = current_node->left;
        }
        free(current_node);
    } else {
        TreeNode *successor_node = current_node->right;
        TreeNode *successor_parent_node = current_node;
        while (successor_node->left != NULL) {
            successor_parent_node = successor_node;
            successor_node = successor_node->left;
        }

        current_node->data = successor_node->data;

        if (successor_parent_node == current_node) {
            successor_parent_node->right = successor_node->right;
        } else {
            successor_parent_node->left = successor_node->right;
        }

        free(successor_node);
    }

    pthread_mutex_unlock(&tree->lock);
}

void print_tree(BinarySearchTree *tree) {
    pthread_mutex_lock(&tree->lock);

    TreeNode *current_node = tree->root;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->right;
    }

    printf("\n");

    pthread_mutex_unlock(&tree->lock);
}

int main() {
    BinarySearchTree *tree = create_binary_search_tree();

    insert_node(tree, 10);
    insert_node(tree, 5);
    insert_node(tree, 15);
    insert_node(tree, 2);
    insert_node(tree, 7);
    insert_node(tree, 12);
    insert_node(tree, 20);

    print_tree(tree);

    if (search_node(tree, 15)) {
        printf("Found 15\n");
    } else {
        printf("Did not find 15\n");
    }

    if (search_node(tree, 13)) {
        printf("Found 13\n");
    } else {
        printf("Did not find 13\n");
    }

    delete_node(tree, 15);

    print_tree(tree);

    delete_node(tree, 10);

    print_tree(tree);

    return 0;
}