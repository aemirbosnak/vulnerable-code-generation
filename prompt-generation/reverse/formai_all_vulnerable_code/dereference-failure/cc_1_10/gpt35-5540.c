//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_HT 256

typedef struct MinHeapNode {
    char data;
    unsigned frequency;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode** arr;
} MinHeap;

typedef struct StackNode {
    struct MinHeapNode* t;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    struct StackNode* head;
} Stack;

MinHeapNode* newNode(char data, unsigned frequency) {
    MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frequency = frequency;
    return temp;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->arr = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinMaxHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->arr[left]->frequency < minHeap->arr[smallest]->frequency) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->arr[right]->frequency < minHeap->arr[smallest]->frequency) {
        smallest = right;
    }
    if (smallest != idx) {
        swapMinMaxHeapNode(&minHeap->arr[smallest], &minHeap->arr[idx]);
        minHeapify(minHeap, smallest);
    }
}

bool isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->frequency < minHeap->arr[(i - 1) / 2]->frequency) {
        minHeap->arr[i] = minHeap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->arr[i] = minHeapNode;
}

bool isLeaf(MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

MinHeap* createAndBuildMinHeap(char data[], int frequency[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        minHeap->arr[i] = newNode(data[i], frequency[i]);
    }
    minHeap->size = size;
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
    return minHeap;
}

MinHeapNode* buildHuffmanTree(char data[], int frequency[], int size) {
    MinHeapNode *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, frequency, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void push(Stack* stack, MinHeapNode* node) {
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    stackNode->t = node;
    stackNode->next = stack->head;
    stack->head = stackNode;
}

MinHeapNode* pop(Stack* stack) {
    StackNode* temp;
    MinHeapNode* res;
    temp = stack->head;
    stack->head = stack->head->next;
    res = temp->t;
    free(temp);
    return res;
}

void printCodes(MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void HuffmanCodes(char data[], int frequency[], int size) {
    MinHeapNode* root = buildHuffmanTree(data, frequency, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[6] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}