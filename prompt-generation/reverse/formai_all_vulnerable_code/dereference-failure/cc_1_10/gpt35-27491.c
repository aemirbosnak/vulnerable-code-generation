//FormAI DATASET v1.0 Category: Binary search trees ; Style: retro
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int newdata) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = newdata;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

struct node* insert(struct node* node, int data) {
    if (node == NULL) return create_node(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
       return root;
    if (root->data < key)
       return search(root->right, key);
    return search(root->left, key);
}

void printPostorder(struct node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    struct node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 40);
    insert(root, 30);
    insert(root, 50);
    printf("The elements of the tree in postorder traversal\n");
    printPostorder(root);
    printf("\n");
    int x = 30;
    struct node *result = search(root, x);
    if(result != NULL)
        printf("%d is present in the tree\n", x);
    else
        printf("%d is not present in the tree\n", x);
    return 0;
}