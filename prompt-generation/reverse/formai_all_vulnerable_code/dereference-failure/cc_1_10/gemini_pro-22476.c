//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: systematic
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
struct BST *createBST() {
    struct BST *bst = (struct BST *)malloc(sizeof(struct BST));
    bst->root = NULL;
    return bst;
}

// Insert a new node into a binary search tree
void insert(struct BST *bst, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
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
struct Node *search(struct BST *bst, int data) {
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

// Find the minimum node in a binary search tree
struct Node *findMin(struct BST *bst) {
    struct Node *current = bst->root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Find the maximum node in a binary search tree
struct Node *findMax(struct BST *bst) {
    struct Node *current = bst->root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Delete a node from a binary search tree
void delete(struct BST *bst, int data) {
    struct Node *current = bst->root;
    struct Node *parent = NULL;
    while (current != NULL) {
        if (data == current->data) {
            break;
        } else if (data < current->data) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }

    if (current == NULL) {
        printf("Node not found\n");
    } else {
        if (current->left == NULL && current->right == NULL) {
            if (parent == NULL) {
                bst->root = NULL;
            } else if (parent->left == current) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            free(current);
        } else if (current->left == NULL) {
            if (parent == NULL) {
                bst->root = current->right;
            } else if (parent->left == current) {
                parent->left = current->right;
            } else {
                parent->right = current->right;
            }
            free(current);
        } else if (current->right == NULL) {
            if (parent == NULL) {
                bst->root = current->left;
            } else if (parent->left == current) {
                parent->left = current->left;
            } else {
                parent->right = current->left;
            }
            free(current);
        } else {
            struct Node *successor = findMin(current->right);
            current->data = successor->data;
            delete(bst, successor->data);
        }
    }
}

// Print a binary search tree in preorder
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Print a binary search tree in inorder
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Print a binary search tree in postorder
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Driver code
int main() {
    struct BST *bst = createBST();
    insert(bst, 10);
    insert(bst, 5);
    insert(bst, 15);
    insert(bst, 2);
    insert(bst, 7);
    insert(bst, 12);
    insert(bst, 20);

    printf("Preorder: ");
    preorder(bst->root);
    printf("\n");

    printf("Inorder: ");
    inorder(bst->root);
    printf("\n");

    printf("Postorder: ");
    postorder(bst->root);
    printf("\n");

    struct Node *node = search(bst, 15);
    if (node != NULL) {
        printf("Node found: %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    delete(bst, 15);
    printf("Inorder after deletion: ");
    inorder(bst->root);
    printf("\n");

    return 0;
}