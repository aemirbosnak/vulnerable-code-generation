//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: systematic
// Huffman Encoding in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman tree node structure
struct HuffmanNode {
    char data;
    unsigned freq;
    struct HuffmanNode *left, *right;
};

// Min Heap node structure
struct MinHeapNode {
    struct HuffmanNode *node;
    struct MinHeapNode *next;
};

// Min Heap structure
struct MinHeap {
    int size;
    struct MinHeapNode *head, *tail;
};

// Huffman tree traversal and encoding structure
struct HuffmanCode {
    char data;
    char *code;
};

// Min Heap node creation function
struct MinHeapNode* createMinHeapNode(struct HuffmanNode *node) {
    struct MinHeapNode *new_node = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    new_node->node = node;
    new_node->next = NULL;
    return new_node;
}

// Min Heap creation function
struct MinHeap* createMinHeap() {
    struct MinHeap *heap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    heap->size = 0;
    heap->head = heap->tail = NULL;
    return heap;
}

// Huffman tree node creation function
struct HuffmanNode* createHuffmanNode(char data, unsigned freq) {
    struct HuffmanNode *new_node = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    new_node->data = data;
    new_node->freq = freq;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to swap two Min Heap nodes
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a new Min Heap node
void insertMinHeap(struct MinHeap *heap, struct HuffmanNode *node) {
    struct MinHeapNode *new_node = createMinHeapNode(node);
    if (heap->head == NULL) {
        heap->head = heap->tail = new_node;
    } else {
        heap->tail->next = new_node;
        heap->tail = new_node;
    }
    heap->size++;
}

// Function to extract minimum value node from Min Heap
struct MinHeapNode* extractMin(struct MinHeap *heap) {
    struct MinHeapNode *min_node = heap->head, *prev = NULL, *temp;
    unsigned min_freq = heap->head->node->freq;
    temp = heap->head->next;
    while (temp != NULL) {
        if (temp->node->freq < min_freq) {
            min_node = temp;
            min_freq = temp->node->freq;
            prev = temp;
        }
        temp = temp->next;
    }
    if (min_node == heap->head) {
        heap->head = heap->head->next;
    } else if (min_node == heap->tail) {
        heap->tail = prev;
        prev->next = NULL;
    } else {
        prev->next = min_node->next;
    }
    heap->size--;
    return min_node;
}

// Function to build Min Heap from given array of Huffman tree nodes
struct MinHeap* buildMinHeap(struct HuffmanNode **nodes, int n) {
    struct MinHeap *heap = createMinHeap();
    for (int i = 0; i < n; i++) {
        insertMinHeap(heap, nodes[i]);
    }
    return heap;
}

// Function to check if given Min Heap contains only one node
int isMinHeapSizeOne(struct MinHeap *heap) {
    return (heap->size == 1);
}

// Function to check if given two nodes are leaf nodes
int isLeafNode(struct HuffmanNode *node) {
    return (node->left == NULL && node->right == NULL);
}

// Function to create Huffman tree from given characters and their corresponding frequencies
struct HuffmanNode* buildHuffmanTree(char *data, unsigned *freq, int n) {
    struct HuffmanNode *left, *right, *top;
    struct MinHeap *heap = buildMinHeap(NULL, 0);
    for (int i = 0; i < n; i++) {
        insertMinHeap(heap, createHuffmanNode(data[i], freq[i]));
    }
    while (!isMinHeapSizeOne(heap)) {
        left = extractMin(heap)->node;
        right = extractMin(heap)->node;
        top = createHuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(heap, top);
    }
    return extractMin(heap)->node;
}

// Function to traverse Huffman tree and create Huffman codes for each character
void createHuffmanCode(struct HuffmanNode *root, char *code, int depth, struct HuffmanCode *codes) {
    if (root->left) {
        code[depth] = '0';
        createHuffmanCode(root->left, code, depth + 1, codes);
    }
    if (root->right) {
        code[depth] = '1';
        createHuffmanCode(root->right, code, depth + 1, codes);
    }
    if (isLeafNode(root)) {
        struct HuffmanCode huff_code;
        huff_code.data = root->data;
        huff_code.code = (char*) malloc(sizeof(char) * (depth + 1));
        strncpy(huff_code.code, code, depth);
        codes[root->data] = huff_code;
    }
}

// Function to encode given string using Huffman codes
char* encodeHuffman(struct HuffmanCode *codes, char *str, int n) {
    char *encoded_str = (char*) malloc(sizeof(char) * n * 100);
    int j = 0;
    for (int i = 0; i < n; i++) {
        struct HuffmanCode huff_code = codes[str[i]];
        strcat(encoded_str, huff_code.code);
    }
    return encoded_str;
}

// Function to decode given string using Huffman codes
char* decodeHuffman(struct HuffmanNode *root, char *str, int n) {
    char *decoded_str = (char*) malloc(sizeof(char) * n);
    struct HuffmanNode *current = root;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            current = current->left;
        } else if (str[i] == '1') {
            current = current->right;
        }
        if (isLeafNode(current)) {
            decoded_str[i] = current->data;
            current = root;
        }
    }
    decoded_str[n] = '\0';
    return decoded_str;
}

// Main function for testing
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {10, 5, 20, 30, 15, 25};
    int n = sizeof(data) / sizeof(data[0]);
    struct HuffmanNode *root = buildHuffmanTree(data, freq, n);
    char code[100];
    struct HuffmanCode codes[256];
    createHuffmanCode(root, code, 0, codes);
    char str[] = "aabcdeffedcba";
    char *encoded_str = encodeHuffman(codes, str, strlen(str));
    printf("Encoded string: %s\n", encoded_str);
    char *decoded_str = decodeHuffman(root, encoded_str, strlen(encoded_str));
    printf("Decoded string: %s\n", decoded_str);
    return 0;
}