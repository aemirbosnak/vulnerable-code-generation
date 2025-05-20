//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR_COUNT 256

typedef struct Node {
    int frequency;
    unsigned char character;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct HuffmanTree {
    Node *root;
} HuffmanTree;

Node *create_node(unsigned char character, int frequency) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

HuffmanTree *create_huffman_tree(unsigned char *input, int input_length) {
    int character_count[MAX_CHAR_COUNT] = { 0 };
    for (int i = 0; i < input_length; i++) {
        character_count[input[i]]++;
    }

    Node *nodes[MAX_CHAR_COUNT];
    int num_nodes = 0;
    for (int i = 0; i < MAX_CHAR_COUNT; i++) {
        if (character_count[i] > 0) {
            nodes[num_nodes++] = create_node(i, character_count[i]);
        }
    }

    while (num_nodes > 1) {
        int min1 = 0, min2 = 1;
        for (int i = 2; i < num_nodes; i++) {
            if (nodes[i]->frequency < nodes[min1]->frequency) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->frequency < nodes[min2]->frequency) {
                min2 = i;
            }
        }

        Node *new_node = create_node('\0', nodes[min1]->frequency + nodes[min2]->frequency);
        new_node->left = nodes[min1];
        new_node->right = nodes[min2];

        nodes[min1] = new_node;
        for (int i = min2; i < num_nodes - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        num_nodes--;
    }

    HuffmanTree *huffman_tree = (HuffmanTree *) malloc(sizeof(HuffmanTree));
    huffman_tree->root = nodes[0];
    return huffman_tree;
}

void encode_character(HuffmanTree *tree, unsigned char character, unsigned char *output, int *output_length) {
    Node *current = tree->root;
    unsigned char bits[8];
    int num_bits = 0;
    while (current) {
        if (current->character == character) {
            break;
        } else if (character < current->character) {
            bits[num_bits++] = 0;
            current = current->left;
        } else {
            bits[num_bits++] = 1;
            current = current->right;
        }
    }

    for (int i = num_bits - 1; i >= 0; i--) {
        if (bits[i]) {
            output[*output_length / 8] |= 1 << (*output_length % 8);
        }
        (*output_length)++;
    }
}

void encode_input(HuffmanTree *tree, unsigned char *input, int input_length, unsigned char *output, int *output_length) {
    for (int i = 0; i < input_length; i++) {
        encode_character(tree, input[i], output, output_length);
    }
}

void decode_character(HuffmanTree *tree, unsigned char *input, int *input_length, unsigned char *output) {
    Node *current = tree->root;
    while (current) {
        if (!(*input_length)) {
            break;
        }
        if (*input & 1) {
            current = current->right;
        } else {
            current = current->left;
        }
        (*input_length)--;
        *input >>= 1;

        if (!current->left && !current->right) {
            *output = current->character;
            current = tree->root;
        }
    }
}

void decode_input(HuffmanTree *tree, unsigned char *input, int input_length, unsigned char *output, int *output_length) {
    int input_index = 0;
    int output_index = 0;
    while (input_index < input_length) {
        decode_character(tree, &input[input_index], &input_length, &output[output_index]);
        output_index++;
    }
}

void free_huffman_tree(HuffmanTree *tree) {
    if (tree->root) {
        free_huffman_tree(tree->root);
    }
    free(tree);
}

int main() {
    unsigned char input[] = "Hello World!";
    int input_length = strlen(input);

    HuffmanTree *tree = create_huffman_tree(input, input_length);

    int output_length = 0;
    unsigned char output[INT_MAX];

    encode_input(tree, input, input_length, output, &output_length);

    printf("Encoded input: ");
    for (int i = 0; i < output_length; i++) {
        printf("%02X", output[i]);
    }
    printf("\n");

    int decoded_output_length = 0;
    unsigned char decoded_output[INT_MAX];

    decode_input(tree, output, output_length, decoded_output, &decoded_output_length);

    printf("Decoded input: %s\n", decoded_output);

    free_huffman_tree(tree);

    return 0;
}