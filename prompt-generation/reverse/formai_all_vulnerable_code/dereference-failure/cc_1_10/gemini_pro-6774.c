//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char c;
  int freq;
  struct node *left, *right;
} node;

typedef struct queue {
  node *data;
  struct queue *next;
} queue;

queue *enqueue(queue *q, node *n) {
  queue *new = malloc(sizeof(queue));
  new->data = n;
  new->next = NULL;
  if (!q)
    return new;
  queue *p = q;
  while (p->next)
    p = p->next;
  p->next = new;
  return q;
}

node *dequeue(queue **q) {
  if (!(*q))
    return NULL;
  queue *p = *q;
  *q = (*q)->next;
  node *n = p->data;
  free(p);
  return n;
}

int compare(const void *a, const void *b) {
  node *n1 = *(node **)a, *n2 = *(node **)b;
  return n1->freq - n2->freq;
}

node *build_tree(char *s) {
  int freq[256] = {0};
  for (char *p = s; *p; p++)
    freq[*p]++;
  queue *q = NULL;
  for (int i = 0; i < 256; i++)
    if (freq[i]) {
      node *n = malloc(sizeof(node));
      n->c = i;
      n->freq = freq[i];
      n->left = n->right = NULL;
      q = enqueue(q, n);
    }
  while (q->next) {
    node *n1 = dequeue(&q);
    node *n2 = dequeue(&q);
    node *n = malloc(sizeof(node));
    n->c = '\0';
    n->freq = n1->freq + n2->freq;
    n->left = n1;
    n->right = n2;
    q = enqueue(q, n);
  }
  return dequeue(&q);
}

void print_code(node *n, char *code) {
  if (!n)
    return;
  if (n->c) {
    printf("%c: %s\n", n->c, code);
    return;
  }
  char lcode[strlen(code) + 2], rcode[strlen(code) + 2];
  strcpy(lcode, code);
  strcpy(rcode, code);
  strcat(lcode, "0");
  strcat(rcode, "1");
  print_code(n->left, lcode);
  print_code(n->right, rcode);
}

void encode(node *root, char *s, char *encoded) {
  for (char *p = s; *p; p++) {
    node *n = root;
    char *code = "";
    while (n->c != *p) {
      if (*p < n->c)
        strcat(code, "0");
      else
        strcat(code, "1");
      n = *p < n->c ? n->left : n->right;
    }
    strcat(encoded, code);
  }
}

char *decode(node *root, char *encoded) {
  char *decoded = malloc(strlen(encoded) + 1);
  node *n = root;
  for (char *p = encoded; *p; p++) {
    if (*p == '0')
      n = n->left;
    else
      n = n->right;
    if (n->c) {
      *decoded++ = n->c;
      n = root;
    }
  }
  *decoded = '\0';
  return decoded - strlen(decoded);
}

int main() {
  char *s = "Hello, world!";
  node *root = build_tree(s);
  char code[strlen(s) * 8 + 1];
  encode(root, s, code);
  printf("Encoded: %s\n", code);
  char *decoded = decode(root, code);
  printf("Decoded: %s\n", decoded);
  return 0;
}