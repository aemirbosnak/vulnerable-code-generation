//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_KEY 100

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
};

void init_tree(struct tree *t) {
    t->root = NULL;
}

int insert_node(struct tree *t, int key) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    if (t->root == NULL) {
        t->root = new_node;
    } else {
        insert_node_rec(t, t->root, new_node);
    }

    return new_node;
}

int insert_node_rec(struct tree *t, struct node *root, struct node *new_node) {
    if (root == NULL) {
        return NULL;
    }

    if (new_node->key < root->key) {
        root->left = insert_node_rec(t, root->left, new_node);
    } else if (new_node->key > root->key) {
        root->right = insert_node_rec(t, root->right, new_node);
    } else {
        // key already exists, do nothing
        return root;
    }

    return root;
}

int search_node(struct tree *t, int key) {
    struct node *current = t->root;

    while (current != NULL) {
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return current;
        }
    }

    return NULL;
}

void print_tree(struct tree *t) {
    struct node *current = t->root;

    while (current != NULL) {
        printf("%d ", current->key);
        current = current->left != NULL ? current->left : current->right;
    }

    printf("\n");
}

int main() {
    struct tree t;

    init_tree(&t);

    insert_node(&t, 5);
    insert_node(&t, 10);
    insert_node(&t, 20);
    insert_node(&t, 30);
    insert_node(&t, 40);

    print_tree(&t);

    struct node *found = search_node(&t, 25);

    if (found != NULL) {
        printf("Found %d\n", found->key);
    } else {
        printf("Not found\n");
    }

    return 0;
}