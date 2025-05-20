//FormAI DATASET v1.0 Category: Binary search trees ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int key;
    struct NODE *left_child, *right_child;
} Node;

Node* create_node(int key) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->key = key;
    new_node->left_child = new_node->right_child = NULL;
    return new_node;
}

Node* insert(Node *root, int key) {
    if (root == NULL) {
        return create_node(key);
    }
    if (key < root->key) {
        root->left_child = insert(root->left_child, key);
    }
    else if (key > root->key) {
        root->right_child = insert(root->right_child, key);
    }
    return root;
}

Node* search(Node *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left_child, key);
    }
    return search(root->right_child, key);
}

Node* delete(Node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left_child = delete(root->left_child, key);
    }
    else if (key > root->key) {
        root->right_child = delete(root->right_child, key);
    }
    else {
        if (root->left_child == NULL) {
            Node *temp = root->right_child;
            free(root);
            return temp;
        }
        else if (root->right_child == NULL) {
            Node *temp = root->left_child;
            free(root);
            return temp;
        }
        Node *temp = root->right_child;
        while (temp && temp->left_child != NULL) {
            temp = temp->left_child;
        }
        root->key = temp->key;
        root->right_child = delete(root->right_child, temp->key);
    }
    return root;
}

void print_preorder(Node *root) {
    if(root != NULL) {
        printf("%d ", root->key);
        print_preorder(root->left_child);
        print_preorder(root->right_child);
    }
}

int main() {
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Preorder traversal: ");
    print_preorder(root);
    printf("\n");

    printf("Deleting node with key 20.\n");
    root = delete(root, 20);
    printf("Preorder traversal after deleting 20: ");
    print_preorder(root);
    printf("\n");

    printf("Searching for node with key 30.\n");
    Node *temp = search(root, 30);
    if (temp == NULL) {
        printf("Node with key 30 not found.\n");
    }
    else {
        printf("Node with key 30 found.\n");
    }

    printf("Deleting node with key 50.\n");
    root = delete(root, 50);
    printf("Preorder traversal after deleting 50: ");
    print_preorder(root);
    printf("\n");

    return 0;
}