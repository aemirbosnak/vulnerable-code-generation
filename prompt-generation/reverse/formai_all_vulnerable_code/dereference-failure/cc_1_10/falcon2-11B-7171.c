//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: happy
#include <stdio.h>

// A binary search tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Insert a new node with the given data into the tree
void insert(struct node **root, int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct node *current = *root;
    while (current!= NULL) {
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = newNode;
                break;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = newNode;
                break;
            }
            current = current->right;
        }
    }
}

// Search for a value in the tree and print the result
void search(struct node *root, int data) {
    if (root == NULL) {
        printf("Not found\n");
    } else if (data == root->data) {
        printf("Found at %d\n", root->data);
    } else if (data < root->data) {
        search(root->left, data);
    } else {
        search(root->right, data);
    }
}

// Print the elements of the tree in inorder traversal
void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node *root = NULL;

    // Insert some numbers into the tree
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);
    insert(&root, 1);

    // Search for some values in the tree
    search(root, 1);
    search(root, 2);
    search(root, 3);
    search(root, 4);
    search(root, 5);
    search(root, 6);
    search(root, 7);
    search(root, 8);

    // Print the elements of the tree in inorder traversal
    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}