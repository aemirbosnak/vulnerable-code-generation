//FormAI DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

  // Check for command line arguments
  if (argc != 3) {
    printf("Usage: ./beautify input_file output_file\n");
    exit(1);
  }

  // Open files
  FILE* input_file = fopen(argv[1], "r");
  FILE* output_file = fopen(argv[2], "w");

  // Check if files opened successfully
  if (input_file == NULL || output_file == NULL) {
    printf("Error: Could not open file\n");
    exit(1);
  }

  // Get file size
  fseek(input_file, 0, SEEK_END);
  long file_size = ftell(input_file);
  fseek(input_file, 0, SEEK_SET);

  // Allocate memory for input file
  char* file_buffer = (char*) malloc(file_size + 1);

  if (file_buffer == NULL) {
    printf("Error: Could not allocate memory\n");
    exit(1);
  }

  // Read input file into buffer
  size_t bytes_read = fread(file_buffer, 1, file_size, input_file);
  
  if (bytes_read != file_size) {
    printf("Error: Could not read entire file\n");
    exit(1);
  }

  // Add null terminator to buffer
  file_buffer[file_size] = '\0';

  // Variables for keeping track of state
  int indent_level = 0;
  int should_indent = 0;
  int in_tag = 0;
  int in_quotes = 0;

  // Loop through input buffer, writing output to output file
  int i;
  for (i = 0; i < file_size; i++) {
    char c = file_buffer[i];

    // Handle quotes
    if (c == '"' || c == '\'') {
      in_quotes = !in_quotes;
    }

    // Handle start tag
    if (!in_quotes && c == '<' && file_buffer[i+1] != '/') {
      in_tag = 1;

      if (should_indent) {
        fprintf(output_file, "\n");
        int j;
        for (j = 0; j < indent_level; j++) {
          fprintf(output_file, "  ");
        }
      }

      indent_level++;
      should_indent = 1;
    }

    // Handle end tag
    else if (!in_quotes && c == '<' && file_buffer[i+1] == '/') {
      in_tag = 1;
      indent_level--;
      should_indent = 0;
      fprintf(output_file, "\n");

      int j;
      for (j = 0; j < indent_level; j++) {
        fprintf(output_file, "  ");
      }
    }

    // Write character to output file
    fprintf(output_file, "%c", c);

    // Handle closing tag
    if (!in_quotes && c == '>') {
      in_tag = 0;

      if (should_indent) {
        should_indent = 0;
      }
    }

    // Insert newline after comments
    if (!in_quotes && c == '-' && file_buffer[i+1] == '-' && in_tag) {
      fprintf(output_file, "\n");
      int j;
      for (j = 0; j < indent_level; j++) {
        fprintf(output_file, "  ");
      }
    }
  }

  // Close input/output files
  fclose(input_file);
  fclose(output_file);

  // Free memory
  free(file_buffer);

  // Success message
  printf("HTML beautification complete!\n");

  return 0;
}