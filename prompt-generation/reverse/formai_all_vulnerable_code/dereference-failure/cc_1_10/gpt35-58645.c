//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Huffman tree node
struct hNode {
    char data;
    unsigned freq;
    struct hNode *left, *right;
};

// Priority queue node
struct pqNode {
    struct hNode *huffmanNode;
    struct pqNode *next;
};

// Create a new Priority Queue Node
struct pqNode *newPQNode(struct hNode *huffmanNode) {
    struct pqNode *pqnode = (struct pqNode *)malloc(sizeof(struct pqNode));
    pqnode->huffmanNode = huffmanNode;
    pqnode->next = NULL;
    return pqnode;
}

// Create a new Huffman Tree Node
struct hNode *newHNode(char data, unsigned freq) {
    struct hNode *huffNode = (struct hNode *)malloc(sizeof(struct hNode));
    huffNode->left = huffNode->right = NULL;
    huffNode->data = data;
    huffNode->freq = freq;

    return huffNode;
}

// Compare two PQ nodes and return true if the first node has lower frequency than the second node
bool compareNodes(struct pqNode *firstNode, struct pqNode *secondNode) {
    return firstNode->huffmanNode->freq < secondNode->huffmanNode->freq;
}

// Insert new node into priority queue
void pqInsert(struct pqNode **pqHead, struct hNode *huffNode) {
    struct pqNode *pqnode = newPQNode(huffNode);
    if ((*pqHead) == NULL || compareNodes(pqnode, (*pqHead))) {
        pqnode->next = (*pqHead);
        (*pqHead) = pqnode;
    } else {
        struct pqNode *current = (*pqHead);
        while (current->next != NULL && !compareNodes(pqnode, current->next)) {
            current = current->next;
        }
        pqnode->next = current->next;
        current->next = pqnode;
    }
}

// Remove and return the node with lowest frequency from priority queue
struct pqNode *pqExtractMin(struct pqNode **pqHead) {
    struct pqNode *temp = (*pqHead);
    (*pqHead) = (*pqHead)->next;
    return temp;
}

// Check if the node is a leaf node
bool isLeafNode(struct hNode *node) {
    return !(node->left) && !(node->right);
}

// Implement Huffman coding algorithm
struct hNode *buildHuffmanTree(char chars[], int freq[], int n) {
    struct pqNode *pqHead = NULL;
    struct hNode *leftNode, *rightNode, *parentNode;

    // Insert all characters and their frequencies in priority queue
    for (int i = 0; i < n; i++) {
        pqInsert(&pqHead, newHNode(chars[i], freq[i]));
    }

    // Construct Huffman Tree
    while (pqHead->next != NULL) {
        leftNode = pqExtractMin(&pqHead)->huffmanNode;
        rightNode = pqExtractMin(&pqHead)->huffmanNode;
        parentNode = newHNode('$', leftNode->freq + rightNode->freq);
        parentNode->left = leftNode;
        parentNode->right = rightNode;
        pqInsert(&pqHead, parentNode);
    }

    return pqExtractMin(&pqHead)->huffmanNode; // Final tree
}

// Print Huffman codes for all characters in Huffman Tree
void printCodes(struct hNode *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeafNode(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Driver Function
void huffmanCode(char chars[], int freq[], int n) {
    struct hNode *huffTree = buildHuffmanTree(chars, freq, n);
    int arr[100], top = 0;
    printCodes(huffTree, arr, top);
}

int main() {
    char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(chars) / sizeof(chars[0]);

    huffmanCode(chars, freq, n);

    return 0;
}