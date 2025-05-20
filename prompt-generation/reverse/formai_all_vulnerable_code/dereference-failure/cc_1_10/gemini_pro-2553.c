//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautified_html = (char *)malloc(strlen(html) * 2);

  // Initialize the beautified HTML code
  beautified_html[0] = '\0';

  // Iterate over the HTML code
  int i = 0;
  while (html[i] != '\0') {
    // If the current character is a '<', then it is the start of a tag
    if (html[i] == '<') {
      // Copy the tag to the beautified HTML code
      int j = i;
      while (html[j] != '>' && html[j] != '\0') {
        beautified_html[j - i] = html[j];
        j++;
      }
      beautified_html[j - i] = html[j];
      i = j + 1;

      // If the tag is a self-closing tag, then add a newline after it
      if (html[j - 1] == '/') {
        strcat(beautified_html, "\n");
      }
    }
    // If the current character is not a '<', then it is part of the text
    else {
      // Copy the text to the beautified HTML code
      int j = i;
      while (html[j] != '<' && html[j] != '\0') {
        beautified_html[j - i] = html[j];
        j++;
      }
      beautified_html[j - i] = '\0';
      i = j;

      // If the text contains a newline, then add a newline to the beautified HTML code
      if (strchr(beautified_html, '\n') != NULL) {
        strcat(beautified_html, "\n");
      }
    }
  }

  // Return the beautified HTML code
  return beautified_html;
}

// Main function
int main() {
  // Get the HTML code from the user
  char *html = (char *)malloc(1024);
  printf("Enter the HTML code: ");
  gets(html);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  printf("Beautified HTML code:\n%s", beautified_html);

  // Free the memory allocated for the beautified HTML code
  free(beautified_html);

  // Free the memory allocated for the HTML code
  free(html);

  return 0;
}