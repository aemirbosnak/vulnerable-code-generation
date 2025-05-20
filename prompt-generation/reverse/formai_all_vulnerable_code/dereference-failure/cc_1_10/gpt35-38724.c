//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Huffman tree node structure
struct MinHeapNode {
  char data;
  unsigned freq;
  struct MinHeapNode *lChild;
  struct MinHeapNode *rChild;
};

// MinHeap structure
struct MinHeap {
  unsigned size;
  unsigned capacity;
  struct MinHeapNode **array;
};

// Create new node
struct MinHeapNode* newNode(char data, unsigned freq) {
  struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
  temp->lChild = temp->rChild = NULL;
  temp->data = data;
  temp->freq = freq;
  return temp;
}

// Create new MinHeap
struct MinHeap* createMinHeap(unsigned capacity) {
  struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
  return minHeap;
}

// Swap two nodes
void swapMinHeapNodes(struct MinHeapNode** a, struct MinHeapNode** b) {
  struct MinHeapNode* t = *a;
  *a = *b;
  *b = t;
}

// Heapify the tree
void minHeapify(struct MinHeap* minHeap, int idx) {
  int smallest = idx;
  int l = 2 * idx + 1;
  int r = 2 * idx + 2;

  if (l < minHeap->size && minHeap->array[l]->freq < minHeap->array[smallest]->freq)
        smallest = l;
  if (r < minHeap->size && minHeap->array[r]->freq < minHeap->array[smallest]->freq)
        smallest = r;
  if (smallest != idx) {
        swapMinHeapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
  }
}

// Check if heap has size 1
int isSizeOne(struct MinHeap* minHeap) {
  return (minHeap->size == 1);
}

// Extract the minimum frequency node
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
  struct MinHeapNode* temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];
  --minHeap->size;
  minHeapify(minHeap, 0);
  return temp;
}

// Insert a node into the heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;
  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
  }
  minHeap->array[i] = minHeapNode;
}

// Standard Huffman coding function to build the tree and encode the data
int HuffmanCoding(char* data, int* freq, int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        insertMinHeap(minHeap, newNode(data[i], freq[i]));

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->lChild = left;
        top->rChild = right;
        insertMinHeap(minHeap, top);
    }
    return 0;
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int freq[] = {5, 9, 12, 13, 16, 45, 67, 89};
 
    int size = sizeof(data)/sizeof(data[0]);
    HuffmanCoding(data, freq, size);

    return 0;
}