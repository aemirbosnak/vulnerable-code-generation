//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a log line
#define MAX_LOG_LINE_LENGTH 1024

// Function to read a log file line by line
char* read_log_line(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  if ((read = getline(&line, &len, fp)) != -1) {
    // Remove the newline character from the end of the line
    line[strcspn(line, "\n")] = '\0';
  }

  return line;
}

// Function to parse a log line and extract the timestamp, log level, and message
void parse_log_line(char *line, time_t *timestamp, char *log_level, char *message) {
  // Split the log line into fields
  char *fields[4];
  int num_fields = 0;
  char *field = strtok(line, " ");
  while (field != NULL) {
    fields[num_fields++] = field;
    field = strtok(NULL, " ");
  }

  // Extract the timestamp
  *timestamp = strtol(fields[0], NULL, 10);

  // Extract the log level
  strcpy(log_level, fields[1]);

  // Extract the message
  strcpy(message, fields[2]);
}

// Function to print the log line in a human-readable format
void print_log_line(time_t timestamp, char *log_level, char *message) {
  // Convert the timestamp to a human-readable format
  char *timestamp_str = ctime(&timestamp);

  // Print the log line
  printf("%s %s %s\n", timestamp_str, log_level, message);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a log file name
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <log_file_name>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the log file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("Error opening log file");
    return EXIT_FAILURE;
  }

  // Read the log file line by line
  char *line;
  while ((line = read_log_line(fp)) != NULL) {
    // Parse the log line
    time_t timestamp;
    char log_level[256];
    char message[MAX_LOG_LINE_LENGTH];
    parse_log_line(line, &timestamp, log_level, message);

    // Print the log line
    print_log_line(timestamp, log_level, message);

    // Free the memory allocated for the log line
    free(line);
  }

  // Close the log file
  fclose(fp);

  return EXIT_SUCCESS;
}