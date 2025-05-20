//GEMINI-pro DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the file buffer
#define BUF_SIZE 1024

// Define the maximum number of lines in the file
#define MAX_LINES 100

// Define the maximum length of a line in the file
#define MAX_LINE_LEN 1024

// Define the name of the input file
#define INPUT_FILE "input.txt"

// Define the name of the output file
#define OUTPUT_FILE "output.txt"

// Main function
int main() {
  // Open the input file for reading
  FILE *input_file = fopen(INPUT_FILE, "r");
  if (input_file == NULL) {
    perror("Error opening input file");
    return EXIT_FAILURE;
  }

  // Open the output file for writing
  FILE *output_file = fopen(OUTPUT_FILE, "w");
  if (output_file == NULL) {
    perror("Error opening output file");
    return EXIT_FAILURE;
  }

  // Read the input file line by line
  char line[MAX_LINE_LEN];
  int line_count = 0;
  while (fgets(line, MAX_LINE_LEN, input_file) != NULL) {
    // Increment the line count
    line_count++;

    // Check if the line is too long
    if (strlen(line) > MAX_LINE_LEN) {
      fprintf(stderr, "Error: Line %d is too long\n", line_count);
      return EXIT_FAILURE;
    }

    // Write the line to the output file
    fputs(line, output_file);
  }

  // Close the input file
  fclose(input_file);

  // Close the output file
  fclose(output_file);

  // Print the number of lines in the file
  printf("Number of lines in the file: %d\n", line_count);

  return EXIT_SUCCESS;
}