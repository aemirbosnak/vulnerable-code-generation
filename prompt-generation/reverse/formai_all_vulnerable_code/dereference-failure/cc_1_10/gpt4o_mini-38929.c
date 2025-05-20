//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *root = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(Node **node, int data) {
    if (*node == NULL) {
        *node = createNode(data);
        return;
    }
    if (data < (*node)->data) {
        insert(&(*node)->left, data);
    } else {
        insert(&(*node)->right, data);
    }
}

void search(Node *node, int data) {
    if (node == NULL) {
        printf("Element %d not found.\n", data);
        return;
    }
    if (node->data == data) {
        printf("Element %d found in the BST.\n", data);
        return;
    }
    if (data < node->data) {
        search(node->left, data);
    } else {
        search(node->right, data);
    }
}

void* threadInsert(void *arg) {
    int data = *((int *)arg);
    pthread_mutex_lock(&lock);
    insert(&root, data);
    printf("Inserted %d into the BST.\n", data);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* threadSearch(void *arg) {
    int data = *((int *)arg);
    pthread_mutex_lock(&lock);
    search(root, data);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[10];
    int valuesToInsert[5] = {5, 3, 8, 1, 4};
    int valuesToSearch[5] = {3, 10, 5, 1, 6};

    // Create threads for inserting values
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, threadInsert, &valuesToInsert[i]);
    }

    // Wait for insert threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Create threads for searching values
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, threadSearch, &valuesToSearch[i]);
    }

    // Wait for search threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up resources
    pthread_mutex_destroy(&lock);
    return 0;
}