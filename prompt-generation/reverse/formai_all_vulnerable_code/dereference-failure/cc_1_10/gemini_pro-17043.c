//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// A binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// A binary search tree
struct BST {
    struct Node *root;
};

// Create a new binary search tree
struct BST *create_bst() {
    struct BST *bst = malloc(sizeof(struct BST));
    bst->root = NULL;
    return bst;
}

// Insert a new node into a binary search tree
void insert_bst(struct BST *bst, int data) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (bst->root == NULL) {
        bst->root = new_node;
    } else {
        struct Node *current = bst->root;
        while (1) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = new_node;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = new_node;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

// Search for a node in a binary search tree
struct Node *search_bst(struct BST *bst, int data) {
    struct Node *current = bst->root;
    while (current != NULL) {
        if (data == current->data) {
            return current;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

// Print a binary search tree in preorder traversal
void preorder_bst(struct BST *bst) {
    struct Node *current = bst->root;
    if (current == NULL) {
        return;
    }
    printf("%d ", current->data);
    preorder_bst(create_bst(current->left));
    preorder_bst(create_bst(current->right));
}

// Print a binary search tree in inorder traversal
void inorder_bst(struct BST *bst) {
    struct Node *current = bst->root;
    if (current == NULL) {
        return;
    }
    inorder_bst(create_bst(current->left));
    printf("%d ", current->data);
    inorder_bst(create_bst(current->right));
}

// Print a binary search tree in postorder traversal
void postorder_bst(struct BST *bst) {
    struct Node *current = bst->root;
    if (current == NULL) {
        return;
    }
    postorder_bst(create_bst(current->left));
    postorder_bst(create_bst(current->right));
    printf("%d ", current->data);
}

// Free a binary search tree
void free_bst(struct BST *bst) {
    if (bst->root == NULL) {
        return;
    }
    free_bst(create_bst(bst->root->left));
    free_bst(create_bst(bst->root->right));
    free(bst->root);
}

// Main function
int main() {
    // Create a binary search tree
    struct BST *bst = create_bst();

    // Insert some data into the binary search tree
    insert_bst(bst, 10);
    insert_bst(bst, 5);
    insert_bst(bst, 15);
    insert_bst(bst, 2);
    insert_bst(bst, 7);
    insert_bst(bst, 12);
    insert_bst(bst, 20);

    // Search for a node in the binary search tree
    struct Node *node = search_bst(bst, 15);
    if (node != NULL) {
        printf("Found node with data %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    // Print the binary search tree in preorder traversal
    printf("Preorder traversal: ");
    preorder_bst(bst);
    printf("\n");

    // Print the binary search tree in inorder traversal
    printf("Inorder traversal: ");
    inorder_bst(bst);
    printf("\n");

    // Print the binary search tree in postorder traversal
    printf("Postorder traversal: ");
    postorder_bst(bst);
    printf("\n");

    // Free the binary search tree
    free_bst(bst);

    return 0;
}