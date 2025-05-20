//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void beautify_html(char *input) {
  char *output = malloc(MAX_LINE_LENGTH);
  int output_length = 0;

  int indent_level = 0;
  char *current_tag = NULL;
  char *previous_tag = NULL;

  char *line = strtok(input, "\n");
  while (line) {
    // Remove whitespace from the beginning of the line
    while (*line == ' ' || *line == '\t') {
      line++;
    }

    // If the line is empty, skip it
    if (*line == '\0') {
      line = strtok(NULL, "\n");
      continue;
    }

    // Check if the line is a start tag
    if (*line == '<') {
      // Find the end of the tag name
      char *tag_end = strchr(line, '>');
      if (!tag_end) {
        // Invalid tag, ignore it
        line = strtok(NULL, "\n");
        continue;
      }

      // Get the tag name
      char *tag_name = malloc(tag_end - line + 1);
      strncpy(tag_name, line + 1, tag_end - line - 1);
      tag_name[tag_end - line - 1] = '\0';

      // If the tag is a self-closing tag, ignore it
      if (*tag_end == '/') {
        free(tag_name);
        line = strtok(NULL, "\n");
        continue;
      }

      // If the tag is the same as the previous tag, increase the indent level
      if (strcmp(tag_name, current_tag) == 0) {
        indent_level++;
      }

      // If the tag is a different tag, reset the indent level and set the current tag
      else {
        indent_level = 0;
        current_tag = tag_name;
      }

      // Add the tag to the output, indented with the appropriate number of spaces
      for (int i = 0; i < indent_level; i++) {
        output[output_length++] = ' ';
      }
      strcat(output, line);
      output_length += strlen(line);
      output[output_length++] = '\n';

      // Set the previous tag to the current tag
      previous_tag = current_tag;
    }

    // If the line is an end tag
    else if (*line == '/') {
      // Find the end of the tag name
      char *tag_end = strchr(line, '>');
      if (!tag_end) {
        // Invalid tag, ignore it
        line = strtok(NULL, "\n");
        continue;
      }

      // Get the tag name
      char *tag_name = malloc(tag_end - line + 1);
      strncpy(tag_name, line + 2, tag_end - line - 2);
      tag_name[tag_end - line - 2] = '\0';

      // If the tag is the same as the current tag, decrease the indent level
      if (strcmp(tag_name, current_tag) == 0) {
        indent_level--;
      }

      // If the tag is a different tag, ignore it
      else {
        free(tag_name);
        line = strtok(NULL, "\n");
        continue;
      }

      // Add the tag to the output, indented with the appropriate number of spaces
      for (int i = 0; i < indent_level; i++) {
        output[output_length++] = ' ';
      }
      strcat(output, line);
      output_length += strlen(line);
      output[output_length++] = '\n';

      // Set the current tag to the previous tag
      current_tag = previous_tag;
    }

    // If the line is not a tag, add it to the output, indented with the appropriate number of spaces
    else {
      for (int i = 0; i < indent_level; i++) {
        output[output_length++] = ' ';
      }
      strcat(output, line);
      output_length += strlen(line);
      output[output_length++] = '\n';
    }

    // Get the next line
    line = strtok(NULL, "\n");
  }

  // Add a newline to the end of the output
  output[output_length++] = '\n';

  // Free the input and output buffers
  free(input);
  free(output);
}

int main() {
  // Get the input HTML from the user
  char *input = malloc(MAX_LINE_LENGTH);
  printf("Enter the HTML to be beautified:\n");
  fgets(input, MAX_LINE_LENGTH, stdin);

  // Beautify the HTML
  beautify_html(input);

  return 0;
}