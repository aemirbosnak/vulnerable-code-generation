//GEMINI-pro DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// A custom data structure to represent a node in a binary tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// A utility function to create a new node with the given data
Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// A recursive function to insert a new node into a binary search tree
Node *insertNode(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// A recursive function to find the minimum value in a binary search tree
int findMin(Node *root) {
    if (root == NULL) {
        return -1;  // Return an error code if the tree is empty
    } else {
        if (root->left == NULL) {
            return root->data;  // Return the data of the leftmost node
        } else {
            return findMin(root->left);  // Recursively find the minimum value in the left subtree
        }
    }
}

// A recursive function to find the maximum value in a binary search tree
int findMax(Node *root) {
    if (root == NULL) {
        return -1;  // Return an error code if the tree is empty
    } else {
        if (root->right == NULL) {
            return root->data;  // Return the data of the rightmost node
        } else {
            return findMax(root->right);  // Recursively find the maximum value in the right subtree
        }
    }
}

// A recursive function to search for a given value in a binary search tree
Node *searchValue(Node *root, int data) {
    if (root == NULL) {
        return NULL;  // Return NULL if the value is not found
    } else {
        if (root->data == data) {
            return root;  // Return the node if the value is found
        } else if (data <= root->data) {
            return searchValue(root->left, data);  // Recursively search for the value in the left subtree
        } else {
            return searchValue(root->right, data);  // Recursively search for the value in the right subtree
        }
    }
}

// A recursive function to print the inorder traversal of a binary search tree
void printInorder(Node *root) {
    if (root == NULL) {
        return;  // Do nothing if the tree is empty
    } else {
        printInorder(root->left);  // Recursively print the inorder traversal of the left subtree
        printf("%d ", root->data);  // Print the data of the current node
        printInorder(root->right);  // Recursively print the inorder traversal of the right subtree
    }
}

// A recursive function to print the preorder traversal of a binary search tree
void printPreorder(Node *root) {
    if (root == NULL) {
        return;  // Do nothing if the tree is empty
    } else {
        printf("%d ", root->data);  // Print the data of the current node
        printPreorder(root->left);  // Recursively print the preorder traversal of the left subtree
        printPreorder(root->right);  // Recursively print the preorder traversal of the right subtree
    }
}

// A recursive function to print the postorder traversal of a binary search tree
void printPostorder(Node *root) {
    if (root == NULL) {
        return;  // Do nothing if the tree is empty
    } else {
        printPostorder(root->left);  // Recursively print the postorder traversal of the left subtree
        printPostorder(root->right);  // Recursively print the postorder traversal of the right subtree
        printf("%d ", root->data);  // Print the data of the current node
    }
}

// A recursive function to delete a node from a binary search tree
Node *deleteNode(Node *root, int data) {
    if (root == NULL) {
        return NULL;  // Return NULL if the value is not found
    } else {
        if (root->data == data) {
            // Case 1: The node to be deleted has no children
            if (root->left == NULL && root->right == NULL) {
                free(root);
                return NULL;
            }
            // Case 2: The node to be deleted has one child
            else if (root->left == NULL) {
                Node *temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                Node *temp = root->left;
                free(root);
                return temp;
            }
            // Case 3: The node to be deleted has two children
            else {
                // Find the minimum value in the right subtree
                Node *minNode = root->right;
                while (minNode->left != NULL) {
                    minNode = minNode->left;
                }
                // Copy the data of the minimum value to the root node
                root->data = minNode->data;
                // Delete the minimum value from the right subtree
                root->right = deleteNode(root->right, minNode->data);
                return root;
            }
        } else if (data <= root->data) {
            root->left = deleteNode(root->left, data);
            return root;
        } else {
            root->right = deleteNode(root->right, data);
            return root;
        }
    }
}

// A utility function to print the height of a binary search tree
int height(Node *root) {
    if (root == NULL) {
        return 0;  // Return 0 for an empty tree
    } else {
        // Recursively calculate the height of the left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        // Return the greater of the two heights plus 1 for the current node
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

int main() {
    // Create a binary search tree
    Node *root = createNode(50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Print the inorder traversal of the tree
    printf("Inorder traversal: ");
    printInorder(root);
    printf("\n");

    // Print the preorder traversal of the tree
    printf("Preorder traversal: ");
    printPreorder(root);
    printf("\n");

    // Print the postorder traversal of the tree
    printf("Postorder traversal: ");
    printPostorder(root);
    printf("\n");

    // Find the minimum value in the tree
    int min = findMin(root);
    printf("Minimum value: %d\n", min);

    // Find the maximum value in the tree
    int max = findMax(root);
    printf("Maximum value: %d\n", max);

    // Search for a value in the tree
    Node *foundNode = searchValue(root, 40);
    if (foundNode != NULL) {
        printf("Value 40 found\n");
    } else {
        printf("Value 40 not found\n");
    }

    // Delete a value from the tree
    deleteNode(root, 40);
    printf("Value 40 deleted\n");

    // Print the inorder traversal of the tree after deletion
    printf("Inorder traversal after deletion: ");
    printInorder(root);
    printf("\n");

    // Calculate the height of the tree
    int treeHeight = height(root);
    printf("Height of the tree: %d\n", treeHeight);

    return 0;
}