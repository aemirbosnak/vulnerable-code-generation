//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);

  // Initialize the beautified HTML code
  strcpy(beautified_html, "");

  // Loop through the HTML code
  int i = 0;
  while (html[i] != '\0') {
    // If the current character is a '<' character, then start a new line
    if (html[i] == '<') {
      strcat(beautified_html, "\n");
    }

    // If the current character is a '>' character, then end the current line
    else if (html[i] == '>') {
      strcat(beautified_html, "\n");
    }

    // Otherwise, add the current character to the beautified HTML code
    else {
      char c = html[i];
      strncat(beautified_html, &c, 1);
    }

    // Increment the index of the current character
    i++;
  }

  // Return the beautified HTML code
  return beautified_html;
}

// Main function
int main() {
  // Get the HTML code from the user
  char *html = malloc(1000);
  printf("Enter HTML code: ");
  scanf("%s", html);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  printf("Beautified HTML code:\n%s", beautified_html);

  // Free the memory allocated for the HTML code and the beautified HTML code
  free(html);
  free(beautified_html);

  return 0;
}