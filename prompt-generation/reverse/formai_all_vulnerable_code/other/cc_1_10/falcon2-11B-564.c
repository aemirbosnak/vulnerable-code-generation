//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getBalance(node->left);
    int rightHeight = getBalance(node->right);
    return (leftHeight - rightHeight);
}

int rotateLeft(Node** root) {
    Node* tmp = *root;
    *root = (*root)->right;
    (*root)->left = tmp;
    return 1;
}

int rotateRight(Node** root) {
    Node* tmp = *root;
    Node* right = tmp->right;
    tmp->right = right->left;
    right->left = tmp;
    return 1;
}

void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
    } else if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else if (data > (*root)->data) {
        insert(&(*root)->right, data);
    }
}

void inorder(Node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main(void) {
    Node* root = NULL;
    pthread_t tid[5];
    int i;
    for (i = 0; i < 5; i++) {
        pthread_create(&tid[i], NULL, insert, (void *) &root);
    }
    for (i = 0; i < 5; i++) {
        pthread_join(tid[i], NULL);
    }
    inorder(root);
    return 0;
}