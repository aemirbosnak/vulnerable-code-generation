//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters in a line of text
#define MAX_LINE_LENGTH 1024

// Define the maximum number of lines of text
#define MAX_LINES 100

// Define the character to use for the ASCII art
#define ASCII_CHARACTER '*'

// Function to convert a line of text to ASCII art
char* text_to_ascii(char* line) {
  int length = strlen(line);
  char* ascii_art = malloc(length * sizeof(char));

  for (int i = 0; i < length; i++) {
    ascii_art[i] = ASCII_CHARACTER;
  }

  return ascii_art;
}

// Function to print the ASCII art for a line of text
void print_ascii_art(char* line) {
  char* ascii_art = text_to_ascii(line);
  printf("%s\n", ascii_art);

  free(ascii_art);
}

// Function to print the ASCII art for a block of text
void print_block_of_ascii_art(char* lines[], int num_lines) {
  for (int i = 0; i < num_lines; i++) {
    print_ascii_art(lines[i]);
  }

  printf("\n");
}

// Function to get the lines of text from a file
char** get_lines_from_file(char* filename, int* num_lines) {
  FILE* file = fopen(filename, "r");

  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  char** lines = malloc(MAX_LINES * sizeof(char*));
  int line_count = 0;

  while (fgets(lines[line_count], MAX_LINE_LENGTH, file) != NULL) {
    line_count++;
  }

  fclose(file);

  *num_lines = line_count;

  return lines;
}

// Main function
int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  char* filename = argv[1];

  int num_lines;
  char** lines = get_lines_from_file(filename, &num_lines);

  print_block_of_ascii_art(lines, num_lines);

  for (int i = 0; i < num_lines; i++) {
    free(lines[i]);
  }

  free(lines);

  return 0;
}