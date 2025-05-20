//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TAB_SIZE 4
#define INDENT_SIZE 2

void html_beautify(char *input_html) {
  char *output_html = NULL;
  char *token = NULL;
  char *prev_token = NULL;
  int indent_level = 0;
  int bracket_level = 0;
  int current_token_len = 0;

  // Step 1: Tokenize the input HTML
  token = strtok(input_html, "<");
  while (token != NULL && token[0] != '\0') {
    current_token_len = strcspn(token, ">");
    if (current_token_len > 0) {
      // Check if the current token is a starting bracket
      if (token[current_token_len - 1] == '<') {
        bracket_level++;
      }
      // Check if the current token is an ending bracket
      else if (token[current_token_len - 1] == '>') {
        bracket_level--;
      }
      // If the current token is not a bracket, add it to the output HTML
      if (bracket_level == 0) {
        if (prev_token != NULL) {
          output_html = realloc(output_html, strlen(output_html) + current_token_len + 1);
          strcat(output_html, token);
          strcat(output_html, " ");
        }
        prev_token = token;
      }
    }
    token = strtok(NULL, "<");
  }

  // Step 2: Indent the output HTML
  for (int i = 0; i < indent_level; i++) {
    output_html = realloc(output_html, strlen(output_html) + TAB_SIZE);
    strcat(output_html, "\t");
  }

  // Step 3: Add spaces between tags
  for (int i = 0; i < bracket_level; i++) {
    output_html = realloc(output_html, strlen(output_html) + 2);
    strcat(output_html, " ");
  }

  // Step 4: Output the final HTML
  printf("%s\n", output_html);

  // Free memory
  free(output_html);
}

int main() {
  char input_html[] = "<html><body><p>This is a sample HTML code.</p><ul><li>Item 1</li><li>Item 2</li></ul></body></html>";
  html_beautify(input_html);
  return 0;
}