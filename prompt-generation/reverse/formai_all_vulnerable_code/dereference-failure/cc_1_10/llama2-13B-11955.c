//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 4

void html_beautify(char *input) {
  char *output = malloc(strlen(input) * 2);
  char *line = output;
  char *prev_line = NULL;
  char *current_line = input;
  int level = 0;

  while (*current_line != '\0') {
    if (*current_line == '<') {
      level++;
      if (level == 1) {
        *line++ = ' ';
      } else if (level == 2) {
        *line++ = '   ';
      } else if (level == 3) {
        *line++ = '    ';
      }
      current_line++;
    } else if (*current_line == '>') {
      level--;
      if (level == 0) {
        *line++ = ' ';
      }
      current_line++;
    } else {
      *line++ = *current_line++;
    }
    if (prev_line != NULL) {
      *prev_line = '\0';
    }
    prev_line = current_line;
  }
  *line = '\0';
  output[strcspn(output, "\n")] = '\0';
  printf("%s\n", output);
  free(output);
}

int main() {
  char input[1024];
  gets(input);
  html_beautify(input);
  return 0;
}