//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Dennis Ritchie
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
    char* code;
    struct HuffmanNode *left, *right;
} HuffmanNode;

typedef struct HuffmanCodes {
    unsigned size;
    HuffmanNode **array;
} HuffmanCodes;

void swap(MinHeapNode** x, MinHeapNode** y) {
    MinHeapNode* t = *x;
    *x = *y;
    *y = t;
}

MinHeapNode* createMinHeapNode(char data, unsigned freq) {
    MinHeapNode* minHeapNode = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    minHeapNode->left = minHeapNode->right = NULL;
    minHeapNode->data = data;
    minHeapNode->freq = freq;
    return minHeapNode;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
        (MinHeapNode**) malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size &&
        minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size &&
        minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swap(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) minHeapify(minHeap, i);
}

int isLeaf(MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; i++)
        minHeap->array[i] = createMinHeapNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(MinHeapNode* root, int arr[], int top, HuffmanCodes* hc) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, hc);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, hc);
    }
    if (isLeaf(root)) {
        HuffmanNode* hn = (HuffmanNode*) malloc(sizeof(HuffmanNode));
        hn->data = root->data;
        hn->left = hn->right = NULL;
        hn->code = (char*) malloc((top + 1) * sizeof(char));
        for (int i = 0; i < top; ++i) {
            hn->code[i] = (char) arr[i] + '0';
        }
        hn->code[top] = '\0';
        hc->array[hc->size++] = hn;
    }
}

HuffmanCodes* getHuffmanCodes(char data[], int freq[], int size) {
    HuffmanCodes* hc = (HuffmanCodes*) malloc(sizeof(HuffmanCodes));
    hc->size = 0;
    hc->array = (HuffmanNode**) malloc(size * sizeof(HuffmanNode*));
    MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top, hc);
    return hc;
}

void displayHuffmanCodes(HuffmanCodes* hc) {
    printf("\nHuffman Codes: \n");
    for (int i = 0; i < hc->size; ++i) {
        printf("%c : %s\n", hc->array[i]->data, hc->array[i]->code);
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    HuffmanCodes* hc = getHuffmanCodes(data, freq, size);
    displayHuffmanCodes(hc);
    return 0;
}