//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char c;
  int freq;
  struct node *left, *right;
} node;

typedef struct heap {
  int size;
  node **arr;
} heap;

node *newnode(char c, int freq) {
  node *n = (node *)malloc(sizeof(node));
  n->c = c;
  n->freq = freq;
  n->left = n->right = NULL;
  return n;
}

heap *newheap(int size) {
  heap *h = (heap *)malloc(sizeof(heap));
  h->size = 0;
  h->arr = (node **)malloc(sizeof(node *) * size);
  return h;
}

void swap(node **a, node **b) {
  node *temp = *a;
  *a = *b;
  *b = temp;
}

void push(heap *h, node *n) {
  h->arr[h->size++] = n;
  int i = h->size - 1;
  while (i > 0 && h->arr[i]->freq < h->arr[(i - 1) / 2]->freq) {
    swap(&h->arr[i], &h->arr[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

node *pop(heap *h) {
  node *n = h->arr[0];
  h->arr[0] = h->arr[--(h->size)];
  int i = 0;
  while (i < h->size / 2) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int min = i;
    if (l < h->size && h->arr[l]->freq < h->arr[min]->freq) min = l;
    if (r < h->size && h->arr[r]->freq < h->arr[min]->freq) min = r;
    if (min != i) {
      swap(&h->arr[i], &h->arr[min]);
      i = min;
    } else
      break;
  }
  return n;
}

heap *buildheap(char *str, int n) {
  int i, freq[256] = {0};
  for (i = 0; i < n; i++) freq[str[i]]++;
  heap *h = newheap(n);
  for (i = 0; i < 256; i++)
    if (freq[i]) push(h, newnode(i, freq[i]));
  return h;
}

node *buildtree(heap *h) {
  while (h->size > 1) {
    node *l = pop(h);
    node *r = pop(h);
    node *n = newnode('$', l->freq + r->freq);
    n->left = l;
    n->right = r;
    push(h, n);
  }
  return pop(h);
}

void printcode(node *root, char *code, int n) {
  if (root->c) {
    printf("%c: %s\n", root->c, code);
    return;
  }
  printcode(root->left, strcat(code, "0"), n + 1);
  printcode(root->right, strcat(code, "1"), n + 1);
}

void encode(char *str, char *enc, int n) {
  heap *h = buildheap(str, n);
  node *root = buildtree(h);
  char code[n];
  code[n] = '\0';
  printcode(root, code, 0);
  int i, j = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < h->size; j++) {
      if (h->arr[j]->c == str[i]) {
        strcat(enc, code + j);
        break;
      }
    }
  }
}

void main() {
  char str[] = "GeeksforGeeks";
  int n = strlen(str);
  char enc[n * 8 + 1];
  encode(str, enc, n);
  printf("Encoded string: %s\n", enc);
}