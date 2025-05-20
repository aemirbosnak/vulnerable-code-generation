//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root;
    }
}

void* searchThread(void* arg) {
    struct Node* root = (struct Node*)arg;
    int searchValue = *(int*)arg;

    struct Node* result = search(root, searchValue);

    if (result!= NULL) {
        printf("Value %d found in the tree.\n", searchValue);
    } else {
        printf("Value %d not found in the tree.\n", searchValue);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    struct Node* root = NULL;

    int values[10] = {5, 2, 8, 1, 3, 6, 7, 4, 9, 10};
    int i;

    for (i = 0; i < 10; i++) {
        root = insert(root, values[i]);
    }

    int searchValues[10] = {8, 3, 6, 9, 10, 1, 5, 2, 4, 7};
    int j;

    for (j = 0; j < 10; j++) {
        pthread_create(&threads[j], NULL, searchThread, (void*)(&searchValues[j]));
    }

    for (j = 0; j < 10; j++) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}