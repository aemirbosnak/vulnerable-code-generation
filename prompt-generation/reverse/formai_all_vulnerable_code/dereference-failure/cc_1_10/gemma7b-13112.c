//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX_SIZE 1024

typedef struct IndexNode {
  int key;
  struct IndexNode* next;
} IndexNode;

IndexNode* insertIndexNode(IndexNode* head, int key) {
  IndexNode* newNode = (IndexNode*)malloc(sizeof(IndexNode));
  newNode->key = key;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    IndexNode* tempNode = head;
    while (tempNode->next != NULL) {
      tempNode = tempNode->next;
    }
    tempNode->next = newNode;
  }

  return head;
}

int searchIndexNode(IndexNode* head, int key) {
  IndexNode* tempNode = head;
  while (tempNode) {
    if (tempNode->key == key) {
      return 1;
    }
    tempNode = tempNode->next;
  }

  return 0;
}

int main() {
  IndexNode* indexHead = NULL;

  insertIndexNode(indexHead, 10);
  insertIndexNode(indexHead, 20);
  insertIndexNode(indexHead, 30);
  insertIndexNode(indexHead, 40);
  insertIndexNode(indexHead, 50);

  if (searchIndexNode(indexHead, 20) == 1) {
    printf("Key found!\n");
  }

  return 0;
}