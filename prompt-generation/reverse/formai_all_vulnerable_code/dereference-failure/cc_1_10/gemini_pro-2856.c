//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *line;
  int length;
} Line;

typedef struct {
  Line *lines;
  int num_lines;
} HtmlDocument;

HtmlDocument *new_html_document() {
  HtmlDocument *doc = malloc(sizeof(HtmlDocument));
  doc->lines = malloc(sizeof(Line) * MAX_LINE_LENGTH);
  doc->num_lines = 0;
  return doc;
}

void free_html_document(HtmlDocument *doc) {
  for (int i = 0; i < doc->num_lines; i++) {
    free(doc->lines[i].line);
  }
  free(doc->lines);
  free(doc);
}

void add_line(HtmlDocument *doc, char *line) {
  doc->lines[doc->num_lines].line = strdup(line);
  doc->lines[doc->num_lines].length = strlen(line);
  doc->num_lines++;
}

void print_html_document(HtmlDocument *doc) {
  for (int i = 0; i < doc->num_lines; i++) {
    printf("%s\n", doc->lines[i].line);
  }
}

int main() {
  HtmlDocument *doc = new_html_document();
  add_line(doc, "<html>");
  add_line(doc, "<head>");
  add_line(doc, "<title>Hello, world!</title>");
  add_line(doc, "</head>");
  add_line(doc, "<body>");
  add_line(doc, "<h1>Hello, world!</h1>");
  add_line(doc, "</body>");
  add_line(doc, "</html>");
  print_html_document(doc);
  free_html_document(doc);
  return 0;
}