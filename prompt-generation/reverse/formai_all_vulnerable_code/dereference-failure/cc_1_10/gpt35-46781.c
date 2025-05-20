//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;

typedef struct HuffmanNode {
    char data;
    char *code;
    struct HuffmanNode *left, *right;
} HuffmanNode;

typedef struct HuffmanTree {
    HuffmanNode *root;
} HuffmanTree;

MinHeapNode *newMinHeapNode(char data, unsigned freq) {
    MinHeapNode *node = (MinHeapNode *) malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

MinHeap *createMinHeap(unsigned capacity) {
    MinHeap *minHeap = (MinHeap *) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode **) malloc(minHeap->capacity * sizeof(MinHeapNode *));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b) {
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int idx) {
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

int isSizeOne(MinHeap *minHeap) {
    return (minHeap->size == 1);
}

MinHeapNode *extractMin(MinHeap *minHeap) {
    MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap *minHeap, MinHeapNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap *minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

int isLeaf(MinHeapNode *root) {
    return !(root->left) && !(root->right);
}

MinHeap *createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap *minHeap = createMinHeap(size);
    int i;
    for (i = 0; i < size; ++i)
        minHeap->array[i] = newMinHeapNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

HuffmanNode *buildHuffmanTree(char data[], int freq[], int size) {
    HuffmanTree *tree = (HuffmanTree *) malloc(sizeof(HuffmanTree));
    MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        MinHeapNode *left = extractMin(minHeap);
        MinHeapNode *right = extractMin(minHeap);
        MinHeapNode *top = newMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    HuffmanNode *root = (HuffmanNode *) malloc(sizeof(HuffmanNode));
    root->code = "";
    root->left = minHeap->array[0];
    root->right = NULL;
    root->data = '$';

    free(minHeap);
    return root;
}

void buildHuffmanCodes(HuffmanNode *root, char *code) {
    if (!root) return;

    if (isLeaf(root)) {
        root->code = (char *) malloc(strlen(code) + 1);
        strcpy(root->code, code);
        return;
    }
    char leftcode[MAX_TREE_HT], rightcode[MAX_TREE_HT];
    strcpy(leftcode, code);
    strcpy(rightcode, code);
    strcat(leftcode, "0");
    strcat(rightcode, "1");
    buildHuffmanCodes(root->left, leftcode);
    buildHuffmanCodes(root->right, rightcode);
}

void printCodes(HuffmanNode *root) {
    if (!root) return;
    if (root->data != '$') printf("%c : %s\n", root->data, root->code);
    printCodes(root->left);
    printCodes(root->right);
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanNode *root = buildHuffmanTree(arr, freq, size);
    buildHuffmanCodes(root, "");
    printf("Huffman Codes:\n");
    printCodes(root);
    return 0;
}