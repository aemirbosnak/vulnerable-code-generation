//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void insert(struct node* node, int data) {
    if (node == NULL) {
        node = (struct node*)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else if (data < node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

void search(struct node* node, int data) {
    if (node != NULL) {
        if (node->data == data) {
            printf("Found!\n");
        } else if (data < node->data) {
            search(node->left, data);
        } else {
            search(node->right, data);
        }
    } else {
        printf("Not found.\n");
    }
}

int main() {
    struct node* root = NULL;
    insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 25);
    insert(root, 15);
    insert(root, 35);

    search(root, 25);
    search(root, 35);
    search(root, 40);

    return 0;
}