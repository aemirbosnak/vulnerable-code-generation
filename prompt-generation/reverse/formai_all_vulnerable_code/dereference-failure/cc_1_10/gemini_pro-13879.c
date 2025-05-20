//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  char character;
  unsigned int frequency;
  struct _node *left;
  struct _node *right;
} node;

typedef struct _heap {
  node **nodes;
  unsigned int size;
} heap;

heap *create_heap(int size) {
  heap *new_heap = malloc(sizeof(heap));
  new_heap->nodes = malloc(sizeof(node *) * size);
  new_heap->size = size;
  return new_heap;
}

void insert_heap(heap *heap, node *new_node) {
  unsigned int i = heap->size++;
  while (i > 0 && heap->nodes[(i - 1) / 2]->frequency > new_node->frequency) {
    heap->nodes[i] = heap->nodes[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  heap->nodes[i] = new_node;
}

node *pop_heap(heap *heap) {
  node *return_node = heap->nodes[0];
  unsigned int i = 0;
  while (i < heap->size / 2) {
    unsigned int left = 2 * i + 1;
    unsigned int right = 2 * i + 2;
    if (left >= heap->size) {
      break;
    }
    unsigned int smaller_child = left;
    if (right < heap->size && heap->nodes[right]->frequency < heap->nodes[left]->frequency) {
      smaller_child = right;
    }
    if (heap->nodes[smaller_child]->frequency < heap->nodes[i]->frequency) {
      node *temp = heap->nodes[i];
      heap->nodes[i] = heap->nodes[smaller_child];
      heap->nodes[smaller_child] = temp;
      i = smaller_child;
    } else {
      break;
    }
  }
  heap->size--;
  return return_node;
}

node *create_node(char character, unsigned int frequency) {
  node *new_node = malloc(sizeof(node));
  new_node->character = character;
  new_node->frequency = frequency;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void print_codes(node *root, char *code) {
  if (root->left == NULL && root->right == NULL) {
    printf("%c: %s\n", root->character, code);
  } else {
    char left_code[strlen(code) + 1];
    char right_code[strlen(code) + 1];
    strcpy(left_code, code);
    strcpy(right_code, code);
    strcat(left_code, "0");
    strcat(right_code, "1");
    print_codes(root->left, left_code);
    print_codes(root->right, right_code);
  }
}

void free_heap(heap *heap) {
  for (unsigned int i = 0; i < heap->size; i++) {
    free(heap->nodes[i]);
  }
  free(heap->nodes);
  free(heap);
}

void free_tree(node *root) {
  if (root->left != NULL) {
    free_tree(root->left);
  }
  if (root->right != NULL) {
    free_tree(root->right);
  }
  free(root);
}

int main() {
  char *input = "Hello, world!";

  unsigned int frequency[256] = {0};

  for (unsigned int i = 0; i < strlen(input); i++) {
    frequency[input[i]]++;
  }

  heap *heap = create_heap(256);

  for (unsigned int i = 0; i < 256; i++) {
    if (frequency[i] > 0) {
      insert_heap(heap, create_node(i, frequency[i]));
    }
  }

  while (heap->size > 1) {
    node *left = pop_heap(heap);
    node *right = pop_heap(heap);
    node *new_node = create_node('\0', left->frequency + right->frequency);
    new_node->left = left;
    new_node->right = right;
    insert_heap(heap, new_node);
  }

  node *root = pop_heap(heap);
  free_heap(heap);

  char code[strlen(input) + 1];
  code[0] = '\0';

  print_codes(root, code);

  free_tree(root);

  return 0;
}