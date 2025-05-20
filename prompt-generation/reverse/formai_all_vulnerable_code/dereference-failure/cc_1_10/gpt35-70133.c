//FormAI DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node* search(struct node *root, int key) {
    if(root==NULL || root->data==key)
        return root;
    if(key < root->data)
        return search(root->leftChild, key);
    else
        return search(root->rightChild, key);
}

struct node* insert(struct node *root, int data) {
    if(root==NULL) {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->leftChild = temp->rightChild = NULL;
        return temp;
    }
    if(data < root->data) {
        root->leftChild = insert(root->leftChild, data);
    } else if(data > root->data) {
        root->rightChild = insert(root->rightChild, data);
    }
    return root;
}

void inorderTraversal(struct node *root) {
    if(root != NULL) {
        inorderTraversal(root->leftChild);
        printf("%d ",root->data);
        inorderTraversal(root->rightChild);
    }
}

int main() {
    struct node *root=NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 12);
    insert(root, 17);
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    int key = 15;
    struct node *temp = search(root, key);
    printf("Key found: %d\n",temp->data);

    key = 9;
    temp = search(root, key);
    if(temp==NULL) {
        printf("Key %d not found.\n",key);
    }

    return 0;
}