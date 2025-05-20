//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: future-proof
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node {
    unsigned char character;
    unsigned int frequency;
    struct Node *left, *right;
} Node;

typedef struct HuffmanTree {
    Node *root;
    unsigned int size;
} HuffmanTree;

HuffmanTree *create_huffman_tree(unsigned char *data, unsigned int size) {
    // Create a frequency table
    unsigned int frequencies[256] = {0};
    for (unsigned int i = 0; i < size; i++) {
        frequencies[data[i]]++;
    }

    // Create a priority queue of nodes
    Node **nodes = malloc(sizeof(Node *) * 256);
    unsigned int num_nodes = 0;
    for (unsigned int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            nodes[num_nodes++] = malloc(sizeof(Node));
            nodes[num_nodes - 1]->character = i;
            nodes[num_nodes - 1]->frequency = frequencies[i];
            nodes[num_nodes - 1]->left = NULL;
            nodes[num_nodes - 1]->right = NULL;
        }
    }

    // Build the Huffman tree
    while (num_nodes > 1) {
        // Find the two nodes with the lowest frequencies
        unsigned int min_index1 = 0, min_index2 = 1;
        for (unsigned int i = 2; i < num_nodes; i++) {
            if (nodes[i]->frequency < nodes[min_index1]->frequency) {
                min_index2 = min_index1;
                min_index1 = i;
            } else if (nodes[i]->frequency < nodes[min_index2]->frequency) {
                min_index2 = i;
            }
        }

        // Create a new node with the combined frequency of the two nodes
        Node *new_node = malloc(sizeof(Node));
        new_node->character = 0;  // Not used
        new_node->frequency = nodes[min_index1]->frequency + nodes[min_index2]->frequency;
        new_node->left = nodes[min_index1];
        new_node->right = nodes[min_index2];

        // Remove the two nodes from the priority queue
        for (unsigned int i = min_index2 + 1; i < num_nodes; i++) {
            nodes[i - 1] = nodes[i];
        }
        num_nodes--;

        // Insert the new node into the priority queue
        nodes[num_nodes++] = new_node;
    }

    // The remaining node is the root of the Huffman tree
    HuffmanTree *tree = malloc(sizeof(HuffmanTree));
    tree->root = nodes[0];
    tree->size = size;

    // Free the allocated memory
    free(nodes);

    return tree;
}

void destroy_huffman_tree(HuffmanTree *tree) {
    // Recursively destroy the tree
    if (tree->root != NULL) {
        destroy_huffman_tree(tree->root->left);
        destroy_huffman_tree(tree->root->right);
        free(tree->root);
    }

    // Free the tree itself
    free(tree);
}

unsigned char *encode_data(HuffmanTree *tree, unsigned char *data, unsigned int size, unsigned int *encoded_size) {
    // Allocate memory for the encoded data
    unsigned char *encoded_data = malloc(size * 8);

    // Encode the data
    unsigned int index = 0;
    for (unsigned int i = 0; i < size; i++) {
        Node *node = tree->root;
        while (node->left != NULL || node->right != NULL) {
            if (data[i] & (1 << (7 - index))) {
                node = node->right;
            } else {
                node = node->left;
            }
            index++;
        }

        encoded_data[index / 8] |= (1 << (7 - (index % 8)));
        index++;
    }

    // Set the encoded size
    *encoded_size = (index + 7) / 8;

    return encoded_data;
}

unsigned char *decode_data(HuffmanTree *tree, unsigned char *encoded_data, unsigned int encoded_size, unsigned int *decoded_size) {
    // Allocate memory for the decoded data
    unsigned char *decoded_data = malloc(tree->size);

    // Decode the data
    unsigned int index = 0;
    Node *node = tree->root;
    for (unsigned int i = 0; i < encoded_size; i++) {
        for (unsigned int j = 0; j < 8; j++) {
            if (encoded_data[i] & (1 << (7 - j))) {
                node = node->right;
            } else {
                node = node->left;
            }

            if (node->left == NULL && node->right == NULL) {
                decoded_data[index++] = node->character;
                node = tree->root;
            }
        }
    }

    // Set the decoded size
    *decoded_size = index;

    return decoded_data;
}

int main() {
    // Data to be compressed
    unsigned char data[] = "This is a test string";

    // Create the Huffman tree
    HuffmanTree *tree = create_huffman_tree(data, strlen(data));

    // Encode the data
    unsigned int encoded_size;
    unsigned char *encoded_data = encode_data(tree, data, strlen(data), &encoded_size);

    // Decode the data
    unsigned int decoded_size;
    unsigned char *decoded_data = decode_data(tree, encoded_data, encoded_size, &decoded_size);

    // Print the original, encoded, and decoded data
    printf("Original data: %s\n", data);
    printf("Encoded data: ");
    for (unsigned int i = 0; i < encoded_size; i++) {
        printf("%02X", encoded_data[i]);
    }
    printf("\n");
    printf("Decoded data: %s\n", decoded_data);

    // Destroy the Huffman tree
    destroy_huffman_tree(tree);

    // Free the allocated memory
    free(encoded_data);
    free(decoded_data);

    return 0;
}