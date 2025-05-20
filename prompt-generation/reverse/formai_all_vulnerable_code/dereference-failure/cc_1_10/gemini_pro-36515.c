//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *line;
  int length;
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
  if (html->num_lines >= MAX_LINE_LENGTH) {
    return -1;
  }
  html->lines = realloc(html->lines, (html->num_lines + 1) * sizeof(line_t));
  if (html->lines == NULL) {
    return -1;
  }
  html->lines[html->num_lines].line = strdup(line);
  if (html->lines[html->num_lines].line == NULL) {
    return -1;
  }
  html->lines[html->num_lines].length = strlen(line);
  html->num_lines++;
  return 0;
}

char *html_beautify(html_t *html) {
  char *beautified_html = malloc(MAX_LINE_LENGTH * html->num_lines);
  if (beautified_html == NULL) {
    return NULL;
  }
  int index = 0;
  for (int i = 0; i < html->num_lines; i++) {
    memcpy(beautified_html + index, html->lines[i].line, html->lines[i].length);
    index += html->lines[i].length;
    beautified_html[index++] = '\n';
  }
  beautified_html[index] = '\0';
  return beautified_html;
}

int main() {
  html_t *html = html_new();
  html_add_line(html, "<html>");
  html_add_line(html, "<head>");
  html_add_line(html, "<title>My Website</title>");
  html_add_line(html, "</head>");
  html_add_line(html, "<body>");
  html_add_line(html, "<h1>Welcome to my website</h1>");
  html_add_line(html, "<p>This is my website. It is still under construction, but I hope you enjoy it.</p>");
  html_add_line(html, "</body>");
  html_add_line(html, "</html>");

  char *beautified_html = html_beautify(html);
  printf("%s", beautified_html);
  free(beautified_html);
  html_free(html);
  return 0;
}