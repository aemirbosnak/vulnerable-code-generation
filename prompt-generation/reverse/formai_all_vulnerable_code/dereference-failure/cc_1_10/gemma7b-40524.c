//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct MetaData {
  char name[100];
  char value[100];
} MetaData;

int main() {
  char **lines = NULL;
  int numLines = 0;
  char line[100];

  printf("Enter C metadata lines (separate lines with a blank line):\n");

  // Read the metadata lines
  while (getline(line, 100, stdin) != NULL) {
    lines = realloc(lines, (numLines + 1) * sizeof(char *));
    lines[numLines++] = strdup(line);
  }

  // Extract the metadata
  MetaData **metaData = NULL;
  int numMetaData = 0;
  for (int i = 0; i < numLines; i++) {
    char *key = strchr(lines[i], ':');
    if (key) {
      key = strdup(key + 1);
      char *value = strchr(lines[i], '=');
      if (value) {
        value = strdup(value + 1);
        metaData = realloc(metaData, (numMetaData + 1) * sizeof(MetaData));
        metaData[numMetaData++] = malloc(sizeof(MetaData));
        strcpy(metaData[numMetaData - 1]->name, key);
        strcpy(metaData[numMetaData - 1]->value, value);
      }
    }
  }

  // Print the extracted metadata
  for (int i = 0; i < numMetaData; i++) {
    printf("%s: %s\n", metaData[i]->name, metaData[i]->value);
  }

  // Free the memory
  free(lines);
  free(metaData);

  return 0;
}