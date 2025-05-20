//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_FILES 10

// Function to read log files and print summary
void analyze_logs(const char* log_files[], int num_files) {
  int i;
  int total_lines = 0;
  int total_unique_lines = 0;
  int total_errors = 0;
  int total_warnings = 0;

  // Iterate over log files
  for (i = 0; i < num_files; i++) {
    FILE* log_file = fopen(log_files[i], "r");
    if (log_file == NULL) {
      perror("Error opening log file");
      continue;
    }

    // Read log file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
      // Check if line is empty or contains only whitespace
      if (strlen(line) == 0 || strspn(line, "\n\r") == strlen(line)) {
        continue;
      }

      // Count line as unique if it doesn't match previous line
      if (total_unique_lines == 0 || strcmp(line, log_files[i - 1]) != 0) {
        total_unique_lines++;
      }

      // Count errors and warnings
      if (strstr(line, "Error:") != NULL) {
        total_errors++;
      } else if (strstr(line, "Warning:") != NULL) {
        total_warnings++;
      }

      // Increment total lines count
      total_lines++;
    }

    // Close log file
    fclose(log_file);
  }

  // Print summary
  printf("Log Analysis Summary:\n");
  printf("Total lines: %d\n", total_lines);
  printf("Unique lines: %d (%.2f%% of total)\n", total_unique_lines,
          (total_unique_lines * 100) / total_lines);
  printf("Errors: %d (%.2f%% of total)\n", total_errors,
          (total_errors * 100) / total_lines);
  printf("Warnings: %d (%.2f%% of total)\n", total_warnings,
          (total_warnings * 100) / total_lines);
}

// Main function
int main(int argc, char* argv[]) {
  // Check command line arguments
  if (argc != 2) {
    printf("Usage: %s <log_files>\n", argv[0]);
    return 1;
  }

  // Initialize log file array
  char* log_files[MAX_LOG_FILES];
  int num_files = 0;

  // Read command line arguments
  for (int i = 1; i < argc; i++) {
    log_files[num_files] = argv[i];
    num_files++;
  }

  // Analyze logs
  analyze_logs(log_files, num_files);

  return 0;
}