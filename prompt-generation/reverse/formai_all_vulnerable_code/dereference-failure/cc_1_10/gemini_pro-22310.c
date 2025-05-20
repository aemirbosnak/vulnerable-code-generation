//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *line;
  int length;
} Line;

typedef struct {
  Line *lines;
  int num_lines;
  int max_line_length;
} Document;

Document *create_document() {
  Document *doc = malloc(sizeof(Document));
  doc->lines = NULL;
  doc->num_lines = 0;
  doc->max_line_length = 0;
  return doc;
}

void free_document(Document *doc) {
  for (int i = 0; i < doc->num_lines; i++) {
    free(doc->lines[i].line);
  }
  free(doc->lines);
  free(doc);
}

void add_line(Document *doc, char *line) {
  doc->lines = realloc(doc->lines, (doc->num_lines + 1) * sizeof(Line));
  doc->lines[doc->num_lines].line = strdup(line);
  doc->lines[doc->num_lines].length = strlen(line);
  doc->num_lines++;
  if (doc->lines[doc->num_lines - 1].length > doc->max_line_length) {
    doc->max_line_length = doc->lines[doc->num_lines - 1].length;
  }
}

void beautify(Document *doc) {
  for (int i = 0; i < doc->num_lines; i++) {
    int j = 0;
    while (j < doc->lines[i].length) {
      if (doc->lines[i].line[j] == '<') {
        int k = j + 1;
        while (k < doc->lines[i].length && doc->lines[i].line[k] != '>') {
          k++;
        }
        if (k < doc->lines[i].length) {
          char *tag = malloc(k - j + 2);
          strncpy(tag, doc->lines[i].line + j, k - j + 1);
          tag[k - j + 1] = '\0';
          int l = 0;
          while (l < strlen(tag)) {
            if (tag[l] == '/') {
              printf("</%s>\n", tag + l + 1);
            } else {
              printf("<%s>\n", tag + l);
            }
            l += strlen(tag + l) + 1;
          }
          free(tag);
          j = k + 1;
        } else {
          j = doc->lines[i].length;
        }
      } else {
        printf("%c", doc->lines[i].line[j]);
        j++;
      }
    }
  }
}

int main() {
  Document *doc = create_document();
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, stdin)) {
    add_line(doc, line);
  }
  beautify(doc);
  free_document(doc);
  return 0;
}