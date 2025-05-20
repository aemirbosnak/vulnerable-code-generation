//FormAI DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int data) {
    if(root == NULL) {
        root = createNode(data);
        return root;
    }
    else if(data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

struct node *search(struct node *root, int data) {
    if(root == NULL)
        return NULL;
    else if(root->data == data)
        return root;
    else if(data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int main() {
    struct node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 8);
    int n;
    printf("Enter number to be searched: ");
    scanf("%d", &n);
    struct node *result = search(root, n);
    if(result == NULL)
        printf("Element not found!\n");
    else
        printf("Element found: %d\n", result->data);
    return 0;
}