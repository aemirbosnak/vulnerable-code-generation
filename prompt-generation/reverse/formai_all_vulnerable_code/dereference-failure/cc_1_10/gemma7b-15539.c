//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1024

int main() {
  char **lines = NULL;
  int line_count = 0;

  // Allocate memory for the lines
  lines = malloc(MAX_LINES * sizeof(char *));
  for (int i = 0; i < MAX_LINES; i++) {
    lines[i] = malloc(1024 * sizeof(char));
  }

  // Read the lines from the input
  while (line_count < MAX_LINES && scanf("%s", lines[line_count]) != EOF) {
    line_count++;
  }

  // Beautify the lines
  for (int i = 0; i < line_count; i++) {
    // Remove unnecessary whitespace
    lines[i] = realloc(lines[i], strlen(lines[i]) + 1);
    lines[i] = strstr(lines[i], "  ") ? strstr(lines[i], "  ") : lines[i];

    // Align the columns
    lines[i] = realloc(lines[i], strlen(lines[i]) + 1);
    lines[i] = align_columns(lines[i], 80);
  }

  // Print the beautified lines
  for (int i = 0; i < line_count; i++) {
    printf("%s\n", lines[i]);
  }

  // Free the memory
  for (int i = 0; i < MAX_LINES; i++) {
    free(lines[i]);
  }
  free(lines);

  return 0;
}

int align_columns(char *line, int columns) {
  int line_length = strlen(line);
  int max_columns = columns - 1;
  int padding = max_columns - (line_length % max_columns);

  if (padding > 0) {
    line = realloc(line, line_length + padding + 1);
    memset(line + line_length, ' ', padding);
  }

  return line;
}