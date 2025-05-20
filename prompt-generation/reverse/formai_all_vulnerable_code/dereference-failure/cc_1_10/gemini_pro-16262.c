//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

struct TreeNode *create_node(int data) {
    struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct TreeNode *insert_node(struct TreeNode *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

struct TreeNode *find_minimum(struct TreeNode *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return find_minimum(root->left);
    }
}

struct TreeNode *find_maximum(struct TreeNode *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        return find_maximum(root->right);
    }
}

int find_height(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

void print_tree(struct TreeNode *root) {
    if (root == NULL) {
        return;
    } else {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}

struct TreeNode *mirror_tree(struct TreeNode *root) {
    if (root == NULL) {
        return NULL;
    } else {
        struct TreeNode *left_mirror = mirror_tree(root->left);
        struct TreeNode *right_mirror = mirror_tree(root->right);
        root->left = right_mirror;
        root->right = left_mirror;
        return root;
    }
}

int main() {
    struct TreeNode *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);
    printf("Inorder traversal: ");
    print_tree(root);
    printf("\n");
    printf("Minimum value in the tree: %d\n", find_minimum(root)->data);
    printf("Maximum value in the tree: %d\n", find_maximum(root)->data);
    printf("Height of the tree: %d\n", find_height(root));
    printf("Mirrored tree: ");
    print_tree(mirror_tree(root));
    printf("\n");
    return 0;
}