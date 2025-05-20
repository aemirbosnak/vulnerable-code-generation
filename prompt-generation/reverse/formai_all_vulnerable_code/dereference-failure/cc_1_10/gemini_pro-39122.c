//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to remove leading and trailing whitespace from a string
char *trim(char *str) {
  char *start = str;
  while (*start && isspace(*start)) {
    start++;
  }
  char *end = str + strlen(str) - 1;
  while (end >= start && isspace(*end)) {
    end--;
  }
  *++end = '\0';
  return start;
}

// Function to convert a string to lowercase
char *to_lower(char *str) {
  char *ptr = str;
  while (*ptr) {
    *ptr = tolower(*ptr);
    ptr++;
  }
  return str;
}

// Function to beautify HTML code
void beautify_html(char *html) {
  // Remove leading and trailing whitespace from the HTML code
  html = trim(html);

  // Convert the HTML code to lowercase
  html = to_lower(html);

  // Split the HTML code into lines
  char *lines[MAX_LINE_LENGTH];
  int num_lines = 0;
  char *line = strtok(html, "\n");
  while (line != NULL) {
    lines[num_lines++] = line;
    line = strtok(NULL, "\n");
  }

  // Beautify each line of HTML code
  for (int i = 0; i < num_lines; i++) {
    line = lines[i];

    // Remove leading and trailing whitespace from the line
    line = trim(line);

    // Add indentation to the line
    char *indentation = "";
    for (int j = 0; j < i; j++) {
      indentation = strcat(indentation, "  ");
    }
    line = strcat(indentation, line);

    // Add a newline character to the end of the line
    line = strcat(line, "\n");

    // Replace the original line with the beautified line
    lines[i] = line;
  }

  // Join the beautified lines of HTML code into a single string
  char *beautified_html = "";
  for (int i = 0; i < num_lines; i++) {
    beautified_html = strcat(beautified_html, lines[i]);
  }

  // Print the beautified HTML code to the console
  printf("%s", beautified_html);
}

int main() {
  // Get the HTML code from the user
  char *html = "";
  printf("Enter HTML code: ");
  gets(html);

  // Beautify the HTML code
  beautify_html(html);

  return 0;
}