//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 16

typedef struct {
    char *symbol;
    int frequency;
    char *code;
} HuffmanNode;

typedef struct {
    HuffmanNode *nodes;
    int size;
} HuffmanTree;

HuffmanTree *createHuffmanTree(char *input) {
    // Count the frequency of each symbol in the input string.
    int frequencies[256] = {0};
    for (int i = 0; i < strlen(input); i++) {
        frequencies[input[i]]++;
    }

    // Create a Huffman node for each symbol.
    HuffmanNode *nodes = malloc(sizeof(HuffmanNode) * 256);
    for (int i = 0; i < 256; i++) {
        nodes[i].symbol = malloc(sizeof(char) * 2);
        nodes[i].symbol[0] = i;
        nodes[i].symbol[1] = '\0';
        nodes[i].frequency = frequencies[i];
        nodes[i].code = NULL;
    }

    // Create a Huffman tree from the nodes.
    HuffmanTree *tree = malloc(sizeof(HuffmanTree));
    tree->nodes = nodes;
    tree->size = 256;

    while (tree->size > 1) {
        // Find the two nodes with the lowest frequencies.
        HuffmanNode *node1 = NULL;
        HuffmanNode *node2 = NULL;
        for (int i = 0; i < tree->size; i++) {
            if (node1 == NULL || tree->nodes[i].frequency < node1->frequency) {
                node1 = &tree->nodes[i];
            }
            if (node2 == NULL || tree->nodes[i].frequency < node2->frequency && tree->nodes[i].frequency != node1->frequency) {
                node2 = &tree->nodes[i];
            }
        }

        // Create a new node that is the parent of the two nodes with the lowest frequencies.
        HuffmanNode *parent = malloc(sizeof(HuffmanNode));
        parent->symbol = malloc(sizeof(char) * 3);
        parent->symbol[0] = '*';
        parent->symbol[1] = node1->symbol[0];
        parent->symbol[2] = node2->symbol[0];
        parent->frequency = node1->frequency + node2->frequency;
        parent->code = NULL;

        // Assign the codes to the parent node and its children.
        node1->code = malloc(sizeof(char) * (strlen(parent->code) + 1));
        strcpy(node1->code, parent->code);
        strcat(node1->code, "0");

        node2->code = malloc(sizeof(char) * (strlen(parent->code) + 1));
        strcpy(node2->code, parent->code);
        strcat(node2->code, "1");

        // Remove the two nodes with the lowest frequencies from the tree.
        for (int i = 0; i < tree->size; i++) {
            if (tree->nodes[i].symbol == node1->symbol) {
                tree->nodes[i] = *parent;
            } else if (tree->nodes[i].symbol == node2->symbol) {
                for (int j = i; j < tree->size - 1; j++) {
                    tree->nodes[j] = tree->nodes[j + 1];
                }
                tree->size--;
                break;
            }
        }
    }

    return tree;
}

char *compress(HuffmanTree *tree, char *input) {
    char *output = malloc(sizeof(char) * strlen(input) * MAX_CODE_LENGTH);
    int output_length = 0;

    for (int i = 0; i < strlen(input); i++) {
        for (int j = 0; j < tree->size; j++) {
            if (tree->nodes[j].symbol[0] == input[i]) {
                strcat(output, tree->nodes[j].code);
                output_length += strlen(tree->nodes[j].code);
                break;
            }
        }
    }

    return output;
}

char *decompress(HuffmanTree *tree, char *input) {
    char *output = malloc(sizeof(char) * strlen(input));
    int output_length = 0;

    HuffmanNode *current_node = &tree->nodes[tree->size - 1];

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '0') {
            current_node = &tree->nodes[current_node - tree->nodes];
        } else if (input[i] == '1') {
            current_node = &tree->nodes[current_node + 1 - tree->nodes];
        }

        if (current_node->symbol[0] != '*') {
            output[output_length++] = current_node->symbol[0];
            current_node = &tree->nodes[tree->size - 1];
        }
    }

    return output;
}

int main() {
    char *input = "abracadabra";
    HuffmanTree *tree = createHuffmanTree(input);
    char *compressed = compress(tree, input);
    char *decompressed = decompress(tree, compressed);

    printf("Input: %s\n", input);
    printf("Compressed: %s\n", compressed);
    printf("Decompressed: %s\n", decompressed);

    return 0;
}