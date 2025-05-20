//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define a node in a binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node with the given data
struct node* create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into a binary tree
struct node* insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Print the binary tree in a pre-order traversal
void pre_order(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

// Print the binary tree in an in-order traversal
void in_order(struct node *root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}

// Print the binary tree in a post-order traversal
void post_order(struct node *root) {
    if (root != NULL) {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->data);
    }
}

// Print the binary tree in a level-order traversal
void level_order(struct node *root) {
    if (root == NULL) {
        return;
    }

    // Create a queue to store the nodes
    struct node *queue[100];
    int front = 0;
    int rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    // While the queue is not empty
    while (front != rear) {
        // Dequeue the front node
        struct node *node = queue[front++];

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
}

// Print the binary tree in a graphical representation
void print_tree(struct node *root, int level) {
    if (root == NULL) {
        return;
    }

    // Print the spaces for the current level
    for (int i = 0; i < level; i++) {
        printf(" ");
    }

    // Print the data of the current node
    printf("%d\n", root->data);

    // Print the left and right subtrees of the current node
    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
}

// Driver code
int main() {
    // Create a binary tree
    struct node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 3);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    // Print the binary tree in a pre-order traversal
    printf("Pre-order: ");
    pre_order(root);
    printf("\n");

    // Print the binary tree in an in-order traversal
    printf("In-order: ");
    in_order(root);
    printf("\n");

    // Print the binary tree in a post-order traversal
    printf("Post-order: ");
    post_order(root);
    printf("\n");

    // Print the binary tree in a level-order traversal
    printf("Level-order: ");
    level_order(root);
    printf("\n");

    // Print the binary tree in a graphical representation
    printf("Graphical representation:\n");
    print_tree(root, 0);

    return 0;
}