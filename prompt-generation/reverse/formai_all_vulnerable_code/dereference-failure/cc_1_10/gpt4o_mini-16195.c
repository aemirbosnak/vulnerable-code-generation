//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in a binary search tree
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to insert a new node with given key in BST
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return newNode(key);
    }

    // Otherwise, recur down the tree
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    // Return the (unchanged) node pointer
    return node;
}

// A utility function to search a given key in BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// A function to perform inorder traversal of BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// A function to get the minimum value node in a given BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// A function to delete a node with a given key from BST
struct Node* deleteNode(struct Node* root, int key) {
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    // If the key to be deleted is greater than the root's key
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    // if key is same as root's key, then this is the node to be deleted
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
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->key); // Delete the inorder successor
    }
    return root;
}

// A function to free the allocated memory in tree
void freeTree(struct Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main program to test the binary search tree functions
int main() {
    struct Node* root = NULL;
    int n, choice, value;

    printf("Welcome to the Mind-Bending Binary Search Tree!\n");
    printf("Enter the number of elements you would like to insert into the BST: ");
    scanf("%d", &n);
    printf("Insert %d values into the BST:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    while (1) {
        printf("\nChoose an option:\n1. Inorder Traversal\n2. Search\n3. Delete\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder Traversal of BST: ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* found = search(root, value);
                if (found)
                    printf("Value %d found in the BST.\n", value);
                else
                    printf("Value %d not found in the BST.\n", value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Value %d deleted from the BST.\n", value);
                break;

            case 4:
                freeTree(root);
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}