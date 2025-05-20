//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// A node in a binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// A binary tree
typedef struct tree {
    struct node *root;
} tree;

// Create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary tree
void insert_node(tree *t, node *new_node) {
    if (t->root == NULL) {
        t->root = new_node;
    } else {
        node *current_node = t->root;
        while (1) {
            if (new_node->data < current_node->data) {
                if (current_node->left == NULL) {
                    current_node->left = new_node;
                    break;
                } else {
                    current_node = current_node->left;
                }
            } else {
                if (current_node->right == NULL) {
                    current_node->right = new_node;
                    break;
                } else {
                    current_node = current_node->right;
                }
            }
        }
    }
}

// Print a binary tree in preorder
void preorder(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Print a binary tree in inorder
void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Print a binary tree in postorder
void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Print a binary tree in level order
void levelorder(node *root) {
    if (root != NULL) {
        node *queue[100];
        int front = 0;
        int rear = 0;
        queue[rear++] = root;
        while (front != rear) {
            node *current_node = queue[front++];
            printf("%d ", current_node->data);
            if (current_node->left != NULL) {
                queue[rear++] = current_node->left;
            }
            if (current_node->right != NULL) {
                queue[rear++] = current_node->right;
            }
        }
    }
}

// Print a binary tree in graphical form
void print_tree(node *root, int space) {
    if (root != NULL) {
        int i;
        space += 5;
        print_tree(root->right, space);
        printf("\n");
        for (i = 5; i < space; i++) {
            printf(" ");
        }
        printf("%d\n", root->data);
        print_tree(root->left, space);
    }
}

int main() {
    tree *t = (tree *)malloc(sizeof(tree));
    t->root = NULL;
    insert_node(t, create_node(50));
    insert_node(t, create_node(30));
    insert_node(t, create_node(20));
    insert_node(t, create_node(40));
    insert_node(t, create_node(70));
    insert_node(t, create_node(60));
    insert_node(t, create_node(80));
    printf("Preorder: ");
    preorder(t->root);
    printf("\n");
    printf("Inorder: ");
    inorder(t->root);
    printf("\n");
    printf("Postorder: ");
    postorder(t->root);
    printf("\n");
    printf("Levelorder: ");
    levelorder(t->root);
    printf("\n");
    printf("Graphical representation:\n");
    print_tree(t->root, 0);
    return 0;
}