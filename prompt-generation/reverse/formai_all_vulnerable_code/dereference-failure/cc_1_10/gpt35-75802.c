//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

/* A Huffman tree node */
struct HuffmanNode {
    char data;
    unsigned frequency;
    struct HuffmanNode *left, *right;
};

/* A min Heap node */
struct MinHeapNode {
    struct HuffmanNode *node;
    struct MinHeapNode *next;
};

/* A min-heap */
struct MinHeap {
    struct MinHeapNode *head;
    int count;
};

/* Utility function to create a new Huffman tree node */
struct HuffmanNode* newHuffmanNode(char data, unsigned frequency) {
    struct HuffmanNode* node = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

/* Utility function to create a new min heap node */
struct MinHeapNode* newMinHeapNode(struct HuffmanNode *node) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->next = NULL;
    minHeapNode->node = node;
    return minHeapNode;
}

/* Utility function to create a min heap */
struct MinHeap* createMinHeap() {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->head = NULL;
    minHeap->count = 0;
    return minHeap;
}

/* Swap function */
void swapNodes(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
    return;
}

/* Reduce the heap size to half */
void heapifyMinHeap(struct MinHeap* minHeap) {
    int half = minHeap->count / 2;
    struct MinHeapNode* currentNode = minHeap->head;
    for (int i = 0; i < half; i++) {
        currentNode = currentNode->next;
    }

    while(half > 0) {
        swapNodes(&(minHeap->head), &currentNode);
        half--;
        currentNode = currentNode->next;
    }
    minHeap->count = minHeap->count / 2;
    return;
}

/* Extract minimum from the heap */
struct HuffmanNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* minHeapNode = minHeap->head;

    minHeap->head = minHeapNode->next;
    minHeap->count--;

    return minHeapNode->node;
}

/* Insert a MinHeap node */
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* newMinHeapNode) {
    if (minHeap->count == 0) {
        minHeap->head = newMinHeapNode;
        minHeap->count++;
        return;
    }

    struct MinHeapNode* currentNode = minHeap->head;
    if (newMinHeapNode->node->frequency <= currentNode->node->frequency) {
        newMinHeapNode->next = currentNode;
        minHeap->head = newMinHeapNode;
        minHeap->count++;
        heapifyMinHeap(minHeap);
        return;
    }

    for (int i = 0; i < minHeap->count - 1; i++) {
        if (newMinHeapNode->node->frequency <= currentNode->next->node->frequency) {
            newMinHeapNode->next = currentNode->next;
            currentNode->next = newMinHeapNode;
            minHeap->count++;
            heapifyMinHeap(minHeap);
            return;
        }
        currentNode = currentNode->next;
    }

    currentNode->next = newMinHeapNode;
    minHeap->count++;
    heapifyMinHeap(minHeap);
    return;
}

/* Build the Huffman tree */
struct HuffmanNode* buildHuffmanTree(char* data, int* frequency, int size) {
    struct HuffmanNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap();

    for (int i = 0; i < size; ++i) {
        insertMinHeap(minHeap, newMinHeapNode(newHuffmanNode(data[i], frequency[i])));
    }

    while (minHeap->count != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newHuffmanNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, newMinHeapNode(top));
    }

    return extractMin(minHeap);
}

/* Generate Huffman codes recursively */
void generateHuffmanCodes(struct HuffmanNode* root, int top, int* codes, int codeSize) {
    if(root->left != NULL) {
        codes[codeSize] = top;
        generateHuffmanCodes(root->left, top << 1, codes, codeSize + 1);
    }

    if(root->right != NULL) {
        codes[codeSize] = top | 1;
        generateHuffmanCodes(root->right, top << 1, codes, codeSize + 1);
    }

    if(root->left == NULL && root->right == NULL) {
        printf("%c: ", root->data);
        for(int i=0; i<codeSize; i++) {
            printf("%d", codes[i]);
        }
        printf("\n");
    }
}

/* Main function */
int main() {
    char data[] = {'a','b','c','d','e','f'};
    int frequency[] = {5,9,12,13,16,45};
    int size = sizeof(data)/sizeof(data[0]);

    struct HuffmanNode* root = buildHuffmanTree(data, frequency, size);

    int codes[MAX_TREE_HT];
    generateHuffmanCodes(root, 0, codes, 0);

    return 0;
}