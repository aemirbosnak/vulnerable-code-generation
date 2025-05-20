//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Node of the Huffman tree
struct Node {
    int data;
    int freq;
    struct Node *left;
    struct Node *right;
};

// Comparator function for the priority queue
int compare(const void *a, const void *b) {
    struct Node *n1 = *(struct Node **)a;
    struct Node *n2 = *(struct Node **)b;
    return n1->freq - n2->freq;
}

// Create a new node
struct Node *createNode(int data, int freq) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Build the Huffman tree
struct Node *buildTree(int *data, int *freq, int size) {
    // Create a priority queue of nodes
    struct Node **pq = malloc(sizeof(struct Node *) * size);
    for (int i = 0; i < size; i++) {
        pq[i] = createNode(data[i], freq[i]);
    }

    // Sort the priority queue
    qsort(pq, size, sizeof(struct Node *), compare);

    // Combine the two smallest nodes until there is only one node left
    while (size > 1) {
        struct Node *n1 = pq[0];
        struct Node *n2 = pq[1];
        pq[0] = pq[size - 1];
        size--;

        struct Node *parent = createNode(-1, n1->freq + n2->freq);
        parent->left = n1;
        parent->right = n2;

        qsort(pq, size, sizeof(struct Node *), compare);
    }

    return pq[0];
}

// Generate the Huffman code for a given character
void generateCode(struct Node *root, char *code, char *result, int size) {
    if (root == NULL) {
        return;
    }
    if (root->data != -1) {
        result[size] = '\0';
        printf("%d: %s\n", root->data, result);
        return;
    }

    code[size] = '0';
    generateCode(root->left, code, result, size + 1);

    code[size] = '1';
    generateCode(root->right, code, result, size + 1);
}

// Encode a string using the Huffman code
char *encode(struct Node *root, char *str) {
    char *result = malloc(strlen(str) * 8);
    int size = 0;
    char code[strlen(str)];

    for (int i = 0; i < strlen(str); i++) {
        generateCode(root, code, result + size * 8, 0);
        size++;
    }

    return result;
}

// Decode a string using the Huffman code
char *decode(struct Node *root, char *str) {
    char *result = malloc(strlen(str));
    int size = 0;

    struct Node *current = root;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '0') {
            current = current->left;
        } else if (str[i] == '1') {
            current = current->right;
        }

        if (current->data != -1) {
            result[size] = current->data;
            size++;
            current = root;
        }
    }

    return result;
}

// Main function
int main() {
    // Define the data and frequency arrays
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int freq[] = {5, 9, 12, 13, 16, 45, 67, 89, 100};
    int size = sizeof(data) / sizeof(data[0]);

    // Build the Huffman tree
    struct Node *root = buildTree(data, freq, size);

    // Generate the Huffman code for each character
    char code[size][8];
    char result[size][8];
    for (int i = 0; i < size; i++) {
        generateCode(root, code[i], result[i], 0);
    }

    // Encode a string using the Huffman code
    char *encodedString = encode(root, "ABCDEFGHIJ");

    // Decode the encoded string using the Huffman code
    char *decodedString = decode(root, encodedString);

    // Print the encoded and decoded strings
    printf("Encoded string: %s\n", encodedString);
    printf("Decoded string: %s\n", decodedString);

    return 0;
}