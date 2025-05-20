//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *start;
  char *end;
} Line;

typedef struct {
  Line *lines;
  int num_lines;
} Document;

Document *create_document(char *html) {
  Document *document = malloc(sizeof(Document));
  document->lines = NULL;
  document->num_lines = 0;

  char *line_start = html;
  char *line_end = strchr(line_start, '\n');

  while (line_end != NULL) {
    Line line;
    line.start = line_start;
    line.end = line_end;

    document->lines = realloc(document->lines, sizeof(Line) * (document->num_lines + 1));
    document->lines[document->num_lines] = line;
    document->num_lines++;

    line_start = line_end + 1;
    line_end = strchr(line_start, '\n');
  }

  return document;
}

void free_document(Document *document) {
  free(document->lines);
  free(document);
}

char *beautify_html(Document *document) {
  int max_line_length = 0;
  for (int i = 0; i < document->num_lines; i++) {
    int line_length = document->lines[i].end - document->lines[i].start + 1;
    if (line_length > max_line_length) {
      max_line_length = line_length;
    }
  }

  char *output = malloc(sizeof(char) * (document->num_lines * max_line_length + 1));
  int output_index = 0;

  for (int i = 0; i < document->num_lines; i++) {
    int line_length = document->lines[i].end - document->lines[i].start + 1;
    int padding = max_line_length - line_length;

    for (int j = 0; j < padding; j++) {
      output[output_index++] = ' ';
    }

    for (int j = 0; j < line_length; j++) {
      output[output_index++] = document->lines[i].start[j];
    }

    output[output_index++] = '\n';
  }

  output[output_index] = '\0';

  return output;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
    return 1;
  }

  FILE *html_file = fopen(argv[1], "r");
  if (html_file == NULL) {
    fprintf(stderr, "Error opening file: %s\n", argv[1]);
    return 1;
  }

  fseek(html_file, 0, SEEK_END);
  long html_file_size = ftell(html_file);
  rewind(html_file);

  char *html = malloc(sizeof(char) * (html_file_size + 1));
  fread(html, 1, html_file_size, html_file);
  fclose(html_file);

  Document *document = create_document(html);
  char *beautified_html = beautify_html(document);
  free_document(document);

  printf("%s", beautified_html);
  free(beautified_html);

  return 0;
}