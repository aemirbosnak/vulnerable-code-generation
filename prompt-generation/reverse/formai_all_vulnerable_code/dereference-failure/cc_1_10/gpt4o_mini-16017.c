//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct ThreadData {
    Node** root;
    int value;
} ThreadData;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to create a new BST node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

// Thread function to insert a value into the BST
void* threadInsert(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    
    pthread_mutex_lock(&mutex);
    insert(data->root, data->value);
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

// Function for in-order traversal of the BST
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to free the memory of the BST
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    pthread_t threads[10];
    ThreadData threadData[10];
    
    int values[10] = { 50, 30, 70, 20, 40, 60, 80, 10, 25, 35 };
    
    // Create threads to insert nodes into the BST
    for (int i = 0; i < 10; i++) {
        threadData[i].root = &root;
        threadData[i].value = values[i];
        pthread_create(&threads[i], NULL, threadInsert, (void*)&threadData[i]);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display the BST in-order
    printf("In-order traversal of the BST: ");
    inOrder(root);
    printf("\n");

    // Free the memory allocated for the BST
    freeTree(root);
    
    // Destroy mutex
    pthread_mutex_destroy(&mutex);
    
    return 0;
}