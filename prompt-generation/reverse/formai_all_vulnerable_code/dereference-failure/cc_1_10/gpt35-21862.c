//FormAI DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/**
 * A struct to store the log entry
 */
typedef struct {
  char timestamp[25];
  char message[MAX_LINE_LENGTH];
} LogEntry;

/**
 * Read a log entry from a string and store it in a LogEntry struct.
 * Assumes the log entry string is in the format "timestamp message".
 */
LogEntry parse_log_entry(char* log_entry_string) {
  LogEntry entry;
  char* token = strtok(log_entry_string, " ");
  strcpy(entry.timestamp, token);
  strcpy(entry.message, strtok(NULL, "\n"));
  return entry;
}

/**
 * Print the given log entry to stdout.
 */
void print_log_entry(LogEntry entry) {
  printf("%s %s\n", entry.timestamp, entry.message);
}

/**
 * Compare function to sort LogEntries by timestamp.
 */
int compare_entries(const void* a, const void* b) {
  LogEntry* entry_a = (LogEntry*)a;
  LogEntry* entry_b = (LogEntry*)b;
  return strcmp(entry_a->timestamp, entry_b->timestamp);
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <log_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE* log_file = fopen(argv[1], "r");

  if (!log_file) {
    printf("Error opening log file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // Read in each log entry
  LogEntry* entries = (LogEntry*)malloc(sizeof(LogEntry) * MAX_LINE_LENGTH);
  char line[MAX_LINE_LENGTH];
  int num_entries = 0;

  while (fgets(line, MAX_LINE_LENGTH, log_file)) {
    entries[num_entries++] = parse_log_entry(line);
  }

  // Sort the entries by timestamp
  qsort(entries, num_entries, sizeof(LogEntry), compare_entries);

  // Print the sorted log entries
  for (int i = 0; i < num_entries; i++) {
    print_log_entry(entries[i]);
  }

  fclose(log_file);
  free(entries);

  return EXIT_SUCCESS;
}