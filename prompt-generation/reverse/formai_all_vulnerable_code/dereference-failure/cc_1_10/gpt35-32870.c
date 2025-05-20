//FormAI DATASET v1.0 Category: Binary search trees ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if(root == NULL) {
        root = new_node;
    } else {
        struct node *current = root;
        while(1) {
            if(data < current->data) {
                if(current->left == NULL) {
                    current->left = new_node;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if(current->right == NULL) {
                    current->right = new_node;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

void inorder(struct node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void search(int data) {
    struct node *current = root;
    while(current != NULL) {
        if(current->data == data) {
            printf("%d found in the tree\n", data);
            return;
        } else if(data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    printf("%d not found in the tree\n", data);
}

int main() {
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int i;
    for(i = 0; i < 9; i++) {
        insert(arr[i]);
    }
    printf("Inorder traversal of the binary search tree: ");
    inorder(root);
    printf("\n");
    search(7);
    search(11);
    return 0;
}