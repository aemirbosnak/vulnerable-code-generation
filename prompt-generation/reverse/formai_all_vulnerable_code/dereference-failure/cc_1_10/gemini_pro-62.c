//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  int length;
  char *data;
} line_t;

typedef struct {
  int count;
  line_t *lines;
} lines_t;

lines_t *lines_new() {
  lines_t *lines = malloc(sizeof(lines_t));
  lines->count = 0;
  lines->lines = NULL;
  return lines;
}

void lines_free(lines_t *lines) {
  for (int i = 0; i < lines->count; i++) {
    free(lines->lines[i].data);
  }
  free(lines->lines);
  free(lines);
}

line_t *lines_add(lines_t *lines, const char *data) {
  lines->lines = realloc(lines->lines, (lines->count + 1) * sizeof(line_t));
  lines->lines[lines->count].length = strlen(data);
  lines->lines[lines->count].data = malloc(lines->lines[lines->count].length + 1);
  strcpy(lines->lines[lines->count].data, data);
  lines->count++;
  return &lines->lines[lines->count - 1];
}

void lines_beautify(lines_t *lines) {
  for (int i = 0; i < lines->count; i++) {
    line_t *line = &lines->lines[i];
    int indent = 0;
    for (int j = 0; j < line->length; j++) {
      if (line->data[j] == ' ') {
        indent++;
      } else if (line->data[j] == '\t') {
        indent = (indent / 4 + 1) * 4;
      } else {
        break;
      }
    }
    if (indent > 0) {
      for (int j = 0; j < indent; j++) {
        line->data[j] = ' ';
      }
      line->length = indent;
    }
  }
}

void lines_print(lines_t *lines) {
  for (int i = 0; i < lines->count; i++) {
    printf("%s", lines->lines[i].data);
  }
}

int main() {
  lines_t *lines = lines_new();
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, stdin)) {
    lines_add(lines, line);
  }
  lines_beautify(lines);
  lines_print(lines);
  lines_free(lines);
  return 0;
}