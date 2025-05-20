//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the Huffman tree
struct HuffmanNode {
    char data;
    int freq;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
};

// Utility function to create a new node
struct HuffmanNode *createNode(char data, int freq) {
    struct HuffmanNode *node = (struct HuffmanNode *) malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Comparator function for sorting the array of nodes based on frequency
int compare(struct HuffmanNode *a, struct HuffmanNode *b) {
    return a->freq - b->freq;
}

// Function to build the Huffman tree
struct HuffmanNode *buildHuffmanTree(char data[], int freq[], int n) {
    struct HuffmanNode *root = NULL;

    // Create a min-heap of nodes
    struct HuffmanNode **minHeap = (struct HuffmanNode **) malloc(n * sizeof(struct HuffmanNode *));
    int i;
    for (i = 0; i < n; i++) {
        minHeap[i] = createNode(data[i], freq[i]);
    }
    int heapSize = n;

    // Build the Huffman tree by repeatedly extracting the two minimum nodes
    while (heapSize > 1) {
        // Extract the minimum two nodes
        struct HuffmanNode *min1 = minHeap[0];
        struct HuffmanNode *min2 = minHeap[1];
        int index = 2;
        if (compare(minHeap[2], min2) < 0) {
            min2 = minHeap[2];
            index = 3;
        }

        // Create a new node and assign it the sum of the frequencies of the two minimum nodes as its frequency
        struct HuffmanNode *node = createNode('\0', min1->freq + min2->freq);
        node->left = min1;
        node->right = min2;

        // Remove the minimum nodes from the heap and add the new node
        minHeap[0] = node;
        minHeap[1] = minHeap[heapSize - 1];
        minHeap[2] = NULL;
        heapSize--;
        int j = 0;
        int k = 1;
        while (k < heapSize) {
            if (k + 1 < heapSize && compare(minHeap[k + 1], minHeap[k]) < 0) {
                k++;
            }
            if (compare(minHeap[k], minHeap[j]) < 0) {
                struct HuffmanNode *temp = minHeap[j];
                minHeap[j] = minHeap[k];
                minHeap[k] = temp;
            }
            j = k;
            k = 2 * j + 1;
        }

        // Save the root node
        root = node;
    }

    free(minHeap);
    return root;
}

// Function to decode the encoded string using the Huffman tree
void decode(struct HuffmanNode *root, char *encodedString, char *decodedString, int *index) {
    if (root == NULL) {
        return;
    }
    if (root->data != '\0') {
        decodedString[*index] = root->data;
        (*index)++;
        return;
    }
    if (*encodedString == '0') {
        decode(root->left, encodedString + 1, decodedString, index);
    } else {
        decode(root->right, encodedString + 1, decodedString, index);
    }
}

// Main function to test the Huffman coding implementation
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(data) / sizeof(data[0]);
    struct HuffmanNode *root = buildHuffmanTree(data, freq, n);

    char encodedString[] = "00110111000";
    int encodedStringLength = strlen(encodedString);
    char decodedString[encodedStringLength];
    int index = 0;
    decode(root, encodedString, decodedString, &index);
    decodedString[encodedStringLength] = '\0';

    printf("Encoded String: %s\n", encodedString);
    printf("Decoded String: %s\n", decodedString);

    return 0;
}