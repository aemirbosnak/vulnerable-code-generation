//FormAI DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int val) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert(struct node *root, int val) {
    if (root == NULL)
        return create_node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node *search(struct node *root, int val) {
    if (root == NULL || root->data == val)
        return root;
    if (root->data < val)
        return search(root->right, val);
    return search(root->left, val);
}

struct node *min_value_node(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node *delete_node(struct node *root, int val) {
    if (root == NULL)
        return root;
    if (val < root->data)
        root->left = delete_node(root->left, val);
    else if (val > root->data)
        root->right = delete_node(root->right, val);
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
        struct node *temp = min_value_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

int main(void) {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 80);
    insert(root, 10);
    insert(root, 30);
    insert(root, 20);
    insert(root, 90);
    printf("Inorder traversal of the binary search tree: ");
    inorder(root);
    struct node *search_result = search(root, 30);
    if (search_result == NULL)
        printf("\n30 is not present in the binary search tree.");
    else
        printf("\n30 is present in the binary search tree.");
    root = delete_node(root, 30);
    printf("\nInorder traversal of the binary search tree after deleting 30: ");
    inorder(root);
    return 0;
}