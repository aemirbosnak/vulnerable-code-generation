//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: retro
/*
  A retro C HTML beautifier program
  Copyright (c) 2023 Ishaan J. Thakker (ijthaker@gmail.com)

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length of a line
#define MAX_LINE_LENGTH 1024

// Maximum number of lines
#define MAX_LINES 1000

// Structure to store a line of HTML
typedef struct line {
  char *text;
  int length;
} line;

// Array of lines
line lines[MAX_LINES];

// Number of lines
int num_lines;

// Read HTML from a file
void read_html(const char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read the file line by line
  char line_buffer[MAX_LINE_LENGTH];
  while (fgets(line_buffer, MAX_LINE_LENGTH, fp) != NULL) {
    // Allocate memory for the line
    lines[num_lines].text = malloc(strlen(line_buffer) + 1);
    if (lines[num_lines].text == NULL) {
      perror("Error allocating memory");
      exit(1);
    }

    // Copy the line into the array
    strcpy(lines[num_lines].text, line_buffer);

    // Increase the number of lines
    num_lines++;
  }

  // Close the file
  fclose(fp);
}

// Beautify HTML
void beautify_html() {
  // Indent level
  int indent_level = 0;

  // Loop through the lines
  for (int i = 0; i < num_lines; i++) {
    // Get the line
    line *line = &lines[i];

    // Remove leading whitespace
    while (line->text[0] == ' ' || line->text[0] == '\t') {
      line->text++;
      line->length--;
    }

    // Remove trailing whitespace
    while (line->text[line->length - 1] == ' ' || line->text[line->length - 1] == '\t') {
      line->text[line->length - 1] = '\0';
      line->length--;
    }

    // Indent the line
    for (int j = 0; j < indent_level; j++) {
      printf("  ");
    }

    // Print the line
    printf("%s\n", line->text);

    // Update the indent level
    if (strstr(line->text, "<") != NULL) {
      indent_level++;
    } else if (strstr(line->text, "</") != NULL) {
      indent_level--;
    }
  }
}

// Write HTML to a file
void write_html(const char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Write the HTML to the file
  for (int i = 0; i < num_lines; i++) {
    // Get the line
    line *line = &lines[i];

    // Write the line to the file
    fprintf(fp, "%s\n", line->text);
  }

  // Close the file
  fclose(fp);
}

// Print usage information
void usage() {
  printf("Usage: htmlbeautifier <input file> <output file>\n");
  exit(1);
}

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 3) {
    usage();
  }

  // Read the HTML from the input file
  read_html(argv[1]);

  // Beautify the HTML
  beautify_html();

  // Write the HTML to the output file
  write_html(argv[2]);

  // Free the memory allocated for the lines
  for (int i = 0; i < num_lines; i++) {
    free(lines[i].text);
  }

  return 0;
}