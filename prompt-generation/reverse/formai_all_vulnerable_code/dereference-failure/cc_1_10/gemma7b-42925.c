//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

Node *insertAtTail(Node *head, char *data) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = malloc(MAX_BUFFER_SIZE);
  strcpy(newNode->data, data);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

char *summaries(Node *head) {
  char *summary = malloc(MAX_BUFFER_SIZE);
  strcpy(summary, "");

  Node *currNode = head;

  while (currNode) {
    char *data = currNode->data;
    char *summaryPtr = summaries(head);

    if (strlen(summaryPtr) > 0) {
      strcat(summaryPtr, ", ");
    }

    strcat(summaryPtr, data);
    currNode = currNode->next;
  }

  return summary;
}

int main() {
  Node *head = NULL;
  insertAtTail(head, "This is the first text.");
  insertAtTail(head, "This is the second text.");
  insertAtTail(head, "This is the third text.");

  char *summary = summaries(head);

  printf("Summary: %s\n", summary);

  free(summary);
  free(head);

  return 0;
}