//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

// Huffman Tree node
struct Node {
  char data;
  unsigned freq;

  struct Node *left, *right;
};

// Min Heap node
struct HeapNode {
  struct Node *node;
  struct HeapNode *next;
};

// Function to create a new HeapNode
struct HeapNode* createHeapNode(struct Node *node)
{
  struct HeapNode* newNode = (struct HeapNode*) malloc(sizeof(struct HeapNode));
  newNode->node = node;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a new HeapNode to the Min Heap
void insert(struct HeapNode **root, struct HeapNode *newNode)
{
  if ((*root) == NULL || ((*root)->node->freq) >= (newNode->node->freq))
  {
    newNode->next = (*root);
    (*root) = newNode;
  }
  else {
    struct HeapNode* current = (*root);
    while (current->next != NULL && current->next->node->freq < newNode->node->freq)
    {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}

// Function to remove the minimum element from the Min Heap
struct HeapNode* removeMin(struct HeapNode** root)
{
  struct HeapNode* temp = (*root);
  (*root) = (*root)->next;
  return temp;
}

// Function to build the Huffman Tree
struct Node* buildHuffmanTree(char data[], int freq[], int size)
{
  struct Node *left, *right, *top;

  // Create a min heap and insert all characters with their frequencies
  struct HeapNode *minHeap = NULL;

  for (int i = 0; i < size; ++i){
    insert(&minHeap, createHeapNode(&(struct Node){data[i], freq[i], NULL, NULL}));
  }
  while (minHeap->next != NULL)
  {
    left = removeMin(&minHeap)->node;
    right = removeMin(&minHeap)->node;
    top = (struct Node*) malloc(sizeof(struct Node));
    top->data = '-';
    top->freq = left->freq + right->freq;
    top->left = left;
    top->right = right;
    insert(&minHeap, createHeapNode(top));
  }
  return removeMin(&minHeap)->node;
}

// Function to print Huffman codes from the root of the Huffman Tree
void printHuffmanCodes(struct Node* root, int arr[], int top)
{
  if (root->left)
  {
    arr[top] = 0;
    printHuffmanCodes(root->left, arr, top + 1);
  }
  if (root->right)
  {
    arr[top] = 1;
    printHuffmanCodes(root->right, arr, top + 1);
  }

  if (root->left == NULL && root->right == NULL)
  {
    printf("%c ", root->data);
    for (int i = 0; i < top; ++i){
      printf("%d", arr[i]);
    }
    printf("\n");
  }
}

int main()
{
  char inputString[SIZE];
  int freq[SIZE] = {0};

  printf("Enter the string to encoding: ");
  fgets(inputString, SIZE, stdin);
  inputString[strcspn(inputString, "\n")] = 0;

  int length = strlen(inputString);

  for (int i = 0; i < length; i++)
  {
    freq[inputString[i]]++;
  }

  struct Node* root = buildHuffmanTree(inputString, freq, 256);

  int arr[100], top = 0;
  printf("\nHuffman Codes:\n");
  printHuffmanCodes(root, arr, top);
  return 0;
}