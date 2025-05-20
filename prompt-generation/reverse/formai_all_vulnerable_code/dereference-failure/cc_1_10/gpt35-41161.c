//FormAI DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} node;

node *insert(node *root, int key) {
    if (root == NULL) {
        node *new_node = (node*) malloc(sizeof(node));
        new_node->key = key;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

node *search(node *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void *insert_thread(void *arg) {
    int *keys = (int*) arg;
    node *root = NULL;
    for (int i = 0; i < 5; ++i) {
        root = insert(root, keys[i]);
    }
    printf("Thread %u completed.\n", (unsigned int) pthread_self());
    return NULL;
}

void *search_thread(void *arg) {
    int *keys = (int*) arg;
    node *root = NULL;
    root = insert(root, keys[0]);
    for (int i = 1; i < 5; ++i) {
        node *result = search(root, keys[i]);
        if (result == NULL) {
            printf("Thread %u: Key %d not found.\n", (unsigned int) pthread_self(), keys[i]);
        } else {
            printf("Thread %u: Key %d found.\n", (unsigned int) pthread_self(), keys[i]);
        }
    }
    printf("Thread %u completed.\n", (unsigned int) pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[2];
    int keys1[5] = {8, 3, 10, 1, 6};
    int keys2[5] = {4, 5, 2, 9, 7};

    void *(*thread_funcs[2])(void*) = {insert_thread, search_thread};
    int *thread_args[2] = {keys1, keys2};

    for (int i = 0; i < 2; ++i) {
        int rc = pthread_create(&threads[i], NULL, thread_funcs[i], (void*) thread_args[i]);
        if (rc) {
            printf("Error: Unable to create thread %d.\n", i);
            exit(-1);
        }
    }

    for (int i = 0; i < 2; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}