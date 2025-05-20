//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

struct node {
  int freq;
  char symbol;
  struct node *left;
  struct node *right;
};

struct queue {
  int size;
  int front;
  int rear;
  struct node **array;
};

struct node *new_node(int freq, char symbol) {
  struct node *node = malloc(sizeof(struct node));

  node->freq = freq;
  node->symbol = symbol;
  node->left = NULL;
  node->right = NULL;

  return node;
}

struct queue *create_queue(int size) {
  struct queue *queue = malloc(sizeof(struct queue));

  queue->size = size;
  queue->front = 0;
  queue->rear = -1;
  queue->array = malloc(size * sizeof(struct node *));

  return queue;
}

int is_full(struct queue *queue){
  return queue->rear == queue->size - 1;
}

int is_empty(struct queue *queue) {
  return queue->front == queue->rear + 1;
}

void enqueue(struct queue *queue, struct node *node) {
  if (is_full(queue)) {
    return;
  }

  queue->rear++;
  queue->array[queue->rear] = node;
}

struct node *dequeue(struct queue *queue) {
  if (is_empty(queue)) {
    return NULL;
  }

  struct node *node = queue->array[queue->front];
  queue->front++;

  return node;
}

void print_array(int *array, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", array[i]);
  }
  printf("\n");
}

void print_codes(struct node *root, int *array, int top) {
  if (root->left) {
    array[top] = 0;
    print_codes(root->left, array, top + 1);
  }

  if (root->right) {
    array[top] = 1;
    print_codes(root->right, array, top + 1);
  }

  if (!root->left && !root->right) {
    printf("%c:", root->symbol);
    print_array(array, top);
  }
}

void huffman_coding(int *freq, char *symbols, int size) {
  struct node *left;
  struct node *right;
  struct node *top;
  struct queue *queue = create_queue(size);

  for (int i = 0; i < size; i++) {
    enqueue(queue, new_node(freq[i], symbols[i]));
  }

  while (!is_empty(queue)) {
    left = dequeue(queue);
    right = dequeue(queue);

    top = new_node(left->freq + right->freq, '-');
    top->left = left;
    top->right = right;

    enqueue(queue, top);
  }

  int array[SIZE] = { 0 };
  print_codes(top, array, 0);
}

int main() {
  int freq[SIZE] = { 6, 13, 7, 21, 14, 1, 2, 5, 12, 3 };
  char symbols[SIZE] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

  huffman_coding(freq, symbols, SIZE);

  return 0;
}