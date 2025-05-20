//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-themed ASCII art
#define CYBER_ART "                                                 _   _ \n" \
                   "                                                | | | |\n" \
                   "  ___  __ _  _ __   ___  ___   _   _  ___   ___ |_| |_|\n" \
                   " / _ \\/ _` || '_ \\ / _ \\/ _ \\ | | | |/ _ \\ / _ \\ __| __|\n" \
                   "|  __/ (_| || | | |  __/  __/ | |_| |  __/|  __/ |_ | |_ \n" \
                   " \\___|\\__,_||_| |_|\\___|\\___|  \\__, |\\___| \\___|\\__|\\__|\n" \
                   "                                 __/ |                    \n" \
                   "                                |___/                     \n"

// HTML tags and attributes
#define HTML_TAGS "<html><head><body><title><p><h1><h2><h3><h4><h5><h6><br>\n" \
                   "<a><img><ul><li><ol><dl><dt><dd><table<tr><td><th><tfoot><tbody>\n" \
                   "<form><input><button><textarea><select><option>"
#define HTML_ATTRIBUTES "href=\"src=\"alt=\"title=\"type=\"value=\""

// Function to beautify HTML code
char *beautify_html(char *input) {
  // Cyberpunk-themed header
  char *output = malloc(strlen(CYBER_ART) + strlen(input) + 100);
  strcpy(output, CYBER_ART);

  // Split the input into tokens
  char *tokens[100];
  int num_tokens = 0;
  char *token = strtok(input, " ");
  while (token != NULL) {
    tokens[num_tokens] = token;
    num_tokens++;
    token = strtok(NULL, " ");
  }

  // Indent and format the tokens
  int indent_level = 0;
  for (int i = 0; i < num_tokens; i++) {
    // Check if the token is a start tag
    if (strstr(HTML_TAGS, tokens[i]) != NULL) {
      // Indent the token and add a newline
      for (int j = 0; j < indent_level; j++) {
        strcat(output, "  ");
      }
      strcat(output, tokens[i]);
      strcat(output, "\n");

      // Increase the indent level
      indent_level++;
    }
    // Check if the token is an end tag
    else if (tokens[i][0] == '<' && tokens[i][1] == '/') {
      // Decrease the indent level
      indent_level--;

      // Indent the token and add a newline
      for (int j = 0; j < indent_level; j++) {
        strcat(output, "  ");
      }
      strcat(output, tokens[i]);
      strcat(output, "\n");
    }
    // Check if the token is an attribute
    else if (strstr(HTML_ATTRIBUTES, tokens[i]) != NULL) {
      // Add the attribute to the previous token
      strcat(output, tokens[i]);
    }
    // Check if the token is a newline
    else if (strcmp(tokens[i], "\n") == 0) {
      // Add a newline to the output
      strcat(output, "\n");
    }
    // Otherwise, add the token to the output
    else {
      // Indent the token
      for (int j = 0; j < indent_level; j++) {
        strcat(output, "  ");
      }
      strcat(output, tokens[i]);
      strcat(output, " ");
    }
  }

  // Cyberpunk-themed footer
  strcat(output, "\n");
  strcat(output, CYBER_ART);

  // Return the beautified HTML code
  return output;
}

// Main function
int main() {
  // Get the input HTML code from the user
  char *input = malloc(1000);
  printf("Enter your HTML code:\n");
  fgets(input, 1000, stdin);

  // Beautify the HTML code
  char *output = beautify_html(input);

  // Print the beautified HTML code to the console
  printf("\nBeautified HTML code:\n%s\n", output);

  // Free the allocated memory
  free(input);
  free(output);

  return 0;
}