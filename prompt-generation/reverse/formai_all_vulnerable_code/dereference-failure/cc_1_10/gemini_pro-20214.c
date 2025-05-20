//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the beautify function
char *beautify(char *html);

// Main function
int main() {
  // Get the HTML code from the user
  char *html = malloc(10000);
  printf("Enter your HTML code:\n");
  scanf("%s", html);

  // Beautify the HTML code
  char *beautifiedHtml = beautify(html);

  // Print the beautified HTML code
  printf("Beautified HTML code:\n");
  printf("%s", beautifiedHtml);

  // Free the allocated memory
  free(html);
  free(beautifiedHtml);

  return 0;
}

// Function to beautify the HTML code
char *beautify(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautifiedHtml = malloc(10000);

  // Initialize the beautified HTML code
  beautifiedHtml[0] = '\0';

  // Loop through the HTML code
  int i = 0;
  while (html[i] != '\0') {
    // Check if the current character is a '<'
    if (html[i] == '<') {
      // Check if the next character is a '/'
      if (html[i + 1] == '/') {
        // Check if the next character is a '>'
        if (html[i + 2] == '>') {
          // Add a newline character to the beautified HTML code
          strcat(beautifiedHtml, "\n");

          // Increment the index by 3
          i += 3;
        } else {
          // Add the current character to the beautified HTML code
          strncat(beautifiedHtml, &html[i], 1);

          // Increment the index by 1
          i++;
        }
      } else {
        // Add the current character to the beautified HTML code
        strncat(beautifiedHtml, &html[i], 1);

        // Increment the index by 1
        i++;
      }
    } else {
      // Add the current character to the beautified HTML code
      strncat(beautifiedHtml, &html[i], 1);

      // Increment the index by 1
      i++;
    }
  }

  // Return the beautified HTML code
  return beautifiedHtml;
}