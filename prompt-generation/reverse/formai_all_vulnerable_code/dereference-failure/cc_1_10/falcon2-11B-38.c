//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new key into the BST
void insert(struct Node* node, int key) {
    if (node == NULL) {
        node = newNode(key);
        return;
    }

    if (key < node->key) {
        insert(node->left, key);
    } else if (key > node->key) {
        insert(node->right, key);
    }
}

// Function to search a key in the BST
int search(struct Node* node, int key) {
    if (node == NULL || node->key == key) {
        return 1;
    }

    if (key < node->key) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

// Function to print the BST in in-order traversal
void printInOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }

    printInOrder(node->left);
    printf("%d ", node->key);
    printInOrder(node->right);
}

// Function to delete a key from the BST
void delete(struct Node* node, int key) {
    if (node == NULL) {
        return;
    }

    if (key < node->key) {
        delete(node->left, key);
    } else if (key > node->key) {
        delete(node->right, key);
    } else {
        if (node->left == NULL) {
            struct Node* temp = node->right;
            free(node);
            node = temp;
        } else if (node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            node = temp;
        } else {
            struct Node* temp = node->right;
            while (temp->left!= NULL) {
                temp = temp->left;
            }
            struct Node* temp2 = temp->left;
            temp->left = node->left;
            node->left = temp2;
            free(node);
        }
    }
}

// Function to print the BST in pre-order traversal
void printPreOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }

    printf("%d ", node->key);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

// Function to print the BST in post-order traversal
void printPostOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }

    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->key);
}

int main() {
    struct Node* root = NULL;
    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    insert(root, 90);

    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    printPreOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    printPostOrder(root);
    printf("\n");

    printf("Search 40: %d\n", search(root, 40));
    printf("Search 50: %d\n", search(root, 50));
    printf("Search 75: %d\n", search(root, 75));

    printf("Delete 40: ");
    delete(root, 40);
    printf("\n");

    printf("In-order traversal after deleting 40: ");
    printInOrder(root);
    printf("\n");

    printf("Pre-order traversal after deleting 40: ");
    printPreOrder(root);
    printf("\n");

    printf("Post-order traversal after deleting 40: ");
    printPostOrder(root);
    printf("\n");

    printf("Search 40 after deleting 40: %d\n", search(root, 40));
    printf("Search 50 after deleting 40: %d\n", search(root, 50));

    return 0;
}