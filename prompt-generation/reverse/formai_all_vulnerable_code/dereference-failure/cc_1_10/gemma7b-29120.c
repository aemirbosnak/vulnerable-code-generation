//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct MetadataEntry {
  char key[MAX_BUFFER_SIZE];
  char value[MAX_BUFFER_SIZE];
} MetadataEntry;

int extractMetadata(char *filename, MetadataEntry **entries) {
  // Open the file and read its contents
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }

  // Allocate memory for the entries
  *entries = malloc(sizeof(MetadataEntry) * 10);
  if (*entries == NULL) {
    fclose(fp);
    return -1;
  }

  // Extract metadata entries
  int i = 0;
  char line[MAX_BUFFER_SIZE];
  while (fgets(line, MAX_BUFFER_SIZE, fp) != NULL) {
    // Remove comments and whitespace
    char *key = strchr(line, ':');
    if (key) {
      key = strchr(key, '#') ? strchr(key, ':') : key;
      strcpy((*entries)[i].key, key);

      // Get the value
      char *value = strchr(line, ' ') + 1;
      strcpy((*entries)[i].value, value);

      i++;
    }
  }

  // Close the file
  fclose(fp);

  // Return the number of entries
  return i;
}

int main() {
  MetadataEntry *entries = NULL;
  int numEntries = extractMetadata("my_file.txt", &entries);

  // Print the entries
  for (int i = 0; i < numEntries; i++) {
    printf("%s: %s\n", entries[i].key, entries[i].value);
  }

  // Free the memory
  free(entries);

  return 0;
}