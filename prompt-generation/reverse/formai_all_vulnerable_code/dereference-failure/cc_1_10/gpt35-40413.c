//FormAI DATASET v1.0 Category: Binary search trees ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }
    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    }
    else {
        insert(&(*root)->right, data);
    }
}

void in_order(Node* root) {
    if (root == NULL) {
        return;
    }
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

Node* find_min(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delete(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete(root->left, data);
    }
    else if (data > root->data){
        root->right = delete(root->right, data);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 6);
    insert(&root, 14);
    insert(&root, 4);
    insert(&root, 7);
    insert(&root, 13);
 
    printf("Inorder traversal: ");
    in_order(root);
    printf("\n");

    printf("Deleting node 13\n");
    root = delete(root, 13);
    printf("Inorder traversal: ");
    in_order(root);
    printf("\n");

    printf("Deleting node 8\n");
    root = delete(root, 8);
    printf("Inorder traversal: ");
    in_order(root);
    printf("\n");

    return 0;
}