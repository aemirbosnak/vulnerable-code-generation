//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// A binary tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new binary tree node
struct node* new_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node with the given key into the binary tree rooted at the given node
struct node* insert(struct node *root, int key) {
    // If the root is NULL, create a new node and return it
    if (root == NULL) {
        return new_node(key);
    }

    // If the key is less than the root's data, insert it into the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }

    // Otherwise, insert it into the right subtree
    else {
        root->right = insert(root->right, key);
    }

    // Return the root of the tree
    return root;
}

// Search for the given key in the binary tree rooted at the given node
struct node* search(struct node *root, int key) {
    // If the root is NULL, the key is not present in the tree
    if (root == NULL) {
        return NULL;
    }

    // If the key is equal to the root's data, the key is present in the tree
    if (key == root->data) {
        return root;
    }

    // If the key is less than the root's data, search for it in the left subtree
    if (key < root->data) {
        return search(root->left, key);
    }

    // Otherwise, search for it in the right subtree
    else {
        return search(root->right, key);
    }
}

// Find the minimum node in the binary tree rooted at the given node
struct node* find_min(struct node *root) {
    // If the root is NULL, the tree is empty
    if (root == NULL) {
        return NULL;
    }

    // Find the minimum node in the left subtree
    if (root->left == NULL) {
        return root;
    }

    return find_min(root->left);
}

// Find the maximum node in the binary tree rooted at the given node
struct node* find_max(struct node *root) {
    // If the root is NULL, the tree is empty
    if (root == NULL) {
        return NULL;
    }

    // Find the maximum node in the right subtree
    if (root->right == NULL) {
        return root;
    }

    return find_max(root->right);
}

// Delete the given node from the binary tree rooted at the given node
struct node* delete(struct node *root, int key) {
    // If the root is NULL, the key is not present in the tree
    if (root == NULL) {
        return NULL;
    }

    // If the key is less than the root's data, delete it from the left subtree
    if (key < root->data) {
        root->left = delete(root->left, key);
    }

    // Otherwise, delete it from the right subtree
    else if (key > root->data) {
        root->right = delete(root->right, key);
    }

    // If the key is equal to the root's data, delete the root
    else {
        // If the root has no children, simply delete it
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // If the root has only one child, replace the root with its child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // If the root has two children, replace the root with the minimum node in the right subtree
        struct node *temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    // Return the root of the tree
    return root;
}

// Print the binary tree in preorder traversal
void preorder(struct node *root) {
    // If the root is NULL, the tree is empty
    if (root == NULL) {
        return;
    }

    // Print the root's data
    printf("%d ", root->data);

    // Print the left subtree
    preorder(root->left);

    // Print the right subtree
    preorder(root->right);
}

// Print the binary tree in inorder traversal
void inorder(struct node *root) {
    // If the root is NULL, the tree is empty
    if (root == NULL) {
        return;
    }

    // Print the left subtree
    inorder(root->left);

    // Print the root's data
    printf("%d ", root->data);

    // Print the right subtree
    inorder(root->right);
}

// Print the binary tree in postorder traversal
void postorder(struct node *root) {
    // If the root is NULL, the tree is empty
    if (root == NULL) {
        return;
    }

    // Print the left subtree
    postorder(root->left);

    // Print the right subtree
    postorder(root->right);

    // Print the root's data
    printf("%d ", root->data);
}

// Main function
int main() {
    // Create a binary search tree
    struct node *root = NULL;

    // Insert some keys into the tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Search for a key in the tree
    struct node *found_node = search(root, 15);

    // If the key was found, print its data
    if (found_node != NULL) {
        printf("The key %d was found in the tree.\n", found_node->data);
    } else {
        printf("The key was not found in the tree.\n");
    }

    // Find the minimum node in the tree
    struct node *min_node = find_min(root);

    // If the minimum node is not NULL, print its data
    if (min_node != NULL) {
        printf("The minimum node in the tree is %d.\n", min_node->data);
    } else {
        printf("The tree is empty.\n");
    }

    // Find the maximum node in the tree
    struct node *max_node = find_max(root);

    // If the maximum node is not NULL, print its data
    if (max_node != NULL) {
        printf("The maximum node in the tree is %d.\n", max_node->data);
    } else {
        printf("The tree is empty.\n");
    }

    // Delete a key from the tree
    root = delete(root, 15);

    // Print the tree in preorder traversal
    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n");

    // Print the tree in inorder traversal
    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    // Print the tree in postorder traversal
    printf("Postorder traversal:\n");
    postorder(root);
    printf("\n");

    // Free the tree
    free(root);

    return 0;
}