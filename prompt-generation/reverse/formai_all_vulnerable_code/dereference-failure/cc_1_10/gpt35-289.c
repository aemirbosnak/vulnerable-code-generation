//FormAI DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert_node(struct node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
        return root;
    }
    if (data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

int search_node(struct node* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1;
    } else if (data <= root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

void in_order(struct node* root) {
    if (root == NULL) {
        return;
    }
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

int main() {
    struct node* root = NULL;
    root = insert_node(root, 10);
    insert_node(root, 5);
    insert_node(root, 15);
    insert_node(root, 7);
    insert_node(root, 9);
    insert_node(root, 12);
    insert_node(root, 18);
    insert_node(root, 2);
    insert_node(root, 21);
    printf("In-order traversal of the binary search tree:\n");
    in_order(root);
    printf("\n");
    int num;
    printf("Enter a number to search: ");
    scanf("%d", &num);
    if (search_node(root, num)) {
        printf("%d is found!\n", num);
    } else {
        printf("%d is not found!\n", num);
    }
    return 0;
}