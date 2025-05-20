//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct HashNode {
  char key[BUFFER_SIZE];
  struct HashNode* next;
} HashNode;

HashNode* insertNode(HashNode* head, char* key) {
  HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
  strcpy(newNode->key, key);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    HashNode* traverse = head;
    while (traverse->next) {
      traverse = traverse->next;
    }
    traverse->next = newNode;
  }

  return head;
}

int calculateChecksum(char* data, int dataLen) {
  int checksum = 0;
  for (int i = 0; i < dataLen; i++) {
    checksum += data[i];
  }

  return checksum;
}

int main() {
  HashNode* hashTable = NULL;

  // Insert keys into the hash table
  insertNode(hashTable, "abc");
  insertNode(hashTable, "def");
  insertNode(hashTable, "ghi");

  // Calculate checksum of a string
  char* data = "hello";
  int dataLen = strlen(data);
  int checksum = calculateChecksum(data, dataLen);

  // Print the checksum
  printf("Checksum: %d", checksum);

  return 0;
}