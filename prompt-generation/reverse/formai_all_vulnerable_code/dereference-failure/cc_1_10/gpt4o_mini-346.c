//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_THREADS 5

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* root = NULL;
pthread_mutex_t tree_lock;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(Node** node, int data) {
    if (*node == NULL) {
        *node = createNode(data);
        return;
    }
    
    if (data < (*node)->data) {
        insert(&((*node)->left), data);
    } else {
        insert(&((*node)->right), data);
    }
}

bool search(Node* node, int data) {
    if (node == NULL) {
        return false;
    }
    
    if (node->data == data) {
        return true;
    } else if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

void* insertThread(void* arg) {
    int data = *((int*)arg);
    pthread_mutex_lock(&tree_lock);
    insert(&root, data);
    pthread_mutex_unlock(&tree_lock);
    free(arg);
    return NULL;
}

void* searchThread(void* arg) {
    int data = *((int*)arg);
    pthread_mutex_lock(&tree_lock);
    bool found = search(root, data);
    pthread_mutex_unlock(&tree_lock);
    
    if (found) {
        printf("Value %d found in the tree\n", data);
    } else {
        printf("Value %d not found in the tree\n", data);
    }
    free(arg);
    return NULL;
}

void inorder(Node* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int rc;

    // Initialize the mutex
    if (pthread_mutex_init(&tree_lock, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }
    
    // Insert random nodes into the binary search tree
    for (int i = 0; i < MAX_THREADS; i++) {
        int* data = malloc(sizeof(int));
        *data = rand() % 100;  // Random value between 0-99
        rc = pthread_create(&threads[i], NULL, insertThread, data);
        if (rc) {
            printf("Error creating thread %d\n", i);
            return 1;
        }
    }

    // Join insert threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Inorder Traversal of BST: ");
    inorder(root);
    printf("\n");

    // Search in the binary search tree
    for (int i = 0; i < MAX_THREADS; i++) {
        int* data = malloc(sizeof(int));
        *data = rand() % 100;  // Random value between 0-99
        rc = pthread_create(&threads[i], NULL, searchThread, data);
        if (rc) {
            printf("Error creating thread for search %d\n", i);
            return 1;
        }
    }

    // Join search threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up and exit
    pthread_mutex_destroy(&tree_lock);
    return 0;
}