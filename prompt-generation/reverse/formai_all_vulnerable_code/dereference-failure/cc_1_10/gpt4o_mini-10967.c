//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_DEPTH 10 // Define max depth for visualization

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert value into the BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return create_node(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Function to visualize the tree
void visualize(Node* root, int depth) {
    if (root == NULL || depth > MAX_DEPTH) return;
    visualize(root->right, depth + 1);
    for (int i = 0; i < depth; i++)
        printf("    ");
    printf("%d\n", root->value);
    visualize(root->left, depth + 1);
}

// Function to free the tree
void free_tree(Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Function to handle pipe communication
void communicate_bst(Node* root) {
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(pipefd[1]); // Close unused write end
        int value;
        while (read(pipefd[0], &value, sizeof(value)) > 0) {
            printf("Received value %d in child process %d\n", value, getpid());
            // Here you could perform other operations on received value
        }
        close(pipefd[0]);
        exit(0);
    } else { // Parent process
        close(pipefd[0]); // Close unused read end
        // For demonstration, insert a few values
        for (int i = 10; i < 15; i++) {
            write(pipefd[1], &i, sizeof(i));
        }
        close(pipefd[1]); // Close write end after sending
        wait(NULL); // Wait for child
    }
}

int main() {
    Node* root = NULL;
    int values[] = {15, 10, 20, 8, 12, 17, 25};

    // Insert values into the BST
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        root = insert(root, values[i]);
    }

    // Visualize the binary search tree
    printf("Binary Search Tree Visualization:\n");
    visualize(root, 0);

    // Demonstrating inter-process communication
    printf("\nCommunicating values via pipe:\n");
    communicate_bst(root);

    // Clean up
    free_tree(root);
    return 0;
}