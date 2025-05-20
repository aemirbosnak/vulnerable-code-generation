//FormAI DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Definition of a Binary Search Tree Node */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* Function to create a new node with the given data */
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to insert a new node with the given data in BST */
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

/* Function to traverse BST in inorder traversal */
void inorderTraversal(struct Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

/* Struct definition for passing arguments to the thread function */
struct ThreadArgs {
    struct Node* node;
    int data;
};

/* Thread Function to search data in BST */
void* searchThread(void* arg) {
    struct ThreadArgs* args = (struct ThreadArgs*)arg;
    struct Node* node = args->node;
    int data = args->data;
    while (node != NULL) {
        if (data > node->data) {
            node = node->right;
        }
        else if (data < node->data) {
            node = node->left;
        }
        else {
            printf("Data found in BST\n");
            return NULL;
        }
    }
    printf("Data not found in BST\n");
    return NULL;
}

/* Main Function */
int main() {
    /* Create a root node and insert data into BST */
    struct Node* root = NULL;
    int data[] = { 10, 5, 15, 3, 8, 12, 18 };
    int size = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < size; i++) {
        root = insert(root, data[i]);
    }

    /* Create Threads for searching data in BST */
    pthread_t threads[3];
    struct ThreadArgs args[3] = { {root, 8}, {root, 25}, {root, 12} };
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, searchThread, &args[i]);
    }

    /* Wait for Threads to complete */
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    /* Traverse BST in inorder traversal */
    printf("\nInorder traversal of BST: ");
    inorderTraversal(root);

    return 0;
}