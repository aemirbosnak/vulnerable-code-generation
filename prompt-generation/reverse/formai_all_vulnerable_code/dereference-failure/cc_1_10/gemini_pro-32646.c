//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *line;
  int length;
} Line;

typedef struct {
  Line *lines;
  int num_lines;
} HTMLDocument;

HTMLDocument *parse_html_document(char *html) {
  HTMLDocument *document = malloc(sizeof(HTMLDocument));
  document->num_lines = 0;
  document->lines = NULL;

  char *line = strtok(html, "\n");
  while (line != NULL) {
    Line *new_line = malloc(sizeof(Line));
    new_line->line = line;
    new_line->length = strlen(line);

    document->lines = realloc(document->lines, (document->num_lines + 1) * sizeof(Line));
    document->lines[document->num_lines] = *new_line;
    document->num_lines++;

    line = strtok(NULL, "\n");
  }

  return document;
}

void beautify_html_document(HTMLDocument *document) {
  for (int i = 0; i < document->num_lines; i++) {
    Line *line = &document->lines[i];

    // Remove leading and trailing whitespace.
    while (line->length > 0 && isspace(line->line[line->length - 1])) {
      line->length--;
    }
    while (line->length > 0 && isspace(line->line[0])) {
      line->line++;
      line->length--;
    }

    // Indent the line.
    for (int j = 0; j < i; j++) {
      printf("  ");
    }

    // Print the line.
    printf("%s\n", line->line);
  }
}

int main() {
  char *html = "<html>\n<head>\n<title>Hello, world!</title>\n</head>\n<body>\n<h1>Hello, world!</h1>\n</body>\n</html>";

  HTMLDocument *document = parse_html_document(html);
  beautify_html_document(document);

  return 0;
}