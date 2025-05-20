//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

char *html_beautify(const char *input) {
  char *output = malloc(sizeof(char) * MAX_LINE_LENGTH);
  int output_index = 0;

  int indent_level = 0;
  int in_tag = 0;
  int in_attribute = 0;
  int in_comment = 0;

  for (int i = 0; i < strlen(input); i++) {
    char c = input[i];

    if (in_comment) {
      if (c == '*' && input[i + 1] == '/') {
        in_comment = 0;
        i++;
      }
      continue;
    }

    if (c == '<') {
      in_tag = 1;
      if (input[i + 1] == '/') {
        indent_level--;
      }
    } else if (c == '>') {
      in_tag = 0;
      if (input[i - 1] != '/') {
        indent_level++;
      }
    }

    if (in_attribute) {
      if (c == '"') {
        in_attribute = 0;
      }
      continue;
    }

    if (c == '"') {
      in_attribute = 1;
    } else if (c == '/' && input[i + 1] == '*') {
      in_comment = 1;
      i++;
    } else if (c == '\n') {
      output[output_index++] = '\n';
      for (int j = 0; j < indent_level; j++) {
        output[output_index++] = '\t';
      }
    } else if (!in_tag) {
      output[output_index++] = ' ';
    }

    output[output_index++] = c;
  }

  output[output_index] = '\0';
  return output;
}

int main() {
  char *html = "<html>\n  <head>\n    <title>My Website</title>\n  </head>\n  <body>\n    <h1>Welcome to my website!</h1>\n    <p>This is my first website.</p>\n  </body>\n</html>";

  char *beautified_html = html_beautify(html);
  printf("%s\n", beautified_html);
  free(beautified_html);
  return 0;
}