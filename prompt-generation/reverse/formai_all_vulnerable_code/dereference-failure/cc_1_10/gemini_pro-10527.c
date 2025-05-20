//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove leading and trailing whitespace from a string
char* trim(char* str) {
  char* end;

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
char* beautify(char* html) {
  int   i, j, k, len;
  char  *beautified, *line, *attr, *val;

  // Allocate memory for beautified HTML
  beautified = (char*)malloc(strlen(html) * 2);

  // Initialize beautified HTML
  beautified[0] = '\0';

  // Split HTML into lines
  line = strtok(html, "\n");
  while(line != NULL) {
    // Trim leading and trailing whitespace from line
    line = trim(line);

    // Check if line is empty
    if(strlen(line) == 0) {
      // Add newline to beautified HTML
      strcat(beautified, "\n");
    }
    // Check if line is a comment
    else if(strncmp(line, "<!--", 4) == 0) {
      // Add comment to beautified HTML
      strcat(beautified, line);
      strcat(beautified, "\n");
    }
    // Check if line is a doctype
    else if(strncmp(line, "<!DOCTYPE", 9) == 0) {
      // Add doctype to beautified HTML
      strcat(beautified, line);
      strcat(beautified, "\n");
    }
    // Check if line is a tag
    else if(line[0] == '<') {
      // Add tag to beautified HTML
      strcat(beautified, line);

      // Get attributes from tag
      attr = strtok(line, " ");
      while(attr != NULL) {
        // Trim leading and trailing whitespace from attribute
        attr = trim(attr);

        // Check if attribute has a value
        if(strchr(attr, '=') != NULL) {
          // Split attribute into name and value
          val = strchr(attr, '=');
          *val++ = '\0';

          // Trim leading and trailing whitespace from value
          val = trim(val);

          // Add attribute to beautified HTML
          strcat(beautified, " ");
          strcat(beautified, attr);
          strcat(beautified, "=\"");
          strcat(beautified, val);
          strcat(beautified, "\"");
        }
        // Otherwise, add attribute to beautified HTML without a value
        else {
          strcat(beautified, " ");
          strcat(beautified, attr);
        }

        // Get next attribute
        attr = strtok(NULL, " ");
      }

      // Add newline to beautified HTML
      strcat(beautified, "\n");
    }
    // Otherwise, line is text
    else {
      // Add text to beautified HTML
      strcat(beautified, line);
      strcat(beautified, "\n");
    }

    // Get next line
    line = strtok(NULL, "\n");
  }

  // Return beautified HTML
  return beautified;
}

int main() {
  // Read HTML code from file
  FILE* fp = fopen("input.html", "r");
  if(fp == NULL) {
    fprintf(stderr, "Error: Unable to open input file.\n");
    return EXIT_FAILURE;
  }

  char* html = (char*)malloc(1024);
  while(fgets(html, 1024, fp) != NULL) {
    // Beautify HTML code
    char* beautified = beautify(html);

    // Write beautified HTML code to file
    FILE* fp = fopen("output.html", "w");
    if(fp == NULL) {
      fprintf(stderr, "Error: Unable to open output file.\n");
      return EXIT_FAILURE;
    }

    fprintf(fp, "%s", beautified);

    // Free memory
    free(beautified);
    fclose(fp);
  }

  // Close file
  fclose(fp);

  return EXIT_SUCCESS;
}