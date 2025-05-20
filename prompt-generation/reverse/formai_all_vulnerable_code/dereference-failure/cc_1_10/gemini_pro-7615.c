//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: innovative
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
} Document;

Document *new_document() {
  Document *document = malloc(sizeof(Document));
  document->lines = NULL;
  document->num_lines = 0;
  return document;
}

void free_document(Document *document) {
  for (int i = 0; i < document->num_lines; i++) {
    free(document->lines[i].text);
  }
  free(document->lines);
  free(document);
}

Line *new_line(char *text, int length) {
  Line *line = malloc(sizeof(Line));
  line->text = malloc(length + 1);
  memcpy(line->text, text, length);
  line->text[length] = '\0';
  line->length = length;
  return line;
}

void free_line(Line *line) {
  free(line->text);
  free(line);
}

void add_line(Document *document, Line *line) {
  document->lines = realloc(document->lines,
                            (document->num_lines + 1) * sizeof(Line));
  document->lines[document->num_lines++] = *line;
}

char *beautify(Document *document) {
  // Convert the document to a string.
  char *result = malloc(1);
  result[0] = '\0';
  for (int i = 0; i < document->num_lines; i++) {
    result = realloc(result,
                     strlen(result) + document->lines[i].length + 2);
    strcat(result, document->lines[i].text);
    strcat(result, "\n");
  }

  // Remove any trailing whitespace.
  char *p = result + strlen(result) - 1;
  while (p >= result && isspace(*p)) {
    *p-- = '\0';
  }

  // Return the beautified string.
  return result;
}

int main() {
  // Create a new document.
  Document *document = new_document();

  // Add some lines to the document.
  add_line(document, new_line("<h1>Hello, world!</h1>", 21));
  add_line(document, new_line("<p>This is a paragraph.</p>", 26));
  add_line(document, new_line("<ul>", 4));
  add_line(document, new_line("  <li>Item 1</li>", 16));
  add_line(document, new_line("  <li>Item 2</li>", 16));
  add_line(document, new_line("  <li>Item 3</li>", 16));
  add_line(document, new_line("</ul>", 5));

  // Beautify the document.
  char *beautified = beautify(document);

  // Print the beautified HTML.
  printf("%s\n", beautified);

  // Free the memory used by the document.
  free_document(document);

  // Free the memory used by the beautified HTML.
  free(beautified);

  return 0;
}