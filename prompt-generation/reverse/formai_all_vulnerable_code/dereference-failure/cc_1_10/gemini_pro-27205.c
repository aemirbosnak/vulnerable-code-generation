//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to remove leading and trailing whitespace from a string
char *trim(char *str) {
  char *end;

  // Trim leading whitespace
  while (isspace(*str)) str++;

  // Trim trailing whitespace
  if ((end = str + strlen(str) - 1) != str) {
    while (isspace(*end)) end--;
    *(end + 1) = '\0';
  }

  return str;
}

// Function to beautify HTML code
char *beautify_html(char *html) {
  char *beautified_html = malloc(sizeof(char) * MAX_LINE_LENGTH);
  char *line = strtok(html, "\n");
  int indent_level = 0;

  while (line != NULL) {
    // Trim leading and trailing whitespace from the line
    line = trim(line);

    // If the line is empty, add a newline and increase the indent level
    if (strlen(line) == 0) {
      strcat(beautified_html, "\n");
      indent_level++;
    }
    // If the line starts with a closing tag, decrease the indent level
    else if (line[0] == '<' && line[1] == '/') {
      indent_level--;
      strcat(beautified_html, line);
      strcat(beautified_html, "\n");
    }
    // If the line starts with an opening tag, add the tag and increase the indent level
    else if (line[0] == '<') {
      strcat(beautified_html, line);
      strcat(beautified_html, "\n");
      indent_level++;
    }
    // If the line is not empty, add the line and a newline
    else {
      for (int i = 0; i < indent_level; i++) {
        strcat(beautified_html, "  ");
      }
      strcat(beautified_html, line);
      strcat(beautified_html, "\n");
    }

    // Get the next line
    line = strtok(NULL, "\n");
  }

  return beautified_html;
}

int main() {
  // Get the HTML code from the user
  char *html = malloc(sizeof(char) * MAX_LINE_LENGTH);
  printf("Enter HTML code:\n");
  fgets(html, MAX_LINE_LENGTH, stdin);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  printf("Beautified HTML code:\n");
  printf("%s", beautified_html);

  return 0;
}