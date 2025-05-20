//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *start;
  char *end;
} Line;

typedef struct {
  Line *lines;
  int num_lines;
} HTMLDocument;

HTMLDocument *parse_html(const char *html) {
  HTMLDocument *doc = malloc(sizeof(HTMLDocument));
  doc->lines = NULL;
  doc->num_lines = 0;

  char *start = (char *)html;
  char *end = start;

  while (*end != '\0') {
    if (*end == '\n') {
      Line line;
      line.start = start;
      line.end = end;
      doc->lines = realloc(doc->lines, sizeof(Line) * (doc->num_lines + 1));
      doc->lines[doc->num_lines++] = line;
      start = end + 1;
    }
    end++;
  }

  return doc;
}

void beautify_html(HTMLDocument *doc) {
  for (int i = 0; i < doc->num_lines; i++) {
    Line line = doc->lines[i];
    char *start = line.start;
    char *end = line.end;

    while (start < end) {
      if (*start == '<') {
        while (*start != '>' && start < end) {
          start++;
        }
        if (start < end) {
          start++;
        }
      } else {
        while (*start != '<' && start < end) {
          start++;
        }
      }

      if (start < end) {
        printf("%.*s", start - line.start, line.start);
        line.start = start;
      }
    }

    printf("\n");
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <html file>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  rewind(fp);

  char *html = malloc(file_size + 1);
  fread(html, 1, file_size, fp);
  html[file_size] = '\0';

  HTMLDocument *doc = parse_html(html);
  beautify_html(doc);

  free(html);
  free(doc->lines);
  free(doc);

  return 0;
}