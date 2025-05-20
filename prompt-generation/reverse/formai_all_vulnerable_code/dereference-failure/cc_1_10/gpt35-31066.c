//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

struct HuffmanNode {
    char key;
    char *code;
    struct HuffmanNode *left, *right;
};

struct HuffmanTree {
    struct HuffmanNode *root;
};

struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) smallest = right;
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

bool isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) minHeapify(minHeap, i);
}

void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i) printf("%d", arr[i]);
    printf("\n");
}

bool isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(struct HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->key);
        printArr(arr, top);
    }
}

struct HuffmanTree* buildHuffmanCodes(char data[], int freq[], int size) {
    struct HuffmanTree* huffmanTree = (struct HuffmanTree*)malloc(sizeof(struct HuffmanTree));
    struct HuffmanNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = (struct HuffmanNode*)extractMin(minHeap);
        right = (struct HuffmanNode*)extractMin(minHeap);
        top = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
        top->left = left;
        top->right = right;
        top->key = '$';
        insertMinHeap(minHeap, (struct MinHeapNode*)top);
    }
    huffmanTree->root = (struct HuffmanNode*)extractMin(minHeap);
    return huffmanTree;
}

void encodeFile(struct HuffmanTree* huffmanTree, char* inputFilePath, char* outputFilePath) {
    FILE* inputFile = fopen(inputFilePath, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file\n");
        return;
    }
    FILE* outputFile = fopen(outputFilePath, "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file\n");
        return;
    }
    char message[1024];
    char output[1024];
    int i, j, k;
    while (fgets(message, 1024, inputFile)) {
        for (i = 0; i < strlen(message); i++) {
            struct HuffmanNode* node = huffmanTree->root;
            while (node->left != NULL && node->right != NULL) {
                if (message[i] == ' ') {
                    output[j] = '0';
                    node = node->left;
                    j++;
                }
                else {
                    output[j] = '1';
                    node = node->right;
                    j++;
                }
            }
            output[j] = '\t';
            output[j + 1] = '\0';
            strcat(outputFile, output);
            memset(output, 0, sizeof(output));
            j = 0;
        }
    }
    fclose(inputFile);
    fclose(outputFile);
}

void decodeFile(struct HuffmanTree* huffmanTree, char* inputFilePath, char* outputFilePath) {
    FILE* inputFile = fopen(inputFilePath, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file\n");
        return;
    }
    FILE* outputFile = fopen(outputFilePath, "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file\n");
        return;
    }
    char message[1024];
    char output[1024];
    int i, j;
    while (fgets(message, 1024, inputFile)) {
        for (i = 0; i < strlen(message) - 1; i++) {
            struct HuffmanNode* node = huffmanTree->root;
            while (node->left != NULL && node->right != NULL) {
                if (message[i] == '0') node = node->left;
                else node = node->right;
                i++;
            }
            output[j] = node->key;
            j++;
        }
        output[j] = '\n';
        output[j + 1] = '\0';
        strcat(outputFile, output);
        memset(output, 0, sizeof(output));
        j = 0;
    }
    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    struct HuffmanTree* huffmanTree = buildHuffmanCodes(data, freq, size);
    encodeFile(huffmanTree, "original.txt", "encoded.txt");
    decodeFile(huffmanTree, "encoded.txt", "decoded.txt");
    return 0;
}