//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of lines to read from the log file
#define MAX_LINES 1000

// Define the maximum length of a line in the log file
#define MAX_LINE_LENGTH 1024

// Define the maximum number of tokens to parse from a line
#define MAX_TOKENS 10

// Define the separator used to parse tokens from a line
#define SEPARATOR ","

// Define the structure of a log entry
typedef struct {
  time_t timestamp;
  char source[MAX_LINE_LENGTH];
  char message[MAX_LINE_LENGTH];
} log_entry;

// Define the function to read the log file and store the entries in an array
int read_log_file(const char *filename, log_entry *entries) {
  // Open the log file for reading
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening log file");
    return -1;
  }

  // Read the lines from the log file
  char line[MAX_LINE_LENGTH];
  int line_count = 0;
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    // Parse the line into tokens
    char *tokens[MAX_TOKENS];
    int token_count = 0;
    char *token = strtok(line, SEPARATOR);
    while (token != NULL) {
      tokens[token_count++] = token;
      token = strtok(NULL, SEPARATOR);
    }

    // Store the log entry in the array
    entries[line_count].timestamp = atol(tokens[0]);
    strcpy(entries[line_count].source, tokens[1]);
    strcpy(entries[line_count].message, tokens[2]);

    // Increment the line count
    line_count++;

    // Check if we have reached the maximum number of lines
    if (line_count >= MAX_LINES) {
      break;
    }
  }

  // Close the log file
  fclose(fp);

  // Return the number of lines read
  return line_count;
}

// Define the function to print the log entries
void print_log_entries(const log_entry *entries, int count) {
  // Print the header
  printf("Timestamp\tSource\t\tMessage\n");

  // Print the entries
  for (int i = 0; i < count; i++) {
    printf("%ld\t%s\t%s\n", entries[i].timestamp, entries[i].source, entries[i].message);
  }
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a log file name
  if (argc != 2) {
    printf("Usage: %s <log file name>\n", argv[0]);
    return -1;
  }

  // Allocate memory for the log entries
  log_entry entries[MAX_LINES];

  // Read the log file and store the entries in the array
  int count = read_log_file(argv[1], entries);
  if (count == -1) {
    return -1;
  }

  // Print the log entries
  print_log_entries(entries, count);

  return 0;
}