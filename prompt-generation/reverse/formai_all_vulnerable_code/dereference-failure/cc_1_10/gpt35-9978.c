//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// structure for Huffman Tree Node
struct HuffNode {
    char data;
    unsigned freq;
    struct HuffNode *left, *right;
};

// structure for Min Heap Node
struct MinHeapNode {
    struct HuffNode *data;
    unsigned priority;
    struct MinHeapNode *next;
};

// structure for Min Heap
struct MinHeap {
    struct MinHeapNode *head;
    unsigned size;
};

// function to create a new Node in Huffman Tree
struct HuffNode* NewHuffNode(char data, unsigned freq) {
    struct HuffNode* huffNode = (struct HuffNode*)malloc(sizeof(struct HuffNode));
    huffNode->left = huffNode->right = NULL;
    huffNode->data = data;
    huffNode->freq = freq;
    return huffNode;
}

// function to create a new Node in Min Heap
struct MinHeapNode* NewMinHeapNode(struct HuffNode *huffNode, unsigned priority) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->data = huffNode;
    minHeapNode->priority = priority;
    minHeapNode->next = NULL;
    return minHeapNode;
}

// function to create a new Min Heap
struct MinHeap* NewMinHeap() {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->head = NULL;
    minHeap->size = 0;
    return minHeap;
}

// function to swap two Min Heap Nodes
void SwapMinHeapNodes(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// function to sort the Min Heap using bubble sort
void SortMinHeap(struct MinHeap* minHeap) {
    struct MinHeapNode* current = minHeap->head;
    while(current) {
        struct MinHeapNode* node = minHeap->head;
        while(node->next) {
            if(node->priority > node->next->priority) {
                SwapMinHeapNodes(&node, &(node->next));
            }
            node = node->next;
        }
        current = current->next;
    }
}

// function to check if Min Heap is empty
int IsMinHeapEmpty(struct MinHeap* minHeap) {
    return (minHeap->size == 0);
}

// function to get the lowest priority Node from Min Heap
struct MinHeapNode* ExtractMin(struct MinHeap* minHeap) {
    if(IsMinHeapEmpty(minHeap)) {
        printf("Min Heap is empty. Cannot extract a node!\n");
        return NULL;
    }
    struct MinHeapNode* temp = minHeap->head;
    minHeap->head = minHeap->head->next;
    minHeap->size--;
    return temp;
}

// function to insert a Node in Min Heap
void InsertMinHeap(struct MinHeap* minHeap, struct HuffNode *huffNode, unsigned priority) {
    struct MinHeapNode* temp = NewMinHeapNode(huffNode, priority);
    if(IsMinHeapEmpty(minHeap)) {
        minHeap->head = temp;
    } else {
        struct MinHeapNode* current = minHeap->head;
        while(current->next) {
            current = current->next;
        }
        current->next = temp;
    }
    minHeap->size++;
}

// function to build Huffman Tree from input characters and their respective frequencies
struct HuffNode* BuildHuffmanTree(char *data, unsigned *freq, unsigned size) {
    struct HuffNode *left, *right, *top;
    struct MinHeap* minHeap = NewMinHeap();
    for (unsigned i = 0; i < size; i++) {
        InsertMinHeap(minHeap, NewHuffNode(data[i], freq[i]), freq[i]);
    }
    SortMinHeap(minHeap);
    while(minHeap->size > 1) {
        left = ExtractMin(minHeap)->data;
        right = ExtractMin(minHeap)->data;
        top = NewHuffNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        InsertMinHeap(minHeap, top, top->freq);
        SortMinHeap(minHeap);
    }
    return ExtractMin(minHeap)->data;
}

// function to print Huffman Codes from the Root of Huffman Tree
void PrintHuffCodes(struct HuffNode *root, int *codes, int top) {
    // if it is a leaf Node, print the character and its code
    if (root->left == NULL && root->right == NULL) {
        printf("%c : ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", codes[i]);
        }
        printf("\n");
        return;
    }
    // if it is a '0', assign '0' to the code and traverse the left subtree
    codes[top] = 0;
    PrintHuffCodes(root->left, codes, top+1);
    // if it is a '1', assign '1' to the code and traverse the right subtree
    codes[top] = 1;
    PrintHuffCodes(root->right, codes, top+1);
}

// main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {45, 13, 12, 16, 9, 5};
    unsigned size = sizeof(data)/sizeof(data[0]);
    struct HuffNode *root = BuildHuffmanTree(data, freq, size);
    int codes[MAX_TREE_HT], top = 0;
    printf("Huffman Codes for the given Characters:\n");
    PrintHuffCodes(root, codes, top);
    return 0;
}