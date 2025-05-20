//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a node for a binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

// Create a new node with the given data
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node with the given data into the binary tree
void insert_node(node_t **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data <= (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

// Print the binary tree in preorder traversal
void preorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// Print the binary tree in inorder traversal
void inorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// Print the binary tree in postorder traversal
void postorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

// Print the binary tree in level order traversal
void level_order_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    // Create a queue to store the nodes in the current level
    node_t **queue = (node_t **)malloc(sizeof(node_t *) * 100);
    int front = 0;
    int rear = 0;
    // Enqueue the root node
    queue[rear++] = root;
    while (front != rear) {
        // Dequeue the first node in the queue
        node_t *node = queue[front++];
        // Print the data of the dequeued node
        printf("%d ", node->data);
        // Enqueue the left and right children of the dequeued node
        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
    free(queue);
}

int main() {
    // Create a binary tree
    node_t *root = NULL;
    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 15);
    insert_node(&root, 2);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 20);

    // Print the binary tree in preorder traversal
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    // Print the binary tree in inorder traversal
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    // Print the binary tree in postorder traversal
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    // Print the binary tree in level order traversal
    printf("Level order traversal: ");
    level_order_traversal(root);
    printf("\n");

    return 0;
}