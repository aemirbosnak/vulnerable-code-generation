//FormAI DATASET v1.0 Category: Binary search trees ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

//Structure of Binary Search Tree Node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

//Insert Node in Binary Search Tree
struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

//Inorder traversal of BST
void inorder_traversal(struct node* node) {
    if (node != NULL) {
        inorder_traversal(node->left);
        printf("%d ", node->data);
        inorder_traversal(node->right);
    }
}

//Delete Node from BST
struct node* delete(struct node* node, int data) {
    if (node == NULL)
        return node;

    if (data < node->data)
        node->left = delete(node->left, data);
    else if (data > node->data)
        node->right = delete(node->right, data);
    else {
        if (node->left == NULL) {
            struct node* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            struct node* temp = node->left;
            free(node);
            return temp;
        }

        struct node* temp = node->right;
        while (temp->left != NULL)
            temp = temp->left;

        node->data = temp->data;
        node->right = delete(node->right, temp->data);
    }
    return node;
}

//Main function
int main() {
    struct node* root = NULL;

    //Inserting Nodes in BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder Traversal of Binary Search Tree: ");
    inorder_traversal(root);

    printf("\n\nDeleting 20 from BST\n");
    root = delete(root, 20);
    printf("Inorder Traversal of Binary Search Tree: ");
    inorder_traversal(root);

    printf("\n\nDeleting 30 from BST\n");
    root = delete(root, 30);
    printf("Inorder Traversal of Binary Search Tree: ");
    inorder_traversal(root);

    printf("\n\nDeleting 50 from BST\n");
    root = delete(root, 50);
    printf("Inorder Traversal of Binary Search Tree: ");
    inorder_traversal(root);

    return 0;
}