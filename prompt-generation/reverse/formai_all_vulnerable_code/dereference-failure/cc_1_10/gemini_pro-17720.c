//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *create_node(int data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node *insert_node(struct Node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (root->data > data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

int find_min(struct Node *root) {
    if (root->left == NULL) {
        return root->data;
    } else {
        return find_min(root->left);
    }
}

int find_max(struct Node *root) {
    if (root->right == NULL) {
        return root->data;
    } else {
        return find_max(root->right);
    }
}

int search_node(struct Node *root, int data) {
    if (root == NULL) {
        return 0;
    } else if (root->data == data) {
        return 1;
    } else if (root->data > data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

void inorder_traversal(struct Node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    // Magically insert nodes into the tree
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // Discover the tiniest value within the tree
    int min = find_min(root);
    printf("Behold, the smallest treasure: %d\n", min);

    // Marvel at the mightiest value in the tree
    int max = find_max(root);
    printf("Witness the grandest pinnacle: %d\n", max);

    // Embark on a hunt for a specific value
    int target = 40;
    int found = search_node(root, target);
    if (found) {
        printf("Eureka! The treasure '%d' has been found!\n", target);
    } else {
        printf("Alas, the treasure '%d' eludes our search.\n", target);
    }

    // Wander through the tree, revealing its secrets
    printf("Unveiling the tree's secrets in order:\n");
    inorder_traversal(root);

    return 0;
}