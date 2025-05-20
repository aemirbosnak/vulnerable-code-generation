//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char symbol;
  int frequency;
} Node;

typedef struct tNode {
  struct tNode *left, *right;
  Node node;
} TreeNode;

typedef struct {
  TreeNode *root;
  int size;
} Tree;

void swap(Node *a, Node *b) {
  Node temp = *a;
  *a = *b;
  *b = temp;
}

void sort(Node nodes[], int n) {
  for (int i = 1; i < n; i++) {
    Node key = nodes[i];
    int j = i - 1;
    while (j >= 0 && key.frequency < nodes[j].frequency) {
      nodes[j + 1] = nodes[j];
      j--;
    }
    nodes[j + 1] = key;
  }
}

Tree *createTree(Node nodes[], int n) {
  Tree *tree = (Tree *)malloc(sizeof(Tree));
  tree->root = NULL;
  tree->size = n;
  if (n == 1) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->left = node->right = NULL;
    node->node = nodes[0];
    tree->root = node;
    return tree;
  }
  while (n > 1) {
    TreeNode *left = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *right = (TreeNode *)malloc(sizeof(TreeNode));
    left->left = left->right = NULL;
    right->left = right->right = NULL;
    left->node = nodes[0];
    right->node = nodes[1];
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->node.symbol = '\0';
    node->node.frequency = left->node.frequency + right->node.frequency;
    node->left = left;
    node->right = right;
    nodes[0] = node->node;
    nodes[1] = nodes[n - 1];
    n--;
    sort(nodes, n);
  }
  return tree;
}

void printCodes(TreeNode *node, char code[]) {
  if (node->left == node->right) {
    printf("'%c': %s\n", node->node.symbol, code);
    return;
  }
  strcpy(code, strcat(code, "0"));
  printCodes(node->left, code);
  strcpy(code, strcat(code, "1"));
  printCodes(node->right, code);
  code[strlen(code) - 1] = '\0';
}

int main() {
  Node nodes[] = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
  int n = sizeof(nodes) / sizeof(nodes[0]);
  sort(nodes, n);
  Tree *tree = createTree(nodes, n);
  printf("\nHuffman Codes:\n");
  char code[100];
  printCodes(tree->root, "");
  return 0;
}