//FormAI DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
//Get ready to dive into the world of Binary Search Trees
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node *newNode(int item) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Traverse the tree
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

//Insert a new node 
struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

//Search for a node
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (root->data < data)
        return search(root->right, data);
    return search(root->left, data);
}

// Finding the minimum value
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Deleting a node
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    printf("Welcome to the Binary Search Tree program!\n");
    
    struct node *root = NULL;
    int min, max, value, choice;
    
    printf("Enter the number of nodes in the tree: ");
    scanf("%d",&choice);
    
    for(int i=0; i<choice; i++){
        printf("Enter value to be inserted in the tree: ");
        scanf("%d",&value);
        root = insert(root,value);
        printf("Updated Tree Elements: \n");
        inorder(root);
        printf("\n");
    }
    
    printf("Enter value to be searched in the tree: ");
    scanf("%d",&value);
    if(search(root, value) == NULL){
        printf("%d not found in the tree\n",value);
    }else{
        printf("%d found in the tree\n", value);
    }
    
    printf("Enter value to be deleted from the tree: ");
    scanf("%d",&value);
    root = deleteNode(root,value);
    printf("Updated Tree Elements: \n");
    inorder(root);
    printf("\n");
    
    printf("Now let me tell you the minimum and maximum values in the tree\n");
    struct node* current = root;
    while (current->left != NULL)
        current = current->left;
    min = current->data;
    printf("Minimum value: %d\n",min);
    current = root;
    while (current->right != NULL)
        current = current->right;
    max = current->data;
    printf("Maximum value: %d\n",max);
    
    return 0;
}