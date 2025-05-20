//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(struct node* node, int data) {
    if (node == NULL) {
        node = create_node(data);
        return;
    }
    
    if (data < node->data) {
        if (node->left == NULL) {
            node->left = create_node(data);
        } else {
            insert(node->left, data);
        }
    } else {
        if (node->right == NULL) {
            node->right = create_node(data);
        } else {
            insert(node->right, data);
        }
    }
}

void inorder_traversal(struct node* node) {
    if (node == NULL) {
        return;
    }
    
    inorder_traversal(node->left);
    printf("%d ", node->data);
    inorder_traversal(node->right);
}

int main() {
    struct node* root = NULL;

    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    insert(root, 90);
    insert(root, 100);
    
    printf("Inorder traversal of binary search tree:\n");
    inorder_traversal(root);

    return 0;
}