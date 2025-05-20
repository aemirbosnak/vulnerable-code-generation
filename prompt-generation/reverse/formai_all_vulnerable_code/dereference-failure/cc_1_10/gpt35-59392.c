//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters
#define MAX_CHARS 256

// Define the Huffman tree node
typedef struct HuffmanNode {
    int frequency;
    char character;
    struct HuffmanNode* left_child;
    struct HuffmanNode* right_child;
} HuffmanNode;

// Define the Huffman code node
typedef struct HuffmanCode {
    char* code;
    char character;
} HuffmanCode;

// Define a compare function for Huffman nodes
int compare_huffman_nodes(const void* node1, const void* node2) {
    HuffmanNode* h1 = *(HuffmanNode**)node1;
    HuffmanNode* h2 = *(HuffmanNode**)node2;
    return h1->frequency - h2->frequency;
}

// Recursively free all nodes of the Huffman tree
void free_huffman_tree(HuffmanNode* node) {
    if (node == NULL) {
        return;
    }
    free_huffman_tree(node->left_child);
    free_huffman_tree(node->right_child);
    free(node);
}

// Recursively traverse the Huffman tree and generate codes
void generate_huffman_codes(HuffmanNode* node, char* code, int index, HuffmanCode* codes) {
    if (node == NULL) {
        return;
    }
    // If node is a leaf, store the code for the character in the codes array
    if (node->left_child == NULL && node->right_child == NULL) {
        code[index] = '\0';
        for (int i = 0; i < MAX_CHARS; i++) {
            if (codes[i].character == node->character) {
                codes[i].code = (char*)realloc(codes[i].code, (strlen(code) + 1) * sizeof(char));
                strcpy(codes[i].code, code);
                break;
            }
        }
    } else {
        // Generate codes for left and right children recursively
        code[index] = '0';
        generate_huffman_codes(node->left_child, code, index + 1, codes);
        code[index] = '1';
        generate_huffman_codes(node->right_child, code, index + 1, codes);
    }
}

// Implement the Huffman coding algorithm
void huffman_coding(char* input_string) {
    // Initialize the frequency array with zeros
    int frequency[MAX_CHARS] = {0};
    // Traverse the input string and count the frequency of each character
    for (int i = 0; i < strlen(input_string); i++) {
        frequency[(int) input_string[i]]++;
    }
    // Initialize an array of Huffman nodes with the characters and their frequencies
    HuffmanNode* nodes[MAX_CHARS];
    int num_nodes = 0;
    for (int i = 0; i < MAX_CHARS; i++) {
        if (frequency[i] > 0) {
            HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
            node->frequency = frequency[i];
            node->character = i;
            node->left_child = NULL;
            node->right_child = NULL;
            nodes[num_nodes++] = node;
        }
    }
    // Build the Huffman tree
    while (num_nodes > 1) {
        // Sort the nodes array in ascending order of frequency
        qsort(nodes, num_nodes, sizeof(HuffmanNode*), compare_huffman_nodes);
        // Create a new node with the combined frequency and the two lowest frequency nodes as children
        HuffmanNode* new_node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        new_node->frequency = nodes[0]->frequency + nodes[1]->frequency;
        new_node->left_child = nodes[0];
        new_node->right_child = nodes[1];
        nodes[0] = new_node;
        // Remove the second lowest frequency node from the array by shifting the other nodes left
        for (int i = 1; i < num_nodes - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        num_nodes--;
    }
    // Generate codes for each character using the Huffman tree
    char code[MAX_CHARS];
    HuffmanCode codes[MAX_CHARS];
    for (int i = 0; i < MAX_CHARS; i++) {
        codes[i].code = NULL;
    }
    generate_huffman_codes(nodes[0], code, 0, codes);
    // Print the codes for each character
    printf("Huffman codes for each character:\n");
    for (int i = 0; i < MAX_CHARS; i++) {
        if (codes[i].code != NULL) {
            printf("%c: %s\n", codes[i].character, codes[i].code);
            free(codes[i].code);
        }
    }
    // Free the memory used by the Huffman tree
    free_huffman_tree(nodes[0]);
}

int main() {
    char input_string[MAX_CHARS];
    printf("Enter an input string to encode with Huffman coding:\n");
    fgets(input_string, MAX_CHARS, stdin);
    input_string[strcspn(input_string, "\n")] = '\0';
    huffman_coding(input_string);
    return 0;
}