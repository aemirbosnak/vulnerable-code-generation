//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom error type
typedef enum {
  ERR_NONE,
  ERR_INVALID_INPUT,
  ERR_MEMORY_ALLOCATION_FAILED,
  ERR_FILE_NOT_FOUND,
  ERR_IO_ERROR,
} error_t;

// Define a custom error handling function
void handle_error(error_t error) {
  switch (error) {
    case ERR_NONE:
      // No error occurred, do nothing
      break;
    case ERR_INVALID_INPUT:
      // Invalid input was provided, print an error message and exit
      fprintf(stderr, "Invalid input provided.\n");
      exit(EXIT_FAILURE);
    case ERR_MEMORY_ALLOCATION_FAILED:
      // Memory allocation failed, print an error message and exit
      fprintf(stderr, "Memory allocation failed.\n");
      exit(EXIT_FAILURE);
    case ERR_FILE_NOT_FOUND:
      // File not found, print an error message and exit
      fprintf(stderr, "File not found.\n");
      exit(EXIT_FAILURE);
    case ERR_IO_ERROR:
      // I/O error occurred, print an error message and exit
      fprintf(stderr, "I/O error occurred.\n");
      exit(EXIT_FAILURE);
  }
}

// Define a function to open a file
FILE *open_file(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    handle_error(ERR_FILE_NOT_FOUND);
  }
  return fp;
}

// Define a function to read a line from a file
char *read_line(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  nread = getline(&line, &len, fp);
  if (nread == -1) {
    handle_error(ERR_IO_ERROR);
  }

  return line;
}

// Define a function to parse a line of input
int parse_line(char *line) {
  int value;

  if (sscanf(line, "%d", &value) != 1) {
    handle_error(ERR_INVALID_INPUT);
  }

  return value;
}

// Define a function to calculate the average of a list of numbers
double calculate_average(int *numbers, int count) {
  double sum = 0.0;
  for (int i = 0; i < count; i++) {
    sum += numbers[i];
  }

  return sum / count;
}

// Define a function to print the output
void print_output(double average) {
  printf("The average of the numbers is: %f\n", average);
}

// Main function
int main(int argc, char **argv) {
  if (argc != 2) {
    handle_error(ERR_INVALID_INPUT);
  }

  FILE *fp = open_file(argv[1]);

  // Read a line from the file
  char *line = read_line(fp);

  // Parse the line of input
  int count = parse_line(line);

  // Allocate memory for the array of numbers
  int *numbers = malloc(count * sizeof(int));
  if (numbers == NULL) {
    handle_error(ERR_MEMORY_ALLOCATION_FAILED);
  }

  // Read the remaining lines from the file and parse them
  for (int i = 0; i < count; i++) {
    line = read_line(fp);
    numbers[i] = parse_line(line);
  }

  // Calculate the average of the numbers
  double average = calculate_average(numbers, count);

  // Print the output
  print_output(average);

  // Free the allocated memory
  free(numbers);
  free(line);
  fclose(fp);

  return 0;
}