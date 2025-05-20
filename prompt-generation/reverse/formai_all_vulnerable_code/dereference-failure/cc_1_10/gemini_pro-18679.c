//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *data;
  int length;
} Line;

typedef struct {
  Line *lines;
  int num_lines;
} HtmlDocument;

HtmlDocument *new_html_document() {
  HtmlDocument *doc = malloc(sizeof(HtmlDocument));
  doc->lines = malloc(sizeof(Line) * 10);
  doc->num_lines = 0;
  return doc;
}

void free_html_document(HtmlDocument *doc) {
  for (int i = 0; i < doc->num_lines; i++) {
    free(doc->lines[i].data);
  }
  free(doc->lines);
  free(doc);
}

void add_line_to_html_document(HtmlDocument *doc, char *line) {
  if (doc->num_lines >= 10) {
    doc->lines = realloc(doc->lines, sizeof(Line) * doc->num_lines * 2);
  }
  doc->lines[doc->num_lines].data = malloc(strlen(line) + 1);
  strcpy(doc->lines[doc->num_lines].data, line);
  doc->lines[doc->num_lines].length = strlen(line);
  doc->num_lines++;
}

void print_html_document(HtmlDocument *doc) {
  for (int i = 0; i < doc->num_lines; i++) {
    printf("%s", doc->lines[i].data);
  }
}

int main() {
  HtmlDocument *doc = new_html_document();
  add_line_to_html_document(doc, "<html>");
  add_line_to_html_document(doc, "  <head>");
  add_line_to_html_document(doc, "    <title>My Website</title>");
  add_line_to_html_document(doc, "  </head>");
  add_line_to_html_document(doc, "  <body>");
  add_line_to_html_document(doc, "    <h1>Welcome to my website!</h1>");
  add_line_to_html_document(doc, "    <p>This is my first website.</p>");
  add_line_to_html_document(doc, "  </body>");
  add_line_to_html_document(doc, "</html>");
  print_html_document(doc);
  free_html_document(doc);
  return 0;
}