//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify the HTML code
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML
  char *beautified = malloc(strlen(html) * 2);

  // Initialize the beautified HTML string
  beautified[0] = '\0';

  // Parse the HTML code
  int level = 0;
  char *start_tag = NULL;
  char *end_tag = NULL;
  int start_tag_length = 0;
  int end_tag_length = 0;
  for (char *p = html; *p != '\0'; p++) {
    // Check if the current character is the start of a tag
    if (*p == '<') {
      start_tag = p;
      start_tag_length = 0;
      end_tag = NULL;
      end_tag_length = 0;
      while (*p != '>' && *p != '\0') {
        p++;
        start_tag_length++;
      }
      if (*p == '>') {
        // Check if the current character is the start of an end tag
        if (*(p + 1) == '/') {
          end_tag = p + 1;
          end_tag_length = 0;
          while (*(p + 1) != '>' && *(p + 1) != '\0') {
            p++;
            end_tag_length++;
          }
        }
      }
    }

    // Check if the current character is the end of a tag
    if (*p == '>') {
      // If the current character is the end of an end tag, decrease the level
      if (end_tag != NULL && end_tag_length > 0) {
        level--;
        end_tag = NULL;
        end_tag_length = 0;
      }

      // If the current character is the end of a start tag, increase the level
      else if (start_tag != NULL && start_tag_length > 0) {
        level++;
        start_tag = NULL;
        start_tag_length = 0;
      }
    }

    // Append the current character to the beautified HTML
    for (int i = 0; i < level; i++) {
      strcat(beautified, "  ");
    }
    strncat(beautified, p, 1);
    if (*p == '\n') {
      strcat(beautified, "\n");
    }
  }

  return beautified;
}

// Main function
int main() {
  // Get the input HTML code from the user
  char *html = malloc(1000);
  printf("Enter the HTML code: ");
  gets(html);

  // Beautify the HTML code
  char *beautified = beautify_html(html);

  // Print the beautified HTML code
  printf("\nBeautified HTML code:\n");
  puts(beautified);

  // Free the allocated memory
  free(html);
  free(beautified);

  return 0;
}