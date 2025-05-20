//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

/* Define the Huffman Node structure */
struct HuffmanNode {
  char data;
  int frequency;
  struct HuffmanNode *left;
  struct HuffmanNode *right;
};

/* Define a new type for the Huffman Node */
typedef struct HuffmanNode HuffmanNode;

/* Define a new type for an array of Huffman Nodes */
typedef HuffmanNode* HuffmanNodeArray;

/* Define a new type for the Huffman Tree */
typedef struct HuffmanTree {
  HuffmanNode *root;
} HuffmanTree;

/* Define a new type for the Huffman Code */
typedef struct HuffmanCode {
  char data;
  char *code;
} HuffmanCode;

/* Define a new type for an array of Huffman Codes */
typedef HuffmanCode* HuffmanCodeArray;

/* Define function prototypes */
HuffmanNodeArray countFrequencies(const char *text);
void sortHuffmanNodes(HuffmanNodeArray nodes, int length);
void printHuffmanNodes(HuffmanNodeArray nodes, int length);
HuffmanNode* generateHuffmanTree(HuffmanNodeArray nodes, int length);
void traverseHuffmanTree(HuffmanTree tree, HuffmanCodeArray codes, char *code, int depth);
void printHuffmanCodes(HuffmanCodeArray codes, int length);

/* Define the main function */
int main() {
  const char *text = "hello world, how are you today?";
  HuffmanNodeArray nodes = countFrequencies(text);
  sortHuffmanNodes(nodes, strlen(text));
  printHuffmanNodes(nodes, strlen(text));
  HuffmanNode *root = generateHuffmanTree(nodes, strlen(text));
  HuffmanTree tree = { root };
  HuffmanCodeArray codes = calloc(256, sizeof(HuffmanCode));
  char code[256];
  code[0] = '\0';
  traverseHuffmanTree(tree, codes, code, 0);
  printHuffmanCodes(codes, 256);
  free(nodes);
  free(codes);

  return 0;
}

/* Count the frequency of each character in the given text */
HuffmanNodeArray countFrequencies(const char *text) {
  /* Create an array to store the frequency of each character */
  int frequencies[256] = { 0 };
  
  /* Count the frequency of each character in the text */
  const char *p = text;
  while(*p != '\0') {
    frequencies[*p]++;
    p++;
  }
  
  /* Create an array of Huffman Nodes with the frequency and data */
  HuffmanNodeArray nodes = calloc(256, sizeof(HuffmanNode));
  for(int i = 0; i < 256; i++) {
    nodes[i] = (HuffmanNode){ i, frequencies[i], NULL, NULL };
  }
  
  return nodes;
}

/* Sort the array of Huffman Nodes by frequency */
void sortHuffmanNodes(HuffmanNodeArray nodes, int length) {
  /* Sort the array of Huffman Nodes by frequency using a bubble sort algorithm */
  for(int i = 0; i < length - 1; i++) {
    for(int j = 0; j < length - i - 1; j++) {
      if(nodes[j].frequency > nodes[j + 1].frequency) {
        HuffmanNode temp = nodes[j];
        nodes[j] = nodes[j + 1];
        nodes[j + 1] = temp;
      }
    }
  }
}

/* Print the array of Huffman Nodes */
void printHuffmanNodes(HuffmanNodeArray nodes, int length) {
  printf("Huffman Nodes:\n");
  for(int i = 0; i < length; i++) {
    printf("  [%c]: %d\n", nodes[i].data, nodes[i].frequency);
  }
}

/* Generate the Huffman Tree from the array of Huffman Nodes */
HuffmanNode* generateHuffmanTree(HuffmanNodeArray nodes, int length) {
  /* Create an array of Huffman Nodes for the Huffman Tree */
  HuffmanNodeArray treeNodes = calloc(length, sizeof(HuffmanNode));
  for(int i = 0; i < length; i++) {
    treeNodes[i] = nodes[i];
  }

  /* Generate the Huffman Tree using a greedy algorithm */
  int treeLength = length;
  while(treeLength > 1) {
    /* Remove the two smallest nodes from the array */
    HuffmanNode left = treeNodes[0];
    HuffmanNode right = treeNodes[1];
    treeLength -= 1;
    for(int i = 0; i < treeLength; i++) {
      treeNodes[i] = treeNodes[i + 2];
    }

    /* Create the new parent node with the sum of the children's frequencies */
    HuffmanNode parent = { '\0', left.frequency + right.frequency, &left, &right };

    /* Insert the new parent node into the array in the correct position */
    int insertIndex = 0;
    while(insertIndex < treeLength && parent.frequency > treeNodes[insertIndex].frequency) {
      insertIndex++;
    }
    for(int i = treeLength; i > insertIndex; i--) {
      treeNodes[i] = treeNodes[i - 1];
    }
    treeNodes[insertIndex] = parent;
    treeLength++;
  }

  /* Return the root of the Huffman Tree */
  return &treeNodes[0];
}

/* Traverse the Huffman Tree to generate each Huffman Code */
void traverseHuffmanTree(HuffmanTree tree, HuffmanCodeArray codes, char *code, int depth) {
  /* Check if the current node is a leaf node */
  if(tree.root->left == NULL && tree.root->right == NULL) {
    /* Add the Huffman Code to the array of Huffman Codes */
    HuffmanCode hc = { tree.root->data, strdup(code) };
    codes[tree.root->data] = hc;

    return;
  }

  /* Traverse the left child */
  code[depth] = '0';
  code[depth + 1] = '\0';
  traverseHuffmanTree((HuffmanTree){ tree.root->left }, codes, code, depth + 1);

  /* Traverse the right child */
  code[depth] = '1';
  code[depth + 1] = '\0';
  traverseHuffmanTree((HuffmanTree){ tree.root->right }, codes, code, depth + 1);
}

/* Print the array of Huffman Codes */
void printHuffmanCodes(HuffmanCodeArray codes, int length) {
  printf("Huffman Codes:\n");
  for(int i = 0; i < length; i++) {
    if(codes[i].data != '\0') {
      printf("  [%c]: %s\n", codes[i].data, codes[i].code);
    }
  }
}