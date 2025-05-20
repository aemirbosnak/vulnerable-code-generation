//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 80
#define MAX_INDENT 4

void beautify_html(char *input) {
  char *line, *token, *new_line = "";
  int i = 0, indent = 0;
  char *output = malloc(strlen(input) * 2);

  // Tokenize the input HTML code
  while ((line = strtok(input, "<")) != NULL) {
    // Check if the current line is a tag start
    if (strncmp(line, "<", 1) == 0) {
      // Tokenize the tag name and attributes
      token = strtok(line, " ");
      while (token != NULL) {
        if (strncmp(token, " ", 1) == 0) {
          token = strtok(NULL, " ");
        }
        // Add the token to the output
        strcat(output, token);
        strcat(output, " ");
      }
      // Increment the indent level
      indent++;
      // Add a new line to the output
      strcat(output, "\n");
    } else {
      // Check if the current line is a tag end
      if (strncmp(line, "</", 2) == 0) {
        // Decrement the indent level
        indent--;
      }
      // Add the current line to the output
      strcat(output, line);
      // Add a space before the next line
      strcat(output, " ");
    }
  }
  // Add the final newline
  strcat(output, "\n");

  // Print the beautified HTML code
  printf("%s\n", output);

  // Free the output buffer
  free(output);
}

int main() {
  char input[100];

  // Ask the user for the input HTML code
  printf("Enter the messy HTML code: ");
  fgets(input, 100, stdin);

  // Beautify the HTML code
  beautify_html(input);

  return 0;
}