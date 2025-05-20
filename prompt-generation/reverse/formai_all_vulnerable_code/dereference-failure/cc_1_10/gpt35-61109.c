//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

//Structure for a Node
struct node {
    int value;
    struct node* left;
    struct node* right;
}node;

//Function to create a new node
struct node * newNode(int val) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->value = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//Function to insert a new node into the Tree
struct node * insert(struct node *node, int val) {
    if(node == NULL)
        return newNode(val);
    else {
        if(val < node->value)
            node->left = insert(node->left, val);
        else if(val > node->value)
            node->right = insert(node->right, val);
        return node;
    }
}

//Function to print the Binary Search Tree
void printBST(struct node *root, int space) {
    if (root == NULL)
        return;
    space += 10;
    printBST(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);
    printBST(root->left, space);
}

//Driver function
int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Visualisation of Binary Search Tree (BST):\n");
    printBST(root, 0);
    return 0;
}