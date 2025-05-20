//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node {
    int data;
    struct bst_node *left;
    struct bst_node *right;
} bst_node;

bst_node* bst_create_node(int data) {
    bst_node *node = malloc(sizeof(bst_node));
    if (node == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for new node.\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void bst_insert(bst_node **root, int data) {
    if (*root == NULL) {
        *root = bst_create_node(data);
        return;
    }
    if (data < (*root)->data) {
        bst_insert(&(*root)->left, data);
    } else if (data > (*root)->data) {
        bst_insert(&(*root)->right, data);
    } else {
        fprintf(stderr, "Error: Duplicate data value encountered.\n");
        exit(EXIT_FAILURE);
    }
}

bst_node* bst_find(bst_node *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        return bst_find(root->left, data);
    } else if (data > root->data) {
        return bst_find(root->right, data);
    } else {
        return root;
    }
}

void bst_delete(bst_node **root, int data) {
    if (*root == NULL) {
        return;
    }
    if (data < (*root)->data) {
        bst_delete(&(*root)->left, data);
    } else if (data > (*root)->data) {
        bst_delete(&(*root)->right, data);
    } else {
        if ((*root)->left == NULL) {
            bst_node *temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            bst_node *temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            bst_node *temp = (*root)->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            (*root)->data = temp->data;
            bst_delete(&(*root)->left, temp->data);
        }
    }
}

void bst_print_inorder(bst_node *root) {
    if (root == NULL) {
        return;
    }
    bst_print_inorder(root->left);
    printf("%d ", root->data);
    bst_print_inorder(root->right);
}

void bst_free(bst_node *root) {
    if (root == NULL) {
        return;
    }
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}

int main() {
    bst_node *root = NULL;

    // Insert some data into the tree
    bst_insert(&root, 10);
    bst_insert(&root, 5);
    bst_insert(&root, 15);
    bst_insert(&root, 2);
    bst_insert(&root, 7);
    bst_insert(&root, 12);
    bst_insert(&root, 20);

    // Print the tree in order
    printf("Inorder traversal: ");
    bst_print_inorder(root);
    printf("\n");

    // Find a value in the tree
    bst_node *found_node = bst_find(root, 12);
    if (found_node == NULL) {
        printf("Error: Value not found in tree.\n");
        exit(EXIT_FAILURE);
    }
    printf("Found value: %d\n", found_node->data);

    // Delete a value from the tree
    bst_delete(&root, 12);

    // Print the tree in order again
    printf("Inorder traversal after deletion: ");
    bst_print_inorder(root);
    printf("\n");

    // Free the tree
    bst_free(root);

    return 0;
}