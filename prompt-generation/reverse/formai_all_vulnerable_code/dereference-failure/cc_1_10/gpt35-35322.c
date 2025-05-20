//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
    } else if (value <= (*root)->value) {
        insert(&((*root)->left), value);
    } else {
        insert(&((*root)->right), value);
    }
}

void traverse(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    traverse(root->left);
    traverse(root->right);
}

void destroy(struct Node* root) {
    if (root == NULL) {
        return;
    }
    destroy(root->left);
    destroy(root->right);
    free(root);
}

struct AsyncContext {
    struct Node* root;
    int operationComplete;
};

void insertAsync(struct AsyncContext* ctxt, int value) {
    insert(&(ctxt->root), value);
    ctxt->operationComplete = 1;
}

void traverseAsync(struct AsyncContext* ctxt) {
    traverse(ctxt->root);
    ctxt->operationComplete = 1;
}

void destroyAsync(struct AsyncContext* ctxt) {
    destroy(ctxt->root);
    ctxt->operationComplete = 1;
}

int main() {
    struct Node* root = NULL;
    struct AsyncContext i, t, d;
    i.root = root;
    i.operationComplete = 0;
    t.root = root;
    t.operationComplete = 0;
    d.root = root;
    d.operationComplete = 0;
    insertAsync(&i, 5);
    insertAsync(&i, 3);
    insertAsync(&i, 8);
    insertAsync(&i, 1);
    insertAsync(&i, 4);
    insertAsync(&i, 7);
    insertAsync(&i, 10);
    while (!i.operationComplete) {
        // Busy wait
    }
    traverseAsync(&t);
    while (!t.operationComplete) {
        // Busy wait
    }
    destroyAsync(&d);
    while (!d.operationComplete) {
        // Busy wait
    }
    printf("Traversal complete!\n");
    return 0;
}