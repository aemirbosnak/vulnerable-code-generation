//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

MinHeapNode* newMinHeapNode(char data, unsigned freq) {
    MinHeapNode* node = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    node -> left = NULL;
    node -> right = NULL;
    node -> data = data;
    node -> freq = freq;
    return node;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap -> size = 0;
    minHeap -> capacity = capacity;
    minHeap -> array = (MinHeapNode**) malloc(minHeap -> capacity * sizeof(MinHeapNode));
    return minHeap;
}

void minHeapify(MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < minHeap -> size && minHeap -> array[left] -> freq < minHeap -> array[smallest] -> freq)
        smallest = left;
    if (right < minHeap -> size && minHeap -> array[right] -> freq < minHeap -> array[smallest] -> freq)
        smallest = right;
    if (smallest != index) {
        MinHeapNode* temp = minHeap -> array[index];
        minHeap -> array[index] = minHeap -> array[smallest];
        minHeap -> array[smallest] = temp;
        minHeapify(minHeap, smallest);
    }
}

bool isSizeOne(MinHeap* minHeap) {
    return (minHeap -> size == 1);
}

MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap -> array[0];
    minHeap -> array[0] = minHeap -> array[minHeap -> size - 1];
    --minHeap -> size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap -> size;
    int i = minHeap -> size - 1;
    while (i && (minHeapNode -> freq < minHeap -> array[(i - 1) / 2] -> freq)) {
        minHeap -> array[i] = minHeap -> array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap -> array[i] = minHeapNode;
}

void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap -> size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int isLeaf(MinHeapNode* root) {
    return !(root -> left) && !(root -> right);
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap -> array[i] = newMinHeapNode(data[i], freq[i]);
    minHeap -> size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

HuffmanNode* createHuffmanTree(char data[], int freq[], int size) {
    HuffmanNode *root = NULL, *left = NULL, *right = NULL;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        root = (HuffmanNode*) malloc(sizeof(HuffmanNode));
        root -> left = (HuffmanNode*) left;
        root -> right = (HuffmanNode*) right;
        root -> data = '$';
        root -> code = NULL;
        root -> left -> code = "0";
        root -> right -> code = "1";
        root -> data = '#';
        root -> left -> data = left -> data;
        root -> right -> data = right -> data;
        root -> left -> code = (char*) malloc(sizeof(char) * (strlen(left -> code) + 1));
        strcpy(root -> left -> code, left -> code);
        root -> right -> code = (char*) malloc(sizeof(char) * (strlen(right -> code) + 1));
        strcpy(root -> right -> code, right -> code);
        insertMinHeap(minHeap, (MinHeapNode*) root);
    }
    return root;
}

void encode(MinHeapNode* root, char* str, int top) {
    if (root -> left) {
        str[top] = '0';
        encode(root -> left, str, top + 1);
    }
    if (root -> right) {
        str[top] = '1';
        encode(root -> right, str, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root -> data);
        str[top] = '\0';
        HuffmanNode* node = (HuffmanNode*) root;
        node -> code = (char*) malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(node -> code, str);
        printf("%s\n", node -> code);
    }
}

void HuffmanCodes(char data[], int freq[], int size) {
    HuffmanNode* root = createHuffmanTree(data, freq, size);
    char arr[MAX_TREE_HT], index = 0;
    encode((MinHeapNode*) root, arr, index);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    HuffmanCodes(data, freq, size);
    return 0;
}