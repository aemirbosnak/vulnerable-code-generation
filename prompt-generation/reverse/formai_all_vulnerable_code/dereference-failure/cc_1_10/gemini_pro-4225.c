//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);

  // Initialize the beautified HTML code
  beautified_html[0] = '\0';

  // Iterate over the HTML code
  int i = 0;
  while (html[i] != '\0') {
    // If the current character is a newline character
    if (html[i] == '\n') {
      // Add a newline character to the beautified HTML code
      strcat(beautified_html, "\n");
    }
    // If the current character is a whitespace character
    else if (isspace(html[i])) {
      // Add a space character to the beautified HTML code
      strcat(beautified_html, " ");
    }
    // If the current character is an opening angle bracket
    else if (html[i] == '<') {
      // Add an opening angle bracket to the beautified HTML code
      strcat(beautified_html, "<");

      // Iterate over the next characters until the closing angle bracket is found
      int j = i + 1;
      while (html[j] != '>') {
        // Add the next character to the beautified HTML code
        strcat(beautified_html, &html[j]);

        // Increment the index of the next character
        j++;
      }

      // Add a closing angle bracket to the beautified HTML code
      strcat(beautified_html, ">");

      // Increment the index of the current character
      i = j;
    }
    // If the current character is a closing angle bracket
    else if (html[i] == '>') {
      // Add a closing angle bracket to the beautified HTML code
      strcat(beautified_html, ">");

      // Increment the index of the current character
      i++;
    }
    // If the current character is any other character
    else {
      // Add the current character to the beautified HTML code
      char c[2];
      c[0] = html[i];
      c[1] = '\0';
      strcat(beautified_html, c);

      // Increment the index of the current character
      i++;
    }
  }

  // Return the beautified HTML code
  return beautified_html;
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

    // Write the beautified HTML code to a file
    FILE *fp2 = fopen("output.html", "a");
    if (fp2 == NULL) {
      perror("Error opening file");
      return EXIT_FAILURE;
    }

    fprintf(fp2, "%s", beautified_html);
    fclose(fp2);

    // Free the memory allocated for the beautified HTML code
    free(beautified_html);
  }

  // Close the file
  fclose(fp);

  return EXIT_SUCCESS;
}