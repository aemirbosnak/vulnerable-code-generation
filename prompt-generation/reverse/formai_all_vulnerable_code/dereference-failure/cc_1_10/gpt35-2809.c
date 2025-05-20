//FormAI DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left_child;
    struct node* right_child;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

void insert(struct node** root, int data) {
    if(*root == NULL) {
        *root = create_node(data);
    }
    else if(data <= (*root)->data) {
        insert(&((*root)->left_child), data);
    }
    else {
        insert(&((*root)->right_child), data);
    }
}

int search(struct node* root, int data) {
    if(root == NULL) {
        return 0;
    }
    else if(root->data == data) {
        return 1;
    }
    else if(data <= root->data) {
        return search(root->left_child, data);
    }
    else {
        return search(root->right_child, data);
    }
}

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left_child);
        printf("%d ", root->data);
        inorder(root->right_child);
    }
}

int main() {
    struct node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
    
    printf("Inorder traversal of BST: ");
    inorder(root);
    printf("\n");
    
    int n;
    printf("Enter value to be searched: ");
    scanf("%d", &n);
    if(search(root, n)) {
        printf("Value found!\n");
    }
    else {
        printf("Value not found.\n");
    }
    
    return 0;
}