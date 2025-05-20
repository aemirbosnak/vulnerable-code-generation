//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char data;
  int freq;
  struct node *left;
  struct node *right;
} node;

typedef struct min_heap {
  int size;
  node *arr[100];
} min_heap;

void swap(node **a, node **b) {
  node *temp = *a;
  *a = *b;
  *b = temp;
}

void insert_heap(min_heap *heap, node *new_node) {
  int i = heap->size++;
  heap->arr[i] = new_node;

  while (i && heap->arr[(i - 1) / 2]->freq > heap->arr[i]->freq) {
    swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

node *delete_min(min_heap *heap) {
  if (heap->size == 0) return NULL;
  node *root = heap->arr[0];
  heap->arr[0] = heap->arr[--(heap->size)];
  int i = 0;
  while (i < heap->size) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heap->size && heap->arr[left]->freq < heap->arr[i]->freq) i = left;
    if (right < heap->size && heap->arr[right]->freq < heap->arr[i]->freq) i = right;
    if (i == left || i == right) swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
    else
      break;
  }
  return root;
}

void build_heap(min_heap *heap) {
  for (int i = heap->size / 2 - 1; i >= 0; i--) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heap->size && heap->arr[left]->freq < heap->arr[i]->freq) i = left;
    if (right < heap->size && heap->arr[right]->freq < heap->arr[i]->freq) i = right;
    if (i == left || i == right) swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
  }
}

void print_codes(node *root, char *code) {
  if (root->left) {
    code[strlen(code)] = '0';
    print_codes(root->left, code);
  }
  if (root->right) {
    code[strlen(code)] = '1';
    print_codes(root->right, code);
  }
  if (!root->left && !root->right) printf("%c: %s\n", root->data, code);
}

void huffman_encoding(char *text) {
  int freq[256] = {0};
  for (int i = 0; text[i]; i++) freq[text[i]]++;

  min_heap heap = {0};
  for (int i = 0; i < 256; i++) {
    if (freq[i] > 0) {
      node *new_node = malloc(sizeof(node));
      new_node->data = i;
      new_node->freq = freq[i];
      new_node->left = new_node->right = NULL;
      insert_heap(&heap, new_node);
    }
  }
  build_heap(&heap);

  while (heap.size > 1) {
    node *left = delete_min(&heap);
    node *right = delete_min(&heap);
    node *new_node = malloc(sizeof(node));
    new_node->data = '$';
    new_node->freq = left->freq + right->freq;
    new_node->left = left;
    new_node->right = right;
    insert_heap(&heap, new_node);
  }

  char code[100];
  code[0] = '\0';
  print_codes(heap.arr[0], code);
}

int main() {
  char text[] = "Huffman coding is a lossless data compression algorithm";
  huffman_encoding(text);
  return 0;
}