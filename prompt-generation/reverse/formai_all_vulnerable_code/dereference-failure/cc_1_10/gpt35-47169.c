//FormAI DATASET v1.0 Category: Binary search trees ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

void* search(void* arg) {
    struct node* root = (struct node*)arg;
    int key;
    printf("Enter a key to search: ");
    scanf("%d", &key);

    struct node* cur = root;
    while (cur != NULL) {
        if (key == cur->value) {
            printf("Found!\n");
            return NULL;
        } else if (key < cur->value) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    printf("Not found.\n");
    return NULL;
}

void traverse(struct node* root) {
    if (root == NULL) { return; }
    traverse(root->left);
    printf("%d ", root->value);
    traverse(root->right);
}

void free_tree(struct node* root) {
    if (root == NULL) { return; }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    struct node* root = NULL;
    root = insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    printf("Inorder traversal of the tree: ");
    traverse(root);
    printf("\n");

    // Multiple threads can search the tree concurrently
    pthread_t t1, t2;
    pthread_create(&t1, NULL, search, (void*)root);
    pthread_create(&t2, NULL, search, (void*)root);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    free_tree(root);
    return 0;
}