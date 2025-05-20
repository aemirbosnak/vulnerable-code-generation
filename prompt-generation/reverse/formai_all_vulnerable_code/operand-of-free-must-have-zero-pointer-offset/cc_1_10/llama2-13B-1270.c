//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 80
#define MAX_INDENT 4

void html_beautify(char *input) {
  char *output = malloc(strlen(input) * 2);
  char *line = output;
  char *indentation = "";
  int indent = 0;

  // Iterate over each line of the input HTML
  for (char *current = input; *current != '\0'; current++) {
    if (*current == '<') {
      // If we encounter a '<', increase the indent level
      indent++;
    } else if (*current == '>') {
      // If we encounter a '>', decrease the indent level
      indent--;
    }

    // If the current character is a whitespace,
    //   and the previous character is not a whitespace,
    //   and the indent level is non-zero,
    //   then add an indentation space
    if (*current == ' ' && *(current - 1) != ' ' && indent > 0) {
      *line++ = indentation;
      indentation = "";
    }

    // Add the current character to the output line
    *line++ = *current;

    // If the current character is a newline,
    //   and the previous character is not a newline,
    //   and the indent level is zero,
    //   then add an indentation space
    if (*current == '\n' && *(current - 1) != '\n' && indent == 0) {
      *line++ = indentation;
      indentation = "";
    }
  }

  // Add the final newline to the output line
  *line++ = '\n';

  // Set the output to the final output line
  output = line;

  // Print the beautified HTML
  printf("%s\n", output);

  free(output);
}

int main() {
  char input[] = "<html><body><p>This is some sample text.</p><p>This is some more sample text.</p></body></html>";
  html_beautify(input);
  return 0;
}