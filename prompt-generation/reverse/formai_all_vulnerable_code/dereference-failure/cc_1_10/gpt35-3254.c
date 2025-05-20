//FormAI DATASET v1.0 Category: Binary search trees ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

/* Binary Search Tree node structure */
struct node {
    int key;
    struct node *left, *right;
};

/* Function to create a new node with the given key */
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* Function to insert a new node with the given key in BST */
struct node* insert(struct node* node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

/* Function to find the inorder successor of a given node */
struct node* minValueNode(struct node* node) {
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Function to delete a node with the given key from the BST */
struct node* deleteNode(struct node* root, int key) {
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
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

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

/* Function to search a node with the given key in BST */
struct node* search(struct node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;
   
    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

/* Function to perform inorder traversal of BST */
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* Driver program to test above functions */
int main() {
    // Create a binary search tree with nodes 8, 9, 5, 6, and 4
    struct node* root = NULL;
    root = insert(root, 8);
    insert(root, 9);
    insert(root, 5);
    insert(root, 6);
    insert(root, 4);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    // Search for a node with the given key
    int key = 6;
    struct node* found = search(root, key);
    if (found != NULL)
        printf("\nFound node with key %d in the BST\n", key);
    else
        printf("\nNode with key %d not found in the BST\n", key);

    // Delete a node with the given key
    int delete_key = 5;
    root = deleteNode(root, delete_key);
    printf("\nInorder traversal after deletion of %d \n", delete_key);
    inorder(root);

    return 0;
}