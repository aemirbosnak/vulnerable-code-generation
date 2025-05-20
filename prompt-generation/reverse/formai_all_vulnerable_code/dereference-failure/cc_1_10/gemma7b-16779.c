//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1024

void beautify_html(char **lines, int num_lines) {
  int i, j, k, indent = 0;
  char **new_lines = malloc(num_lines * MAX_LINES);

  for (i = 0; i < num_lines; i++) {
    new_lines[i] = strdup(lines[i]);
  }

  for (i = 0; i < num_lines; i++) {
    for (j = 0; j < MAX_LINES; j++) {
      if (new_lines[i][j] == '<' && new_lines[i][j + 1] == 'h') {
        indent = 0;
      } else if (new_lines[i][j] == '>' && new_lines[i][j + 1] == 'h') {
        indent = MAX_LINES;
      } else if (new_lines[i][j] == '\n') {
        if (indent > 0) {
          for (k = 0; k < indent; k++) {
            new_lines[i][j - k] = ' ';
          }
        }
        indent--;
      } else {
        indent++;
      }
    }
  }

  free(lines);
  free(new_lines);
}

int main() {
  char **lines = malloc(MAX_LINES);
  lines[0] = "<p>This is a sample HTML document.</p>";
  lines[1] = "<h3>Heading 3</h3>";
  lines[2] = "<p>This paragraph is indented.</p>";
  lines[3] = "<h2>Heading 2</h2>";
  lines[4] = "<p>This paragraph is also indented.</p>";

  beautify_html(lines, 5);

  for (int i = 0; i < 5; i++) {
    printf("%s\n", lines[i]);
  }

  free(lines);

  return 0;
}