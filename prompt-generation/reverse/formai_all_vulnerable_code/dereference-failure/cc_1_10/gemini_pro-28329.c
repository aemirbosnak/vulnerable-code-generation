//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *level;
  char *component;
  char *message;
} LogEntry;

LogEntry *parse_log_line(char *line) {
  LogEntry *entry = malloc(sizeof(LogEntry));

  char *level = strtok(line, " ");
  char *component = strtok(NULL, " ");
  char *message = strtok(NULL, "\0");

  entry->level = level;
  entry->component = component;
  entry->message = message;

  return entry;
}

void print_log_entry(LogEntry *entry) {
  printf("%s - %s - %s\n", entry->level, entry->component, entry->message);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <log_file>\n", argv[0]);
    return 1;
  }

  FILE *log_file = fopen(argv[1], "r");
  if (log_file == NULL) {
    printf("Could not open log file: %s\n", argv[1]);
    return 1;
  }

  char line[1024];
  while (fgets(line, sizeof(line), log_file) != NULL) {
    LogEntry *entry = parse_log_line(line);
    print_log_entry(entry);
    free(entry);
  }

  fclose(log_file);
  return 0;
}