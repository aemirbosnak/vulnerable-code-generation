//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *line;
  int length;
} Line;

typedef struct {
  int num_lines;
  Line *lines;
} HtmlDocument;

HtmlDocument *new_html_document() {
  HtmlDocument *document = malloc(sizeof(HtmlDocument));
  document->num_lines = 0;
  document->lines = NULL;
  return document;
}

void free_html_document(HtmlDocument *document) {
  for (int i = 0; i < document->num_lines; i++) {
    free(document->lines[i].line);
  }
  free(document->lines);
  free(document);
}

Line *new_line(char *line) {
  Line *new_line = malloc(sizeof(Line));
  new_line->line = strdup(line);
  new_line->length = strlen(line);
  return new_line;
}

void free_line(Line *line) {
  free(line->line);
  free(line);
}

void add_line_to_document(HtmlDocument *document, Line *line) {
  document->num_lines++;
  document->lines = realloc(document->lines,
                            document->num_lines * sizeof(Line));
  document->lines[document->num_lines - 1] = *line;
}

char *beautify_html(HtmlDocument *document) {
  char *beautified_html = malloc(MAX_LINE_LENGTH * document->num_lines);
  int index = 0;
  for (int i = 0; i < document->num_lines; i++) {
    Line *line = &document->lines[i];
    memcpy(beautified_html + index, line->line, line->length);
    index += line->length;
    beautified_html[index++] = '\n';
  }
  beautified_html[index] = '\0';
  return beautified_html;
}

int main() {
  HtmlDocument *document = new_html_document();
  add_line_to_document(document, new_line("<html>"));
  add_line_to_document(document, new_line("  <head>"));
  add_line_to_document(document, new_line("    <title>My Website</title>"));
  add_line_to_document(document, new_line("  </head>"));
  add_line_to_document(document, new_line("  <body>"));
  add_line_to_document(document, new_line("    <h1>Hello, world!</h1>"));
  add_line_to_document(document, new_line("  </body>"));
  add_line_to_document(document, new_line("</html>"));

  char *beautified_html = beautify_html(document);
  printf("%s", beautified_html);

  free(beautified_html);
  free_html_document(document);

  return 0;
}