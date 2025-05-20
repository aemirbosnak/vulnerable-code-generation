//FormAI DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 

// function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

// function to insert a new node in BST 
struct node* insert(struct node* node, int key) 
{ 
    // if the tree is empty, return a new node 
    if (node == NULL) return newNode(key); 

    // otherwise, recur down the tree 
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    

    // return the root 
    return node; 
} 

// function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
} 

// function to search for a given key in BST 
struct node* search(struct node* root, int key) 
{ 
    // base cases: root is null or key is present at root 
    if (root == NULL || root->key == key) 
       return root; 
    
    // key is greater than root's key 
    if (root->key < key) 
       return search(root->right, key); 
    
    // key is smaller than root's key 
    return search(root->left, key); 
} 

int main() 
{ 
    struct node *root = NULL; 

    // insert nodes into the BST 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 

    // print inorder traversal of the BST 
    printf("Inorder traversal of the BST: "); 
    inorder(root); 
    printf("\n"); 

    // search for a key in the BST 
    int key = 30; 
    struct node* temp = search(root, key); 
    if (temp != NULL) 
        printf("%d is present in the BST\n", key); 
    else
        printf("%d is not present in the BST\n", key); 

    return 0; 
}