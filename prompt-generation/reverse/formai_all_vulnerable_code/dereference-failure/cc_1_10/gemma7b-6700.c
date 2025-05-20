//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void beautify_html(char **html_code) {
  int i = 0, j = 0, indent = 0;
  char buffer[MAX_BUFFER_SIZE] = "";

  // Allocate memory for the output buffer
  *html_code = malloc(MAX_BUFFER_SIZE);

  // Loop over the input HTML code
  for (i = 0; html_code[i] != NULL; i++) {
    // Check for tags and adjust indentation
    if (html_code[i] == '<' && html_code[i + 1] == ' ') {
      indent++;
    } else if (html_code[i] == '>' && html_code[i - 1] == ' ') {
      indent--;
    }

    // Append characters to the output buffer with indentation
    buffer[j++] = html_code[i];
    for (int k = 0; k < indent; k++) {
      buffer[j++] = ' ';
    }
  }

  // Copy the beautified HTML code to the output buffer
  strcpy(*html_code, buffer);

  // Free the memory allocated for the temporary buffer
  free(buffer);
}

int main() {
  char *html_code = NULL;

  // Example HTML code
  char html_text[] = "<p>This is a sample HTML paragraph.</p><h1>This is a heading</h1>";

  // Beautify the HTML code
  beautify_html(&html_code);

  // Print the beautified HTML code
  printf("%s", html_code);

  // Free the memory allocated for the beautified HTML code
  free(html_code);

  return 0;
}