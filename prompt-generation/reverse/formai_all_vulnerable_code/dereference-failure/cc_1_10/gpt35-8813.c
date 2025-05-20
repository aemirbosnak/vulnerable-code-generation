//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the character node struct
typedef struct CharacterNode {
    struct CharacterNode* left;
    struct CharacterNode* right;
    char character;
    int frequency;
} CharacterNode;

// Function to create a new character node
CharacterNode* createNode(char character, int frequency) {
    CharacterNode* node = (CharacterNode*)malloc(sizeof(CharacterNode));
    node->left = NULL;
    node->right = NULL;
    node->character = character;
    node->frequency = frequency;

    return node;
}

// Function to determine if a node is a leaf node
bool isLeaf(CharacterNode* node) {
    return node->left == NULL && node->right == NULL;
}

// Huffman Algorithm function
CharacterNode* huffmanEncoding(char characters[], int frequencies[], int size) {
    // Create priority queue
    int queueSize = size;
    CharacterNode** queue = (CharacterNode**)malloc(queueSize*sizeof(CharacterNode*));
    int queueIndex = 0;

    // Create the initial nodes
    for (int i = 0; i < size; i++) {
        CharacterNode* node = createNode(characters[i], frequencies[i]);
        queue[queueIndex] = node;
        queueIndex++;
    }

    // Build Huffman Tree
    while (queueIndex > 1) {
        // Sort the queue in ascending order
        for (int i = 0; i < queueIndex; i++) {
            for (int j = i+1; j < queueIndex; j++) {
                if (queue[i]->frequency > queue[j]->frequency) {
                    CharacterNode* temp = queue[i];
                    queue[i] = queue[j];
                    queue[j] = temp;
                }
            }
        }

        // Create new node with lowest frequency
        CharacterNode* left = queue[0];
        CharacterNode* right = queue[1];
        CharacterNode* parent = createNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        // Remove the two lowest frequency nodes
        for (int i = 0; i < queueIndex-2; i++) {
            queue[i] = queue[i+2];
        }
        queueIndex--;

        // Add the new parent node to the queue
        queue[queueIndex-1] = parent;
    }

    // Return the top of the queue (the root of the Huffman tree)
    return queue[0];
}

// Function to write the Huffman codes to a file
void writeHuffmanCodes(FILE* file, CharacterNode* node, int code[], int codeIndex) {
    if (node == NULL) {
        return;
    }

    // Write the Huffman codes to the file recursively
    if (isLeaf(node)) {
        fprintf(file, "%c ", node->character);
        for (int i = 0; i < codeIndex; i++) {
            fprintf(file, "%d", code[i]);
        }
        fprintf(file, "\n");
    } else {
        code[codeIndex] = 0;
        writeHuffmanCodes(file, node->left, code, codeIndex+1);

        code[codeIndex] = 1;
        writeHuffmanCodes(file, node->right, code, codeIndex+1);
    }
}

// Main function
int main() {
    // Input data
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {20, 10, 15, 8, 45, 2};
    int size = sizeof(characters) / sizeof(characters[0]);

    // Generate Huffman tree and codes
    CharacterNode* root = huffmanEncoding(characters, frequencies, size);

    // Write the Huffman codes to a file
    FILE* file = fopen("huffman_codes.txt", "w");
    int code[100];
    int codeIndex = 0;
    writeHuffmanCodes(file, root, code, codeIndex);
    fclose(file);

    // Print confirmation message
    printf("Huffman Codes written to file successfully.\n");

    return 0;
}