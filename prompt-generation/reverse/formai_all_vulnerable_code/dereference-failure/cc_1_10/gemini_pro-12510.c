//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Node of the Huffman tree
typedef struct Node {
    int data;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

// Create a new node
Node *createNode(int data, int frequency) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Compare two nodes based on their frequency
int compareNodes(const void *a, const void *b) {
    Node *node1 = (Node *)a;
    Node *node2 = (Node *)b;
    return node1->frequency - node2->frequency;
}

// Build the Huffman tree
Node *buildHuffmanTree(int data[], int frequency[], int size) {
    // Create a priority queue of nodes
    Node **priorityQueue = (Node **)malloc(sizeof(Node *) * size);
    for (int i = 0; i < size; i++) {
        priorityQueue[i] = createNode(data[i], frequency[i]);
    }

    qsort(priorityQueue, size, sizeof(Node *), compareNodes);

    // Build the Huffman tree
    while (size > 1) {
        // Remove the two nodes with the smallest frequencies
        Node *node1 = priorityQueue[0];
        Node *node2 = priorityQueue[1];
        priorityQueue[0] = NULL;
        priorityQueue[1] = NULL;

        // Create a new node with the sum of the frequencies of the two nodes
        Node *newNode = createNode(0, node1->frequency + node2->frequency);

        // Set the left and right children of the new node
        newNode->left = node1;
        newNode->right = node2;

        // Insert the new node into the priority queue
        priorityQueue[size - 2] = newNode;

        // Sort the priority queue
        qsort(priorityQueue, size - 1, sizeof(Node *), compareNodes);

        size--;
    }

    return priorityQueue[0];
}

// Generate the Huffman code for a given character
char *generateHuffmanCode(Node *root, int data, char *code) {
    if (root->data == 0) {
        return NULL;
    }

    if (root->data == data) {
        return code;
    }

    char *leftCode = generateHuffmanCode(root->left, data, code);
    char *rightCode = generateHuffmanCode(root->right, data, code);

    return leftCode ? leftCode : rightCode;
}

// Print the Huffman code for all characters
void printHuffmanCode(Node *root) {
    if (root->data != 0) {
        printf("%c: %s\n", root->data, generateHuffmanCode(root, root->data, ""));
    } else {
        printHuffmanCode(root->left);
        printHuffmanCode(root->right);
    }
}

// Encode a string using the Huffman code
char *encodeString(char *string, Node *root) {
    char *encodedString = "";
    for (int i = 0; string[i] != '\0'; i++) {
        char *code = generateHuffmanCode(root, string[i], "");
        encodedString = strcat(encodedString, code);
    }
    return encodedString;
}

// Decode a string using the Huffman code
char *decodeString(char *encodedString, Node *root) {
    char *decodedString = "";
    Node *current = root;
    for (int i = 0; i < strlen(encodedString); i++) {
        if (encodedString[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->data != 0) {
            decodedString = strcat(decodedString, current->data);
            current = root;
        }
    }
    return decodedString;
}

int main() {
    // Input data and frequency
    int data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    // Build the Huffman tree
    Node *root = buildHuffmanTree(data, frequency, size);

    // Print the Huffman code for each character
    printHuffmanCode(root);

    // Encode and decode a string
    char *string = "abcdef";
    char *encodedString = encodeString(string, root);
    char *decodedString = decodeString(encodedString, root);

    printf("Original string: %s\n", string);
    printf("Encoded string: %s\n", encodedString);
    printf("Decoded string: %s\n", decodedString);

    return 0;
}