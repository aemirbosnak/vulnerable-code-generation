//Gemma-7B DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

typedef struct Line {
  char **words;
  int num_words;
  struct Line *next;
} Line;

Line *add_line(Line **head) {
  Line *new_line = malloc(sizeof(Line));
  new_line->words = malloc(MAX_LINES * sizeof(char *));
  new_line->num_words = 0;
  new_line->next = NULL;

  if (*head) {
    (*head)->next = new_line;
  } else {
    *head = new_line;
  }

  return new_line;
}

int main() {
  Line *head = NULL;

  char line[MAX_LINES];

  printf("Enter a line: ");
  fgets(line, MAX_LINES, stdin);

  while (!feof(stdin)) {
    add_line(&head);
    printf("Enter a line: ");
    fgets(line, MAX_LINES, stdin);
  }

  Line *current = head;

  while (current) {
    printf("Line: ");
    for (int i = 0; i < current->num_words; i++) {
      printf("%s ", current->words[i]);
    }
    printf("\n");
    current = current->next;
  }

  return 0;
}