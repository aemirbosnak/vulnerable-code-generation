//FormAI DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 

struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 

struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 

    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 

    return node; 
} 

int main() 
{ 
    struct node *root = NULL; 
    printf("Enter the number of players: ");
    int n, i, key;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter player %d's score: ", i+1);
        scanf("%d", &key);
        root = insert(root, key);
    }
    printf("\nThe player ranks are as follows: \n\n");
    inorder(root); 
    return 0; 
}