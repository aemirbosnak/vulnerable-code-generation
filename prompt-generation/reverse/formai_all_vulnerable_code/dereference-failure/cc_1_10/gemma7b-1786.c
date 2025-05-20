//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define MAX_STRING_LENGTH 1024

typedef struct HashNode {
  char *data;
  struct HashNode *next;
} HashNode;

HashNode *insert(HashNode *head, char *data) {
  HashNode *newNode = malloc(sizeof(HashNode));
  newNode->data = strdup(data);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    HashNode *traversal = head;
    while (traversal->next) {
      traversal = traversal->next;
    }
    traversal->next = newNode;
  }

  return head;
}

int hashFunction(char *data) {
  int hashValue = 0;
  for (int i = 0; data[i] != '\0'; i++) {
    hashValue += (int) data[i] * i;
  }

  return hashValue;
}

int main() {
  char *testStr = "This is a string to hash!";
  HashNode *head = insert(NULL, testStr);

  int hashValue = hashFunction(testStr);
  printf("Hash value for string: %s is %d\n", testStr, hashValue);

  return 0;
}