//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TAB_SIZE 4
#define MAX_DEPTH 5

// Function to traverse the HTML tree and perform formatting
void format_html(char *html) {
  char *token, *next_token;
  int depth = 0;
  int tab_count = 0;

  // Iterate through the HTML tokens
  for (token = strtok(html, " "); token != NULL; token = next_token) {
    // If the token is a tag, format it appropriately
    if (isalpha(*token)) {
      // Increase the depth of the tag
      depth++;

      // If the tag is a self-closing tag, format it as a single line
      if (strcmp(token, "/") == 0) {
        printf("%s%s%s", tab_count * TAB_SIZE, "/>", token + 1);
        continue;
      }

      // Otherwise, format the tag with proper indentation
      printf("%s%s%s", tab_count * TAB_SIZE, "<", token);
      for (next_token = strtok(NULL, " "); next_token != NULL; next_token = strtok(NULL, " ")) {
        if (isalpha(*next_token)) {
          printf("%s%s%s", tab_count * TAB_SIZE, " ", next_token);
        } else {
          printf("%s%s%s", tab_count * TAB_SIZE, "/>", next_token);
        }
      }
      printf("%s%s%s", tab_count * TAB_SIZE, "/>", token + 1);
    }

    // If the token is a text node, format it as a single line
    else if (isspace(*token)) {
      printf("%s%s", tab_count * TAB_SIZE, token);
    }

    // Increment the tab count for the next token
    tab_count++;
  }
}

int main() {
  char input[100];
  char output[100];

  // Read the input HTML from the user
  printf("Enter the raw HTML:\n");
  fgets(input, 100, stdin);

  // Format the HTML and print the output
  format_html(input);
  printf("\nFormatted HTML:\n%s", output);

  return 0;
}