//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node for a binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary tree
struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Print a binary tree in preorder traversal
void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Print a binary tree in inorder traversal
void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Print a binary tree in postorder traversal
void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Print a binary tree in level order traversal
void levelorder(struct node *root) {
    if (root == NULL) {
        return;
    }

    // Create a queue to store nodes
    struct node **queue = (struct node **)malloc(sizeof(struct node *) * 100);
    int front = 0;
    int rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    // While the queue is not empty
    while (front != rear) {

        // Dequeue the front node
        struct node *current_node = queue[front++];

        // Print the data of the front node
        printf("%d ", current_node->data);

        // Enqueue the left and right children of the front node
        if (current_node->left != NULL) {
            queue[rear++] = current_node->left;
        }
        if (current_node->right != NULL) {
            queue[rear++] = current_node->right;
        }
    }

    // Free the memory allocated to the queue
    free(queue);
}

// Print a binary tree in graphical representation
void print_tree(struct node *root, int level) {
    if (root == NULL) {
        return;
    }

    // Print the level of the root node
    printf("Level %d: %d\n", level, root->data);

    // Print the left and right subtrees of the root node
    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
}

int main() {
    // Create a binary tree
    struct node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    // Print the binary tree in preorder traversal
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    // Print the binary tree in inorder traversal
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Print the binary tree in postorder traversal
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    // Print the binary tree in level order traversal
    printf("Level order traversal: ");
    levelorder(root);
    printf("\n");

    // Print the binary tree in graphical representation
    printf("Graphical representation of the binary tree:\n");
    print_tree(root, 0);

    return 0;
}