//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Create a node for the binary tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

// Create a new node with the given data
node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into the binary tree
void insert_node(node** root, int data) {
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

// Print the binary tree in preorder traversal
void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Print the binary tree in inorder traversal
void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Print the binary tree in postorder traversal
void postorder(node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Print the binary tree in level order traversal
void level_order(node* root) {
    if (root == NULL) {
        return;
    }
    // Create a queue to store the nodes
    node** queue = (node**)malloc(sizeof(node*) * 100);
    int front = 0;
    int rear = 0;
    // Enqueue the root node
    queue[rear++] = root;
    while (front != rear) {
        // Dequeue the front node
        node* current_node = queue[front++];
        // Print the data of the current node
        printf("%d ", current_node->data);
        // Enqueue the left and right children of the current node
        if (current_node->left != NULL) {
            queue[rear++] = current_node->left;
        }
        if (current_node->right != NULL) {
            queue[rear++] = current_node->right;
        }
    }
    // Free the queue
    free(queue);
}

// Print the binary tree in graphical form
void print_tree(node* root, int depth) {
    if (root == NULL) {
        return;
    }
    // Print the spaces for the current depth
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    // Print the data of the current node
    printf("%d\n", root->data);
    // Print the left and right subtrees
    print_tree(root->left, depth + 1);
    print_tree(root->right, depth + 1);
}

// Main function
int main() {
    // Create a binary tree
    node* root = NULL;
    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 15);
    insert_node(&root, 2);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 20);

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
    level_order(root);
    printf("\n");

    // Print the binary tree in graphical form
    printf("Graphical representation of the binary tree:\n");
    print_tree(root, 0);

    return 0;
}