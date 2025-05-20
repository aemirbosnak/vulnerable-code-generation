//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Huffman tree node structure
typedef struct node {
  char symbol;
  int frequency;
  struct node *left;
  struct node *right;
} Node;

// Heap node structure (for Priority Queue)
typedef struct heapNode {
  Node *treeNode;
  struct heapNode *next;
} HeapNode;

// Priority Queue structure
typedef struct {
  HeapNode *head;
} PriorityQueue;

// Create new node
Node *createNode(char symbol, int frequency) {
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->symbol = symbol;
  newNode->frequency = frequency;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Enqueue a new heap node to the priority queue
void enqueue(PriorityQueue *pq, Node *treeNode) {
  HeapNode *newNode = (HeapNode *) malloc(sizeof(HeapNode));
  newNode->treeNode = treeNode;
  newNode->next = NULL;
  
  if (pq->head == NULL) {
    pq->head = newNode;
    return;
  }
  
  HeapNode *curr = pq->head;
  HeapNode *prev = NULL;
  
  while (curr != NULL && curr->treeNode->frequency < treeNode->frequency) {
    prev = curr;
    curr = curr->next;
  }
  
  if (prev == NULL) {
    newNode->next = pq->head;
    pq->head = newNode;
  } else {
    newNode->next = prev->next;
    prev->next = newNode;
  }
}

// Dequeue the highest priority heap node from the priority queue
Node *dequeue(PriorityQueue *pq) {
  if (pq->head == NULL)
    return NULL;
    
  HeapNode *delNode = pq->head;
  pq->head = pq->head->next;
  
  Node *treeNode = delNode->treeNode;
  free(delNode);
  
  return treeNode;
}

// Build Huffman tree from the given input symbols and frequencies
Node *buildTree(char *symbols, int *frequencies, int n) {
  PriorityQueue *pq = (PriorityQueue *) malloc(sizeof(PriorityQueue));
  pq->head = NULL;
  
  for (int i = 0; i < n; i++) {
    Node *newNode = createNode(symbols[i], frequencies[i]);
    enqueue(pq, newNode);
  }
  
  while (pq->head->next != NULL) {
    Node *left = dequeue(pq);
    Node *right = dequeue(pq);
    
    Node *parent = createNode('#', left->frequency + right->frequency);
    parent->left = left;
    parent->right = right;
    
    enqueue(pq, parent);
  }
  
  Node *root = dequeue(pq);
  free(pq);
  return root;
}

// Traverse the Huffman tree and assign codes to each symbol
void assignCode(Node *root, char *codeTable[], char *buffer, int depth) {
  if (root == NULL)
    return;
    
  if (root->left == NULL && root->right == NULL) {
    buffer[depth] = '\0';
    codeTable[root->symbol] = (char *) malloc(sizeof(char) * depth);
    strcpy(codeTable[root->symbol], buffer);
    return;
  }
  
  buffer[depth] = '0';
  assignCode(root->left, codeTable, buffer, depth+1);
  
  buffer[depth] = '1';
  assignCode(root->right, codeTable, buffer, depth+1);
}

// Print the Huffman codes for each symbol
void printCodes(char *symbols, char *codeTable[], int *frequencies, int n) {
  int totalBits = 0;
  
  for (int i = 0; i < n; i++) {
    printf("%c: %s\n", symbols[i], codeTable[symbols[i]]);
    totalBits += frequencies[i] * strlen(codeTable[symbols[i]]);
  }
  
  printf("Total bits used: %d\n", totalBits);
}

int main() {
  // Sample input data
  char symbols[] = {'A', 'B', 'C', 'D', 'E'};
  int frequencies[] = {5, 1, 4, 10, 3};
  int n = sizeof(symbols) / sizeof(char);
  
  // Build Huffman tree
  Node *root = buildTree(symbols, frequencies, n);
  
  // Traverse Huffman tree and assign codes to each symbol
  char *codeTable[256] = {NULL};
  char buffer[256];
  assignCode(root, codeTable, buffer, 0);
  
  // Print Huffman codes for each symbol
  printCodes(symbols, codeTable, frequencies, n);
  
  return 0;
}