//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// A binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// A utility function to create a new Binary Tree node
struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// A utility function to insert a new node with given key in BST
struct Node *insert(struct Node *node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to search a given key in BST
struct Node *search(struct Node *node, int key) {
    /* Base Cases: root is null or key is present at root */
    if (node == NULL || node->data == key)
        return node;

    /* Key is greater than root's key */
    if (node->data < key)
        return search(node->right, key);

    /* Key is smaller than root's key */
    return search(node->left, key);
}

// A utility function to find the minimum value in BST
struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// A utility function to find the maximum value in BST
struct Node *maxValueNode(struct Node *node) {
    struct Node *current = node;

    /* loop down to find the rightmost leaf */
    while (current && current->right != NULL)
        current = current->right;

    return current;
}

// A utility function to print the preorder traversal of the BST
void preorder(struct Node *node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// A utility function to print the inorder traversal of the BST
void inorder(struct Node *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

// A utility function to print the postorder traversal of the BST
void postorder(struct Node *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

// Driver program to test the above functions
int main() {
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the inorder traversal of the BST
    printf("Inorder traversal: ");
    inorder(root);

    // Print the preorder traversal of the BST
    printf("\nPreorder traversal: ");
    preorder(root);

    // Print the postorder traversal of the BST
    printf("\nPostorder traversal: ");
    postorder(root);

    // Search a key in the BST
    struct Node *found = search(root, 40);
    if (found)
        printf("\n40 is found in the BST");
    else
        printf("\n40 is not found in the BST");

    // Find the minimum value in the BST
    struct Node *min = minValueNode(root);
    printf("\nMinimum value in the BST: %d", min->data);

    // Find the maximum value in the BST
    struct Node *max = maxValueNode(root);
    printf("\nMaximum value in the BST: %d", max->data);

    return 0;
}