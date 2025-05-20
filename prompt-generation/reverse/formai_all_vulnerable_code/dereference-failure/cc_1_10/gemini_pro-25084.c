//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Initialize variables
  char *result = malloc(strlen(html) * 2); // Allocate memory for the result
  int i = 0, j = 0, indent = 0;
  int in_tag = 0, in_comment = 0;

  // Iterate over the HTML code
  while (html[i] != '\0') {
    // Check if we are inside a tag
    if (html[i] == '<') {
      in_tag = 1;
    } else if (html[i] == '>') {
      in_tag = 0;
    }

    // Check if we are inside a comment
    if (html[i] == '-' && html[i + 1] == '-') {
      in_comment = 1;
    } else if (html[i] == '\n') {
      in_comment = 0;
    }

    // If we are inside a tag or a comment, just copy the character to the result
    if (in_tag || in_comment) {
      result[j++] = html[i++];
      continue;
    }

    // If we are not inside a tag or a comment, check if we need to indent
    if (html[i] == '\n') {
      // If the previous character was not a newline, add an indent
      if (result[j - 1] != '\n') {
        for (int k = 0; k < indent; k++) {
          result[j++] = ' ';
        }
      }
    } else if (html[i] == ' ') {
      // If the previous character was not a space, add a space
      if (result[j - 1] != ' ') {
        result[j++] = ' ';
      }
    } else {
      // If the previous character was not a newline or a space, add a newline
      if (result[j - 1] != '\n') {
        result[j++] = '\n';
      }
    }

    // Copy the character to the result
    result[j++] = html[i++];
  }

  // Add a newline at the end of the result
  result[j++] = '\n';

  // Return the result
  return result;
}

// Main function
int main() {
  // Get the HTML code from the user
  char *html = malloc(1024);
  printf("Enter HTML code:\n");
  gets(html);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  printf("\nBeautified HTML code:\n\n%s\n", beautified_html);

  // Free the memory allocated for the HTML code and the beautified HTML code
  free(html);
  free(beautified_html);

  return 0;
}