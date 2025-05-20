//FormAI DATASET v1.0 Category: Binary search trees ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

/* A struct to represent a node in the binary search tree */
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

/* A function to create a new node */
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* A recursive function to insert a new node in the binary search tree */
struct Node* insert(struct Node* root, int data){
    /* If the tree is empty, return a new node */
    if(root == NULL){
        return newNode(data);
    }
    /* Otherwise, recur down the tree */
    if(data < root->data){
        root->left = insert(root->left, data);
    }else if(data > root->data){
        root->right = insert(root->right, data);
    }

    /* Return the (unchanged) node pointer */
    return root;
}

/* A recursive function to delete a node from the binary search tree */
struct Node* delete(struct Node* root, int data){
    /* If the tree is empty, return NULL */
    if(root == NULL){
        return root;
    }
    /* Otherwise, recur down the tree */
    if(data < root->data){
        root->left = delete(root->left, data);
    }else if(data > root->data){
        root->right = delete(root->right, data);
    }
    /* If the key is same as root's key, then this node is to be deleted */
    else{
        /* Case 1: Node with only one child or no child */
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        /* Case 2: Node with two children. 
         * Get the in-order successor (smallest in the right subtree) */
        struct Node* temp = root->right;
        while(temp && temp->left != NULL){
            temp = temp->left;
        }
        /* Copy the in-order successor's content to this node */
        root->data = temp->data;
        /* Delete the in-order successor */
        root->right = delete(root->right, temp->data);
    }
    /* Return the (unchanged) node pointer */
    return root;
}

/* A recursive function to search a key in the binary search tree */
struct Node* search(struct Node* root, int data){
    /* If the tree is empty or the root is the key */
    if(root == NULL || root->data == data){
        return root;
    }
    /* Recur down the tree */
    if(data < root->data){
        return search(root->left, data);
    }else{
        return search(root->right, data);
    }
}

/* A function to print the binary search tree in in-order traversal */
void inOrderTraversal(struct Node* root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

/* A function to print the binary search tree in pre-order traversal */
void preOrderTraversal(struct Node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

/* A function to print the binary search tree in post-order traversal */
void postOrderTraversal(struct Node* root){
    if(root != NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("Deleting 20: ");
    root = delete(root, 20);
    printf("In-order traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Deleting 30: ");
    root = delete(root, 30);
    printf("In-order traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Searching for 70: ");
    if(search(root, 70) != NULL){
        printf("Found\n");
    }else{
        printf("Not found\n");
    }

    printf("Searching for 90: ");
    if(search(root, 90) != NULL){
        printf("Found\n");
    }else{
        printf("Not found\n");
    }
    return 0;
}