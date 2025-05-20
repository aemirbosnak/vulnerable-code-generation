//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants and Macros
#define INDENT 2
#define MAX_LINE_LENGTH 100

// Function Declarations
char *ReadFile(char *filename);
void BeautifyHTML(char *html);
void PrintHTML(char *html);

// Main Function
int main() {
  // Read HTML code from file
  char *html = ReadFile("input.html");

  // Beautify the HTML code
  BeautifyHTML(html);

  // Print the beautified HTML code
  PrintHTML(html);

  return 0;
}

// Reads HTML code from a file
char *ReadFile(char *filename) {
  FILE *file;
  char *html;
  long length;

  // Open the file
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Could not open file %s\n", filename);
    exit(1);
  }

  // Get the length of the file
  fseek(file, 0, SEEK_END);
  length = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory for the HTML code
  html = malloc(length);
  if (html == NULL) {
    printf("Error: Could not allocate memory for HTML code\n");
    exit(1);
  }

  // Read the HTML code from the file
  fread(html, 1, length, file);
  fclose(file);

  return html;
}

// Beautifies the HTML code
void BeautifyHTML(char *html) {
  int i, j, level;
  char *newHtml;
  char *line;
  char *token;
  char *tags[100];
  int tagCount = 0;

  // Allocate memory for the new HTML code
  newHtml = malloc(strlen(html) * 2);
  if (newHtml == NULL) {
    printf("Error: Could not allocate memory for new HTML code\n");
    exit(1);
  }

  // Initialize the new HTML code
  newHtml[0] = '\0';

  // Split the HTML code into lines
  line = strtok(html, "\n");
  while (line != NULL) {
    // Trim leading and trailing whitespace from the line
    line = strtok(NULL, "\n");
    line = strtok(line, "\t");
    line = strtok(line, " ");

    // If the line is empty, continue to the next line
    if (line == NULL) {
      continue;
    }

    // Get the level of indentation for the line
    level = 0;
    for (i = 0; i < strlen(line); i++) {
      if (line[i] == ' ') {
        level++;
      } else {
        break;
      }
    }

    // Indent the line
    for (i = 0; i < level * INDENT; i++) {
      strcat(newHtml, " ");
    }

    // Parse the line and add it to the new HTML code
    token = strtok(line, "<>");
    while (token != NULL) {
      if (strstr(token, "<") != NULL) {
        // It is a tag
        tags[tagCount++] = token;
        strcat(newHtml, token);
      } else {
        // It is text
        strcat(newHtml, token);
      }
      token = strtok(NULL, "<>");
    }

    // Add a newline to the new HTML code
    strcat(newHtml, "\n");
  }

  // Free the old HTML code
  free(html);

  // Replace the old HTML code with the new HTML code
  html = newHtml;
}

// Prints the HTML code
void PrintHTML(char *html) {
  printf("%s", html);
}