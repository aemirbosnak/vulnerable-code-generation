//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Let the games begin: Insert function
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        printf("A wandering soul has found its home here: %d!\n", data);
        return createNode(data);
    }
    if (data < root->data) {
        printf("%d seeks the left path of wisdom...\n", data);
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        printf("%d strolls down the right path of glory...\n", data);
        root->right = insert(root->right, data);
    }
    return root;
}

// Time for a quest: Search function
struct Node* search(struct Node* root, int data) {
    if (root == NULL) {
        printf("This brave knight %d has lost its way...\n", data);
        return NULL;
    }
    if (root->data == data) {
        printf("Ah! The quest for %d has reached its glorious end!\n", data);
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// A riddle for the ages: Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// An epic showdown: Remove function
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* removeNode(struct Node* root, int data) {
    if (root == NULL) {
        printf("We cannot remove what does not exist!\n");
        return root;
    }
    if (data < root->data) {
        printf("A mental battle ensues at %d as we search left...\n", root->data);
        root->left = removeNode(root->left, data);
    } else if (data > root->data) {
        printf("The right path is fraught with challenges as we determine %d...\n", root->data);
        root->right = removeNode(root->right, data);
    } else {
        printf("A great sacrifice is made as %d is destined to fade...\n", data);
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
        // Node with two children: Get the inorder successor
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

// The saga concludes: Main function
int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nKnight's BST Adventure!\n");
        printf("1. Insert a value\n");
        printf("2. Search for a value\n");
        printf("3. Inorder traversal\n");
        printf("4. Remove a value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;
            case 3:
                printf("Here lies the values in their balanced beauty: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the value to remove: ");
                scanf("%d", &value);
                root = removeNode(root, value);
                break;
            case 5:
                printf("The adventure has concluded. Farewell, brave knight!\n");
                break;
            default:
                printf("Choose wisely, for errors can lead to confusion!\n");
        }
    } while (choice != 5);

    return 0;
}