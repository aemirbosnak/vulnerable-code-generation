//FormAI DATASET v1.0 Category: Binary search trees ; Style: funny
#include<stdio.h>
#include<stdlib.h>

//explaining BST with some funny characters
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}Node;

Node *insert(Node *root, int data) {
    if (root == NULL) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        printf("New Node added to the tree! Hoorray!!! :)\n");
        return root;
    }
    if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *findMin(Node *root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left != NULL) {
        return findMin(root->left);
    }
    return root;
}

Node *delete(Node *root, int data) {
    if (root == NULL) {
        printf("Node not found \n");
        return NULL;
    }
    else if (data < root->data) {
        root->left = delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = delete(root->right, data);
    } 
    else {
        if (root->left == NULL && root->right == NULL) { //case 1
            free(root);
            root = NULL;
            printf("Node deleted from the tree! Good Bye!!! :D\n");
        } else if (root->left == NULL) {  //case 2
            Node *temp = root;
            root = root->right;
            free(temp);
            printf("Node deleted from the tree! Good Bye!!! :D\n");
        } else if (root->right == NULL) { //case 2
            Node *temp = root;
            root = root->left;
            free(temp);
            printf("Node deleted from the tree! Good Bye!!! :D\n");
        } else { //case 3
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
            printf("Node deleted from the tree! Good Bye!!! :D\n");
        }
    }
    return root;
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d, ", root->data);
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    printf("Welcome to the Funny Binary Search Tree! :D\n");
    printf("Adding some nodes to the tree...\n");
    root = insert(root, 12);
    root = insert(root, 8);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 20);
    printf("Great! Here are the nodes in inorder fashion: \n");
    inorder(root);
    printf("\nDeleting nodes from the tree... Bye bye nodes!!!\n");
    root = delete(root, 8);
    root = delete(root, 12);
    printf("Nice! Here are the remaining nodes in inorder fashion:\n");
    inorder(root);
    printf("\nThank you for using the Funny Binary Search Tree program :)\n");
    return 0;
}