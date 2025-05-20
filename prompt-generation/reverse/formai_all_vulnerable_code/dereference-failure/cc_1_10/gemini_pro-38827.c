//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);

  // Initialize the beautified HTML code
  strcpy(beautified_html, "");

  // Iterate over the HTML code
  for (int i = 0; i < strlen(html); i++) {
    // Get the current character
    char c = html[i];

    // If the current character is a newline, add a newline to the beautified HTML code
    if (c == '\n') {
      strcat(beautified_html, "\n");
    }
    // If the current character is a tab, add two spaces to the beautified HTML code
    else if (c == '\t') {
      strcat(beautified_html, "  ");
    }
    // If the current character is a space, add a space to the beautified HTML code
    else if (c == ' ') {
      strcat(beautified_html, " ");
    }
    // If the current character is a less than sign, add a newline and two spaces to the beautified HTML code
    else if (c == '<') {
      strcat(beautified_html, "\n  ");
    }
    // If the current character is a greater than sign, add a newline to the beautified HTML code
    else if (c == '>') {
      strcat(beautified_html, "\n");
    }
    // Otherwise, add the current character to the beautified HTML code
    else {
      char str[2];
      str[0] = c;
      str[1] = '\0';
      strcat(beautified_html, str);
    }
  }

  // Return the beautified HTML code
  return beautified_html;
}

// Main function
int main() {
  // Get the HTML code from the user
  char *html = malloc(1024);
  printf("Enter HTML code: ");
  scanf("%[^\n]%*c", html);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  printf("\nBeautified HTML code:\n%s", beautified_html);

  // Free the memory allocated for the HTML code and the beautified HTML code
  free(html);
  free(beautified_html);

  return 0;
}