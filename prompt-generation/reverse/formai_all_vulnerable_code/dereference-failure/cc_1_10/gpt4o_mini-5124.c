//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the Binary Search Tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node in the BST
struct Node* insert(struct Node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(data);

    // Otherwise, recur down the tree
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    // Return the unchanged node pointer
    return node;
}

// Function to perform an in-order traversal of the tree
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to search for a given key in the BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's key
    if (key > root->data)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function for the delicate dance of deletion in the tree
struct Node* deleteNode(struct Node* root, int key) {
    // Base case
    if (root == NULL) return root;

    // Recursive calls for ancestors of node to be deleted
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function to demonstrate the enchanting life of a Binary Search Tree
int main() {
    struct Node* root = NULL;

    // Each whispered number a loved one desires, courting one another
    int numbers[] = {40, 20, 60, 10, 30, 50, 70};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    for(int i = 0; i < size; i++) {
        root = insert(root, numbers[i]);
    }

    printf("Loving In-Order Traversal of the BST: ");
    inOrder(root);
    printf("\n");

    // Searching for a romantic number in the hearts of the tree
    int searchKey = 30;
    struct Node* searchResult = search(root, searchKey);
    if (searchResult != NULL) {
        printf("Found the love, the number %d nestled in the heart of the tree!\n", searchKey);
    } else {
        printf("Alas! The sought-after number %d is lost to the shadows.\n", searchKey);
    }

    // Deleting a number from the heart of the tree
    int deleteKey = 20;
    root = deleteNode(root, deleteKey);
    printf("After bidding farewell to %d, love remains vibrant: ", deleteKey);
    inOrder(root);
    printf("\n");

    // Find again to ensure numerals still dance passionately
    printf("Final enchanting In-Order Traversal of the BST: ");
    inOrder(root);
    printf("\n");

    // Evoking a bittersweet farewell to memory
    // In the end, every love must be cherished and let go
    free(root);
    return 0;
}