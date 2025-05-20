//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct Compress {
  Node* head;
  int size;
  int (*compress)(char*, int);
  int (*decompress)(char*, int);
} Compress;

Compress* compress_init(int size) {
  Compress* comp = malloc(sizeof(Compress));
  comp->head = NULL;
  comp->size = size;
  comp->compress = NULL;
  comp->decompress = NULL;
  return comp;
}

void compress_add(Compress* comp, char data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = comp->head;
  comp->head = node;
  comp->size++;
}

int compress(Compress* comp, char* buffer, int buffer_size) {
  int i = 0;
  for (; i < buffer_size && comp->head; i++) {
    buffer[i] = comp->head->data;
    comp->head = comp->head->next;
  }
  return i;
}

int decompress(Compress* comp, char* buffer, int buffer_size) {
  int i = 0;
  for (; i < buffer_size && comp->head; i++) {
    buffer[i] = comp->head->data;
    comp->head = comp->head->next;
  }
  return i;
}

int main() {
  Compress* comp = compress_init(10);
  compress_add(comp, 'a');
  compress_add(comp, 'b');
  compress_add(comp, 'c');
  compress_add(comp, 'd');

  char* buffer = malloc(MAX_BUFFER_SIZE);
  int buffer_size = compress(comp, buffer, MAX_BUFFER_SIZE);

  printf("Compressed size: %d\n", buffer_size);

  int decompressed_size = decompress(comp, buffer, MAX_BUFFER_SIZE);

  printf("Decompressed size: %d\n", decompressed_size);

  return 0;
}