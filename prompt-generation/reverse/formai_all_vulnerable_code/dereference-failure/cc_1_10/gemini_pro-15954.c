//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// A node in a binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node with the given data
struct Node *create_node(int data) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary search tree
void insert_node(struct Node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }
    if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

// Search for a node in a binary search tree
struct Node *search_node(struct Node *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Delete a node from a binary search tree
void delete_node(struct Node **root, int data) {
    if (*root == NULL) {
        return;
    }
    if (data < (*root)->data) {
        delete_node(&(*root)->left, data);
    } else if (data > (*root)->data) {
        delete_node(&(*root)->right, data);
    } else {
        // Found the node to delete
        if ((*root)->left == NULL) {
            // No left child, so replace the node with its right child
            struct Node *temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            // No right child, so replace the node with its left child
            struct Node *temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            // Two children, so find the smallest node in the right subtree
            struct Node *temp = (*root)->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            // Replace the node with the smallest node in the right subtree
            (*root)->data = temp->data;
            // Delete the smallest node in the right subtree
            delete_node(&(*root)->right, temp->data);
        }
    }
}

// Print a binary search tree in order
void print_tree_inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    print_tree_inorder(root->left);
    printf("%d ", root->data);
    print_tree_inorder(root->right);
}

// Print a binary search tree in preorder
void print_tree_preorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_tree_preorder(root->left);
    print_tree_preorder(root->right);
}

// Print a binary search tree in postorder
void print_tree_postorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    print_tree_postorder(root->left);
    print_tree_postorder(root->right);
    printf("%d ", root->data);
}

// Get the height of a binary search tree
int get_height(struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = get_height(root->left);
    int right_height = get_height(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

// Check if a binary search tree is balanced
int is_balanced(struct Node *root) {
    if (root == NULL) {
        return 1;
    }
    int left_height = get_height(root->left);
    int right_height = get_height(root->right);
    return abs(left_height - right_height) <= 1 && is_balanced(root->left) && is_balanced(root->right);
}

int main() {
    // Create a binary search tree
    struct Node *root = NULL;
    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 15);
    insert_node(&root, 3);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 17);

    // Print the tree in order
    printf("In order: ");
    print_tree_inorder(root);
    printf("\n");

    // Print the tree in preorder
    printf("Pre order: ");
    print_tree_preorder(root);
    printf("\n");

    // Print the tree in postorder
    printf("Post order: ");
    print_tree_postorder(root);
    printf("\n");

    // Search for a node in the tree
    struct Node *found_node = search_node(root, 12);
    if (found_node != NULL) {
        printf("Node found: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the tree
    delete_node(&root, 12);

    // Print the tree in order again
    printf("In order (after deletion): ");
    print_tree_inorder(root);
    printf("\n");

    // Get the height of the tree
    int height = get_height(root);
    printf("Height of the tree: %d\n", height);

    // Check if the tree is balanced
    int balanced = is_balanced(root);
    if (balanced) {
        printf("Tree is balanced\n");
    } else {
        printf("Tree is not balanced\n");
    }

    return 0;
}