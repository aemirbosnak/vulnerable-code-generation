//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
  char *line;
  int len;
} line_t;

typedef struct {
  line_t *lines;
  int num_lines;
} html_t;

html_t *html_new() {
  html_t *html = malloc(sizeof(html_t));
  html->lines = NULL;
  html->num_lines = 0;
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
  html->lines = realloc(html->lines, (html->num_lines + 1) * sizeof(line_t));
  if (!html->lines) {
    return -1;
  }
  html->lines[html->num_lines].line = strdup(line);
  html->lines[html->num_lines].len = strlen(line);
  html->num_lines++;
  return 0;
}

char *html_beautify(html_t *html) {
  char *buf = malloc(MAX_LINE_LEN * html->num_lines);
  if (!buf) {
    return NULL;
  }
  int pos = 0;
  for (int i = 0; i < html->num_lines; i++) {
    memcpy(buf + pos, html->lines[i].line, html->lines[i].len);
    pos += html->lines[i].len;
    buf[pos++] = '\n';
  }
  buf[pos] = '\0';
  return buf;
}

int main() {
  html_t *html = html_new();
  char line[MAX_LINE_LEN];
  while (fgets(line, MAX_LINE_LEN, stdin)) {
    html_add_line(html, line);
  }
  char *beautified = html_beautify(html);
  printf("%s\n", beautified);
  free(beautified);
  html_free(html);
  return 0;
}