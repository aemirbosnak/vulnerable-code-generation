//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a log line
#define MAX_LOG_LINE_SIZE 1024

// Define the maximum number of log lines to analyze
#define MAX_LOG_LINES 1000

// Define the structure of a log line
typedef struct {
  char *line;
  int line_number;
} log_line;

// Define the function to read a log file into an array of log lines
int read_log_file(char *filename, log_line *log_lines) {
  // Open the log file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening log file");
    return -1;
  }

  // Read the log file line by line
  int line_number = 0;
  char line[MAX_LOG_LINE_SIZE];
  while (fgets(line, MAX_LOG_LINE_SIZE, file) != NULL) {
    // Allocate memory for the log line
    log_lines[line_number].line = malloc(strlen(line) + 1);
    if (log_lines[line_number].line == NULL) {
      perror("Error allocating memory for log line");
      return -1;
    }

    // Copy the log line into the array
    strcpy(log_lines[line_number].line, line);

    // Increment the line number
    line_number++;
  }

  // Close the log file
  fclose(file);

  // Return the number of log lines
  return line_number;
}

// Define the function to analyze the log lines
void analyze_log_lines(log_line *log_lines, int num_log_lines) {
  // Loop through the log lines
  for (int i = 0; i < num_log_lines; i++) {
    // Print the log line number
    printf("Log line %d: %s", log_lines[i].line_number, log_lines[i].line);

    // Parse the log line
    char *tokens[10];
    int num_tokens = 0;
    char *token = strtok(log_lines[i].line, " ");
    while (token != NULL) {
      tokens[num_tokens] = token;
      num_tokens++;
      token = strtok(NULL, " ");
    }

    // Check if the log line contains an error
    if (strstr(log_lines[i].line, "ERROR") != NULL) {
      // Print the error message
      printf("Error: %s", tokens[2]);
    } else if (strstr(log_lines[i].line, "WARNING") != NULL) {
      // Print the warning message
      printf("Warning: %s", tokens[2]);
    } else if (strstr(log_lines[i].line, "INFO") != NULL) {
      // Print the info message
      printf("Info: %s", tokens[2]);
    } else {
      // Print the debug message
      printf("Debug: %s", tokens[2]);
    }

    // Print a newline
    printf("\n");
  }
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user specified a log file
  if (argc != 2) {
    printf("Usage: %s <log file>\n", argv[0]);
    return -1;
  }

  // Read the log file into an array of log lines
  log_line log_lines[MAX_LOG_LINES];
  int num_log_lines = read_log_file(argv[1], log_lines);
  if (num_log_lines == -1) {
    return -1;
  }

  // Analyze the log lines
  analyze_log_lines(log_lines, num_log_lines);

  // Free the memory allocated for the log lines
  for (int i = 0; i < num_log_lines; i++) {
    free(log_lines[i].line);
  }

  // Return 0 to indicate success
  return 0;
}