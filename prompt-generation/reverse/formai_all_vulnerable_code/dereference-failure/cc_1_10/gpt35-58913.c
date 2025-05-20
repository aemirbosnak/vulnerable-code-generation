//FormAI DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function to read input file
char* read_file(char* filename) {
  FILE* input_file = fopen(filename, "r");
  if (input_file == NULL) {
    printf("Failed to open input file.\n");
    exit(1);
  }

  // Find size of file
  fseek(input_file, 0, SEEK_END);
  long size = ftell(input_file);
  fseek(input_file, 0, SEEK_SET);

  // Allocate memory for file contents
  char* file_contents = (char*)malloc(size + 1);

  // Read file contents into memory
  fread(file_contents, 1, size, input_file);
  fclose(input_file);

  // Add null terminator
  file_contents[size] = '\0';

  return file_contents;
}

// Function to write beautified HTML to output file
void write_file(char* filename, char* file_contents) {
  FILE* output_file = fopen(filename, "w");
  if (output_file == NULL) {
    printf("Failed to open output file.\n");
    exit(1);
  }

  // Write contents to file
  fwrite(file_contents, 1, sizeof(file_contents), output_file);
  fclose(output_file);
}

// Function to beautify HTML
char* beautify_html(char* file_contents) {
  int indentation_level = 0;
  char* beautified_html = (char*)malloc(sizeof(file_contents));
  char* current_position = beautified_html;

  // Loop through each character in file contents
  for (int i = 0; i < sizeof(file_contents); i++) {
    char current_character = file_contents[i];

    // Check if current character is an opening or closing tag
    if (current_character == '<') {
      if (file_contents[i+1] == '/') {
        indentation_level--;
      }

      // Add new line and indentation
      *current_position = '\n';
      current_position++;
      for (int j = 0; j < indentation_level; j++) {
        *current_position = '\t';
        current_position++;
      }

      // Add current character to beautified HTML
      *current_position = current_character;
      current_position++;

      if (file_contents[i+1] != '/') {
        indentation_level++;
      }
    } else if (current_character == '>') {
      // Add current character to beautified HTML
      *current_position = current_character;
      current_position++;
    } else {
      // Add current character to beautified HTML
      *current_position = current_character;
      current_position++;
    }
  }

  return beautified_html;
}

int main() {
  char* input_filename = "input.html";
  char* output_filename = "output.html";

  // Read input file
  char* file_contents = read_file(input_filename);

  // Beautify HTML
  char* beautified_html = beautify_html(file_contents);

  // Write beautified HTML to output file
  write_file(output_filename, beautified_html);

  printf("Finished beautifying HTML.\n");

  return 0;
}