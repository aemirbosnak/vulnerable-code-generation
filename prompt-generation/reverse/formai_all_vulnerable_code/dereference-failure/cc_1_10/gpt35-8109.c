//FormAI DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node_t;

typedef struct bst {
    node_t *root;
    pthread_mutex_t lock;
} bst_t;

void initialize_bst(bst_t *bst) {
    bst->root = NULL;
    pthread_mutex_init(&bst->lock, NULL);
}

node_t* create_node(int value) {
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

bool insert(bst_t *bst, int value) {
    node_t *new_node = create_node(value);
    if (new_node == NULL) {
        return false;
    }
    pthread_mutex_lock(&bst->lock);
    if (bst->root == NULL) {
        bst->root = new_node;
        pthread_mutex_unlock(&bst->lock);
        return true;
    }
    node_t *temp = bst->root;
    while (true) {
        if (value == temp->value) {
            pthread_mutex_unlock(&bst->lock);
            return false;
        } else if (value < temp->value) {
            if (temp->left == NULL) {
                temp->left = new_node;
                pthread_mutex_unlock(&bst->lock);
                return true;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == NULL) {
                temp->right = new_node;
                pthread_mutex_unlock(&bst->lock);
                return true;
            } else {
                temp = temp->right;
            }
        }
    }
}

bool search(node_t *node, int value) {
    if (node == NULL) {
        return false;
    }
    if (node->value == value) {
        return true;
    } else if (value < node->value) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

bool contains(bst_t *bst, int value) {
    pthread_mutex_lock(&bst->lock);
    bool result = search(bst->root, value);
    pthread_mutex_unlock(&bst->lock);
    return result;
}

void* delete_node(node_t *node, int value) {
    if (node == NULL) {
        return NULL;
    } else if (value < node->value) {
        node->left = delete_node(node->left, value);
    } else if (value > node->value) {
        node->right = delete_node(node->right, value);
    } else {
        if (node->left == NULL && node->right == NULL) {
            free(node);
            node = NULL;
        } else if (node->left == NULL) {
            node_t *temp = node;
            node = node->right;
            free(temp);
        } else if (node->right == NULL) {
            node_t *temp = node;
            node = node->left;
            free(temp);
        } else {
            node_t *temp = node->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            node->value = temp->value;
            node->right = delete_node(node->right, temp->value);
        }
    }
    return node;
}

bool delete(bst_t *bst, int value) {
    pthread_mutex_lock(&bst->lock);
    bst->root = delete_node(bst->root, value);
    pthread_mutex_unlock(&bst->lock);
    return true;
}

void inorder_traversal(node_t *node) {
    if (node == NULL) {
        return;
    }
    inorder_traversal(node->left);
    printf("%d ", node->value);
    inorder_traversal(node->right);
}

void print_tree(bst_t *bst) {
    printf("BST: ");
    pthread_mutex_lock(&bst->lock);
    inorder_traversal(bst->root);
    pthread_mutex_unlock(&bst->lock);
    printf("\n");
}

int main() {
    bst_t bst;
    initialize_bst(&bst);

    insert(&bst, 10);
    insert(&bst, 5);
    insert(&bst, 15);
    insert(&bst, 7);
    insert(&bst, 3);
    insert(&bst, 12);
    insert(&bst, 17);

    print_tree(&bst);

    delete(&bst, 7);
    delete(&bst, 10);

    print_tree(&bst);

    bool result;

    result = contains(&bst, 3);
    printf("Contains 3: %d\n", result);

    result = contains(&bst, 7);
    printf("Contains 7: %d\n", result);

    pthread_mutex_destroy(&bst.lock);

    return 0;
}