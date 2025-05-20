//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char **data;
  struct Node *next;
} Node;

void free_node(Node *node) {
  free(node->data);
  free(node);
}

void summarize(char **text, int text_length) {
  Node *head = NULL;
  for (int i = 0; i < text_length; i++) {
    char **new_data = malloc(sizeof(char *) * 10);
    new_data[0] = text[i];
    Node *new_node = malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
  }

  head = head->next;
  while (head) {
    char **summary = malloc(sizeof(char *) * 20);
    int summary_length = 0;
    for (int j = 0; head->data[j] != NULL; j++) {
      summary[summary_length++] = head->data[j];
    }
    summary[summary_length] = '\0';

    printf("%s\n", summary);
    free(summary);
    free_node(head);
    head = head->next;
  }
}

int main() {
  char **text = malloc(sizeof(char *) * 100);
  text[0] = "This is a long text that needs to be summarized.";
  text[1] = "It is a very long text, but I will summarize it for you.";

  summarize(text, 2);

  free(text);

  return 0;
}