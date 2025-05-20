//FormAI DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left_child;
    struct node* right_child;
} Node;

Node* new_node(int value) {
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = value;
    new->left_child = NULL;
    new->right_child = NULL;
    return new;
}

Node* insert(Node* root, int value) {
    if(root == NULL) {
        return new_node(value);
    }
    if(value < root->data) {
        root->left_child = insert(root->left_child, value);
    }
    else if(value > root->data) {
        root->right_child = insert(root->right_child, value);
    }
    return root;
}

Node* search(Node* root, int value) {
    if(root == NULL || root->data == value) {
        return root;
    }
    if(value < root->data) {
        return search(root->left_child, value);
    }
    else {
        return search(root->right_child, value);
    }
}

void inorder_traversal(Node* root) {
    if(root != NULL) {
        inorder_traversal(root->left_child);
        printf("%d ", root->data);
        inorder_traversal(root->right_child);
    }
}

int main() {
    Node* root = NULL;
    int arr[] = {5, 7, 2, 9, 1, 4};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }
    printf("Inorder traversal of the binary search tree: ");
    inorder_traversal(root);
    printf("\n");

    int search_value = 9;
    Node* search_result = search(root, search_value);
    if(search_result != NULL) {
        printf("%d found in the binary search tree.\n", search_value);
    }
    else {
        printf("%d not found in the binary search tree.\n", search_value);
    }

    search_value = 3;
    search_result = search(root, search_value);
    if(search_result != NULL) {
        printf("%d found in the binary search tree.\n", search_value);
    }
    else {
        printf("%d not found in the binary search tree.\n", search_value);
    }

    return 0;
}