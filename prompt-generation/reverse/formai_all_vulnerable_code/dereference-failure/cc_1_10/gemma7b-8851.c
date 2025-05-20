//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

Node *newNode(char *data) {
  Node *node = malloc(sizeof(Node));
  node->data = strdup(data);
  node->next = NULL;
  return node;
}

void summarize(Node *head) {
  char buffer[MAX_BUFFER_SIZE];
  int length = 0;
  Node *current = head;

  while (current) {
    int dataLength = strlen(current->data) + 1;
    if (length + dataLength > MAX_BUFFER_SIZE) {
      buffer[length - 1] = '\0';
      printf("%s\n", buffer);
      length = 0;
    }
    strcat(buffer, current->data);
    length += dataLength;
    current = current->next;
  }

  if (length > 0) {
    buffer[length - 1] = '\0';
    printf("%s\n", buffer);
  }
}

int main() {
  Node *head = newNode("This is the first text.");
  head->next = newNode("This is the second text.");
  head->next->next = newNode("This is the third text.");

  summarize(head);

  return 0;
}