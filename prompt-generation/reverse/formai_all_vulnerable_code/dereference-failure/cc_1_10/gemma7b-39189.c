//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STASH 256

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct Stash {
  Node** stash;
  int top;
} Stash;

Stash* stash_new() {
  Stash* stash = malloc(sizeof(Stash));
  stash->stash = malloc(MAX_STASH * sizeof(Node));
  stash->top = 0;
  return stash;
}

void stash_push(Stash* stash, char data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;

  if (stash->top == MAX_STASH - 1) {
    printf("Error: stash is full!\n");
    exit(1);
  }

  stash->stash[stash->top++] = node;
}

int stash_pop(Stash* stash) {
  if (stash->top == 0) {
    printf("Error: stash is empty!\n");
    exit(1);
  }

  int data = stash->stash[stash->top - 1]->data;
  free(stash->stash[stash->top - 1]);
  stash->top--;
  return data;
}

int main() {
  Stash* stash = stash_new();

  // Encode the secret message "Donald Knuth is the best!"
  stash_push(stash, 'D');
  stash_push(stash, 'o');
  stash_push(stash, 'n');
  stash_push(stash, 'a');
  stash_push(stash, 'ld');
  stash_push(stash, 'K');
  stash_push(stash, 'n');
  stash_push(stash, 'uth');
  stash_push(stash, 'i');
  stash_push(stash, 's');
  stash_push(stash, 'the');
  stash_push(stash, 'best');
  stash_push(stash, '!');

  // Decode the secret message
  for (int i = 0; i < stash->top; i++) {
    printf("%c", stash_pop(stash));
  }

  printf("\n");

  return 0;
}