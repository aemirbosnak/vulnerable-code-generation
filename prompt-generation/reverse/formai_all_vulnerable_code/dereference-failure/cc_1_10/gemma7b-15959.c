//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct MetaDataEntry {
  char *name;
  char *value;
  struct MetaDataEntry *next;
} MetaDataEntry;

int main() {
  char buffer[MAX_BUFFER_SIZE];
  char *line;
  int lineNumber = 0;
  MetaDataEntry *head = NULL;

  // Read the input file
  FILE *file = fopen("metadata.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Line-by-line processing
  while ((line = fgets(buffer, MAX_BUFFER_SIZE, file)) != NULL) {
    lineNumber++;
    // Extract metadata entries
    char *key = strstr(line, ":");
    if (key) {
      char *value = strstr(line, "=");
      if (value) {
        value++; // Skip the "=" character
        MetaDataEntry *newEntry = malloc(sizeof(MetaDataEntry));
        newEntry->name = strdup(key);
        newEntry->value = strdup(value);
        newEntry->next = head;
        head = newEntry;
      }
    }
  }

  // Print the extracted metadata
  printf("Extracted metadata:\n");
  for (MetaDataEntry *entry = head; entry; entry = entry->next) {
    printf("%s: %s\n", entry->name, entry->value);
  }

  fclose(file);
  return 0;
}