//FormAI DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *left, *right;
} BSTNode;

BSTNode *new_node(int data) {
    BSTNode *node = (BSTNode*)malloc(sizeof(BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

BSTNode *insert(BSTNode *root, int data) {
    if(root == NULL)
        return new_node(data);
    if(root->data > data)
        root->left = insert(root->left, data);
    else if(root->data < data)
        root->right = insert(root->right, data);
    return root;
}

BSTNode *search(BSTNode *root, int data) {
    if(root == NULL || root->data == data) 
        return root;
    if(root->data < data) 
        return search(root->right, data);
    return search(root->left, data);
}

void inorder(BSTNode *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

BSTNode *find_min(BSTNode *root) {
    BSTNode *curr = root;
    while(curr->left != NULL)
        curr = curr->left;
    return curr;
}

BSTNode *delete(BSTNode *root, int data) {
    if(root == NULL) return root;
    if(root->data > data) 
        root->left = delete(root->left, data);  
    else if(root->data < data) 
        root->right = delete(root->right, data);  
    else {
        if(root->left == NULL) {
            BSTNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            BSTNode *temp = root->left;
            free(root);
            return temp;
        }
        BSTNode *temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int main() {
    BSTNode *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nDelete 20\n");
    root = delete(root, 20);
    printf("Inorder traversal after deletion: ");
    inorder(root);

    printf("\nDelete 30\n");
    root = delete(root, 30);
    printf("Inorder traversal after deletion: ");
    inorder(root);

    printf("\nDelete 50\n");
    root = delete(root, 50);
    printf("Inorder traversal after deletion: ");
    inorder(root);

    return 0;
}