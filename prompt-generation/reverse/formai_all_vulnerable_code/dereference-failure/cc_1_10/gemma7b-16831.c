//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 512

typedef struct Node {
  char data[MAX_BUFFER_SIZE];
  struct Node* next;
} Node;

Node* createNode(char* data) {
  Node* node = malloc(sizeof(Node));
  strcpy(node->data, data);
  node->next = NULL;
  return node;
}

void appendNode(Node* head, char* data) {
  Node* newNode = createNode(data);
  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
  head = newNode;
}

void summarizeText(Node* head) {
  char* summary = malloc(MAX_BUFFER_SIZE);
  int summaryLength = 0;
  Node* current = head;
  while (current) {
    char* sentence = current->data;
    int sentenceLength = strlen(sentence);
    if (sentenceLength > summaryLength) {
      summaryLength = sentenceLength;
      memcpy(summary, sentence, sentenceLength);
    }
    current = current->next;
  }

  printf("Summary:\n%s", summary);

  free(summary);
}

int main() {
  Node* head = NULL;
  appendNode(head, "This is a long text that will be summarized.");
  appendNode(head, "It contains many sentences, some short, some long.");
  appendNode(head, "The text is about a variety of topics, including science, technology, and literature.");
  summarizeText(head);

  return 0;
}