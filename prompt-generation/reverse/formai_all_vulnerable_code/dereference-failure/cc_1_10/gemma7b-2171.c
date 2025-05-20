//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 1024
#define MAX_COL 80

typedef struct Line {
  char **data;
  int length;
  struct Line *next;
} Line;

Line *createLine(int length) {
  Line *line = malloc(sizeof(Line));
  line->data = malloc(sizeof(char *) * length);
  line->length = length;
  line->next = NULL;
  return line;
}

void addWord(Line *line, char *word) {
  line->data[line->length++] = strdup(word);
}

void formatLines(Line *lines) {
  for (Line *line = lines; line; line = line->next) {
    int maxLen = 0;
    for (int i = 0; line->data[i]; i++) {
      int len = strlen(line->data[i]);
      if (len > maxLen) {
        maxLen = len;
      }
    }

    for (int i = 0; line->data[i]; i++) {
      int padding = maxLen - strlen(line->data[i]);
      for (int j = 0; j < padding; j++) {
        line->data[i] = strcat(line->data[i], " ");
      }
    }
  }
}

int main() {
  Line *lines = createLine(MAX_LINES);
  addWord(lines, "Hello, world!");
  addWord(lines, "This is a long sentence that will be formatted.");
  addWord(lines, "It has many words and will be wrapped to the specified column width.");

  formatLines(lines);

  for (Line *line = lines; line; line = line->next) {
    printf("%s\n", line->data[0]);
  }

  return 0;
}