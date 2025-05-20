//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the log file name
#define LOG_FILE "mylog.txt"

// Define the maximum line length
#define MAX_LINE_LENGTH 1024

// Define the maximum number of lines
#define MAX_NUM_LINES 1000

// Define the log entry structure
typedef struct log_entry {
  char *line;
  int line_number;
} log_entry;

// Define the log structure
typedef struct log {
  log_entry *entries;
  int num_entries;
} log;

// Create a new log
log *create_log() {
  log *l = malloc(sizeof(log));
  l->entries = malloc(sizeof(log_entry) * MAX_NUM_LINES);
  l->num_entries = 0;
  return l;
}

// Destroy a log
void destroy_log(log *l) {
  for (int i = 0; i < l->num_entries; i++) {
    free(l->entries[i].line);
  }
  free(l->entries);
  free(l);
}

// Read a log from a file
log *read_log(char *filename) {
  log *l = create_log();

  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    perror("Error opening log file");
    return NULL;
  }

  char line[MAX_LINE_LENGTH];
  int line_number = 0;
  while (fgets(line, MAX_LINE_LENGTH, f) != NULL) {
    l->entries[l->num_entries].line = strdup(line);
    l->entries[l->num_entries].line_number = line_number;
    l->num_entries++;
    line_number++;
  }

  fclose(f);

  return l;
}

// Print a log
void print_log(log *l) {
  for (int i = 0; i < l->num_entries; i++) {
    printf("%d: %s", l->entries[i].line_number, l->entries[i].line);
  }
}

// Search a log for a string
int search_log(log *l, char *string) {
  for (int i = 0; i < l->num_entries; i++) {
    if (strstr(l->entries[i].line, string) != NULL) {
      return l->entries[i].line_number;
    }
  }

  return -1;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if a log file was specified
  if (argc != 2) {
    printf("Usage: %s <log file>\n", argv[0]);
    return 1;
  }

  // Read the log file
  log *l = read_log(argv[1]);
  if (l == NULL) {
    return 1;
  }

  // Print the log
  print_log(l);

  // Search the log for a string
  int line_number = search_log(l, "error");
  if (line_number == -1) {
    printf("No errors found in log file\n");
  } else {
    printf("Error found on line %d\n", line_number);
  }

  // Destroy the log
  destroy_log(l);

  return 0;
}