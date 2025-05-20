//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to beautify HTML code
char *beautify_html(char *html) {
  // allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);

  // initialize the beautified HTML code
  beautified_html[0] = '\0';

  // loop through the HTML code
  for (int i = 0; i < strlen(html); i++) {
    // if the current character is a '<' or '>'
    if (html[i] == '<' || html[i] == '>') {
      // append the current character to the beautified HTML code
      strcat(beautified_html, &html[i]);

      // if the current character is a '<'
      if (html[i] == '<') {
        // append a newline character to the beautified HTML code
        strcat(beautified_html, "\n");
      }
    }
    // if the current character is a whitespace character
    else if (isspace(html[i])) {
      // append a space character to the beautified HTML code
      strcat(beautified_html, " ");
    }
    // otherwise
    else {
      // append the current character to the beautified HTML code
      strcat(beautified_html, &html[i]);
    }
  }

  // return the beautified HTML code
  return beautified_html;
}

// main function
int main() {
  // read the HTML code from standard input
  char *html = NULL;
  size_t len = 0;
  getline(&html, &len, stdin);

  // beautify the HTML code
  char *beautified_html = beautify_html(html);

  // print the beautified HTML code to standard output
  printf("%s", beautified_html);

  // free the memory allocated for the beautified HTML code
  free(beautified_html);

  // return 0 to indicate successful execution
  return 0;
}