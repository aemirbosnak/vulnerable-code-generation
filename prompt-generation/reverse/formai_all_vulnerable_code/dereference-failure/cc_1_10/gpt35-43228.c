//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TREE_HT 100
#define MAX_CODE_LENGTH 20

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

MinHeapNode* createNode(char data, unsigned freq) {
  MinHeapNode* newNode = (MinHeapNode*) malloc(sizeof(MinHeapNode));
  newNode->left = newNode->right = NULL;
  newNode->data = data;
  newNode->freq = freq;
  return newNode;
}

MinHeap* createMinHeap(unsigned capacity) {
  MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (MinHeapNode**) malloc(minHeap->capacity * sizeof(MinHeapNode*));
  return minHeap;
}

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b) {
  MinHeapNode* t = *a;
  *a = *b;
  *b = t;
}

void minHeapify(MinHeap* minHeap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
    smallest = left;

  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
    smallest = right;

  if (smallest != idx) {
    swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

bool isLeaf(MinHeapNode* root) {
  return !(root->left) && !(root->right);
}

MinHeap* buildMinHeap(char data[], int freq[], int size) {
  MinHeap* minHeap = createMinHeap(size);
  for (int i = 0; i < size; ++i)
    minHeap->array[i] = createNode(data[i], freq[i]);
  minHeap->size = size;

  for (int i = (size - 2) / 2; i >= 0; --i)
    minHeapify(minHeap, i);

  return minHeap;
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

void printArr(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    printf("%d", arr[i]);
}

bool isBinary(char str[]) {
  int len = strlen(str);
  for (int i = 0; i < len; ++i) {
    if (str[i] != '0' && str[i] != '1')
      return false;
  }
  return true;
}

bool isInRange(int num, int min, int max) {
  return (num >= min && num <= max);
}

void encode(MinHeapNode* root, int arr[], int top, int huffmanCode[][MAX_CODE_LENGTH], int *maxCodeLength) {
  if (root->left) {
    arr[top] = 0;
    encode(root->left, arr, top + 1, huffmanCode, maxCodeLength);
  }

  if (root->right) {
    arr[top] = 1;
    encode(root->right, arr, top + 1, huffmanCode, maxCodeLength);
  }

  if (isLeaf(root)) {
    int i;
    for (i = 0; i < top; ++i) {
      huffmanCode[root->data][i] = arr[i];
    }
    huffmanCode[root->data][i] = '\0';
    if (strlen(huffmanCode[root->data]) > *maxCodeLength) {
      *maxCodeLength = strlen(huffmanCode[root->data]);
    }
  }
}

void printHuffmanCode(char data[], int freq[], int size) {
  MinHeapNode* left, * right, * top;
  int arr[MAX_TREE_HT], huffmanCode[MAX_TREE_HT][MAX_CODE_LENGTH], maxCodeLength = 0;

  MinHeap* minHeap = buildMinHeap(data, freq, size);

  while (minHeap->size != 1) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);
    top = createNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    insertMinHeap(minHeap, top);
  }

  int i;
  printf("Char\tFreq\tHuffman Code\n");
  for (i = 0; i < size; ++i) {
    printf("%c\t%d\t", data[i], freq[i]);
    if (strlen(huffmanCode[data[i]]) > 0) {
      printf("%s", huffmanCode[data[i]]);
    } else if (isBinary(huffmanCode[data[i]])) {
      printf("%s", huffmanCode[data[i]]);
    }
    printf("\n");
  }

  printf("Max Code Length: %d", maxCodeLength);
}

int main() {
  char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(data) / sizeof(data[0]);
  printHuffmanCode(data, freq, size);
  return 0;
}