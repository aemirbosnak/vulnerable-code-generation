//FormAI DATASET v1.0 Category: Binary search trees ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// define struct node of binary search tree
typedef struct Node {
    int data;
    struct Node* right;
    struct Node* left;
} Node;

// create new node with 'data'
Node* createNode(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->right = NULL;
    node->left = NULL;

    return node;
}

// insert 'data' into the binary search tree
Node* insert(Node* node, int data){
    if(node == NULL) {
        return createNode(data);
    }

    if(data < node->data) {
        node->left = insert(node->left, data);
    } else if(data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

// search for 'data' in binary search tree
int search(Node* node, int data){
    if(node == NULL) {
        return 0;
    } else if(data < node->data) {
        return search(node->left, data);
    } else if(data > node->data) {
        return search(node->right, data);
    } else {
        return 1;
    }
}

// function to print inorder traversal of binary search tree
void inorder(Node* node) {
    if(node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main() {
    Node* root = NULL;

    // inserting data into binary search tree
    root = insert(root, 10);
    insert(root, 8);
    insert(root, 20);
    insert(root, 15);
    insert(root, 25);
    insert(root, 5);
    insert(root, 1);

    // print inorder traversal of binary search tree
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // search for data in binary search tree
    int searchKey = 15;
    if(search(root, searchKey)) {
        printf("%d found in binary search tree\n", searchKey);
    } else {
        printf("%d not found in binary search tree\n", searchKey);
    }

    searchKey = 17;
    if(search(root, searchKey)) {
        printf("%d found in binary search tree\n", searchKey);
    } else {
        printf("%d not found in binary search tree\n", searchKey);
    }

    return 0;
}