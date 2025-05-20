//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Structure to store a Huffman tree node
struct node {
    char data;
    unsigned freq;
    struct node *left, *right;
};

// Structure to store a priority queue
struct pqnode {
    struct node *treeNode;
    struct pqnode *nextNode;
};

// Function to create a new Huffman tree node
struct node *newNode(char data, unsigned freq) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Function to create a new priority queue node
struct pqnode *newPQNode(struct node *node) {
    struct pqnode *temp = (struct pqnode*)malloc(sizeof(struct pqnode));
    temp->treeNode = node;
    temp->nextNode = NULL;
    return temp;
}

// Compare the frequencies of two priority queue nodes
int compareNodes(struct pqnode *firstNode, struct pqnode *secondNode) {
    return (firstNode->treeNode->freq) > (secondNode->treeNode->freq);
}

// Insert a new priority queue node into the priority queue
void insertPQNode(struct pqnode **queue, struct pqnode *node) {
    struct pqnode *temp = (*queue), *prev;
    if (!temp || compareNodes(node, temp)) {
        node->nextNode = (*queue);
        (*queue) = node;
    }
    else {
        while (temp && !compareNodes(node, temp)) {
            prev = temp;
            temp = temp->nextNode;
        }
        node->nextNode = temp;
        prev->nextNode = node;
    }
}

// Remove the minimum frequency node from the priority queue
struct pqnode *getMinimumFreqNode(struct pqnode **queue) {
    struct pqnode *temp = (*queue);
    (*queue) = (*queue)->nextNode;
    return temp;
}

// Build a Huffman tree and return its root node
struct node *buildHuffmanTree(char data[], int freq[], int size) {
    struct node *left, *right, *top;
    struct pqnode *queue = NULL;
    for (int i = 0; i < size; ++i) {
        insertPQNode(&queue, newPQNode(newNode(data[i], freq[i])));
    }
    while (queue && queue->nextNode) {
        left = getMinimumFreqNode(&queue)->treeNode;
        right = getMinimumFreqNode(&queue)->treeNode;
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertPQNode(&queue, newPQNode(top));
    }
    return getMinimumFreqNode(&queue)->treeNode;
}

// Print Huffman codes from the root node
void printHuffmanCodes(struct node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Huffman coding function
void HuffmanCoding(char data[], int freq[], int size) {
    struct node *root = buildHuffmanTree(data, freq, size);
    int codes[MAX_TREE_HT], top = 0;
    printHuffmanCodes(root, codes, top);
}

// Main function
int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    printf("Huffman codes:\n");
    HuffmanCoding(data, freq, size);
    return 0;
}