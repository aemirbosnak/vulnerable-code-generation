//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *name;
  int count;
} LogEntry;

LogEntry *log_entries;
int num_log_entries;

void parse_log_file(FILE *fp) {
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    // Parse the line into a log entry.
    char *name = strtok(line, " ");
    int count = atoi(strtok(NULL, " "));

    // Add the log entry to the array.
    log_entries = realloc(log_entries, (num_log_entries + 1) * sizeof(LogEntry));
    log_entries[num_log_entries].name = strdup(name);
    log_entries[num_log_entries].count = count;
    num_log_entries++;
  }
}

void print_log_entries() {
  for (int i = 0; i < num_log_entries; i++) {
    printf("%s: %d\n", log_entries[i].name, log_entries[i].count);
  }
}

void free_log_entries() {
  for (int i = 0; i < num_log_entries; i++) {
    free(log_entries[i].name);
  }
  free(log_entries);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <log file>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }

  parse_log_file(fp);
  fclose(fp);

  print_log_entries();
  free_log_entries();

  return 0;
}