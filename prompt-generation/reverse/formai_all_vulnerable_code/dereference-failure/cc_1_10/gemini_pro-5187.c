//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a happy struct to store log data
typedef struct {
  char *message;
  int happiness_level;
} happy_log;

// Create a new happy log entry
happy_log *happy_log_new(char *message, int happiness_level) {
  happy_log *log = malloc(sizeof(happy_log));
  if (!log) {
    return NULL;
  }
  log->message = strdup(message);
  log->happiness_level = happiness_level;
  return log;
}

// Free a happy log entry
void happy_log_free(happy_log *log) {
  if (!log) {
    return;
  }
  free(log->message);
  free(log);
}

// Print a happy log entry
void happy_log_print(happy_log *log) {
  if (!log) {
    return;
  }
  printf("%s (%d)\n", log->message, log->happiness_level);
}

// Analyze a happy log file
void happy_log_analyze(char *filename) {
  // Open the log file
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Could not open log file");
    return;
  }

  // Read the log file line by line
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    // Parse the log line
    char *message = strtok(line, " ");
    int happiness_level = atoi(strtok(NULL, " "));

    // Create a new happy log entry
    happy_log *log = happy_log_new(message, happiness_level);
    if (!log) {
      perror("Could not create log entry");
      continue;
    }

    // Print the log entry
    happy_log_print(log);

    // Free the log entry
    happy_log_free(log);
  }

  // Close the log file
  fclose(file);
}

// Main function
int main(int argc, char **argv) {
  // Check if a log file was specified
  if (argc < 2) {
    printf("Usage: %s <log file>\n", argv[0]);
    return 1;
  }

  // Analyze the log file
  happy_log_analyze(argv[1]);

  return 0;
}