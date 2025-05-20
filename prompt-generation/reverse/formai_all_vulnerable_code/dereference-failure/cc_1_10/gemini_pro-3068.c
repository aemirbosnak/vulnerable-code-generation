//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdlib.h>
#include <pthread.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef struct tree {
    node_t *root;
    pthread_mutex_t lock;
} tree_t;

void insert(tree_t *tree, int data) {
    pthread_mutex_lock(&tree->lock);
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        node_t *current = tree->root;
        while (1) {
            if (data < current->data) {
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
    pthread_mutex_unlock(&tree->lock);
}

int search(tree_t *tree, int data) {
    pthread_mutex_lock(&tree->lock);
    node_t *current = tree->root;
    while (current != NULL) {
        if (data == current->data) {
            pthread_mutex_unlock(&tree->lock);
            return 1;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    pthread_mutex_unlock(&tree->lock);
    return 0;
}

void *thread_func(void *arg) {
    tree_t *tree = (tree_t *)arg;

    for (int i = 0; i < 10000; i++) {
        insert(tree, rand() % 10000);
    }

    return NULL;
}

int main() {
    tree_t tree;
    pthread_mutex_init(&tree.lock, NULL);

    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, thread_func, &tree);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&tree.lock);

    int found = search(&tree, 5000);
    printf("Found: %d\n", found);

    return 0;
}