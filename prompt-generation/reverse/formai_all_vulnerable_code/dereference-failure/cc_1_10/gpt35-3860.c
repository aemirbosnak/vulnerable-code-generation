//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Huffman tree node structure
struct huffmanNode {
    int data;
    unsigned freq;
    struct huffmanNode *left, *right;
};

// minHeap node structure
struct minHeapNode {
    struct huffmanNode *huffmanNode;
    struct minHeapNode *next;
};

// minHeap structure
struct minHeap {
    struct minHeapNode *head;
};

// function to create a new huffman tree node
struct huffmanNode* createHuffmanNode(int data, unsigned freq) {
    struct huffmanNode* node = (struct huffmanNode*) malloc(sizeof(struct huffmanNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// function to create a new minHeap node
struct minHeapNode* createMinHeapNode(struct huffmanNode* node) {
    struct minHeapNode* minHeapNode = (struct minHeapNode*) malloc(sizeof(struct minHeapNode));
    minHeapNode->next = NULL;
    minHeapNode->huffmanNode = node;
    return minHeapNode;
}

// function to create a new minHeap
struct minHeap* createMinHeap() {
    struct minHeap* minHeap = (struct minHeap*) malloc(sizeof(struct minHeap));
    minHeap->head = NULL;
    return minHeap;
}

// function to check if the minHeap is empty
int isMinHeapEmpty(struct minHeap* minHeap) {
    if(minHeap->head == NULL) return 1;
    else return 0;
}

// function to insert a new minHeap node
void insertMinHeap(struct minHeap* minHeap, struct huffmanNode* node) {
    struct minHeapNode* minHeapNode = createMinHeapNode(node);
    struct minHeapNode* tempNode = minHeap->head;
    
    if(isMinHeapEmpty(minHeap)) {
        minHeap->head = minHeapNode;
    } else {
        if(node->freq < tempNode->huffmanNode->freq) {
            minHeapNode->next = minHeap->head;
            minHeap->head = minHeapNode;
            return;
        }
        while(tempNode->next && tempNode->next->huffmanNode->freq < node->freq) {
            tempNode = tempNode->next;
        }
        minHeapNode->next = tempNode->next;
        tempNode->next = minHeapNode;
    }
}

// function to remove the minnode from minHeap
struct minHeapNode* extractMin(struct minHeap* minHeap) {
    struct minHeapNode* minHeapNode = minHeap->head;
    if(!isMinHeapEmpty(minHeap)) {
        minHeap->head = minHeapNode->next;
    }
    return minHeapNode;
}

// function to merge the two taes
struct huffmanNode* mergeTrees(struct huffmanNode* left, struct huffmanNode* right) {
    struct huffmanNode* mergeNode = createHuffmanNode('$', left->freq + right->freq);
    mergeNode->left = left;
    mergeNode->right = right;
    return mergeNode;
}

// function to build the huffman tree
struct huffmanNode* buildHuffmanTree(int data[], unsigned freq[], int size) {
    struct huffmanNode *left, *right, *mergeNode;
    struct minHeap* minHeap = createMinHeap();
  
    for(int i = 0; i < size; ++i) {
        insertMinHeap(minHeap, createHuffmanNode(data[i], freq[i]));
    }
  
    while(!isMinHeapEmpty(minHeap)) {
        left = extractMin(minHeap)->huffmanNode;
        right = extractMin(minHeap)->huffmanNode;
        mergeNode = mergeTrees(left, right);
        insertMinHeap(minHeap, mergeNode);
    }
  
    return extractMin(minHeap)->huffmanNode;
}

// function to print huffman codes from the huffman tree
void printHuffmanCodes(struct huffmanNode* node, int arr[], int top) {
    if(node->left) {
        arr[top] = 0;
        printHuffmanCodes(node->left, arr, top + 1);
    }
  
    if(node->right) {
        arr[top] = 1;
        printHuffmanCodes(node->right, arr, top + 1);
    }
  
    if(node->left == NULL && node->right == NULL) {
        printf("%c: ", node->data);
        for(int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// driver function to test the huffman coding implementation
int main() {
    int data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {2, 3, 5, 7, 9, 14};
    int size = sizeof(data)/sizeof(data[0]);
    struct huffmanNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printf("Huffman Codes: \n");
    printHuffmanCodes(root, arr, top);
    return 0;
}