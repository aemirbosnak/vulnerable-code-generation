//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// A Huffman tree node structure
struct Node {
  char data;
  unsigned freq;
  struct Node *left, *right;
};

// A priority queue node structure
struct PQNode {
  struct Node *data;
  unsigned priority;
  struct PQNode *next;
};

// Function to create a new node
struct Node *newNode(char data, unsigned freq) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->left = node->right = NULL;
  node->data = data;
  node->freq = freq;

  return node;
}

// Function to create a new priority queue node
struct PQNode *newPQNode(struct Node *node, unsigned priority) {
  struct PQNode *pNode = (struct PQNode *)malloc(sizeof(struct PQNode));
  pNode->data = node;
  pNode->priority = priority;
  pNode->next = NULL;

  return pNode;
}

// Function to swap the contents of a and b
void swap(struct PQNode **a, struct PQNode **b) {
  struct PQNode *temp = *a;
  *a = *b;
  *b = temp;
}

// Function to re-order a Min Heap
void minHeapify(struct PQNode **head, int n) {
  struct PQNode *curr = *head;
  while (curr->next != NULL && n > 1) {
    if (curr->priority > curr->next->priority)
      swap(&curr, &(curr->next));

    curr = curr->next;
    n--;
  }
}

// Function to insert a node in a priority queue
void insertNode(struct PQNode **head, struct PQNode *newNode) {
  newNode->next = *head;
  *head = newNode;

  minHeapify(head, 0);
}

// Function to remove the minimum element from a priority queue
struct PQNode *popNode(struct PQNode **head) {
  struct PQNode *min = *head;
  *head = (*head)->next;

  return min;
}

// Function to check if a priority queue is empty
int queueIsEmpty(struct PQNode **head) {
  return (*head == NULL);
}

// Function to build a Huffman Tree and to return its root
struct Node *buildHuffmanTree(char *data, int *freq, int size) {
  struct Node *left, *right, *top;

  // Create a priority queue and initialize it with all of the characters and their frequencies
  struct PQNode *head = NULL;
  for (int i = 0; i < size; i++) {
    insertNode(&head, newPQNode(newNode(data[i], freq[i]), freq[i]));
  }

  // While there is more than one node
  while (!queueIsEmpty(&head)) {

    // Pop the two nodes with the lowest frequency
    left = popNode(&head)->data;
    right = popNode(&head)->data;

    // Create a new parent node with an increased frequency
    top = newNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;

    // Insert the new node into the priority queue
    insertNode(&head, newPQNode(top, top->freq));
  }

  // The remaining node is the root node of the Huffman Tree
  return popNode(&head)->data;
}

// Function to print the codes of the characters
void printCodes(struct Node *root, int arr[], int top) {
  if (root->left) {
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }
  if (root->right) {
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }
  if (!(root->left) && !(root->right)) {
    printf("%c: ", root->data);
    for (int i = 0; i < top; i++) {
      printf("%d", arr[i]);
    }
    printf("\n");
  }
}

// Function to encode a string using the Huffman Tree
void encodeString(struct Node *root, char *str) {
  int n = strlen(str);
  int arr[MAX_TREE_HT], i;
  
  for (i = 0; i < n; i++) {
    int j = 0;
    struct Node *curr = root;
    while (curr->data != str[i]) {
      if (curr->left && strchr(curr->left->data, str[i])) {
        arr[j++] = 0;
        curr = curr->left;
      } else if (curr->right && strchr(curr->right->data, str[i])) {
        arr[j++] = 1;
        curr = curr->right;
      }
    }
    printf("%d", arr[j]);
  }
}

int main() {

  char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(data) / sizeof(data[0]);

  struct Node *root = buildHuffmanTree(data, freq, size);

  int arr[MAX_TREE_HT], top = 0;
  printCodes(root, arr, top);

  char str[] = "deadbeef";
  encodeString(root, str);

  return 0;
}