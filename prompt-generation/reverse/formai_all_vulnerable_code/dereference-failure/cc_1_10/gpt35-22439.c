//FormAI DATASET v1.0 Category: Binary search trees ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} Node;

Node* create_node(int key) {
    Node* new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(Node** root, int key) {
    if (*root == NULL) {
        *root = create_node(key);
        return;
    }
    
    if (key < (*root)->key) {
        insert_node(&((*root)->left), key);
    } else if (key > (*root)->key) {
        insert_node(&((*root)->right), key);
    }
}

void inorder_traversal(Node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

Node* search_node(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    
    if (key < root->key) {
        return search_node(root->left, key);
    } else {
        return search_node(root->right, key);
    }
}

Node* min_value_node(Node* node) {
    Node* current = node;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* delete_node(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    
    if (key < root->key) {
        root->left = delete_node(root->left, key);
    } else if (key > root->key) {
        root->right = delete_node(root->right, key);
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
        
        Node* temp = min_value_node(root->right);
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

int main() {
    Node* root = NULL;
    
    // insert nodes
    insert_node(&root, 50);
    insert_node(&root, 30);
    insert_node(&root, 70);
    insert_node(&root, 20);
    insert_node(&root, 40);
    insert_node(&root, 60);
    insert_node(&root, 80);
    
    // print inorder traversal
    printf("Inorder traversal:\n");
    inorder_traversal(root);
    printf("\n");
    
    // search nodes
    int key = 40;
    Node* searched_node = search_node(root, key);
    if (searched_node != NULL) {
        printf("Node with key %d is found in the tree.\n", searched_node->key);
    } else {
        printf("Node with key %d is not found in the tree.\n", key);
    }
    
    key = 100;
    searched_node = search_node(root, key);
    if (searched_node != NULL) {
        printf("Node with key %d is found in the tree.\n", searched_node->key);
    } else {
        printf("Node with key %d is not found in the tree.\n", key);
    }
    
    // delete nodes
    key = 30;
    printf("Deleting node with key %d.\n", key);
    root = delete_node(root, key);
    printf("Inorder traversal after deletion:\n");
    inorder_traversal(root);
    printf("\n");
    
    key = 70;
    printf("Deleting node with key %d.\n", key);
    root = delete_node(root, key);
    printf("Inorder traversal after deletion:\n");
    inorder_traversal(root);
    printf("\n");
    
    return 0;
}