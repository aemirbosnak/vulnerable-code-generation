//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

typedef struct Line {
  char *text;
  struct Line *next;
} Line;

Line *head = NULL;

void insert_line(char *text) {
  Line *new_line = malloc(sizeof(Line));
  new_line->text = strdup(text);
  new_line->next = NULL;

  if (head == NULL) {
    head = new_line;
  } else {
    head->next = new_line;
  }
}

void beautify() {
  Line *current = head;
  while (current) {
    char *line = current->text;
    int i = 0;
    for (; line[i] != '\0'; i++) {
      if (line[i] == '\t') {
        line[i] = ' ';
      }
    }
    current = current->next;
  }
}

int main() {
  insert_line("This is the first line.\n");
  insert_line("This is the second line.\n");
  insert_line("This is the third line with\ta tab.\n");

  beautify();

  Line *current = head;
  while (current) {
    printf("%s", current->text);
  }

  return 0;
}