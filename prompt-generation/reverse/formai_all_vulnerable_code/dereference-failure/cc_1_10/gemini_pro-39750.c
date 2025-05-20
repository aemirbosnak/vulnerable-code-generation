//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursively parses a log file and prints its contents to the console.
void parse_log(FILE *file, int depth) {
  // Base case: End of file reached.
  if (feof(file)) {
    return;
  }

  // Read a line from the file.
  char line[1024];
  if (!fgets(line, sizeof(line), file)) {
    fprintf(stderr, "Error reading file.\n");
    exit(EXIT_FAILURE);
  }

  // Indent the line based on the depth.
  for (int i = 0; i < depth; i++) {
    printf("  ");
  }

  // Print the line.
  printf("%s", line);

  // Recursively parse any sublogs within the current line.
  char *start = strstr(line, "[");
  char *end = strstr(line, "]");
  if (start && end) {
    // Parse the sublog.
    FILE *sublog = fmemopen(start + 1, (end - start) - 1, "r");
    parse_log(sublog, depth + 1);
    fclose(sublog);
  }

  // Recursively parse the next line.
  parse_log(file, depth);
}

int main(int argc, char *argv[]) {
  // Check if a log file was specified.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Open the log file.
  FILE *file = fopen(argv[1], "r");
  if (!file) {
    fprintf(stderr, "Error opening file.\n");
    exit(EXIT_FAILURE);
  }

  // Parse the log file.
  parse_log(file, 0);

  // Close the log file.
  fclose(file);

  return EXIT_SUCCESS;
}