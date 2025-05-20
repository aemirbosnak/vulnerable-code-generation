//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HEIGHT 100

typedef struct node {
    int frequency;
    char character;
    struct node *left;
    struct node *right;
} node;

typedef struct huffman_tree {
    struct node *root;
    int size;
} huffman_tree;

huffman_tree *create_huffman_tree(int frequencies[], char characters[], int size) {
    huffman_tree *tree = (huffman_tree *)malloc(sizeof(huffman_tree));
    tree->size = size;

    // Create a priority queue to store the nodes
    node *queue[MAX_TREE_HEIGHT];
    int queue_size = 0;

    // Create a node for each character
    for (int i = 0; i < size; i++) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->frequency = frequencies[i];
        new_node->character = characters[i];
        new_node->left = NULL;
        new_node->right = NULL;

        // Insert the node into the priority queue
        queue[queue_size++] = new_node;
    }

    // Build the Huffman tree
    while (queue_size > 1) {
        // Get the two nodes with the lowest frequencies
        node *left_node = queue[0];
        node *right_node = queue[1];

        // Create a new node for the parent of the two nodes
        node *new_node = (node *)malloc(sizeof(node));
        new_node->frequency = left_node->frequency + right_node->frequency;
        new_node->character = '\0';
        new_node->left = left_node;
        new_node->right = right_node;

        // Remove the two nodes from the priority queue
        queue_size -= 2;
        for (int i = 0; i < queue_size; i++) {
            queue[i] = queue[i + 2];
        }

        // Insert the new node into the priority queue
        queue[queue_size++] = new_node;
    }

    // The root of the Huffman tree is the only node left in the priority queue
    tree->root = queue[0];

    return tree;
}

void print_huffman_tree(huffman_tree *tree) {
    // Create a stack to store the nodes
    node *stack[MAX_TREE_HEIGHT];
    int stack_size = 0;

    // Push the root of the tree onto the stack
    stack[stack_size++] = tree->root;

    // While the stack is not empty
    while (stack_size > 0) {
        // Pop the top node off the stack
        node *node = stack[stack_size--];

        // Print the node's frequency and character
        printf("%d: %c\n", node->frequency, node->character);

        // Push the node's children onto the stack
        if (node->left != NULL) {
            stack[stack_size++] = node->left;
        }
        if (node->right != NULL) {
            stack[stack_size++] = node->right;
        }
    }
}

void free_huffman_tree(huffman_tree *tree) {
    // Create a stack to store the nodes
    node *stack[MAX_TREE_HEIGHT];
    int stack_size = 0;

    // Push the root of the tree onto the stack
    stack[stack_size++] = tree->root;

    // While the stack is not empty
    while (stack_size > 0) {
        // Pop the top node off the stack
        node *node = stack[stack_size--];

        // Free the node
        free(node);

        // Push the node's children onto the stack
        if (node->left != NULL) {
            stack[stack_size++] = node->left;
        }
        if (node->right != NULL) {
            stack[stack_size++] = node->right;
        }
    }

    // Free the tree
    free(tree);
}

int main() {
    // Define the frequencies and characters of the characters
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int size = 6;

    // Create a Huffman tree
    huffman_tree *tree = create_huffman_tree(frequencies, characters, size);

    // Print the Huffman tree
    print_huffman_tree(tree);

    // Free the Huffman tree
    free_huffman_tree(tree);

    return 0;
}