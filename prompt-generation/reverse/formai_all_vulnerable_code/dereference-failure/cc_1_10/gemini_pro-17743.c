//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

pthread_mutex_t lock;

void *insert(void *args) {
    node_t **root = (node_t **)args;
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = rand() % 100;
    new_node->left = NULL;
    new_node->right = NULL;

    pthread_mutex_lock(&lock);
    if (*root == NULL) {
        *root = new_node;
    } else {
        node_t *current = *root;
        while (true) {
            if (new_node->data < current->data) {
                if (current->left == NULL) {
                    current->left = new_node;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = new_node;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

void *search(void *args) {
    node_t **root = (node_t **)args;
    int target = rand() % 100;

    pthread_mutex_lock(&lock);
    bool found = false;
    node_t *current = *root;
    while (current != NULL && !found) {
        if (target == current->data) {
            found = true;
        } else if (target < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    pthread_mutex_unlock(&lock);

    if (found) {
        printf("Found %d in the tree\n", target);
    } else {
        printf("Did not find %d in the tree\n", target);
    }

    return NULL;
}

int main() {
    pthread_t threads[10];
    node_t *root = NULL;

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, insert, &root);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, search, &root);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}