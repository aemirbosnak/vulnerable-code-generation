//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a log line
#define MAX_LINE_LENGTH 1024

// Define the maximum number of log lines to store
#define MAX_LINES 1000

// Define the structure of a log line
typedef struct log_line {
  char *line;
  int line_number;
} log_line;

// Create an array of log lines
log_line lines[MAX_LINES];

// The current number of log lines
int num_lines = 0;

// Read the log file into the array of log lines
void read_log_file(char *filename) {
  // Open the log file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening log file");
    exit(EXIT_FAILURE);
  }

  // Read each line of the log file
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    // Allocate memory for the log line
    lines[num_lines].line = malloc(strlen(line) + 1);
    if (lines[num_lines].line == NULL) {
      perror("Error allocating memory for log line");
      exit(EXIT_FAILURE);
    }

    // Copy the log line into the array
    strcpy(lines[num_lines].line, line);

    // Increment the number of log lines
    num_lines++;
  }

  // Close the log file
  fclose(fp);
}

// Search the array of log lines for a given string
int search_log_lines(char *string) {
  // Iterate over the array of log lines
  for (int i = 0; i < num_lines; i++) {
    // Check if the log line contains the string
    if (strstr(lines[i].line, string) != NULL) {
      // Print the log line
      printf("%s", lines[i].line);

      // Increment the number of matches
      return 1;
    }
  }
  return 0;
}

// Print the array of log lines
void print_log_lines() {
  // Iterate over the array of log lines
  for (int i = 0; i < num_lines; i++) {
    // Print the log line
    printf("%s", lines[i].line);
  }
}

// Free the memory allocated for the array of log lines
void free_log_lines() {
  // Iterate over the array of log lines
  for (int i = 0; i < num_lines; i++) {
    // Free the memory allocated for the log line
    free(lines[i].line);
  }
}

// The main function
int main(int argc, char *argv[]) {
  // Check if the user specified a log file
  if (argc != 2) {
    printf("Usage: %s <log file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Read the log file into the array of log lines
  read_log_file(argv[1]);

  // Search the array of log lines for the string "error"
  int num_matches = search_log_lines("error");

  // Print the number of matches
  printf("Found %d matches\n", num_matches);

  // Print the array of log lines
  print_log_lines();

  // Free the memory allocated for the array of log lines
  free_log_lines();

  return EXIT_SUCCESS;
}