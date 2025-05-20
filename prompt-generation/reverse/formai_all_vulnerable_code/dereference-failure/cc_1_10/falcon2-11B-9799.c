//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: surrealist
#include <stdio.h>

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} node;

// Create a node
node* create_node(int key) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into the tree
void insert_node(node* root, int key) {
    if (root == NULL) {
        root = create_node(key);
        return;
    }
    if (key < root->key) {
        insert_node(root->left, key);
    } else if (key > root->key) {
        insert_node(root->right, key);
    }
}

// Search for a node in the tree
int search_node(node* root, int key) {
    if (root == NULL) {
        return -1;
    }
    if (key == root->key) {
        return 1;
    }
    if (key < root->key) {
        return search_node(root->left, key);
    } else {
        return search_node(root->right, key);
    }
}

// Print the tree in in-order traversal
void print_tree(node* root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->key);
    print_tree(root->right);
}

int main() {
    node* root = NULL;
    insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    print_tree(root);

    printf("%d\n", search_node(root, 80));
    printf("%d\n", search_node(root, 30));
    printf("%d\n", search_node(root, 90));

    return 0;
}