//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

struct node* find_min(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return find_min(root->left);
    }
}

struct node* find_max(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        return find_max(root->right);
    }
}

int find_height(struct node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

void print_inorder(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}

void print_preorder(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        printf("%d ", root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

void print_postorder(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    printf("Inorder traversal: ");
    print_inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    print_preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    print_postorder(root);
    printf("\n");

    printf("Minimum value: %d\n", find_min(root)->data);
    printf("Maximum value: %d\n", find_max(root)->data);
    printf("Height of the tree: %d\n", find_height(root));

    return 0;
}