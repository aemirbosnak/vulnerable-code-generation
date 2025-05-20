//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to beautify the HTML code
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);
  if (beautified_html == NULL) {
    return NULL;
  }

  // Initialize the beautified HTML code
  beautified_html[0] = '\0';

  // Iterate over the HTML code
  int i = 0;
  while (html[i] != '\0') {
    // Check if the current character is a '<' character
    if (html[i] == '<') {
      // Check if the next character is a '/' character
      if (html[i + 1] == '/') {
        // Check if the next character is a '>' character
        if (html[i + 2] == '>') {
          // Append a newline character to the beautified HTML code
          strcat(beautified_html, "\n");

          // Increment the index by 3
          i += 3;
        } else {
          // Append the current character to the beautified HTML code
          strcat(beautified_html, &html[i]);

          // Increment the index by 1
          i++;
        }
      } else {
        // Append the current character to the beautified HTML code
        strcat(beautified_html, &html[i]);

        // Increment the index by 1
        i++;
      }
    } else {
      // Check if the current character is a '>' character
      if (html[i] == '>') {
        // Append a newline character to the beautified HTML code
        strcat(beautified_html, "\n");

        // Increment the index by 1
        i++;
      } else {
        // Append the current character to the beautified HTML code
        strcat(beautified_html, &html[i]);

        // Increment the index by 1
        i++;
      }
    }
  }

  // Append a newline character to the beautified HTML code
  strcat(beautified_html, "\n");

  // Return the beautified HTML code
  return beautified_html;
}

// Main function
int main() {
  // Get the HTML code from the user
  char html[MAX_LINE_LENGTH];
  printf("Enter the HTML code: ");
  fgets(html, MAX_LINE_LENGTH, stdin);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  printf("Beautified HTML code:\n%s", beautified_html);

  // Free the memory allocated for the beautified HTML code
  free(beautified_html);

  return 0;
}