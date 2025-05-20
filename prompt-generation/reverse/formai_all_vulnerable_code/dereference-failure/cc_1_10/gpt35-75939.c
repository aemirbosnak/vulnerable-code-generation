//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

// A Huffman tree node
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// A min heap array of Huffman nodes
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

// A Huffman tree
struct HuffmanTree {
    char* codes[MAX_TREE_HT];
    struct MinHeapNode* root;
};

// Create a new Huffman node
struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Swap two nodes in min heap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify a sub-tree for a given index
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if a node is a leaf node
bool isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// Create a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Insert a new node to the min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Build a min heap from given min heap nodes
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Extract the minimum value node from min heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Build Huffman Tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        insertMinHeap(minHeap, newNode(data[i], freq[i]));
    buildMinHeap(minHeap);
    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Assign codes to the Huffman tree
void assignCodesUtil(struct MinHeapNode* root, char code[], int top, struct HuffmanTree* tree) {
    if (root->left) {
        code[top] = '0';
        assignCodesUtil(root->left, code, top + 1, tree);
    }
    if (root->right) {
        code[top] = '1';
        assignCodesUtil(root->right, code, top + 1, tree);
    }
    if (isLeaf(root)) {
        code[top] = '\0';
        tree->codes[root->data] = code;
    }
}

// Create a Huffman tree and assign codes to the nodes
struct HuffmanTree* buildHuffmanCode(char data[], int freq[], int size) {
    struct HuffmanTree* tree = (struct HuffmanTree*)malloc(sizeof(struct HuffmanTree));
    tree->root = buildHuffmanTree(data, freq, size);
    for (int i = 0; i < size; ++i)
        tree->codes[i] = (char*)calloc(MAX_TREE_HT, sizeof(char));
    char code[MAX_TREE_HT];
    assignCodesUtil(tree->root, code, 0, tree);
    return tree;
}

// Encode input string using Huffman tree
char* encode(struct HuffmanTree* tree, char* input) {
    int n = strlen(input);
    char* encoded = (char*)calloc(2 * n, sizeof(char));
    for (int i = 0; i < n; ++i) {
        strcat(encoded, tree->codes[input[i]]);
    }
    return encoded;
}

// Decode Huffman codes and print the result
void decode(struct HuffmanTree* tree, char* encoded) {
    int index = 0;
    int n = strlen(encoded);
    struct MinHeapNode* root = tree->root;
    while (index < n) {
        if (encoded[index] == '0')
            root = root->left;
        else
            root = root->right;
        if (isLeaf(root)) {
            printf("%c", root->data);
            root = tree->root;
        }
        ++index;
    }
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    struct HuffmanTree* tree = buildHuffmanCode(data, freq, size);
    printf("Original String: %s\n", "abcdef");
    char* encoded = encode(tree, "abcdef");
    printf("Encoded String: %s\n", encoded);
    printf("Decoded String: ");
    decode(tree, encoded);
    printf("\n");
    return 0;
}