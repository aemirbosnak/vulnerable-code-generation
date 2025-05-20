//FormAI DATASET v1.0 Category: Binary search trees ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int item) {
   struct node *temp =  (struct node *)malloc(sizeof(struct node));
   temp->data = item;
   temp->left = temp->right = NULL;
   return temp;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);    
    return node;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
       return root;
    if (root->data < data)
       return search(root->right, data);
    return search(root->left, data);
}

struct node * minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);
    printf("Enter data to search: ");
    int search_data;
    scanf("%d", &search_data);
    struct node *result = search(root, search_data);
    if (result == NULL) printf("%d not found in the binary search tree.\n", search_data);
    else printf("%d found in the binary search tree.\n", result->data);
    printf("Enter data to delete: ");
    int delete_data;
    scanf("%d", &delete_data);
    root = deleteNode(root, delete_data);
    printf("Inorder traversal after deleting the node: ");
    inorder(root);
    return 0;
}