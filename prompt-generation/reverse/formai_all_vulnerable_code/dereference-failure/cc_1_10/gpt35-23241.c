//FormAI DATASET v1.0 Category: Binary search trees ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Unable to allocate memory for new node.\n");
        exit(-1);
    }
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder_traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->value);
    inorder_traversal(root->right);
}

void preorder_traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->value);
}

Node* delete(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->value) {
        root->left = delete(root->left, key);
    } else if (key > root->value) {
        root->right = delete(root->right, key);
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
        root->value = temp->value;
        root->right = delete(root->right, temp->value);
    }
    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->value == key) {
        return root;
    }
    if (key < root->value) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    printf("Deleting node with value 20\n");
    root = delete(root, 20);
    printf("Inorder traversal after deletion: ");
    inorder_traversal(root);
    printf("\n");

    printf("Searching for node with value 40\n");
    Node* search_result = search(root, 40);
    if (search_result != NULL) {
        printf("Node with value 40 found.\n");
    } else {
        printf("Node with value 40 not found.\n");
    }

    return 0;
}