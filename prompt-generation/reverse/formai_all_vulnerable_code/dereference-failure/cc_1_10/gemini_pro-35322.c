//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to remove leading and trailing whitespace from a string
char *trim(char *str) {
  char *end;

  // Trim leading whitespace
  while(isspace(*str)) str++;

  // Trim trailing whitespace
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--;

  // Write new null terminator
  *++end = '\0';

  return str;
}

// Function to beautify HTML code
char *beautify_html(char *html) {
  char *new_html = NULL;
  char *line = NULL;
  int line_num = 0;
  int indent_level = 0;

  // Tokenize HTML code by line
  line = strtok(html, "\n");
  while(line) {
    // Trim leading and trailing whitespace from line
    line = trim(line);

    // Skip empty lines
    if(!*line) {
      line = strtok(NULL, "\n");
      continue;
    }

    // Increase indent level for open tags
    if(strstr(line, "<") && !strstr(line, "/>")) {
      indent_level++;
    }

    // Decrease indent level for close tags
    if(strstr(line, "</")) {
      indent_level--;
    }

    // Add indentation to line
    char *indentation = malloc(indent_level * 2 + 1);
    memset(indentation, ' ', indent_level * 2);
    indentation[indent_level * 2] = '\0';
    line = strcat(indentation, line);

    // Add line to new HTML code
    new_html = realloc(new_html, strlen(new_html) + strlen(line) + 1);
    strcat(new_html, line);
    strcat(new_html, "\n");

    // Get next line
    line = strtok(NULL, "\n");
  }

  return new_html;
}

int main() {
  // Read HTML code from file
  FILE *fp = fopen("input.html", "r");
  if(fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  rewind(fp);

  char *html = malloc(file_size + 1);
  if(html == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return EXIT_FAILURE;
  }

  fread(html, 1, file_size, fp);
  fclose(fp);

  // Beautify HTML code
  char *new_html = beautify_html(html);
  if(new_html == NULL) {
    perror("Error beautifying HTML code");
    free(html);
    return EXIT_FAILURE;
  }

  // Write beautified HTML code to file
  fp = fopen("output.html", "w");
  if(fp == NULL) {
    perror("Error opening file");
    free(html);
    free(new_html);
    return EXIT_FAILURE;
  }

  fwrite(new_html, 1, strlen(new_html), fp);
  fclose(fp);

  // Free memory
  free(html);
  free(new_html);

  return EXIT_SUCCESS;
}