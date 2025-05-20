//FormAI DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* root = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void insert(int data);
node* insertRecursive(node* temp, int data);
void delete(int data);
node* deleteRecursive(node* root, int data);
void inorderTraversal(node* root);
void* insertThread(void *arg);
void* deleteThread(void *arg);

int main() {
    srand(time(0));
    pthread_t insertThread1, insertThread2, deleteThread1, deleteThread2;

    for(int i=0; i<5; i++) {
        int randomData = rand() % 100 + 1;
        insert(randomData);
    }

    printf("Initial Binary Search Tree:\n");
    inorderTraversal(root);

    pthread_create(&insertThread1, NULL, insertThread, NULL);
    pthread_create(&insertThread2, NULL, insertThread, NULL);
    pthread_create(&deleteThread1, NULL, deleteThread, NULL);
    pthread_create(&deleteThread2, NULL, deleteThread, NULL);

    pthread_join(insertThread1, NULL);
    pthread_join(insertThread2, NULL);
    pthread_join(deleteThread1, NULL);
    pthread_join(deleteThread2, NULL);

    printf("\nFinal Binary Search Tree:\n");
    inorderTraversal(root);

    return 0;
}

void* insertThread(void *arg) {
    for(int i=0; i<10; i++) {
        int randomData = rand() % 100 + 1;
        insert(randomData);
        usleep(rand() % 500 + 500);
    }

    pthread_exit(NULL);
}

void* deleteThread(void *arg) {
    for(int i=0; i<5; i++) {
        int randomData = rand() % 100 + 1;
        delete(randomData);
        usleep(rand() % 500 + 500);
    }

    pthread_exit(NULL);
}

void insert(int data) {
    pthread_mutex_lock(&mutex);
    root = insertRecursive(root, data);
    pthread_mutex_unlock(&mutex);
}

node* insertRecursive(node* temp, int data) {
    if(temp == NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if(data < temp->data) {
        temp->left = insertRecursive(temp->left, data);
    } else if(data > temp->data) {
        temp->right = insertRecursive(temp->right, data);
    }

    return temp;
}

void delete(int data) {
    pthread_mutex_lock(&mutex);
    root = deleteRecursive(root, data);
    pthread_mutex_unlock(&mutex);
}

node* deleteRecursive(node* root, int data) {
    if(root == NULL) {
        return root;
    }

    if(data < root->data) {
        root->left = deleteRecursive(root->left, data);
    } else if(data > root->data) {
        root->right = deleteRecursive(root->right, data);
    } else {
        if(root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node* temp = root->right;
        while(temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteRecursive(root->right, temp->data);
    }

    return root;
}

void inorderTraversal(node* root) {
    if(root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}