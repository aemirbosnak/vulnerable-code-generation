//FormAI DATASET v1.0 Category: Log analysis ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_LINE_LENGTH 100

struct log_entry_t {
  char timestamp[20];
  char severity[10];
  char message[MAX_LOG_LINE_LENGTH];
};

int main() {
  char log_filename[] = "example.log";

  FILE *log_file = fopen(log_filename, "r");
  if (log_file == NULL) {
    printf("Error opening file %s\n", log_filename);
    return 1;
  }

  struct log_entry_t log_entries[MAX_LOG_ENTRIES];
  int num_entries = 0;

  char line[MAX_LOG_LINE_LENGTH];
  while (fgets(line, MAX_LOG_LINE_LENGTH, log_file)) {
    // Parse the timestamp, severity, and message from the log line
    char* timestamp = strtok(line, ",");
    char* severity = strtok(NULL, ",");
    char* message = strtok(NULL, ",");

    // Remove trailing newline from message
    message[strlen(message) - 1] = '\0';

    // Store the log entry in our log_entries array
    struct log_entry_t entry;
    strcpy(entry.timestamp, timestamp);
    strcpy(entry.severity, severity);
    strcpy(entry.message, message);
    log_entries[num_entries++] = entry;
  }

  // Analyze the log entries in various ways
  int num_errors = 0;
  int num_warnings = 0;
  for (int i = 0; i < num_entries; i++) {
    struct log_entry_t entry = log_entries[i];

    // Count number of errors and warnings
    if (strcmp(entry.severity, "ERROR") == 0) {
      num_errors++;
    } else if (strcmp(entry.severity, "WARNING") == 0) {
      num_warnings++;
    }

    // Print all log entries with "foo" in the message
    if (strstr(entry.message, "foo") != NULL) {
      printf("Log entry %d had 'foo' in the message: %s\n", i, entry.message);
    }
  }

  printf("Number of entries: %d\n", num_entries);
  printf("Number of errors: %d\n", num_errors);
  printf("Number of warnings: %d\n", num_warnings);

  fclose(log_file);
  return 0;
}