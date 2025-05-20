//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: active
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
    MinHeapNode** array;
} MinHeap;

typedef struct HuffmanNode {
    char data;
    char *code;
    struct HuffmanNode *left, *right;
} HuffmanNode;

MinHeapNode* createMinHeapNode(char data, unsigned freq) {
    MinHeapNode* node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != index) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[index]);
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
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

void storeCodes(HuffmanNode* root, int arr[], int top, char *code[]) {
    if (root->left) {
        arr[top] = 0;
        storeCodes(root->left, arr, top + 1, code);
    }
    if (root->right) {
        arr[top] = 1;
        storeCodes(root->right, arr, top + 1, code);
    }
    if (!root->left && !root->right) {
        int i;
        char s[10];
        for (i = 0; i < top; ++i)
            sprintf(s + i, "%d", arr[i]);
        code[(int)root->data] = malloc(top + 1);
        strcpy(code[(int)root->data], s);
    }
}

void HuffmanCodes(char data[], int freq[], int size, char *code[]) {
    int i;
    MinHeap* minHeap = createMinHeap(size);
    for (i = 0; i < size; ++i)
        minHeap->array[i] = createMinHeapNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    while (!isSizeOne(minHeap)) {
        MinHeapNode* left = extractMin(minHeap);
        MinHeapNode* right = extractMin(minHeap);
        MinHeapNode* top = createMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    int arr[MAX_TREE_HT], top = 0;
    HuffmanNode* root = createMinHeapNode('$', 0);
    root->left = minHeap->array[0];
    storeCodes(root, arr, top, code);
}

void HuffmanDecode(char *s, HuffmanNode* root) {
    int i;
    int n = strlen(s);
    for (i = 0; i < n; ++i) {
        if (s[i] == '0')
            root = root->left;
        else
            root = root->right;
        if (!root->left && !root->right) {
            printf("%c", root->data);
            root = createMinHeapNode('$', 0);
            root->left = root->right = NULL;
        }
    }
}

int main() {
    char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(alphabet) / sizeof(alphabet[0]);
    char *code[size];
    HuffmanCodes(alphabet, freq, size, code);
    printf("Huffman Codes:\n");
    int i;
    for (i = 0; i < size; ++i)
        printf("%c: %s\n", alphabet[i], code[i]);
    printf("\nEncoded Message: ");
    char message[] = "fbcdc";
    char *encoded = malloc(1);
    *encoded = 0;
    for (i = 0; i < strlen(message); ++i) {
        strcat(encoded, code[(int)message[i]]);
    }
    printf("%s\n", encoded);
    printf("\nDecoded Message: ");
    HuffmanNode* root = createMinHeapNode('$', 0);
    root->left = createMinHeapNode('f', 0);
    root->right = createMinHeapNode('$', 27);
    root->right->left = createMinHeapNode('c', 0);
    root->right->right = createMinHeapNode('$', 13);
    root->right->right->left = createMinHeapNode('d', 0);
    root->right->right->right = createMinHeapNode('$', 16);
    root->right->right->right->left = createMinHeapNode('e', 0);
    root->right->right->right->right = createMinHeapNode('b', 0);
    HuffmanDecode(encoded, root);
    printf("\n");
    return 0;
}