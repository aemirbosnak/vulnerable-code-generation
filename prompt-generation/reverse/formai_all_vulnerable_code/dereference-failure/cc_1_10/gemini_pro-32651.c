//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into a binary tree
struct node* insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to print a binary tree in a pre-order traversal
void preorder_traversal(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Function to print a binary tree in an in-order traversal
void inorder_traversal(struct node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Function to print a binary tree in a post-order traversal
void postorder_traversal(struct node *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to print a binary tree in a level-order traversal
void levelorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }

    // Create a queue to store the nodes of the binary tree
    struct node **queue = malloc(sizeof(struct node*) * 100);
    int front = 0;
    int rear = 0;

    // Enqueue the root node into the queue
    queue[rear++] = root;

    // While the queue is not empty, dequeue the front node and print its data
    while (front != rear) {
        struct node *current_node = queue[front++];
        printf("%d ", current_node->data);

        // If the left child of the current node is not NULL, enqueue it into the queue
        if (current_node->left != NULL) {
            queue[rear++] = current_node->left;
        }

        // If the right child of the current node is not NULL, enqueue it into the queue
        if (current_node->right != NULL) {
            queue[rear++] = current_node->right;
        }
    }

    // Free the memory allocated to the queue
    free(queue);
}

// Main function
int main() {
    // Create a binary tree
    struct node *root = create_node(10);
    insert_node(root, 5);
    insert_node(root, 15);
    insert_node(root, 2);
    insert_node(root, 7);
    insert_node(root, 12);
    insert_node(root, 20);

    // Print the binary tree in a pre-order traversal
    printf("Pre-order traversal: ");
    preorder_traversal(root);
    printf("\n");

    // Print the binary tree in an in-order traversal
    printf("In-order traversal: ");
    inorder_traversal(root);
    printf("\n");

    // Print the binary tree in a post-order traversal
    printf("Post-order traversal: ");
    postorder_traversal(root);
    printf("\n");

    // Print the binary tree in a level-order traversal
    printf("Level-order traversal: ");
    levelorder_traversal(root);
    printf("\n");

    return 0;
}