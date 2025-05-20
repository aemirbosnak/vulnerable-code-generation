//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: expert-level
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

  // Create a linked list to store the unique characters
  while (str[i] != '\0') {
    char currentChar = str[i];
    Node* newNode = malloc(sizeof(Node));
    newNode->data = currentChar;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    i++;
  }

  // Calculate the number of unique characters
  int numUniqueChars = tail->next == NULL ? 1 : tail->next->next == NULL ? 2 : tail->next->next->next == NULL ? 3 : 0;

  // Compress the string
  char compressedStr[MAX_BUFFER_SIZE];
  int j = 0;
  sprintf(compressedStr, "%c%d", head->data, numUniqueChars);
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == head->data) {
      compressedStr[j++] = str[i] - head->data + 'a';
    } else {
      compressedStr[j++] = str[i];
    }
  }

  // Print the compressed string
  printf("%s", compressedStr);
}

int main() {
  char str[] = "aabbbbcccc";
  compress(str);

  return 0;
}