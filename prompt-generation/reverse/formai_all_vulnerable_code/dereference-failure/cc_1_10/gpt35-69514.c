//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// A Huffman tree node structure
struct MinHeapNode {
  char data;
  unsigned freq;
  struct MinHeapNode *left, *right;
};

// A Huffman tree structure
struct MinHeap {
  unsigned size;
  unsigned capacity;
  struct MinHeapNode **array;
};

// Function to create a new Huffman tree node
struct MinHeapNode *newNode(char data, unsigned freq) {
  struct MinHeapNode *temp = (struct MinHeapNode *) malloc(sizeof(struct MinHeapNode));
  temp->left = temp->right = NULL;
  temp->data = data;
  temp->freq = freq;
  return temp;
}

// Function to create a new Huffman tree
struct MinHeap *createMinHeap(unsigned capacity) {
  struct MinHeap *minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
  return minHeap;
}

// Function to swap two nodes of the min heap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) { 
  struct MinHeapNode* temp = *a;
  *a = *b;
  *b = temp;
}

// Function to maintain the min heap property
void minHeapify(struct MinHeap* minHeap, int idx) {
  int smallest = idx;
  int left = 2*idx + 1;
  int right = 2*idx + 2;
  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
    smallest = left;
  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
    smallest = right;
  if (smallest != idx) {
    swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}
 
// Function to check if size of heap one and two exceed the capacity of third heap 
int maxHeapCapacity(struct MinHeapNode *root, int *len, int *cap){
    while(root){
        if(root->left) maxHeapCapacity(root->left, len, cap);
        if(root->right) maxHeapCapacity(root->right, len, cap);
        if(root->left == NULL && root->right == NULL){
            ++(*len);
            if(((*len)+2) > (*cap)) return 1;
        }
        return 0;
    }
}
  
// Function to check if the given min heap size is 1 or not
int isSizeOne(struct MinHeap* minHeap) {
  return (minHeap->size == 1);
}

// Function to extract the minimum value node from a min heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
  struct MinHeapNode* temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];
  --minHeap->size;
  minHeapify(minHeap, 0);
  return temp;
}
 
// Function to insert a new node to the min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;
  while (i && minHeapNode->freq < minHeap->array[(i - 1)/2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1)/2];
    i = (i - 1)/2;
  }
  minHeap->array[i] = minHeapNode;
}
 
// Function to build a min heap
void buildMinHeap(struct MinHeap* minHeap) {
  int n = minHeap->size - 1;
  int i;
  for (i = (n - 1)/2; i >= 0; --i)
    minHeapify(minHeap, i);
}

// Function to build a Huffman tree and print its codes
void buildHuffmanTree(char *data, int *freq, int n) {
  struct MinHeapNode *left, *right, *top;
  struct MinHeap *minHeap = createMinHeap(n);
  for (int i = 0; i < n; ++i)
    insertMinHeap(minHeap, newNode(data[i], freq[i]));

  while (!isSizeOne(minHeap)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);
    top = newNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    insertMinHeap(minHeap, top);
  }

  int len = 0, cap = MAX_TREE_HT;
  int overCap = maxHeapCapacity(top, &len, &cap);
  if(overCap == 1){
    printf("Tree Size Over Capacity!");
    exit(0);
  }
}

// Driver program to test above functions
int main() {
  char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {5, 9, 12, 13, 16, 45};
  int n = sizeof(data)/sizeof(data[0]);
  buildHuffmanTree(data, freq, n);
  return 0;
}