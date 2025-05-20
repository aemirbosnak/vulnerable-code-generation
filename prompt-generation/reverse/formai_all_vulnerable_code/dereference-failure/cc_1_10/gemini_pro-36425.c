//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line.
#define MAX_LINE_LENGTH 1000

// Define the number of indentation levels.
#define MAX_INDENTATION_LEVELS 10

// Define the indentation string.
#define INDENTATION_STRING "  "

// Define the HTML tags that should be indented.
char *indented_tags[] = {"html", "head", "body", "h1", "h2", "h3", "h4", "h5", "h6", "p", "ul", "ol", "li", "a"};

// Define the HTML tags that should be on a new line.
char *new_line_tags[] = {"html", "head", "body", "h1", "h2", "h3", "h4", "h5", "h6", "p", "ul", "ol", "li", "a"};

// Function to indent a string.
char *indent(char *str, int level) {
  char *indented_str = malloc(strlen(str) + level * strlen(INDENTATION_STRING) + 1);
  for (int i = 0; i < level; i++) {
    strcat(indented_str, INDENTATION_STRING);
  }
  strcat(indented_str, str);
  return indented_str;
}

// Function to beautify HTML code.
char *beautify_html(char *html) {
  // Split the HTML code into lines.
  char **lines = malloc(sizeof(char *) * MAX_LINE_LENGTH);
  int num_lines = 0;
  char *line = strtok(html, "\n");
  while (line != NULL) {
    lines[num_lines++] = line;
    line = strtok(NULL, "\n");
  }

  // Indent the lines of HTML code.
  for (int i = 0; i < num_lines; i++) {
    char *trimmed_line = strtok(lines[i], " >");
    char *tag = strtok(NULL, " >");
    int indentation_level = 0;
    for (int j = 0; j < sizeof(indented_tags) / sizeof(char *); j++) {
      if (strcmp(tag, indented_tags[j]) == 0) {
        indentation_level++;
      }
    }
    lines[i] = indent(lines[i], indentation_level);
  }

  // Put the lines of HTML code back together.
  char *beautified_html = malloc(strlen(html) + 1);
  for (int i = 0; i < num_lines; i++) {
    strcat(beautified_html, lines[i]);
    strcat(beautified_html, "\n");
  }

  // Free the allocated memory.
  free(lines);

  // Return the beautified HTML code.
  return beautified_html;
}

// Main function.
int main() {
  // Get the HTML code from the user.
  char *html = malloc(10000);
  printf("Enter HTML code: ");
  scanf("%s", html);

  // Beautify the HTML code.
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code.
  printf("Beautified HTML code:\n%s", beautified_html);

  // Free the allocated memory.
  free(html);
  free(beautified_html);

  return 0;
}