//Gemma-7B DATASET v1.0 Category: Cryptography Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

typedef struct Block {
  int data[BLOCK_SIZE];
  struct Block* next;
} Block;

void encrypt_block(Block* block, int key[]) {
  for (int i = 0; i < BLOCK_SIZE; i++) {
    block->data[i] ^= key[i % KEY_SIZE];
  }
}

void encrypt_message(char* message, int key[]) {
  Block* head = NULL;
  char* p = message;

  while (*p) {
    Block* new_block = malloc(sizeof(Block));
    new_block->next = head;
    head = new_block;

    int block_size = 0;
    for (int i = 0; i < BLOCK_SIZE && *p; i++) {
      new_block->data[i] = (int)*p;
      p++;
      block_size++;
    }

    encrypt_block(head, key);

    if (block_size < BLOCK_SIZE) {
      memset(new_block->data + block_size, 0, BLOCK_SIZE - block_size);
    }
  }

  free(head);
}

int main() {
  int key[] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xFF,
    0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xFF};

  char message[] = "Hello, world!";

  encrypt_message(message, key);

  printf("%s\n", message);

  return 0;
}