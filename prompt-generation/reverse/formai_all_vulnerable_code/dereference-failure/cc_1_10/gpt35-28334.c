//FormAI DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(struct node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }
    if (data < (*root)->data) {
        insert_node(&((*root)->left), data);
    }
    else {
        insert_node(&((*root)->right), data);
    }
}

void inorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void visualize_tree(struct node *root, int level) {
    if (root == NULL) {
        return;
    }
    visualize_tree(root->right, level + 1);
    for (int i = 1; i <= level; i++) {
        printf("\t");
    }
    printf("%d\n", root->data);
    visualize_tree(root->left, level + 1);
}

int main() {
    struct node *root = NULL;
    insert_node(&root, 50);
    insert_node(&root, 30);
    insert_node(&root, 70);
    insert_node(&root, 20);
    insert_node(&root, 40);
    insert_node(&root, 60);
    insert_node(&root, 80);
    printf("Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n\nVisualizing the Tree:\n\n");
    visualize_tree(root, 0);
    return 0;
}