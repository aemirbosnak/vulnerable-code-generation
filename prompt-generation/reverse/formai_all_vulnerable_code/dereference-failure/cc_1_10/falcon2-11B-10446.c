//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include<stdio.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data <= node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

void inorder(struct node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    insert(root, 90);
    insert(root, 100);
    printf("Inorder traversal of binary search tree is: ");
    inorder(root);
    return 0;
}