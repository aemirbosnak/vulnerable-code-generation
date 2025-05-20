//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *text;
  int length;
} Line;

typedef struct {
  Line *lines;
  int num_lines;
  int capacity;
} HtmlDocument;

HtmlDocument *new_html_document() {
  HtmlDocument *doc = malloc(sizeof(HtmlDocument));
  doc->lines = malloc(sizeof(Line) * 10);
  doc->num_lines = 0;
  doc->capacity = 10;
  return doc;
}

void free_html_document(HtmlDocument *doc) {
  for (int i = 0; i < doc->num_lines; i++) {
    free(doc->lines[i].text);
  }
  free(doc->lines);
  free(doc);
}

void add_line_to_html_document(HtmlDocument *doc, char *text) {
  if (doc->num_lines == doc->capacity) {
    doc->capacity *= 2;
    doc->lines = realloc(doc->lines, sizeof(Line) * doc->capacity);
  }
  doc->lines[doc->num_lines].text = strdup(text);
  doc->lines[doc->num_lines].length = strlen(text);
  doc->num_lines++;
}

void print_html_document(HtmlDocument *doc) {
  for (int i = 0; i < doc->num_lines; i++) {
    printf("%s\n", doc->lines[i].text);
  }
}

int main() {
  HtmlDocument *doc = new_html_document();
  add_line_to_html_document(doc, "<html>");
  add_line_to_html_document(doc, "<head>");
  add_line_to_html_document(doc, "<title>My Website</title>");
  add_line_to_html_document(doc, "</head>");
  add_line_to_html_document(doc, "<body>");
  add_line_to_html_document(doc, "<h1>Hello, world!</h1>");
  add_line_to_html_document(doc, "</body>");
  add_line_to_html_document(doc, "</html>");
  print_html_document(doc);
  free_html_document(doc);
  return 0;
}