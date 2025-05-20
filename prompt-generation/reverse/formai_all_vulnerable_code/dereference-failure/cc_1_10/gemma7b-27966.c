//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void beautify_html(char **html) {
  int i = 0, j = 0, k = 0, indent = 0;
  char **lines = NULL;

  lines = malloc(MAX_SIZE * sizeof(char *));

  for (i = 0; html[i] != NULL; i++) {
    lines[k] = malloc(MAX_SIZE * sizeof(char));

    for (j = 0; html[i][j] != '\0'; j++) {
      lines[k][j] = html[i][j];
    }

    lines[k][j] = '\0';

    k++;
  }

  free(html);

  html = lines;

  for (i = 0; lines[i] != NULL; i++) {
    for (j = 0; lines[i][j] != '\0'; j++) {
      if (lines[i][j] == '<') {
        indent++;
      } else if (lines[i][j] == '>') {
        indent--;
      } else {
        for (k = 0; k < indent; k++) {
          lines[i][j] = ' ';
        }
      }
    }

    free(lines[i]);
  }

  free(lines);

  return;
}

int main() {
  char **html = NULL;

  html = malloc(MAX_SIZE * sizeof(char *));

  html[0] = "<h1>Hello, world!</h1>";
  html[1] = "<p>This is a paragraph.</p>";
  html[2] = "<div>This is a div.</div>";

  beautify_html(html);

  for (int i = 0; html[i] != NULL; i++) {
    printf("%s", html[i]);
  }

  free(html);

  return 0;
}