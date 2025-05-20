//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
} node;

typedef struct huffman_tree {
    node *root;
} huffman_tree;

huffman_tree *create_huffman_tree(char *string) {
    // Create a frequency table
    int frequency_table[256] = {0};
    for (int i = 0; i < strlen(string); i++) {
        frequency_table[string[i]]++;
    }

    // Create a priority queue of nodes
    node *nodes[256];
    int num_nodes = 0;
    for (int i = 0; i < 256; i++) {
        if (frequency_table[i] > 0) {
            nodes[num_nodes++] = malloc(sizeof(node));
            nodes[num_nodes - 1]->character = i;
            nodes[num_nodes - 1]->frequency = frequency_table[i];
            nodes[num_nodes - 1]->left = NULL;
            nodes[num_nodes - 1]->right = NULL;
        }
    }

    // Build the Huffman tree
    while (num_nodes > 1) {
        // Find the two nodes with the lowest frequencies
        int lowest_frequency_1 = -1;
        int lowest_frequency_2 = -1;
        for (int i = 0; i < num_nodes; i++) {
            if (nodes[i]->frequency < lowest_frequency_1 || lowest_frequency_1 == -1) {
                lowest_frequency_1 = nodes[i]->frequency;
            }
        }
        for (int i = 0; i < num_nodes; i++) {
            if (nodes[i]->frequency < lowest_frequency_2 && nodes[i]->frequency != lowest_frequency_1) {
                lowest_frequency_2 = nodes[i]->frequency;
            }
        }

        // Create a new node with the combined frequency of the two nodes
        node *new_node = malloc(sizeof(node));
        new_node->character = '\0';
        new_node->frequency = lowest_frequency_1 + lowest_frequency_2;
        new_node->left = nodes[lowest_frequency_1];
        new_node->right = nodes[lowest_frequency_2];

        // Remove the two nodes from the priority queue
        for (int i = 0; i < num_nodes; i++) {
            if (nodes[i]->frequency == lowest_frequency_1) {
                nodes[i] = nodes[num_nodes - 1];
                num_nodes--;
            }
            if (nodes[i]->frequency == lowest_frequency_2) {
                nodes[i] = nodes[num_nodes - 1];
                num_nodes--;
            }
        }

        // Add the new node to the priority queue
        nodes[num_nodes++] = new_node;
    }

    // Create a Huffman tree with the root node
    huffman_tree *tree = malloc(sizeof(huffman_tree));
    tree->root = nodes[0];

    return tree;
}

void print_huffman_tree(huffman_tree *tree, char *code) {
    if (tree->root->left == NULL && tree->root->right == NULL) {
        printf("%c: %s\n", tree->root->character, code);
    } else {
        print_huffman_tree(tree->root->left, strcat(code, "0"));
        print_huffman_tree(tree->root->right, strcat(code, "1"));
    }
}

char *encode_string(huffman_tree *tree, char *string) {
    char *encoded_string = malloc(strlen(string) * 8 + 1);
    int encoded_string_index = 0;
    for (int i = 0; i < strlen(string); i++) {
        node *current_node = tree->root;
        while (current_node->left != NULL && current_node->right != NULL) {
            if (string[i] == current_node->left->character) {
                encoded_string[encoded_string_index++] = '0';
                current_node = current_node->left;
            } else {
                encoded_string[encoded_string_index++] = '1';
                current_node = current_node->right;
            }
        }
        encoded_string[encoded_string_index++] = current_node->frequency;
    }
    encoded_string[encoded_string_index] = '\0';
    return encoded_string;
}

char *decode_string(huffman_tree *tree, char *encoded_string) {
    char *decoded_string = malloc(strlen(encoded_string));
    int decoded_string_index = 0;
    node *current_node = tree->root;
    for (int i = 0; i < strlen(encoded_string); i++) {
        if (encoded_string[i] == '0') {
            current_node = current_node->left;
        } else {
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
    char *string = "Hello World!";
    huffman_tree *tree = create_huffman_tree(string);
    print_huffman_tree(tree, "");
    char *encoded_string = encode_string(tree, string);
    printf("Encoded string: %s\n", encoded_string);
    char *decoded_string = decode_string(tree, encoded_string);
    printf("Decoded string: %s\n", decoded_string);
    return 0;
}