//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A magnifying glass for log analysis
typedef struct {
  char *filename;
  int lineno;
  char *message;
} LogEntry;

// Elementary, my dear Watson!
int main(int argc, char *argv[]) {
  // Acquiring the log file
  if (argc < 2) {
    printf("Usage: %s <log_file>\n", argv[0]);
    return EXIT_FAILURE;
  }
  char *filename = argv[1];

  // Opening the case file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening log file: %s\n", filename);
    return EXIT_FAILURE;
  }

  // Collecting the evidence
  LogEntry *entries = NULL;
  int num_entries = 0;
  char line[256];
  while (fgets(line, sizeof(line), file) != NULL) {
    // Parsing the clue
    LogEntry entry;
    entry.filename = strdup(filename);
    entry.lineno = 0;
    entry.message = strdup(line);

    // Extracting the line number
    char *ptr = strstr(line, ":");
    if (ptr != NULL) {
      entry.lineno = atoi(ptr + 1);
    }

    // Adding the entry to the case file
    entries = realloc(entries, (num_entries + 1) * sizeof(LogEntry));
    entries[num_entries++] = entry;
  }

  // Closing the case file
  fclose(file);

  // Examining the clues
  printf("Log Analysis Report for %s\n", filename);
  for (int i = 0; i < num_entries; i++) {
    LogEntry entry = entries[i];
    printf("Line %d: %s\n", entry.lineno, entry.message);
  }

  // Elementary, my dear Watson!
  printf("The analysis is complete, my friend.\n");

  // Cleaning up the crime scene
  for (int i = 0; i < num_entries; i++) {
    free(entries[i].filename);
    free(entries[i].message);
  }
  free(entries);

  return EXIT_SUCCESS;
}