//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a line
#define MAX_LINE_LENGTH 1024

// Define the number of spaces to indent each level
#define INDENT_SPACES 2

// Define the characters that are considered whitespace
#define WHITESPACE " \t\n\r"

// Function to indent a string
char *indent(char *str, int level) {
  // Allocate memory for the indented string
  char *indented_str = malloc(strlen(str) + level * INDENT_SPACES + 1);

  // Indent the string
  int i;
  for (i = 0; i < level * INDENT_SPACES; i++) {
    indented_str[i] = ' ';
  }
  strcpy(indented_str + level * INDENT_SPACES, str);

  // Return the indented string
  return indented_str;
}

// Function to beautify HTML
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML
  char *beautified_html = malloc(strlen(html) * 2 + 1);

  // Initialize the beautified HTML
  beautified_html[0] = '\0';

  // Parse the HTML
  char *line;
  char *token;
  int level = 0;
  while ((line = strtok(html, "\n")) != NULL) {
    // Remove leading and trailing whitespace from the line
    line = strtok(line, WHITESPACE);

    // If the line is empty, continue to the next line
    if (strlen(line) == 0) {
      continue;
    }

    // If the line is a start tag, increment the level
    if (line[0] == '<' && line[1] != '/') {
      level++;
    }

    // If the line is an end tag, decrement the level
    if (line[0] == '<' && line[1] == '/') {
      level--;
    }

    // Indent the line
    char *indented_line = indent(line, level);

    // Append the indented line to the beautified HTML
    strcat(beautified_html, indented_line);
    strcat(beautified_html, "\n");

    // Free the memory allocated for the indented line
    free(indented_line);
  }

  // Return the beautified HTML
  return beautified_html;
}

// Main function
int main() {
  // Get the HTML from the user
  char *html = malloc(1024);
  printf("Enter HTML to beautify: ");
  gets(html);

  // Beautify the HTML
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML
  printf("\nBeautified HTML:\n\n%s", beautified_html);

  // Free the memory allocated for the HTML and the beautified HTML
  free(html);
  free(beautified_html);

  return 0;
}