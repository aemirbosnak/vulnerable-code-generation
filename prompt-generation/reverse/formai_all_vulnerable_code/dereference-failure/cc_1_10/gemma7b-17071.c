//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void compress(char* str) {
  Node* head = NULL;
  Node* tail = NULL;
  int i = 0;

  for (; str[i] != '\0'; i++) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = str[i];
    newNode->next = NULL;

    if (head == NULL) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  int count = 0;
  char* compressedStr = malloc(MAX_BUFFER_SIZE);

  for (head = head->next; head != NULL; head = head->next) {
    char repeated = 1;
    for (Node* current = head->next; current != NULL && current->data == head->data; current = current->next) {
      repeated++;
    }

    compressedStr[count++] = head->data;
    if (repeated > 1) {
      sprintf(compressedStr + count, "%d", repeated);
      count += 2;
    }
  }

  printf("%s", compressedStr);
}

int main() {
  char str[] = "aabbbbcccc";
  compress(str);

  return 0;
}