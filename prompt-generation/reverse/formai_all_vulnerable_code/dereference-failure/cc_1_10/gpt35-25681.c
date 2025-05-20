//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(struct node* root, int key) {
    struct node *temp = createNode(key);
    struct node *current = root;
    while (1) {
        if (key == current->data) {
            printf("Duplicate key!\n");
            return;
        }
        else if (key < current->data) {
            if (current->left == NULL) {
                current->left = temp;
                return;
            }
            current = current->left;
        }
        else {
            if (current->right == NULL) {
                current->right = temp;
                return;
            }
            current = current->right;
        }
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

int main() {
    struct node* root = NULL;
    root = createNode(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);
    printf("\n");

    struct node* temp = search(root, 70);
    if (temp != NULL)
        printf("Key 70 found!\n");
    else
        printf("Key 70 not found!\n");

    return 0;
}