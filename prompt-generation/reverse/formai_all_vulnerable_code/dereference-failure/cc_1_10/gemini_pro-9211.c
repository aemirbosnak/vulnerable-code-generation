//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a log line
#define MAX_LOG_LINE_LENGTH 1024

// Define the maximum number of log lines to store
#define MAX_LOG_LINES 1000

// Create a structure to store a log line
typedef struct log_line {
  char *line;
  int line_number;
} log_line;

// Create an array to store the log lines
log_line log_lines[MAX_LOG_LINES];

// Create a variable to store the number of log lines
int num_log_lines = 0;

// Read the log file into the array of log lines
int read_log_file(char *filename) {
  // Open the log file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }

  // Read each line from the log file
  char line[MAX_LOG_LINE_LENGTH];
  while (fgets(line, MAX_LOG_LINE_LENGTH, fp) != NULL) {
    // Allocate memory for the log line
    log_line *log_line = malloc(sizeof(log_line));
    if (log_line == NULL) {
      return -1;
    }

    // Copy the log line into the array of log lines
    log_line->line = strdup(line);
    log_line->line_number = num_log_lines;

    // Increment the number of log lines
    num_log_lines++;
  }

  // Close the log file
  fclose(fp);

  return 0;
}

// Print the log lines to the console
void print_log_lines() {
  // Iterate over each log line
  for (int i = 0; i < num_log_lines; i++) {
    // Print the log line
    printf("%d: %s", log_lines[i].line_number, log_lines[i].line);
  }
}

// Search the log lines for a specific string
int search_log_lines(char *string) {
  // Iterate over each log line
  for (int i = 0; i < num_log_lines; i++) {
    // Check if the log line contains the string
    if (strstr(log_lines[i].line, string) != NULL) {
      // Print the log line
      printf("%d: %s", log_lines[i].line_number, log_lines[i].line);

      return 0;
    }
  }

  // The string was not found in the log lines
  return -1;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user specified a log file
  if (argc != 2) {
    printf("Usage: %s <log_file>\n", argv[0]);
    return -1;
  }

  // Read the log file into the array of log lines
  if (read_log_file(argv[1]) != 0) {
    printf("Error reading log file\n");
    return -1;
  }

  // Print the log lines to the console
  print_log_lines();

  // Search the log lines for the string "error"
  if (search_log_lines("error") != 0) {
    printf("No errors found in the log file\n");
  }

  return 0;
}