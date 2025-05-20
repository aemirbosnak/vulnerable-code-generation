//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 4096

typedef struct TextBlock {
  char *buffer;
  int size;
  struct TextBlock *next;
} TextBlock;

void insert_text_block(TextBlock **head, char *text, int text_size) {
  TextBlock *new_block = malloc(sizeof(TextBlock));
  new_block->buffer = malloc(text_size);
  new_block->size = text_size;
  new_block->next = NULL;

  strcpy(new_block->buffer, text);

  if (*head == NULL) {
    *head = new_block;
  } else {
    (*head)->next = new_block;
  }
}

void summarize_text(TextBlock *head) {
  int total_size = 0;
  char *summary = malloc(MAX_BUFFER_SIZE);
  summary[0] = '\0';

  for (TextBlock *block = head; block; block = block->next) {
    total_size += block->size;
    strcat(summary, block->buffer);
  }

  int summary_size = total_size / 5;
  summary[summary_size] = '\0';

  printf("%s", summary);
}

int main() {
  TextBlock *head = NULL;

  insert_text_block(&head, "This is the first text block.", 25);
  insert_text_block(&head, "This is the second text block.", 30);
  insert_text_block(&head, "This is the third text block.", 20);

  summarize_text(head);

  return 0;
}