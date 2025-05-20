//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store frequency of characters and their code in Huffman tree
struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* newNode(char character, int frequency) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to traverse the Huffman tree and generate codes for each character
void generateCodes(struct Node* root, int prefix[], int prefix_size) {
    if (root->left != NULL) {
        prefix[prefix_size] = 0;
        generateCodes(root->left, prefix, prefix_size + 1);
    }
    if (root->right != NULL) {
        prefix[prefix_size] = 1;
        generateCodes(root->right, prefix, prefix_size + 1);
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->character);
        for (int i = 0; i < prefix_size; i++) {
            printf("%d", prefix[i]);
        }
        printf("\n");
    }
}

// Function to build Huffman tree
void buildHuffmanTree(char characters[], int frequencies[], int num_chars) {
    // Create a priority queue for storing nodes
    struct Node* pq[num_chars];
    int pq_size = 0;
    for (int i = 0; i < num_chars; i++) {
        pq[i] = newNode(characters[i], frequencies[i]);
        pq_size++;
    }
    // Build Huffman tree
    while (pq_size > 1) {
        // Remove two nodes with smallest frequency
        struct Node* left = pq[0];
        pq_size--;
        for (int i = 0; i < pq_size; i++) {
            pq[i] = pq[i+1];
        }
        struct Node* right = pq[0];
        pq_size--;
        for (int i = 0; i < pq_size; i++) {
            pq[i] = pq[i+1];
        }
        // Create a new node with merged frequency and add to priority queue
        int frequency = left->frequency + right->frequency;
        struct Node* merged = newNode('*', frequency);
        merged->left = left;
        merged->right = right;
        pq[pq_size] = merged;
        pq_size++;
        // Resort priority queue
        for (int i = pq_size-1; i > 0 && pq[i]->frequency < pq[i-1]->frequency; i--) {
            struct Node* temp = pq[i];
            pq[i] = pq[i-1];
            pq[i-1] = temp;
        }
    }
    // Generate codes for characters
    int prefix[num_chars];
    generateCodes(pq[0], prefix, 0);
}

int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int num_chars = sizeof(characters) / sizeof(characters[0]);
    buildHuffmanTree(characters, frequencies, num_chars);
    return 0;
}