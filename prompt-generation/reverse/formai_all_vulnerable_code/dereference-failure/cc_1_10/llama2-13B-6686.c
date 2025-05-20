//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 4

// Function to print a line of HTML
void print_html_line(char *line) {
  printf("%s\n", line);
}

// Function to print a block of HTML
void print_html_block(char *block) {
  printf("%s\n", block);
}

// Function to beautify HTML code
void html_beautify(char *input) {
  // Step 1: Remove empty lines and trailing whitespace
  char *line = strtok(input, "\n");
  while (line != NULL) {
    if (*line == '\0' || strchr(line, '\n') != NULL) {
      free(line);
    } else {
      print_html_line(line);
      line = strtok(NULL, "\n");
    }
  }

  // Step 2: Indent lines
  char *block = strtok(input, "<");
  while (block != NULL) {
    char *token = strtok(block, " ");
    while (token != NULL && token[0] == ' ') {
      token++;
    }
    if (token[0] == '<') {
      // Indent the line
      char *indent = malloc(MAX_INDENT * sizeof(char));
      for (int i = 0; i < MAX_INDENT; i++) {
        indent[i] = ' ';
      }
      strcat(block, indent);
      token = strtok(NULL, " ");
    }
    print_html_block(block);
    block = strtok(NULL, "<");
  }
}

int main() {
  char input[1024];
  printf("Enter HTML code: ");
  fgets(input, sizeof(input), stdin);
  html_beautify(input);
  return 0;
}