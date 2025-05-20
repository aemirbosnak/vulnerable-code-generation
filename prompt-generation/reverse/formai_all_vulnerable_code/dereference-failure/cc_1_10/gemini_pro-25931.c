//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *buffer;
  int length;
  int capacity;
} String;

String *string_new() {
  String *string = malloc(sizeof(String));
  string->buffer = malloc(MAX_LINE_LENGTH);
  string->length = 0;
  string->capacity = MAX_LINE_LENGTH;
  return string;
}

void string_free(String *string) {
  free(string->buffer);
  free(string);
}

void string_append(String *string, char *data, int length) {
  if (string->length + length > string->capacity) {
    string->capacity *= 2;
    string->buffer = realloc(string->buffer, string->capacity);
  }
  memcpy(string->buffer + string->length, data, length);
  string->length += length;
}

char *html_beautify(char *html) {
  String *output = string_new();
  int indent_level = 0;
  int in_tag = 0;
  int in_comment = 0;
  char *current_tag = NULL;
  for (char *p = html; *p != '\0'; p++) {
    if (in_comment) {
      if (*p == '*' && *(p + 1) == '/') {
        in_comment = 0;
        string_append(output, " */", 3);
        p++;
      } else {
        string_append(output, p, 1);
      }
    } else if (in_tag) {
      if (*p == '>' && *(p - 1) != '/') {
        string_append(output, ">", 1);
        in_tag = 0;
        current_tag = NULL;
      } else if (*p == '/') {
        string_append(output, p, 1);
        current_tag = NULL;
      } else {
        string_append(output, p, 1);
      }
    } else if (*p == '<') {
      in_tag = 1;
      current_tag = p + 1;
      string_append(output, p, 1);
    } else if (*p == '\n' || *p == '\r') {
      if (current_tag && strcmp(current_tag, "/pre") != 0) {
        string_append(output, "\n", 1);
        for (int i = 0; i < indent_level; i++) {
          string_append(output, "  ", 2);
        }
      }
    } else if (*p == '/' && *(p + 1) == '*' && *(p + 2) == '*') {
      in_comment = 1;
      string_append(output, "/*", 3);
      p += 2;
    } else {
      string_append(output, p, 1);
    }
  }
  return output->buffer;
}

int main() {
  char *html = "<html>\n<head>\n<title>Example</title>\n</head>\n<body>\n<h1>Hello, world!</h1>\n<p>This is an example of how to beautify HTML.</p>\n</body>\n</html>";
  char *beautified_html = html_beautify(html);
  printf("%s\n", beautified_html);
  free(beautified_html);
  return 0;
}