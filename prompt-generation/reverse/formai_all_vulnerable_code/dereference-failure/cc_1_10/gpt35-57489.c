//FormAI DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
#include<stdlib.h>
#include<stdio.h>
 
typedef struct BSTnode {
    int key;
    struct BSTnode *left, *right;
} BSTnode;
 
BSTnode* new_BSTnode(int key) {
    BSTnode* node = (BSTnode*) malloc(sizeof(BSTnode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
 
BSTnode* insert(BSTnode* node, int key) {
    if (node == NULL) return new_BSTnode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
 
void inorder(BSTnode* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
}
 
BSTnode* search(BSTnode* node, int key) {
    if (node == NULL || node->key == key)
       return node;
    if (node->key < key)
       return search(node->right, key);
    return search(node->left, key);
}
 
BSTnode* minValueNode(BSTnode* node) {
    BSTnode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
 
BSTnode* delete(BSTnode* root, int key) {
    if (root == NULL) return root;
    if (key < root->key)
        root->left = delete(root->left, key);
    else if (key > root->key)
        root->right = delete(root->right, key);
    else {
        if (root->left == NULL) {
            BSTnode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BSTnode *temp = root->left;
            free(root);
            return temp;
        }
        BSTnode* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }
    return root;
}
 
int main() {
    BSTnode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);
    printf("\nDeleting node 20...\n");
    root = delete(root, 20);
    printf("Inorder traversal of the modified binary search tree is: ");
    inorder(root);
    return 0;
}