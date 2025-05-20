//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *line;
  int length;
  int capacity;
} Line;

typedef struct {
  Line *lines;
  int num_lines;
  int capacity;
} Document;

Document *document_create() {
  Document *document = malloc(sizeof(Document));
  document->lines = malloc(sizeof(Line) * 16);
  document->num_lines = 0;
  document->capacity = 16;
  return document;
}

void document_destroy(Document *document) {
  for (int i = 0; i < document->num_lines; i++) {
    free(document->lines[i].line);
  }
  free(document->lines);
  free(document);
}

void document_add_line(Document *document, char *line) {
  if (document->num_lines == document->capacity) {
    document->lines = realloc(document->lines, sizeof(Line) * document->capacity * 2);
    document->capacity *= 2;
  }
  document->lines[document->num_lines].line = strdup(line);
  document->lines[document->num_lines].length = strlen(line);
  document->lines[document->num_lines].capacity = strlen(line) + 1;
  document->num_lines++;
}

void document_beautify(Document *document) {
  for (int i = 0; i < document->num_lines; i++) {
    Line *line = &document->lines[i];
    int indent = 0;
    for (int j = 0; j < line->length; j++) {
      if (line->line[j] == ' ') {
        indent++;
      } else if (line->line[j] == '<') {
        if (indent > 0) {
          for (int k = 0; k < indent; k++) {
            printf("  ");
          }
          indent = 0;
        }
        printf("<");
      } else if (line->line[j] == '>') {
        printf(">\n");
      } else {
        printf("%c", line->line[j]);
      }
    }
  }
}

int main() {
  Document *document = document_create();
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;
  while ((nread = getline(&line, &len, stdin)) != -1) {
    document_add_line(document, line);
  }
  document_beautify(document);
  document_destroy(document);
  return 0;
}