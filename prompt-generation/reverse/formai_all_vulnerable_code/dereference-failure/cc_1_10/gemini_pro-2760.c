//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
} node_t;

typedef struct huffman_tree {
    node_t *root;
} huffman_tree_t;

huffman_tree_t *create_huffman_tree(char *string) {
    huffman_tree_t *tree = malloc(sizeof(huffman_tree_t));
    tree->root = NULL;

    if (string == NULL || strlen(string) == 0) {
        return tree;
    }

    // Create a frequency table
    int frequency_table[256] = {0};

    for (int i = 0; i < strlen(string); i++) {
        frequency_table[string[i]]++;
    }

    // Create a priority queue of nodes
    node_t **nodes = malloc(sizeof(node_t *) * 256);
    int num_nodes = 0;

    for (int i = 0; i < 256; i++) {
        if (frequency_table[i] > 0) {
            nodes[num_nodes] = malloc(sizeof(node_t));
            nodes[num_nodes]->character = i;
            nodes[num_nodes]->frequency = frequency_table[i];
            nodes[num_nodes]->left = NULL;
            nodes[num_nodes]->right = NULL;
            num_nodes++;
        }
    }

    // Build the Huffman tree
    while (num_nodes > 1) {
        // Find the two nodes with the lowest frequencies
        node_t *smallest_node1 = NULL;
        node_t *smallest_node2 = NULL;

        for (int i = 0; i < num_nodes; i++) {
            if (smallest_node1 == NULL || nodes[i]->frequency < smallest_node1->frequency) {
                smallest_node1 = nodes[i];
            }
        }

        for (int i = 0; i < num_nodes; i++) {
            if (smallest_node2 == NULL || nodes[i] != smallest_node1 && (smallest_node2 == NULL || nodes[i]->frequency < smallest_node2->frequency)) {
                smallest_node2 = nodes[i];
            }
        }

        // Create a new node with the combined frequency of the two smallest nodes
        node_t *new_node = malloc(sizeof(node_t));
        new_node->character = '\0';
        new_node->frequency = smallest_node1->frequency + smallest_node2->frequency;
        new_node->left = smallest_node1;
        new_node->right = smallest_node2;

        // Remove the two smallest nodes from the priority queue
        for (int i = 0; i < num_nodes; i++) {
            if (nodes[i] == smallest_node1) {
                for (int j = i; j < num_nodes - 1; j++) {
                    nodes[j] = nodes[j + 1];
                }
                break;
            }
        }

        for (int i = 0; i < num_nodes; i++) {
            if (nodes[i] == smallest_node2) {
                for (int j = i; j < num_nodes - 1; j++) {
                    nodes[j] = nodes[j + 1];
                }
                break;
            }
        }

        // Add the new node to the priority queue
        nodes[num_nodes - 2] = new_node;
        num_nodes--;
    }

    tree->root = nodes[0];

    return tree;
}

void print_huffman_tree(huffman_tree_t *tree, char *prefix) {
    if (tree->root == NULL) {
        return;
    }

    if (tree->root->left == NULL && tree->root->right == NULL) {
        printf("%s%c\n", prefix, tree->root->character);
        return;
    }

    print_huffman_tree(tree->root->left, strcat(prefix, "0"));
    print_huffman_tree(tree->root->right, strcat(prefix, "1"));
}

char *encode_string(huffman_tree_t *tree, char *string) {
    char *encoded_string = malloc(sizeof(char) * strlen(string) * 8);
    int encoded_string_index = 0;

    for (int i = 0; i < strlen(string); i++) {
        node_t *current_node = tree->root;

        while (current_node->left != NULL || current_node->right != NULL) {
            if (string[i] == current_node->character) {
                break;
            } else if (string[i] < current_node->character) {
                current_node = current_node->left;
                encoded_string[encoded_string_index++] = '0';
            } else {
                current_node = current_node->right;
                encoded_string[encoded_string_index++] = '1';
            }
        }
    }

    encoded_string[encoded_string_index] = '\0';

    return encoded_string;
}

char *decode_string(huffman_tree_t *tree, char *encoded_string) {
    char *decoded_string = malloc(sizeof(char) * strlen(encoded_string));
    int decoded_string_index = 0;

    node_t *current_node = tree->root;

    for (int i = 0; i < strlen(encoded_string); i++) {
        if (encoded_string[i] == '0') {
            current_node = current_node->left;
        } else if (encoded_string[i] == '1') {
            current_node = current_node->right;
        }

        if (current_node->left == NULL && current_node->right == NULL) {
            decoded_string[decoded_string_index++] = current_node->character;
            current_node = tree->root;
        }
    }

    decoded_string[decoded_string_index] = '\0';

    return decoded_string;
}

int main() {
    char *string = "Huffman coding is a data compression algorithm";

    huffman_tree_t *tree = create_huffman_tree(string);

    print_huffman_tree(tree, "");

    char *encoded_string = encode_string(tree, string);
    printf("Encoded string: %s\n", encoded_string);

    char *decoded_string = decode_string(tree, encoded_string);
    printf("Decoded string: %s\n", decoded_string);

    return 0;
}