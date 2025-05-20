//FormAI DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node *newNode(int item) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

void *threadFunc(void *tree) {
    int keys[] = {65, 45, 90, 23, 67, 34, 60, 50, 78, 300};
    int i;
    struct node *temp = (struct node*)tree;
    for (i = 0; i < 10; i++) {
        temp = insert(temp, keys[i]);
    }
    return NULL;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    pthread_t thread1, thread2;
    struct node *root = NULL;
    pthread_create(&thread1, NULL, threadFunc, (void*)root);
    pthread_create(&thread2, NULL, threadFunc, (void*)root);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("\nInorder traversal of the binary search tree is:\n");
    inorder(root);
    printf("\n");
    return 0;
}