//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_NODES 100

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
    int size;
};

struct search_result {
    struct node *node;
    int index;
};

struct search_args {
    struct tree *tree;
    int key;
    struct search_result *result;
};

void *search_thread(void *args) {
    struct search_args *search_args = (struct search_args *)args;
    struct tree *tree = search_args->tree;
    int key = search_args->key;
    struct search_result *result = search_args->result;

    result->node = NULL;
    result->index = -1;

    struct node *current_node = tree->root;
    int current_index = 0;

    while (current_node != NULL) {
        if (current_node->data == key) {
            result->node = current_node;
            result->index = current_index;
            break;
        } else if (key < current_node->data) {
            current_node = current_node->left;
            current_index = current_index * 2 + 1;
        } else {
            current_node = current_node->right;
            current_index = current_index * 2 + 2;
        }
    }

    return NULL;
}

int main() {
    struct tree tree;
    tree.root = NULL;
    tree.size = 0;

    int nodes[] = {10, 5, 15, 2, 7, 12, 17, 1, 3, 6, 8, 11, 13, 16, 18};
    int num_nodes = sizeof(nodes) / sizeof(int);

    for (int i = 0; i < num_nodes; i++) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = nodes[i];
        new_node->left = NULL;
        new_node->right = NULL;

        if (tree.root == NULL) {
            tree.root = new_node;
            tree.size = 1;
        } else {
            struct node *current_node = tree.root;

            while (1) {
                if (new_node->data < current_node->data) {
                    if (current_node->left == NULL) {
                        current_node->left = new_node;
                        tree.size++;
                        break;
                    } else {
                        current_node = current_node->left;
                    }
                } else {
                    if (current_node->right == NULL) {
                        current_node->right = new_node;
                        tree.size++;
                        break;
                    } else {
                        current_node = current_node->right;
                    }
                }
            }
        }
    }

    int key = 13;

    struct search_result result;
    result.node = NULL;
    result.index = -1;

    struct search_args search_args;
    search_args.tree = &tree;
    search_args.key = key;
    search_args.result = &result;

    pthread_t search_thread_id;
    pthread_create(&search_thread_id, NULL, search_thread, &search_args);
    pthread_join(search_thread_id, NULL);

    if (result.node != NULL) {
        printf("Found node with key %d at index %d\n", key, result.index);
    } else {
        printf("Node with key %d not found\n", key);
    }

    return 0;
}