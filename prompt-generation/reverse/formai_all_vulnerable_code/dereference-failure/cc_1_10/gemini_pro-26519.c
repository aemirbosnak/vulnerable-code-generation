//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

void buildTree(const char *text) {
    // Calculate frequencies
    int frequencies[256] = {0};
    for (size_t i = 0; i < strlen(text); i++) {
        frequencies[(unsigned char)text[i]]++;
    }

    // Build heap-based priority queue
    Node *nodes[256];
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            Node *node = (Node *)malloc(sizeof(Node));
            node->character = (char)i;
            node->frequency = frequencies[i];
            nodes[i] = node;
        }
    }

    int num_nodes = 0;
    for (int i = 0; i < 256; i++) {
        if (nodes[i] != NULL) {
            num_nodes++;
        }
    }

    while (num_nodes > 1) {
        // Find the two nodes with the lowest frequencies
        Node *node1 = NULL, *node2 = NULL;
        for (int i = 0; i < 256; i++) {
            if (nodes[i]) {
                if (!node1 || nodes[i]->frequency < node1->frequency) {
                    node1 = nodes[i];
                } else if (!node2 || nodes[i]->frequency < node2->frequency) {
                    node2 = nodes[i];
                }
            }
        }

        // Create a new node with the combined frequency
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->character = '\0';
        new_node->frequency = node1->frequency + node2->frequency;
        new_node->left = node1;
        new_node->right = node2;

        // Replace the two nodes with the new node
        nodes[(unsigned char)node1->character] = NULL;
        nodes[(unsigned char)node2->character] = NULL;
        nodes[(unsigned char)new_node->character] = new_node;

        num_nodes--;
    }
}

void generateCodebook(Node *tree, char *codebook, char *code, int length) {
    if (!tree) {
        return;
    }

    if (!tree->character) {
        generateCodebook(tree->left, codebook, code, length + 1);
        code[length] = '0';
        generateCodebook(tree->right, codebook, code, length + 1);
        code[length] = '1';
    } else {
        codebook[(unsigned char)tree->character] = strdup(code);
    }
}

char *encode(const char *text, const char *codebook) {
    size_t encoded_length = 0;
    for (size_t i = 0; i < strlen(text); i++) {
        encoded_length += strlen(codebook[(unsigned char)text[i]]);
    }

    char *encoded = (char *)malloc(sizeof(char) * encoded_length + 1);
    encoded[0] = '\0';
    for (size_t i = 0; i < strlen(text); i++) {
        strcat(encoded, codebook[(unsigned char)text[i]]);
    }

    return encoded;
}

void decode(const char *encoded, const Node *tree, char *result) {
    size_t index = 0;
    Node *current = tree;
    while (encoded[index]) {
        if (encoded[index] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (!current->character) {
            continue;
        }

        *result++ = current->character;
        current = tree;
        index++;
    }

    *result = '\0';
}

int main() {
    const char *text = "The quick brown fox jumps over the lazy dog.";
    Node *tree = NULL;
    char codebook[256] = {0};
    char code[256] = {0};
    char *encoded = NULL;
    char result[256] = {0};

    buildTree(text);
    generateCodebook(tree, codebook, code, 0);
    encoded = encode(text, codebook);
    printf("Original text: %s\n", text);
    printf("Encoded text: %s\n", encoded);
    decode(encoded, tree, result);
    printf("Decoded text: %s\n", result);

    free(encoded);
    return 0;
}