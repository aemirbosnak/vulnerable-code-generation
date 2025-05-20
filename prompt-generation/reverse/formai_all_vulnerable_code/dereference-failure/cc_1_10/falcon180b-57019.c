//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;

    while (current && current->left!= NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct node* temp) {
    if (temp == NULL)
        return;

    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}

void preorder(struct node* temp) {
    if (temp == NULL)
        return;

    printf("%d ", temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(struct node* temp) {
    if (temp == NULL)
        return;

    postorder(temp->left);
    postorder(temp->right);
    printf("%d ", temp->data);
}

int main() {
    struct node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the given tree\n");
    inorder(root);

    printf("\n");

    printf("Preorder traversal of the given tree\n");
    preorder(root);

    printf("\n");

    printf("Postorder traversal of the given tree\n");
    postorder(root);

    printf("\n");

    root = deleteNode(root, 20);

    printf("Inorder traversal of the modified tree\n");
    inorder(root);

    return 0;
}