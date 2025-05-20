//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

void beautify(char **lines, int num_lines) {
  for (int i = 0; i < num_lines; i++) {
    lines[i] = realloc(lines[i], MAX_LINES);
  }

  for (int i = 0; i < num_lines; i++) {
    int line_length = strlen(lines[i]);
    int padding = MAX_LINES - line_length;
    char *line = lines[i];
    lines[i] = malloc(MAX_LINES);
    memset(lines[i], ' ', padding);
    strcat(lines[i], line);
  }

  for (int i = 0; i < num_lines; i++) {
    free(lines[i]);
  }
}

int main() {
  int num_lines = 20;
  char **lines = malloc(num_lines * sizeof(char *));

  for (int i = 0; i < num_lines; i++) {
    lines[i] = malloc(MAX_LINES);
  }

  lines[0] = "This is the first line.";
  lines[1] = "It is a long line that will be beautified.";
  lines[2] = "This line is shorter.";

  beautify(lines, num_lines);

  for (int i = 0; i < num_lines; i++) {
    printf("%s\n", lines[i]);
  }

  for (int i = 0; i < num_lines; i++) {
    free(lines[i]);
  }

  free(lines);

  return 0;
}