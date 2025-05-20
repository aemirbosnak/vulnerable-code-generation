//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Length of HTML code
  int len = strlen(html);

  // Create a new string to store the beautified HTML code
  char *beautified_html = malloc(len * 2); // Double the length to accommodate for indentation

  // Index of the current character in the HTML code
  int i = 0;

  // Index of the current character in the beautified HTML code
  int j = 0;

  // Indentation level
  int level = 0;

  // Loop through the HTML code
  while (i < len) {
    // Get the current character
    char c = html[i];

    // If the current character is a '<'
    if (c == '<') {
      // Increment the indentation level
      level++;

      // Add the current character to the beautified HTML code
      beautified_html[j++] = c;

      // If the next character is a '/'
      if (html[i + 1] == '/') {
        // Add a newline to the beautified HTML code
        beautified_html[j++] = '\n';

        // Add the next character to the beautified HTML code
        beautified_html[j++] = html[i + 1];

        // Increment the index of the current character
        i++;

        // If the next character is not a '>'
        if (html[i + 1] != '>') {
          // Add a newline to the beautified HTML code
          beautified_html[j++] = '\n';
        }
      } else {
        // Add a newline to the beautified HTML code
        beautified_html[j++] = '\n';

        // Add the indentation for the current level
        for (int k = 0; k < level; k++) {
          beautified_html[j++] = ' ';
        }

        // Add the next character to the beautified HTML code
        beautified_html[j++] = html[i + 1];

        // Increment the index of the current character
        i++;

        // If the next character is not a '>'
        if (html[i + 1] != '>') {
          // Add a newline to the beautified HTML code
          beautified_html[j++] = '\n';
        }
      }
    } else if (c == '>') {
      // Decrement the indentation level
      level--;

      // Add the current character to the beautified HTML code
      beautified_html[j++] = c;

      // Add a newline to the beautified HTML code
      beautified_html[j++] = '\n';

      // Add the indentation for the current level
      for (int k = 0; k < level; k++) {
        beautified_html[j++] = ' ';
      }
    } else {
      // Add the current character to the beautified HTML code
      beautified_html[j++] = c;
    }

    // Increment the index of the current character
    i++;
  }

  // Add a null-terminator to the beautified HTML code
  beautified_html[j] = '\0';

  // Return the beautified HTML code
  return beautified_html;
}

// Main function
int main() {
  // HTML code to beautify
  char *html = "<html>\n<head>\n<title>Hello, World!</title>\n</head>\n<body>\n<h1>Hello, World!</h1>\n</body>\n</html>";

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  printf("%s", beautified_html);

  // Free the memory allocated for the beautified HTML code
  free(beautified_html);

  return 0;
}