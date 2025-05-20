//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERROR_COUNT 10
#define MAX_WARNING_COUNT 10

// Function to extract the log file name and line number from a log line
void get_log_info(char *line, char **log_file_name, int *log_line_number) {
  char *token;
  int i = 0;

  // Split the log line into tokens
  token = strtok(line, ":");
  while (token != NULL && i < MAX_LINE_LENGTH) {
    log_file_name[i] = token;
    token = strtok(NULL, ":");
    i++;
  }

  // Get the log line number
  token = strtok(NULL, "\n");
  *log_line_number = atoi(token);
}

// Function to count the number of errors, warnings, and infos
void count_log_messages(char *log_file_name, int log_line_number, char *message) {
  int error_count = 0;
  int warning_count = 0;
  int info_count = 0;

  // Check if the message is an error, warning, or info
  if (strstr(message, "Error:") != NULL) {
    error_count++;
  } else if (strstr(message, "Warning:") != NULL) {
    warning_count++;
  } else if (strstr(message, "Info:") != NULL) {
    info_count++;
  }
}

// Function to analyze the log file and print the results
void analyze_log(char *log_file_name) {
  int error_count = 0;
  int warning_count = 0;
  int info_count = 0;
  int max_error_count = 0;
  int max_warning_count = 0;
  int max_info_count = 0;
  char *log_file_path = NULL;
  int log_file_fd = 0;

  // Open the log file
  log_file_path = strdup(log_file_name);
  log_file_fd = open(log_file_path, O_RDONLY);
  if (log_file_fd == -1) {
    perror("Error opening log file");
    exit(EXIT_FAILURE);
  }

  // Read the log file line by line
  char line[MAX_LINE_LENGTH];
  while (read(log_file_fd, line, MAX_LINE_LENGTH) > 0) {
    // Extract the log file name and line number from the log line
    char *log_file_name = NULL;
    int log_line_number = 0;
    get_log_info(line, &log_file_name, &log_line_number);

    // Count the number of errors, warnings, and infos
    count_log_messages(log_file_name, log_line_number, line);

    // Update the maximum error, warning, and info counts
    if (error_count > max_error_count) {
      max_error_count = error_count;
    }
    if (warning_count > max_warning_count) {
      max_warning_count = warning_count;
    }
    if (info_count > max_info_count) {
      max_info_count = info_count;
    }
  }

  // Print the results
  printf("Log Analysis Report:\n");
  printf("Log File: %s\n", log_file_name);
  printf("Error Count: %d\n", max_error_count);
  printf("Warning Count: %d\n", max_warning_count);
  printf("Info Count: %d\n", max_info_count);

  // Close the log file
  close(log_file_fd);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <log_file_name>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Analyze the log file
  analyze_log(argv[1]);

  return 0;
}