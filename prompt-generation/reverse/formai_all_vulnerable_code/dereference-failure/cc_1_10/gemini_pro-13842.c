//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to beautify HTML code
char *beautify_html(char *html) {
  int i, j, k;
  int in_tag = 0;
  int in_attribute = 0;
  int in_string = 0;
  int indent_level = 0;
  char *result = malloc(strlen(html) * 2);
  char *indent = malloc(indent_level + 1);

  // Initialize the result string
  result[0] = '\0';

  // Iterate over the HTML code
  for (i = 0; i < strlen(html); i++) {
    // If we are in a string, skip the current character
    if (in_string) {
      if (html[i] == '"') {
        in_string = 0;
      }
      continue;
    }

    // If we are in an attribute, skip the current character
    if (in_attribute) {
      if (html[i] == '>') {
        in_attribute = 0;
      }
      continue;
    }

    // If we are in a tag, skip the current character
    if (in_tag) {
      if (html[i] == '>') {
        in_tag = 0;
        indent_level--;
        strcat(result, "\n");
        for (j = 0; j < indent_level; j++) {
          strcat(result, "  ");
        }
      }
      continue;
    }

    // If we are at the beginning of a tag, add the appropriate indentation
    if (html[i] == '<') {
      in_tag = 1;
      strcat(result, "\n");
      for (j = 0; j < indent_level; j++) {
        strcat(result, "  ");
      }
      strcat(result, "<");
      continue;
    }

    // If we are at the beginning of an attribute, add the appropriate indentation
    if (html[i] == '=') {
      in_attribute = 1;
      strcat(result, " ");
      continue;
    }

    // If we are at the beginning of a string, add the appropriate indentation
    if (html[i] == '"') {
      in_string = 1;
      strcat(result, "\"");
      continue;
    }

    // Add the current character to the result string
    strcat(result, &html[i]);
  }

  // Free the allocated memory
  free(indent);
  return result;
}

// Main function
int main() {
  // Read the HTML code from a file
  FILE *fp = fopen("input.html", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  char *html = malloc(MAX_LINE_LENGTH);
  while (fgets(html, MAX_LINE_LENGTH, fp) != NULL) {
    // Beautify the HTML code
    char *beautified_html = beautify_html(html);

    // Print the beautified HTML code
    printf("%s", beautified_html);

    // Free the allocated memory
    free(beautified_html);
  }
  fclose(fp);

  return EXIT_SUCCESS;
}