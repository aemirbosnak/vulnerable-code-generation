//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }

    if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
        return;
    } else {
        insert_node(&(*root)->right, data);
        return;
    }
}

node *search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

void delete_node(node **root, int data) {
    if (*root == NULL) {
        return;
    }

    if (data < (*root)->data) {
        delete_node(&(*root)->left, data);
        return;
    } else if (data > (*root)->data) {
        delete_node(&(*root)->right, data);
        return;
    } else {
        if ((*root)->left == NULL) {
            node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return;
        } else if ((*root)->right == NULL) {
            node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return;
        } else {
            node *temp = (*root)->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            (*root)->data = temp->data;
            delete_node(&(*root)->left, temp->data);
            return;
        }
    }
}

void inorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

int main() {
    node *root = NULL;

    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 15);
    insert_node(&root, 2);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 20);

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    node *found_node = search_node(root, 10);
    if (found_node != NULL) {
        printf("Node with data 10 found!\n");
    } else {
        printf("Node with data 10 not found!\n");
    }

    delete_node(&root, 10);

    printf("Inorder traversal after deleting node with data 10: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}