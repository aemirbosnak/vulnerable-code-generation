//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

pthread_mutex_t lock;

struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void *search(void *arg) {
    struct node *root = (struct node *)arg;
    int data = (int)pthread_self();
    pthread_mutex_lock(&lock);
    struct node *curr = root;
    while (curr != NULL) {
        if (data == curr->data) {
            printf("Found %d in the tree!\n", data);
            pthread_mutex_unlock(&lock);
            return NULL;
        } else if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    printf("Could not find %d in the tree!\n", data);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_mutex_init(&lock, NULL);
    struct node *root = NULL;
    int i;
    for (i = 0; i < 100; i++) {
        root = insert(root, i);
    }
    pthread_t threads[100];
    for (i = 0; i < 100; i++) {
        pthread_create(&threads[i], NULL, search, (void *)root);
    }
    for (i = 0; i < 100; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}