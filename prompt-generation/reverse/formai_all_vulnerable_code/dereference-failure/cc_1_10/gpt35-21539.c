//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

typedef struct treeNode {
    char data;
    int freq;
    struct treeNode *left, *right;
} TreeNode;

typedef struct minHeap {
    int size;
    int capacity;
    TreeNode** array;
} MinHeap;

TreeNode* newNode(char data, int freq) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (TreeNode**)malloc(heap->capacity * sizeof(TreeNode*));
    return heap;
}

void swapNodes(TreeNode** first, TreeNode** second) {
    TreeNode* temp = *first;
    *first = *second;
    *second = temp;
}

void minHeapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq) {
        smallest = left;
    }

    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != index) {
        swapNodes(&heap->array[smallest], &heap->array[index]);
        minHeapify(heap, smallest);
    }
}

TreeNode* extractMin(MinHeap* heap) {
    TreeNode* node = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return node;
}

void insertMinHeap(MinHeap* heap, TreeNode* node) {
    heap->size++;
    int index = heap->size - 1;

    while (index && node->freq < heap->array[(index - 1) / 2]->freq) {
        heap->array[index] = heap->array[(index - 1) / 2];
        index = (index - 1) / 2;
    }

    heap->array[index] = node;
}

void buildMinHeap(MinHeap* heap) {
    int n = heap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; i--) {
        minHeapify(heap, i);
    }
}

bool checkLeaf(TreeNode* node) {
    return !(node->left) && !(node->right);
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap* heap = createMinHeap(size);

    for (int i = 0; i < size; ++i) {
        heap->array[i] = newNode(data[i], freq[i]);
    }

    heap->size = size;
    buildMinHeap(heap);

    return heap;
}

TreeNode* buildHuffmanTree(char data[], int freq[], int size) {
    TreeNode *left, *right, *top;

    MinHeap* heap = createAndBuildMinHeap(data, freq, size);

    while (heap->size > 1) {
        left = extractMin(heap);
        right = extractMin(heap);

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(heap, top);
    }

    return extractMin(heap);
}

void printCodes(TreeNode* root, int array[], int top) {
    if (root->left) {
        array[top] = 0;
        printCodes(root->left, array, top + 1);
    }

    if (root->right) {
        array[top] = 1;
        printCodes(root->right, array, top + 1);
    }

    if (checkLeaf(root)) {
        printf("%c: ", root->data);

        for (int i = 0; i < top; ++i) {
            printf("%d", array[i]);
        }

        printf("\n");
    }
}

void huffmanCoding(char data[], int freq[], int size) {
    TreeNode* root = buildHuffmanTree(data, freq, size);
    int array[MAX_TREE_HT], top = 0;
    printCodes(root, array, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Huffman Coding:\n");
    huffmanCoding(data, freq, size);

    return 0;
}