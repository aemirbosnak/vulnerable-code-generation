//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* newNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);
    
    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    // return the (unchanged) node pointer
    return node;
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

Node* bstRoot = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* insertNodes(void* arg) {
    int numbers[] = {50, 30, 20, 40, 70, 60, 80};
    
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        pthread_mutex_lock(&mutex);
        printf("Inserting %d into the tree...\n", numbers[i]);
        bstRoot = insert(bstRoot, numbers[i]);
        pthread_mutex_unlock(&mutex);
        sleep(1); // Simulate some delay for insertion
    }
    return NULL;
}

void* printTree(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        printf("Current BST (In-order): ");
        inOrder(bstRoot);
        printf("\n");
        pthread_mutex_unlock(&mutex);
        sleep(2); // Simulate printing delay
    }
    return NULL;
}

int main() {
    pthread_t insertThread, printThread;

    // Create threads for insertion and printing
    pthread_create(&insertThread, NULL, insertNodes, NULL);
    pthread_create(&printThread, NULL, printTree, NULL);

    // Wait for the insertion thread to finish
    pthread_join(insertThread, NULL);
    
    // Non-terminating print thread will continue running, let's exit gracefully
    pthread_cancel(printThread);
    
    pthread_join(printThread, NULL);
    
    pthread_mutex_destroy(&mutex);
    
    return 0;
}