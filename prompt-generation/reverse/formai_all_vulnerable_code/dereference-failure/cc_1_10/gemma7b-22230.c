//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

int main() {
  char line[MAX_LINE_LENGTH];
  char **metadata = NULL;
  char **lines = NULL;
  int line_num = 0;

  // Allocate memory for lines and metadata
  lines = malloc(MAX_LINE_LENGTH * sizeof(char *));
  metadata = malloc(MAX_LINE_LENGTH * sizeof(char *));

  // Read the file
  FILE *fp = fopen("example.txt", "r");
  if (fp) {
    // Line loop
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
      line_num++;

      // Strip whitespace from the line
      char *trimmed_line = strdup(line);
      char *start = trimmed_line;
      char *end = trimmed_line + strlen(trimmed_line) - 1;
      while (start <= end && isspace(*start)) {
        start++;
      }

      // Extract metadata from the line
      char *key = strchr(start, ':');
      if (key) {
        *key = '\0';
        metadata[line_num - 1] = strdup(start);
      } else {
        metadata[line_num - 1] = NULL;
      }

      // Store the line
      lines[line_num - 1] = strdup(line);
    }

    fclose(fp);
  }

  // Print the metadata
  for (int i = 0; metadata[i] != NULL; i++) {
    printf("%s: %s\n", metadata[i], lines[i]);
  }

  // Free the memory
  free(lines);
  free(metadata);

  return 0;
}