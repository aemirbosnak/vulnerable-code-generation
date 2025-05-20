//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NESTING_LEVEL 10

typedef struct {
  char *line;
  int line_length;
  int nesting_level;
} line_t;

typedef struct {
  line_t *lines;
  int num_lines;
  int max_nesting_level;
} html_t;

html_t *html_new() {
  html_t *html = malloc(sizeof(html_t));
  html->lines = NULL;
  html->num_lines = 0;
  html->max_nesting_level = 0;
  return html;
}

void html_free(html_t *html) {
  for (int i = 0; i < html->num_lines; i++) {
    free(html->lines[i].line);
  }
  free(html->lines);
  free(html);
}

int html_add_line(html_t *html, char *line) {
  line_t *new_line = malloc(sizeof(line_t));
  new_line->line = strdup(line);
  new_line->line_length = strlen(line);
  new_line->nesting_level = 0;
  html->lines = realloc(html->lines, (html->num_lines + 1) * sizeof(line_t));
  html->lines[html->num_lines] = *new_line;
  html->num_lines++;
  return 0;
}

int html_beautify(html_t *html) {
  for (int i = 0; i < html->num_lines; i++) {
    line_t *line = &html->lines[i];
    int nesting_level = 0;
    for (int j = 0; j < line->line_length; j++) {
      if (line->line[j] == '<') {
        nesting_level++;
      } else if (line->line[j] == '>') {
        nesting_level--;
      }
    }
    line->nesting_level = nesting_level;
    if (nesting_level > html->max_nesting_level) {
      html->max_nesting_level = nesting_level;
    }
  }

  for (int i = 0; i < html->num_lines; i++) {
    line_t *line = &html->lines[i];
    printf("%*s%s\n", line->nesting_level * 2, "", line->line);
  }

  return 0;
}

int main() {
  html_t *html = html_new();

  char *line = NULL;
  size_t len = 0;
  while (getline(&line, &len, stdin) != -1) {
    html_add_line(html, line);
  }

  html_beautify(html);

  html_free(html);

  return 0;
}