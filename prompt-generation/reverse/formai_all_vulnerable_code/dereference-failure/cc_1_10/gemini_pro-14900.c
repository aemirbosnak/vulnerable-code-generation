//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct bnode {
    int val;
    struct bnode *left, *right;
} bnode;

bnode* bnode_new(int val) {
    bnode *node = malloc(sizeof(bnode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int bnode_is_leaf(bnode *node) {
    return !node->left && !node->right;
}

void bnode_free(bnode *node) {
    if (node) {
        bnode_free(node->left);
        bnode_free(node->right);
        free(node);
    }
}

void bnode_print_tree(bnode *node) {
    if (node) {
        bnode_print_tree(node->left);
        printf("%d ", node->val);
        bnode_print_tree(node->right);
    }
}

void bnode_insert(bnode **node, int val) {
    if (!*node) {
        *node = bnode_new(val);
    } else if (val < (*node)->val) {
        bnode_insert(&(*node)->left, val);
    } else {
        bnode_insert(&(*node)->right, val);
    }
}

int bnode_find(bnode *node, int val) {
    if (!node) {
        return 0;
    } else if (node->val == val) {
        return 1;
    } else if (val < node->val) {
        return bnode_find(node->left, val);
    } else {
        return bnode_find(node->right, val);
    }
}

int bnode_max(bnode *node) {
    if (!node) {
        return 0;
    }
    while (node->right) {
        node = node->right;
    }
    return node->val;
}

int bnode_min(bnode *node) {
    if (!node) {
        return 0;
    }
    while (node->left) {
        node = node->left;
    }
    return node->val;
}

int bnode_height(bnode *node) {
    if (!node) {
        return 0;
    }
    int left_height = bnode_height(node->left);
    int right_height = bnode_height(node->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

int bnode_is_balanced(bnode *node) {
    if (!node) {
        return 1;
    }
    int left_height = bnode_height(node->left);
    int right_height = bnode_height(node->right);
    return abs(left_height - right_height) <= 1 && bnode_is_balanced(node->left) && bnode_is_balanced(node->right);
}

bnode* bnode_remove(bnode *node, int val) {
    if (!node) {
        return NULL;
    }
    if (val < node->val) {
        node->left = bnode_remove(node->left, val);
    } else if (val > node->val) {
        node->right = bnode_remove(node->right, val);
    } else {
        if (bnode_is_leaf(node)) {
            free(node);
            return NULL;
        } else if (!node->left) {
            bnode *tmp = node->right;
            free(node);
            return tmp;
        } else if (!node->right) {
            bnode *tmp = node->left;
            free(node);
            return tmp;
        } else {
            node->val = bnode_min(node->right);
            node->right = bnode_remove(node->right, node->val);
        }
    }
    return node;
}

int main() {
    bnode *root = NULL;
    bnode_insert(&root, 10);
    bnode_insert(&root, 5);
    bnode_insert(&root, 15);
    bnode_insert(&root, 2);
    bnode_insert(&root, 7);
    bnode_insert(&root, 12);
    bnode_insert(&root, 20);
    bnode_print_tree(root);
    printf("\n");
    printf("Is the tree balanced? %d\n", bnode_is_balanced(root));
    printf("Maximum value in the tree: %d\n", bnode_max(root));
    printf("Minimum value in the tree: %d\n", bnode_min(root));
    printf("Height of the tree: %d\n", bnode_height(root));
    printf("Is the value 10 present in the tree? %d\n", bnode_find(root, 10));
    printf("Is the value 17 present in the tree? %d\n", bnode_find(root, 17));
    bnode_remove(&root, 10);
    bnode_print_tree(root);
    printf("\n");
    bnode_free(root);
    return 0;
}