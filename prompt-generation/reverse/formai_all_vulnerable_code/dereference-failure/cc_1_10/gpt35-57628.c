//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t *root = NULL;
pthread_mutex_t lock;

void insert(int data) {
    node_t *new = (node_t*)malloc(sizeof(node_t));
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    pthread_mutex_lock(&lock);

    if (root == NULL) {
        root = new;
    }
    else {
        node_t *current = root;
        while (current != NULL) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = new;
                    break;
                }
                else {
                    current = current->left;
                }
            }
            else {
                if (current->right == NULL) {
                    current->right = new;
                    break;
                }
                else {
                    current = current->right;
                }
            }
        }
    }

    pthread_mutex_unlock(&lock);
}

void print_node(node_t *node) {
    printf("%d ", node->data);
}

void traverse_in_order(node_t *node) {
    if (node == NULL) {
        return;
    }
    traverse_in_order(node->left);
    print_node(node);
    traverse_in_order(node->right);
}

void *thread_func(void *arg) {
    int data = *((int*)arg);
    insert(data);
    return NULL;
}

int main() {

    pthread_t threads[5];
    int thread_args[5] = {3, 5, 1, 4, 2};

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("In order traversal: ");
    traverse_in_order(root);
    printf("\n");

    pthread_mutex_destroy(&lock);

    return 0;
}