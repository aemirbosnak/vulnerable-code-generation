//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: optimized
#include <stdio.h>
#include <stdint.h>

#define HASH_SIZE 1024

typedef struct HashNode {
  uint32_t key;
  struct HashNode* next;
} HashNode;

HashNode* hash_insert(HashNode* head, uint32_t key) {
  HashNode* newNode = malloc(sizeof(HashNode));
  newNode->key = key;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    HashNode* traverse = head;
    while (traverse->next) {
      if (traverse->key == key) {
        return NULL;
      }
      traverse = traverse->next;
    }
    traverse->next = newNode;
  }

  return head;
}

uint32_t hash_checksum(HashNode* head) {
  uint32_t checksum = 0;
  HashNode* traverse = head;

  while (traverse) {
    checksum += traverse->key;
    traverse = traverse->next;
  }

  return checksum;
}

int main() {
  HashNode* head = NULL;
  head = hash_insert(head, 10);
  head = hash_insert(head, 20);
  head = hash_insert(head, 30);
  head = hash_insert(head, 40);

  uint32_t checksum = hash_checksum(head);
  printf("Checksum: %d\n", checksum);

  return 0;
}