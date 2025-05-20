//GEMINI-pro DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line
#define MAX_LINE_LENGTH 1024

// Define the maximum number of lines
#define MAX_LINES 100

// Define the structure of a line
typedef struct line {
  char *str;
  int length;
} line;

// Define the structure of a list of lines
typedef struct line_list {
  line *lines;
  int num_lines;
} line_list;

// Read a line from a file
line read_line(FILE *file) {
  char *str = malloc(MAX_LINE_LENGTH);
  int length = 0;
  char c;
  while ((c = fgetc(file)) != '\n' && c != EOF) {
    str[length++] = c;
  }
  str[length] = '\0';
  return (line){str, length};
}

// Read a list of lines from a file
line_list read_lines(FILE *file) {
  line_list lines = {malloc(MAX_LINES * sizeof(line)), 0};
  while (!feof(file)) {
    lines.lines[lines.num_lines++] = read_line(file);
  }
  return lines;
}

// Print a line to a file
void print_line(FILE *file, line line) {
  fprintf(file, "%s\n", line.str);
}

// Print a list of lines to a file
void print_lines(FILE *file, line_list lines) {
  for (int i = 0; i < lines.num_lines; i++) {
    print_line(file, lines.lines[i]);
  }
}

// Free the memory allocated for a line
void free_line(line line) {
  free(line.str);
}

// Free the memory allocated for a list of lines
void free_lines(line_list lines) {
  for (int i = 0; i < lines.num_lines; i++) {
    free_line(lines.lines[i]);
  }
  free(lines.lines);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  line_list lines = read_lines(file);

  fclose(file);

  print_lines(stdout, lines);

  free_lines(lines);

  return 0;
}