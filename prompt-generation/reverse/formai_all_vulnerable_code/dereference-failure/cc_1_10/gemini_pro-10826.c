//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

typedef struct bst {
    struct node *root;
} bst;

node* createNode(int data) {
    node *n = (node*) malloc(sizeof (node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

bst* createBST() {
    bst *t = (bst*) malloc(sizeof (bst));
    t->root =NULL;
    return t;
}

void insert(bst *t, int data) {
    node *n = createNode(data);
    if (t->root == NULL) {
        t->root = n;
        return;
    }
    node *current = t->root;
    while (1) {
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = n;
                return;
            } else {
                current = current->left;
            }
        } else {
            if (current->right == NULL) {
                current->right = n;
                return;
            } else {
                current = current->right;
            }
        }
    }
}

node* search(bst *t, int data) {
    if (t->root == NULL) {
        return NULL;
    }
    node *current = t->root;
    while (current != NULL) {
        if (data == current->data) {
            return current;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

void delete(bst *t, int data) {
    if (t->root == NULL) {
        return;
    }
    node *current = t->root;
    node *parent = NULL;
    while (current != NULL) {
        if (data == current->data) {
            break;
        } else if (data < current->data) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }
    if (current == NULL) {
        return;
    }
    if (current->left == NULL && 
        current->right == NULL) {
        if (parent == NULL) {
            t->root = NULL;
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    } else if (current->left != NULL && 
               current->right == NULL) {
        if (parent == NULL) {
            t->root = current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
    } else if (current->left == NULL && 
               current->right != NULL) {
        if (parent == NULL) {
            t->root = current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
    } else {
        node *successor = current->right;
        node *successorParent = current;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        if (successorParent == current) {
            successorParent->right = successor->right;
        } else {
            successorParent->left = successor->right;
        }
    }
    free(current);
}

void inorder(node *n) {
    if (n == NULL) {
        return;
    }
    inorder(n->left);
    printf("%d ", n->data);
    inorder(n->right);
}

int main() {
    bst *t = createBST();
    insert(t, 50);
    insert(t, 30);
    insert(t, 20);
    insert(t, 40);
    insert(t, 70);
    insert(t, 60);
    insert(t, 80);
    inorder(t->root);
    printf("\n");
    node *s = search(t, 40);
    if (s != NULL) {
        printf("Found: %d\n", s->data);
    } else {
        printf("Not found\n");
    }
    delete(t, 40);
    inorder(t->root);
    printf("\n");
    return 0;
}