//FormAI DATASET v1.0 Category: Binary search trees ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
        return root;
    }

    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

Node* search_node(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search_node(root->left, data);
    } else if (data > root->data) {
        return search_node(root->right, data);
    }
}

Node* delete_node(Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = root->right;

        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }

    return root;
}

void inorder_traversal(Node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    printf("Inorder traversal of the BST: ");
    inorder_traversal(root);
    printf("\n");

    Node* search_result = search_node(root, 60);
    if (search_result == NULL) {
        printf("Element not found in the BST\n");
    } else {
        printf("Element found in the BST\n");
    }

    delete_node(root, 50);
    printf("Inorder traversal after deletion of 50: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}