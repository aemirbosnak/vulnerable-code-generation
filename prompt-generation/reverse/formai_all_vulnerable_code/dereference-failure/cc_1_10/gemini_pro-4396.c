//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to hold the log entry information
typedef struct {
  char *timestamp;
  char *level;
  char *message;
} LogEntry;

// A function to parse a log entry from a line of text
LogEntry *parseLogEntry(char *line) {
  LogEntry *entry = malloc(sizeof(LogEntry));
  char *timestamp = strtok(line, " ");
  char *level = strtok(NULL, " ");
  char *message = strtok(NULL, "\n");
  entry->timestamp = strdup(timestamp);
  entry->level = strdup(level);
  entry->message = strdup(message);
  return entry;
}

// A function to print a log entry
void printLogEntry(LogEntry *entry) {
  printf("%s %s %s\n", entry->timestamp, entry->level, entry->message);
}

// A function to free the memory allocated for a log entry
void freeLogEntry(LogEntry *entry) {
  free(entry->timestamp);
  free(entry->level);
  free(entry->message);
  free(entry);
}

// A function to read a log file and print the entries
void readLogFile(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening log file");
    return;
  }

  char line[1024];
  while (fgets(line, sizeof(line), file) != NULL) {
    LogEntry *entry = parseLogEntry(line);
    printLogEntry(entry);
    freeLogEntry(entry);
  }

  fclose(file);
}

// The main function
int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <log file>\n", argv[0]);
    return 1;
  }

  readLogFile(argv[1]);

  return 0;
}