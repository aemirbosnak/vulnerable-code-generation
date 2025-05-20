//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent a log line.
typedef struct {
  char *timestamp;
  char *level;
  char *message;
} LogLine;

// Parse a line into its component parts.
int parse_log_line(char *line, LogLine *log_line) {
  char *tokens[3];
  int num_tokens = sscanf(line, "%s %s %s", tokens[0], tokens[1], tokens[2]);
  if (num_tokens != 3) {
    return 1;
  }

  log_line->timestamp = strdup(tokens[0]);
  log_line->level = strdup(tokens[1]);
  log_line->message = strdup(tokens[2]);

  return 0;
}

// Print a log line to the console.
void print_log_line(LogLine *log_line) {
  printf("%s %s %s\n", log_line->timestamp, log_line->level, log_line->message);
}

// Free the memory allocated for a log line.
void free_log_line(LogLine *log_line) {
  free(log_line->timestamp);
  free(log_line->level);
  free(log_line->message);
}

// Main function.
int main() {
  // Open the log file.
  FILE *log_file = fopen("log.txt", "r");
  if (log_file == NULL) {
    perror("fopen");
    return 1;
  }

  // Read each line from the log file and parse it.
  char line[1024];
  while (fgets(line, sizeof(line), log_file) != NULL) {
    LogLine log_line;
    if (parse_log_line(line, &log_line) == 0) {
      print_log_line(&log_line);
      free_log_line(&log_line);
    }
  }

  // Close the log file.
  fclose(log_file);

  return 0;
}