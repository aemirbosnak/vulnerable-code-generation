//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman tree
typedef struct node {
    int frequency;
    char character;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node
node *create_node(int frequency, char character) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->frequency = frequency;
    new_node->character = character;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to compare two nodes based on their frequencies
int compare_nodes(const void *a, const void *b) {
    node *node1 = (node *)a;
    node *node2 = (node *)b;
    return node1->frequency - node2->frequency;
}

// Function to build Huffman tree
node *build_huffman_tree(char *characters, int *frequencies, int size) {
    // Create a priority queue to store the nodes
    node **priority_queue = (node **)malloc(size * sizeof(node *));
    int front = 0, rear = -1;

    // Insert nodes into the priority queue
    for (int i = 0; i < size; i++) {
        priority_queue[++rear] = create_node(frequencies[i], characters[i]);
    }

    // Sort the priority queue based on frequencies
    qsort(priority_queue, size, sizeof(node *), compare_nodes);

    // Build the Huffman tree
    while (rear > 0) {
        // Remove the two nodes with the lowest frequencies
        node *node1 = priority_queue[front++];
        node *node2 = priority_queue[front++];

        // Create a new node with the sum of the frequencies of the two removed nodes
        node *new_node = create_node(node1->frequency + node2->frequency, '\0');

        // Make the two removed nodes as children of the new node
        new_node->left = node1;
        new_node->right = node2;

        // Insert the new node into the priority queue
        priority_queue[++rear] = new_node;

        // Sort the priority queue based on frequencies
        qsort(priority_queue, rear + 1, sizeof(node *), compare_nodes);
    }

    // Return the root of the Huffman tree
    return priority_queue[front];
}

// Function to generate Huffman codes for each character
void generate_huffman_codes(node *root, char *codes, char *current_code, int index) {
    if (root->left == NULL && root->right == NULL) {
        // If the node is a leaf, assign the current code to the character
        codes[index] = '\0';
        printf("%c: %s\n", root->character, current_code);
        return;
    }

    // If the node is not a leaf, traverse the left and right subtrees
    current_code[index] = '0';
    generate_huffman_codes(root->left, codes, current_code, index + 1);
    current_code[index] = '1';
    generate_huffman_codes(root->right, codes, current_code, index + 1);
}

// Function to compress a string using Huffman coding
char *compress(char *string, char *codes) {
    int string_length = strlen(string);
    char *compressed_string = (char *)malloc(string_length * sizeof(char) + 1);
    int index = 0;

    for (int i = 0; i < string_length; i++) {
        strcat(compressed_string, codes[string[i]]);
    }

    return compressed_string;
}

// Function to decompress a string using Huffman coding
char *decompress(char *compressed_string, node *root) {
    int compressed_string_length = strlen(compressed_string);
    char *decompressed_string = (char *)malloc(compressed_string_length * sizeof(char) + 1);
    int index = 0;

    node *current_node = root;
    for (int i = 0; i < compressed_string_length; i++) {
        if (compressed_string[i] == '0') {
            current_node = current_node->left;
        } else if (compressed_string[i] == '1') {
            current_node = current_node->right;
        }

        if (current_node->left == NULL && current_node->right == NULL) {
            decompressed_string[index++] = current_node->character;
            current_node = root;
        }
    }

    return decompressed_string;
}

// Main function
int main() {
    // Input characters and their frequencies
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(characters) / sizeof(characters[0]);

    // Build Huffman tree
    node *root = build_huffman_tree(characters, frequencies, size);

    // Generate Huffman codes for each character
    char codes[size];
    char current_code[size];
    generate_huffman_codes(root, codes, current_code, 0);

    // Compress a string using Huffman coding
    char *string = "ababcab";
    char *compressed_string = compress(string, codes);
    printf("Compressed string: %s\n", compressed_string);

    // Decompress the compressed string using Huffman coding
    char *decompressed_string = decompress(compressed_string, root);
    printf("Decompressed string: %s\n", decompressed_string);

    return 0;
}