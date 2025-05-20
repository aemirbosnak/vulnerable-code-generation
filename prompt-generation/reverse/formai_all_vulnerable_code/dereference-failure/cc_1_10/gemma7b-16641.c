//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 200
#define MAX_COL 80

typedef struct Line {
  char **data;
  int len;
  struct Line *next;
} Line;

Line *head = NULL;

void add_line() {
  Line *new_line = malloc(sizeof(Line));
  new_line->data = malloc(MAX_COL * sizeof(char));
  new_line->len = 0;
  new_line->next = head;
  head = new_line;
}

void beautify() {
  int i, j, k, l, max_len = 0;
  Line *current = head;

  for (i = 0; current; i++) {
    l = current->len;
    if (l > max_len) {
      max_len = l;
    }
  }

  for (i = 0; current; i++) {
    for (j = 0; j < max_len; j++) {
      if (j < l) {
        printf("%c", current->data[j]);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  add_line();
  add_line();
  add_line();
  add_line();

  beautify();

  return 0;
}