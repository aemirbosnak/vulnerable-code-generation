//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 4

void html_beautify(char *input) {
  char *output = malloc(strlen(input) * 2);
  char *line = output;
  char *current = input;
  char *previous = NULL;
  int indent = 0;

  while (*current != '\0') {
    if (*current == '<') {
      if (previous == NULL || previous[0] != '/') {
        if (indent > MAX_INDENT) {
          indent = 0;
        }
        *line++ = '<';
        *line++ = *current++;
      } else {
        *line++ = '/';
        *line++ = *current++;
      }
    } else if (*current == '>') {
      if (indent > 0) {
        indent--;
      }
      *line++ = '>';
      *line++ = *current++;
    } else if (*current == ' ' || *current == '\t') {
      if (indent > 0) {
        indent--;
      }
      *line++ = *current++;
    } else {
      *line++ = *current++;
    }
    previous = current;
  }
  *line++ = '\0';

  printf("%s\n", output);
  free(output);
}

int main() {
  char input[] = "<html><body><p>This is a paragraph</p><p>With<b>bold</b>text</p></body></html>";
  html_beautify(input);
  return 0;
}