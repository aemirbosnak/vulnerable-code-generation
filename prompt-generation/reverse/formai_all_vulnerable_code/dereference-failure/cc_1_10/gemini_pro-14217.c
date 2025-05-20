//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: Romeo and Juliet
// Romeo and Juliet in Huffman Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    int freq;
    struct node *left;
    struct node *right;
} node;

node* create_node(char data, int freq) {
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->freq = freq;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void swap_nodes(node** a, node** b) {
  node* temp = *a;
  *a = *b;
  *b = temp;
}

void min_heapify(node** heap, int size, int i) {
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < size && heap[left]->freq < heap[smallest]->freq) {
    smallest = left;
  }
  if (right < size && heap[right]->freq < heap[smallest]->freq) {
    smallest = right;
  }
  if (smallest != i) {
    swap_nodes(&heap[i], &heap[smallest]);
    min_heapify(heap, size, smallest);
  }
}

node* extract_min(node** heap, int* size) {
  node* min = heap[0];
  heap[0] = heap[*size - 1];
  *size = *size - 1;
  min_heapify(heap, *size, 0);
  return min;
}

void insert_node(node** heap, int* size, node* new_node) {
  int i = *size;
  heap[*size] = new_node;
  *size = *size + 1;
  while (i > 0 && heap[(i - 1) / 2]->freq > heap[i]->freq) {
    swap_nodes(&heap[(i - 1) / 2], &heap[i]);
    i = (i - 1) / 2;
  }
}

node* build_huffman_tree(char* data, int* freq, int size) {
  node** heap = (node**)malloc(sizeof(node*) * size);
  int heap_size = 0;

  for (int i = 0; i < size; i++) {
    insert_node(heap, &heap_size, create_node(data[i], freq[i]));
  }

  while (heap_size > 1) {
    node* left = extract_min(heap, &heap_size);
    node* right = extract_min(heap, &heap_size);

    node* new_node = create_node(' ', left->freq + right->freq);
    new_node->left = left;
    new_node->right = right;

    insert_node(heap, &heap_size, new_node);
  }

  return extract_min(heap, &heap_size);
}

void print_codes(node* root, char* code, int top) {
  if (root->left == NULL && root->right == NULL) {
    printf("%c: %s\n", root->data, code);
    return;
  }

  print_codes(root->left, strcat(code, "0"), top + 1);
  print_codes(root->right, strcat(code, "1"), top + 1);
}

void huffman_encoding(char* data, int* freq, int size) {
  node* root = build_huffman_tree(data, freq, size);

  char code[100];
  code[0] = '\0';

  print_codes(root, code, 0);
}

int main() {
  char data[] = "Romeo and Juliet";
  int freq[] = {6, 5, 4, 3, 2, 2, 1};
  int size = sizeof(data) / sizeof(data[0]);

  huffman_encoding(data, freq, size);

  return 0;
}