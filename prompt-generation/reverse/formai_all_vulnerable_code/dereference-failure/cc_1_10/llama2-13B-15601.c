//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 80
#define MAX_INDENT 4

void html_beautify(char *input) {
  char *output = malloc(strlen(input) * 2);
  char *current = output;
  char *previous = output;
  char *line = input;

  while (*line != '\0') {
    if (*line == '<') {
      // Found an opening tag, let's indent it
      current = previous;
      while (*current != '>') {
        *current++ = ' ';
      }
      *current = '\0';

      // Move to the next character in the input string
      line++;
    } else if (*line == '>') {
      // Found a closing tag, let's unindent it
      current = previous;
      while (*current != '<') {
        *current-- = ' ';
      }
      *current = '\0';

      // Move to the next character in the input string
      line++;
    } else {
      // Normal character, just append it to the output
      *current = *line;
      current++;
    }

    previous = current;
  }

  // Add a final newline to the output
  *(current++) = '\n';

  // Copy the output to the input string
  strcpy(input, output);
}

int main() {
  char input[] = "<html><body>This is some <b>ugly</b> HTML code.</body></html>";
  char expected_output[] = "<html>\n<body>\nThis is some <b>ugly</b> HTML code.</body>\n</html>";

  html_beautify(input);
  if (strcmp(input, expected_output) != 0) {
    printf("Input: %s\nExpected output: %s\nActual output: %s\n", input, expected_output, input);
    return 1;
  }

  return 0;
}