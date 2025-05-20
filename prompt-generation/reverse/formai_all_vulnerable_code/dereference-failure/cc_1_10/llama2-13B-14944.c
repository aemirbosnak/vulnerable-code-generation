//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define MAX_INDENT 4

void html_beautify(char *input) {
  char *output = malloc(strlen(input) * 2);
  char *line = output;
  char *indent = output;
  char *current_element = input;

  while (*current_element != '\0') {
    if (*current_element == '<') {
      current_element++;
      if (*current_element == '/') {
        // Close tag
        *line++ = '>';
        *line++ = '>';
        current_element++;
      } else {
        // Open tag
        *line++ = '<';
        *line++ = *current_element++;
        *line++ = '>';
      }
    } else if (*current_element == '>') {
      // End of tag
      *line++ = '>';
      current_element++;
    } else if (*current_element == '\n') {
      // New line
      *line++ = '\n';
      *indent++ = ' ';
    } else if (*current_element == ' ' && *(current_element + 1) != '\0') {
      // Indent
      *indent++ = ' ';
    } else {
      // Normal character
      *line++ = *current_element++;
    }
  }
  *line = '\0';

  // Print the beautified HTML
  printf("%s\n", output);

  free(output);
}

int main() {
  char input[] = "<html><body><p>This is a sample text</p><ul><li>Item 1</li><li>Item 2</li></ul></body></html>";
  html_beautify(input);
  return 0;
}