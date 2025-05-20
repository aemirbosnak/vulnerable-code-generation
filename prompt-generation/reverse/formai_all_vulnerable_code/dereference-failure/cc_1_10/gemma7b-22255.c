//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
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
  int i = 0;
  char currentChar = str[i];
  int frequency = 1;

  for (i = 1; str[i] != '\0'; i++) {
    if (str[i] == currentChar) {
      frequency++;
    } else {
      if (head == NULL) {
        head = malloc(sizeof(Node));
        head->data = currentChar;
        head->next = NULL;
      } else {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = currentChar;
        newNode->next = NULL;
        head->next = newNode;
      }

      currentChar = str[i];
      frequency = 1;
    }
  }

  char* compressedStr = malloc(MAX_BUFFER_SIZE);
  int j = 0;

  for (Node* node = head; node; node = node->next) {
    compressedStr[j++] = node->data;
    if (frequency > 1) {
      compressedStr[j++] = (char)frequency - 1;
    }
  }

  compressedStr[j] = '\0';

  printf("%s", compressedStr);
}

int main() {
  char str[] = "aabbbbcccc";
  compress(str);

  return 0;
}