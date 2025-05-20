//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// A binary search tree (BST) node
struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

// A utility function to create a new BST node
struct BSTNode *newNode(int data) {
    struct BSTNode *node = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// A utility function to insert a new node with the given key into the BST
struct BSTNode *insert(struct BSTNode *node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return (newNode(key));

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to search for a given key in the BST
struct BSTNode *search(struct BSTNode *node, int key) {
    // Base Cases: root is null or key is present at root
    if (node == NULL || node->data == key)
        return node;

    // Key is greater than root's key
    if (key > node->data)
        return search(node->right, key);

    // Key is smaller than root's key
    return search(node->left, key);
}

// A utility function to find the minimum value in the BST
struct BSTNode *minValueNode(struct BSTNode *node) {
    struct BSTNode *current = node;

    // loop down to find the leftmost leaf
    while (current->left != NULL)
        current = current->left;

    return current;
}

// A utility function to delete a node from the BST
struct BSTNode *deleteNode(struct BSTNode *node, int key) {
    // Base case
    if (node == NULL)
        return node;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < node->data)
        node->left = deleteNode(node->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > node->data)
        node->right = deleteNode(node->right, key);

    // If the key to be deleted is the same as the root's key,
    // then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (node->left == NULL) {
            struct BSTNode *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct BSTNode *temp = node->left;
            free(node);
            return temp;
        }

        // Node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct BSTNode *temp = minValueNode(node->right);

        // Copy the inorder successor's content to this node
        node->data = temp->data;

        // Delete the inorder successor
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

// A utility function to print the preorder traversal of the BST
void preorder(struct BSTNode *node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// Driver program to test the above functions
int main() {
    struct BSTNode *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print the inorder traversal of the BST
    printf("Inorder traversal: ");
    preorder(root);

    printf("\n");

    // search for a key in the BST
    struct BSTNode *node = search(root, 40);
    if (node != NULL)
        printf("Key 40 found in the BST\n");
    else
        printf("Key 40 not found in the BST\n");

    // delete a node from the BST
    root = deleteNode(root, 20);
    printf("Inorder traversal after deleting key 20: ");
    preorder(root);

    printf("\n");

    return 0;
}