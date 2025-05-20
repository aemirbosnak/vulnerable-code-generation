//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
  char **data;
  struct Node *next;
} Node;

void insert(Node **head, char **text) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = malloc(MAX * sizeof(char *));
  newNode->next = NULL;

  for (int i = 0; text[i] != '\0'; i++) {
    newNode->data[i] = &text[i];
  }

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void summarize(Node *head) {
  int count = 0;
  char **summary = malloc(MAX * sizeof(char *));

  for (Node *current = head; current; current = current->next) {
    for (int i = 0; current->data[i] != '\0'; i++) {
      summary[count++] = current->data[i];
    }
  }

  printf("%s", summary);
  free(summary);
}

int main() {
  Node *head = NULL;

  char **text = malloc(MAX * sizeof(char *));
  text[0] = "This is a text to be summarized.";
  text[1] = "It is a long text with many words.";
  text[2] = "The text is divided into sentences.";

  insert(&head, text);

  summarize(head);

  free(text);
  free(head);

  return 0;
}