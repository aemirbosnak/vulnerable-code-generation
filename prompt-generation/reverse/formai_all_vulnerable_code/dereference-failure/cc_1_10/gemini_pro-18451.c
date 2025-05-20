//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 256

typedef struct node {
  char *sentence;
  struct node *next;
} node;

node *insert_sentence(node *head, char *sentence) {
  node *new_node = malloc(sizeof(node));
  new_node->sentence = strdup(sentence);
  new_node->next = head;
  return new_node;
}

void print_summary(node *head, int num_sentences) {
  if (head == NULL || num_sentences == 0) {
    return;
  }

  printf("%s\n", head->sentence);
  print_summary(head->next, num_sentences - 1);
}

int main() {
  // Get the input text.
  char *text = malloc(sizeof(char) * 1000);
  printf("Enter a text: ");
  fgets(text, 1000, stdin);

  // Tokenize the text into sentences.
  node *head = NULL;
  char *sentence;
  while ((sentence = strtok(text, ".!?")) != NULL) {
    head = insert_sentence(head, sentence);
    text = NULL;
  }

  // Get the number of sentences to summarize.
  int num_sentences;
  printf("How many sentences would you like to summarize? ");
  scanf("%d", &num_sentences);

  // Print the summary.
  print_summary(head, num_sentences);

  // Free the memory allocated for the text and the linked list.
  free(text);
  while (head != NULL) {
    node *next_head = head->next;
    free(head->sentence);
    free(head);
    head = next_head;
  }

  return 0;
}