//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char* file_name;
  char* author;
  char* description;
  int version;
  char* date_created;
} Metadata;

Metadata* extract_metadata(char* file_path) {
  FILE* file_handle = fopen(file_path, "r");
  if (file_handle == NULL) {
    return NULL;
  }
  Metadata* metadata = malloc(sizeof(Metadata));
  metadata->file_name = NULL;
  metadata->author = NULL;
  metadata->description = NULL;
  metadata->version = 0;
  metadata->date_created = NULL;
  char line[255];
  while (fgets(line, sizeof(line), file_handle)) {
    if (strncmp(line, "// FILE NAME:", 14) == 0) {
      char* file_name = malloc(sizeof(char) * strlen(line));
      sscanf(line, "// FILE NAME: %[^\n]", file_name);
      metadata->file_name = file_name;
    }
    else if (strncmp(line, "// AUTHOR:", 10) == 0) {
      char* author = malloc(sizeof(char) * strlen(line));
      sscanf(line, "// AUTHOR: %[^\n]", author);
      metadata->author = author;
    }
    else if (strncmp(line, "// DESCRIPTION:", 15) == 0) {
      char* description = malloc(sizeof(char) * strlen(line));
      sscanf(line, "// DESCRIPTION: %[^\n]", description);
      metadata->description = description;
    }
    else if (strncmp(line, "// VERSION:", 10) == 0) {
      int version;
      sscanf(line, "// VERSION: %d", &version);
      metadata->version = version;
    }
    else if (strncmp(line, "// DATE CREATED:", 15) == 0) {
      char* date_created = malloc(sizeof(char) * strlen(line));
      sscanf(line, "// DATE CREATED: %[^\n]", date_created);
      metadata->date_created = date_created;
    }
  }
  fclose(file_handle);
  return metadata;
}

int main() {
  Metadata* metadata = extract_metadata("example_file.c");
  if (metadata == NULL) {
    printf("Failed to extract metadata from file\n");
    return 1;
  }
  printf("File Name: %s\n", metadata->file_name);
  printf("Author: %s\n", metadata->author);
  printf("Description: %s\n", metadata->description);
  printf("Version: %d\n", metadata->version);
  printf("Date Created: %s\n", metadata->date_created);
  free(metadata->file_name);
  free(metadata->author);
  free(metadata->description);
  free(metadata->date_created);
  free(metadata);
  return 0;
}